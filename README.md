# Windows(PC) SDK 开发手册(C++ 封装层)
## <span id="概述">概述</span>
Windows(PC) SDK对外暴露的是C接口，为了让桌面开发者更加方便快捷的接入SDK，我们基于C接口封装了C++ SDK，既可以让开发者方便直观的调用接口使用云信的服务，也可以供基于C接口开发的的开发者作为参考。

## <span id="开发准备">开发准备</span>
可以通过官网下载SDK以及Demo源码，SDK包含C接口API文件和C++封装层的API文件及项目文件。 

### <span id="SDK内容">SDK内容</span>
* nim.dll： SDK核心功能模块；放在用户程序目录下
* nim_audio.dll： 负责语音录制和播放；放在用户程序目录下
* nim\_tools\_http.dll： 负责通用的http传输；nim.dll模块使用了此功能，C++封装层(需要依赖Demo工程)
* nrtc.dll： 负责视频聊天功能；放在用户程序目录下
* nim_conf： SDK版本相关；放在用户程序目录下
* nim_include： SDK所有头文件；用户自己决定放在合适位置  
* nim\_c\_sdk： C 接口头文件
* nim\_cpp\_sdk: C++ 头文件、实现文件以及工程文件

### <span id="SDK C++封装层类讲解">SDK C++封装层类讲解</span>

SDK C++封装层代码在nim\_cpp\_sdk\下，主要封装了以下核心类：

* nim::Client: 全局管理功能：主要包括SDK初始化/清理、客户端登录/注销/重连/掉线/多点登录/把其他端踢下线等功能
* nim::DataSync: 数据同步接口：提供注册监听数据同步结果的接口
* nim::Friend: 好友功能：主要包括添加、删除好友、通过验证，拒绝好友请求、获取好友列表等功能
* nim::Global: 全局接口：提供SDK分配的内存的释放的相关接口
* nim::User: 用户特殊关系管理功能：主要包括设置对方消息静音和取消静音，把对方加入黑名单和从黑名单移除
* nim::Talk: 聊天功能：主要包括发送消息、接受消息等功能
* nim::Team: 群功能：主要包括查询群信息、查询群成员信息、加人、踢人、转移群主、设置管理员、接受入群邀请等功能
* nim::Audio: 语音消息功能：主要包括语音消息录制和播放功能
* nim::VChat: 音视频功能：主要包括初始化/清理、发起会话、设置通话模式、会话控制、结束会话等功能
* nim::SystemMsg: 系统消息和自定义通知功能：主要包括注册接收系统消息、发送自定义通知，删除查询系统消息等功能
* nim::Session: 会话列表管理功能：主要包括查询会话列表，删除会话列表等功能
* nim::MsgLog: 消息历史功能（不包含系统消息）：主要包括查询消息，设置消息读取状态，删除消息和导出消息到本地等功能。
* nim::NOS: NOS云服务功能：主要包括资源文件的上传和下载功能，支持断点续传。
* nim::Rts:	RTS会话功能：主要包括发起RTS会话，接收会话请求，监听会话，会话控制和结束会话等功能。
* nim::Tool: 提供的一些工具接口，主要包括获取SDK里app account对应的app data目录、计算md5、语音转文字等
* nim::User: 用户信息托管：提供基础的用户信息托管服务。
* nim_audio::Audio: 语音播放功能
* nim_http::HttpRequest: Http上传下载功能

此外，每个类都包含一个对应Helper文件，如nim\_cpp\_client.h对应nim\_client\_helper.h，主要包含接口需要的辅助方法和数据结构的定义。

## <span id="接入SDK C++封装层">接入SDK C++封装层</span>
### <span id="添加SDK C++封装层">添加SDK C++封装层</span>
在nim\_cpp\_sdk\nim\_sdk\_cpp_vs2010下包含nim\_sdk\_cpp\_lib.vcxproj项目文件，该工程是基于Visual Studio 2010开发，开发者可以通过解决方案右键添加已有项目将该项目文件添加到自己的工程，如果开发者已有解决方案的开发环境高于VS2010，请在导入的同时升级SDK项目，导入后编辑需要引用到SDK API的项目，在属性-通用属性-框架和引用中添加SDK项目为新的引用。当然开发者也可以仅仅将提供的SDK静态库添加到自己的工程，但是这里还是建议开发者将源码引入到自己的工程，方便扩展和调试。

### <span id="添加所需的第三方库">添加所需的第三方库</span>
SDK C++项目文件依赖第三方库jsoncpp，我们随包提供了基于vs2010编译的jsoncpp\_d.lib和jsoncpp.lib(nim\_cpp\_sdk\nim\_sdk\_cpp\_vs2010\libs)，同时为了方便vs其他版本的开发者使用，也附带了jsoncpp的源码(nim\_cpp\_sdk\nim\_sdk\_cpp_vs2010\third\_party)，开发者可以根据需要编译不同版本的json库(解决方案文件在nim\_cpp\_sdk\nim\_sdk\_cpp\_vs2010\third\_party\jsoncpp\makefiles\msvc2010)，编译第三方库的时候要注意属性-C/C++/代码生成选项卡中的运行库要与主程序的运行库保持一致。

当然，开发者也可以使用自己熟悉的json有关的第三方库，如果使用其他第三方库，需要手工调整C++ SDK源码中引用到jsoncpp对象的代码。

添加完第三方库后，还需要设置工程属性中，C/C++-常规中，附加包含目录添加第三方库的头文件路径(nim\_cpp\_sdk\nim\_sdk\_cpp\_vs2010\third\_party\jsoncpp\include)，这样方便在代码中包含json所需的头文件。
 
## <span id="初始化SDK">初始化SDK</span>
*代码示例摘抄自DEMO源码，main.cpp。*

	static void InitNim()
	{
		std::wstring server_conf_path = QPath::GetAppPath();
		server_conf_path.append(L"server_conf.txt");
		nim::SDKConfig config;
		TiXmlDocument document;
		if (shared::LoadXmlFromFile(document, server_conf_path))
		{
			TiXmlElement* root = document.RootElement();
			if (root)
			{
				bool use_private_server = false;
				Json::Value srv_config;
				if (auto pchar = root->Attribute("kNIMLbsAddress")) {
					config.lbs_address_ = pchar;
					use_private_server = true;
				}
				if (auto pchar = root->Attribute("kNIMNosLbsAddress")) {
					config.nos_lbs_address_ = pchar;
					use_private_server = true;
				}
				if (auto pchar = root->Attribute("kNIMDefaultLinkAddress")) {
					config.default_link_address_.push_back(pchar);
					use_private_server = true;
				}
				if (auto pchar = root->Attribute("kNIMDefaultNosUploadAddress")) {
					config.default_nos_upload_address_.push_back(pchar);
					use_private_server = true;
				}
				if (auto pchar = root->Attribute("kNIMDefaultNosDownloadAddress")) {
					config.default_nos_download_address_.push_back(pchar);
				}
				if (auto pchar = root->Attribute("kNIMDefaultNosAccessAddress")) {
					config.default_nos_access_address_.push_back(pchar);
					use_private_server = true;
				}
				if (auto pchar = root->Attribute("kNIMRsaPublicKeyModule")) {
					config.rsa_public_key_module_ = pchar;
					use_private_server = true;
				}
				if (auto pchar = root->Attribute("kNIMRsaVersion")) {
					nbase::StringToInt((std::string)pchar, &config.rsa_version_);
					use_private_server = true;
				}
				config.use_private_server_ = use_private_server;
			}
		}

		//sdk能力参数（必填）
		config.database_encrypt_key_ = "Netease"; //string（db key必填，目前只支持最多32个字符的加密密钥！建议使用32个字符）

		bool ret = nim::Client::Init("Netease", "", config); // 载入云信sdk，初始化安装目录和用户目录
		assert(ret);

		nim_ui::InitManager::GetInstance()->InitUiKit();
	}

在程序退出前，调用接口：

*代码摘抄自DEMO源码，nim\_ui\_init\_manager.cpp。*

	void InitManager::CleanupUiKit()
	{
		nim::Client::Cleanup();
	}


## <span id="登录与登出">登录与登出</span>

### <span id="首次登录">首次登录</span>

SDK 登录后会同步群信息，离线消息，漫游消息，系统通知等数据，所以首次登录前需要提前注册一些全局回调（具体说明请参阅API 文档）：

*代码摘抄自DEMO源码，nim\_ui\_init\_manager.cpp。*

	 void InitManager::InitUiKit()
	{
		bool ret = nim::VChat::Init(""); // 初始化云信音视频
		assert(ret);

		nim_http::Init(); // 初始化云信http

		/* 以下注册的回调函数，都是在收到服务器推送的消息或事件时执行的。因此需要在程序开始时就注册好。 */
		//注册重连、被踢、掉线、多点登录、把移动端踢下线的回调
		nim::Client::RegReloginCb(&nim_comp::LoginCallback::OnReLoginCallback);
		nim::Client::RegKickoutCb(&nim_comp::LoginCallback::OnKickoutCallback);
		nim::Client::RegDisconnectCb(&nim_comp::LoginCallback::OnDisconnectCallback);
		nim::Client::RegMultispotLoginCb(&nim_comp::LoginCallback::OnMultispotLoginCallback);
		nim::Client::RegKickOtherClientCb(&nim_comp::LoginCallback::OnKickoutOtherClientCallback);

		//注册返回发送消息结果的回调，和收到消息的回调。
		nim::Talk::RegSendMsgCb(nbase::Bind(&nim_comp::TalkCallback::OnSendMsgCallback, std::placeholders::_1));
		nim::Talk::RegReceiveCb(nbase::Bind(&nim_comp::TalkCallback::OnReceiveMsgCallback, std::placeholders::_1));
		nim::SystemMsg::RegSendCustomSysmsgCb(nbase::Bind(&nim_comp::TalkCallback::OnSendCustomSysmsgCallback, std::placeholders::_1));

		//注册群事件的回调
		nim::Team::RegTeamEventCb(nbase::Bind(&nim_comp::TeamCallback::OnTeamEventCallback, std::placeholders::_1));

		//注册返回发送自定义消息的结果的回调，和收到系统消息（包括自定义消息）的回调
		nim::SystemMsg::RegSendCustomSysmsgCb(nbase::Bind(&nim_comp::TalkCallback::OnSendCustomSysmsgCallback, std::placeholders::_1));
		nim::SystemMsg::RegSysmsgCb(nbase::Bind(&nim_comp::TeamCallback::OnReceiveSysmsgCallback, std::placeholders::_1));

		//注册NOS下载回调
		nim::NOS::RegDownloadCb(nbase::Bind(&nim_comp::HttpCallback::OnHttpDownloadCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

		//注册音视频回调
		nim::VChat::SetVideoDataCb(true, nim_comp::VChatCallback::VideoCaptureData);
		nim::VChat::SetVideoDataCb(false, nim_comp::VChatCallback::VideoRecData);
		nim::VChat::SetCbFunc(nim_comp::VChatCallback::VChatCb);

		//注册白板消息回调
		nim::Rts::SetStartNotifyCb(nbase::Bind(&nim_comp::RtsCallback::StartNotifyCb, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
		nim::Rts::SetAckNotifyCb(nbase::Bind(&nim_comp::RtsCallback::AckNotifyCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
		nim::Rts::SetSyncAckNotifyCb(nbase::Bind(&nim_comp::RtsCallback::SyncAckNotifyCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		nim::Rts::SetConnectNotifyCb(nbase::Bind(&nim_comp::RtsCallback::ConnectNotifyCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
		nim::Rts::SetMemberChangeCb(nbase::Bind(&nim_comp::RtsCallback::MemberNotifyCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
		nim::Rts::SetHangupNotifyCb(nbase::Bind(&nim_comp::RtsCallback::HangupNotifyCallback, std::placeholders::_1, std::placeholders::_2));
		nim::Rts::SetControlNotifyCb(nbase::Bind(&nim_comp::RtsCallback::ControlNotifyCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		nim::Rts::SetRecDataCb(nbase::Bind(&nim_comp::RtsCallback::RecDataCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

		nim_comp::emoji::LoadEmoji();
	}

### <span id="登录">登录</span>

*代码摘抄自DEMO源码，login\_callback.cpp。*

	void LoginCallback::DoLogin( std::string user, std::string pass )
	{
		assert(LoginManager::GetInstance()->GetLoginStatus() == LoginStatus_NONE);
		LoginManager::GetInstance()->SetLoginStatus(LoginStatus_LOGIN);

		LoginManager::GetInstance()->SetAccount(user);
		std::string pass_md5 = QString::GetMd5(pass);
		LoginManager::GetInstance()->SetPassword(pass_md5);

		_InitUserFolder();
		_InitLog();
		{
			int ver = 0;
			std::wstring vf;
			LocalHelper::GetAppLocalVersion(ver, vf);
			QLOG_APP(L"App Version {0}") << ver;
			QLOG_APP(L"Account {0}") << LoginManager::GetInstance()->GetAccount();
			QLOG_APP(L"UI ThreadId {0}") << GetCurrentThreadId();
			QLOG_APP(L"-----login begin-----");
		}

		//app key是应用的标识，不同应用之间的数据（用户、消息、群组等）是完全隔离的。开发自己的应用时，请替换为自己的app key。
		std::string app_key = "45c6af3c98409b18a84451215d0bdd6e";
		std::string new_app_key = GetConfigValue(g_AppKey);
		if (!new_app_key.empty())
		{
			app_key = new_app_key;
		}
		auto cb = std::bind(OnLoginCallback, std::placeholders::_1, nullptr);
		nim::Client::Login(app_key, LoginManager::GetInstance()->GetAccount(), LoginManager::GetInstance()->GetPassword(), cb);
	}

登录回调函数：

*代码摘抄自DEMO源码，login\_callback.cpp。*

	void LoginCallback::OnLoginCallback( const nim::LoginRes& login_res, const void* user_data )
	{
		QLOG_APP(L"OnLoginCallback: {0} - {1}") << login_res.login_step_ << login_res.res_code_;

		if (login_res.res_code_ == nim::kNIMResSuccess)
		{
			if (login_res.login_step_ == nim::kNIMLoginStepLogin)
			{
				Post2UI(nbase::Bind(&UILoginCallback, login_res.res_code_, false));
				if (!login_res.other_clients_.empty())
				{
					Post2UI(nbase::Bind(LoginCallback::OnMultispotChange, true, login_res.other_clients_));
				}
			}
		}
		else
		{
			Post2UI(nbase::Bind(&UILoginCallback, login_res.res_code_, false));
		}
	}

**注意：**

SDK的回调函数并不会保存用户调用接口时的线程状态，所以用户需要自行切换线程，例如上面源码中，通过调用Post2UI方法，将回调实际处理函数抛到主线程(UI线程)中运行。
  
### <span id="注销/登出">注销/登出</span>

*代码摘抄自DEMO源码，login\_callback.cpp。*

	void NimLogout(nim::NIMLogoutType type = nim::kNIMLogoutAppExit)
	{
		QLOG_APP(L"-----logout begin {0}-----") << type;
		nim::Client::Logout( type, &LoginCallback::OnLogoutCallback );
	}

## <span id="基础消息功能">基础消息功能</span>

### <span id="消息功能概述">消息功能概述</span>
SDK(PC) 原生支持发送文本、图片、文件等3种类型消息，同时支持用户发送自定义的消息类型。

### <span id="发送消息">发送消息</span>

以发送图片消息为例。

*代码摘抄自DEMO源码，session\_form.cpp。*

	void SessionForm::SendImage( const std::wstring &src )
	{
		nim::IMMessage msg;
		PackageMsg(msg);
		msg.type_ = nim::kNIMMessageTypeImage;

		std::wstring filename = nbase::UTF8ToUTF16(msg.client_msg_id_);
		std::wstring dest = GetUserImagePath() + filename;
		GenerateUploadImage(src, dest);
		msg.local_res_path_ = nbase::UTF16ToUTF8(dest);

		nim::IMImage img;
		img.md5_ = GetFileMD5(dest);
		img.size_ = (long)nbase::GetFileSize(dest);

		Gdiplus::Image image(dest.c_str());
		if (image.GetLastStatus() != Gdiplus::Ok)
		{
			assert(0);
		}
		else
		{
			img.width_ = image.GetWidth();
			img.height_ = image.GetHeight();
		}

		msg.attach_ = img.ToJsonString();
		
		AddSendingMsg(msg);

		std::string json_msg = nim::Talk::CreateImageMessage(msg.receiver_accid_, msg.session_type_, msg.client_msg_id_, img, msg.local_res_path_, msg.timetag_);
		nim::Talk::SendMsg(json_msg);
	}

### <span id="接收消息">接收消息</span>

提前注册好接收消息的回调函数。在接收到消息时，如果是图片、语音消息，那么SDK 会自动下载，然后通过注册的HTTP回调函数通知。如果下载失败，则调用接口nim_http_fetch_media 重新下载。此外，还可以调用nim_http_stop_fetch_media 停止下载（目前仅对文件消息类型有效）。

*代码摘抄自DEMO源码，session\_callback.cpp。*

	void TalkCallback::OnReceiveMsgCallback(const nim::IMMessage& message)
	{
		QLOG_PRO(L"OnReceiveMsgCallback: {0}") << message.client_msg_id_;
		std::string id = GetSessionId(message);
		//会话窗口
		if (message.feature_ == nim::kNIMMessageFeatureDefault)
		{
			if (message.type_ == nim::kNIMMessageTypeNotification)
			{
				SessionForm* session = SessionManager::GetInstance()->Find(id);
				if (session)
				{
					session->AddNewMsg(message, false);
				}
			}
			else
			{
				SessionManager::GetInstance()->AddNewMsg(message);
			}
		}
		else if (message.feature_ == nim::kNIMMessageFeatureSyncMsg || message.feature_ == nim::kNIMMessageFeatureRoamMsg)
		{
			SessionForm* session = SessionManager::GetInstance()->Find(id);
			if (session)
			{
				session->AddNewMsg(message, false);
			}
		}
		else if (message.feature_ == nim::kNIMMessageFeatureCustomizedMsg)
		{
			SessionForm* session = SessionManager::GetInstance()->Find(id);
			if (session)
			{
				session->AddNewMsg(message, false);
			}
		}
	}