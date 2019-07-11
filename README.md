# Windows(PC) SDK 开发手册(C++ 封装层)

## 前言

### 版本更新
[传输门](http://dev.netease.im/docs/product/IM%E5%8D%B3%E6%97%B6%E9%80%9A%E8%AE%AF/%E6%9B%B4%E6%96%B0%E6%97%A5%E5%BF%97/Windows%E7%AB%AF%E6%9B%B4%E6%96%B0%E6%97%A5%E5%BF%97)

### 开发集成
[传输门](http://dev.netease.im/docs/product/IM%E5%8D%B3%E6%97%B6%E9%80%9A%E8%AE%AF/SDK%E5%BC%80%E5%8F%91%E9%9B%86%E6%88%90/Windows%E5%BC%80%E5%8F%91%E9%9B%86%E6%88%90)

### 接口文档
[传输门](http://dev.netease.im/docs/interface/%E5%8D%B3%E6%97%B6%E9%80%9A%E8%AE%AFWindows%E7%AB%AF/NIMSDKAPI_CPP/html/index.html)

## 概述
Windows(PC) SDK对外暴露的是C接口，为了让桌面开发者更加方便快捷的接入SDK，我们基于C接口封装了C++ SDK，既可以让开发者方便直观的调用接口使用云信的服务，也可以供基于C接口开发的的开发者作为参考。

注：SDK 兼容的系统有 Windows xp(sp2及以上）、Windows 7、Windows 8/8.1、Windows 10。**SDK 从V3.2.5版本开始全面支持32位和64位程序接入。**

## 开发准备
可以通过官网下载SDK以及Demo源码，SDK包含C接口API文件和C++封装层的API文件及项目文件。 

### SDK内容
### <span id="SDK 目录结构及主要文件介绍">SDK 目录结构及主要文件介绍</span>
    nim_sdk ........................................................ SDK目录
        bin ........................................................ SDK二进制文件目录
	        x86_dlls ............................................... x86 SDK二进制文件目录
	            redist_packages .................................... vs2017 x86 运行时库
	        x64_dlls ............................................... x64 SDK二进制文件目录
                redist_packages .................................... vs2017 x64 运行时库
        include .................................................... SDK 引入包含目录
            depend_lib ............................................. SDK C++封装层依赖库目录
                include ............................................ SDK C++封装层依赖库包含目录
                    json ........................................... Json工具包含目录
                    nim_json_util.h ................................ JSON工具辅助方法
                    nim_sdk_util.h ................................. 提供加载/卸载SDK以及获取接口的方法
            nim_c_api.h ............................................ c im api引入文件
            nim_chatroom_c_api.h ................................... c chatroom api引入文件
            nim_cpp_api.h .......................................... c++ im api 引入文件
            nim_chatroom_cpp_api.h ................................. c++ chatroom api 引入文件
            nim_cpp_tools_api.h .................................... nim 工具类api 引入文件
        public_define .............................................. SDK 共公类型定义目录 c/c++都会引用到数据结构定义
            defines ................................................ im/chatroom/nim_tools数据类型定义目录
            util ................................................... 编译开关及基础类型定义目录
            nim_sdk_define_include.h ............................... im 公共数据类型定义引入文件
            nim_chatroom_define_include.h .......................... chatroom 公共数据类型定义引入文件
            nim_tool_define_include.h .............................. nim_tools 公共数据类型定义引入文件
            nim_util_include.h ..................................... 基础类型定义引入文件
        src ........................................................ c api/c++封装层实现代码目录
            c_sdk .................................................. c api 定义代码目录                
            cpp_sdk ................................................ c++封装层代码目录
                depend_lib ......................................... c++封装层依赖库的实现代码目录
                    cpp_wrapper_util_md.sln ........................ c++封装层依赖库 md/mdd 运行时库工程的解决方案文件
                    cpp_wrapper_util_mt.sln ........................ c++封装层依赖库 mt/mtd 运行时库工程的解决方案文件
                nim ................................................ im c++封装层实现代码目录
                    nim_sdk_cpp_wrapper_dll.vcxproj ................ im c++封装层动态库工程文件 
                    nim_sdk_cpp_wrapper_lib_md.vcxproj ............. im c++封装层静态库 md/mdd 运行时库工程文件
                    nim_sdk_cpp_wrapper_lib_mt.vcxproj ............. im c++封装层静态库 mt/mtd 运行时库工程文件
                nim_chatroom ....................................... chatrooom c++封装层实现代码目录
                    nim_chatroom_sdk_cpp_wrapper_dll.vcxproj ....... chatrooom c++封装层动态库工程文件
                    nim_chatroom_sdk_cpp_wrapper_lib_md.vcxproj .... chatrooom c++封装层静态库 md/mdd 运行时库工程文件
                    nim_chatroom_sdk_cpp_wrapper_lib_mt.vcxproj .... chatrooom c++封装层静态库 mt/mtd 运行时库工程文件
                nim_tools .......................................... nim tools c++封装层实现代码目录
                    audio .......................................... audio模块 c++封装层实现代码目录
                    http ........................................... http模块 c++封装层实现代码目录
        libs ....................................................... c++封装层(静态库)、依赖库输出目录
            x86 .................................................... x86平台输出目录
                md ................................................. md/mdd 运行时库输出目录
                mt ................................................. mt/mtd 运行时库输出目录
            x64 .................................................... x64平台输出目录
                md ................................................. md/mdd 运行时库输出目录
                mt ................................................. mt/mtd 运行时库输出目录

#### <span id="SDK二进制文件介绍">SDK二进制文件介绍</span>
* x64_dlls：存放64位Dll的文件夹
* x86_dlls：存放32位Dll的文件夹
* nim.dll： SDK主模块；放在用户程序目录下
* nim_audio.dll： 负责语音录制和播放；放在用户程序目录下
* nim\_tools\_http.dll： 负责通用的http传输；nim.dll加载了此模块，需要放在用户程序目录下
* nrtc.dll： 负责视频聊天功能；放在用户程序目录下
* nrtc\_audio\_process.dll： 负责音频处理；放在用户程序目录下
* nim\_audio\_hook.dll： 负责辅助采集播放器音频，由nrtc.dll调用；放在用户程序目录下，x64位暂时不提供该Dll。
* nim_conf： SDK版本相关；放在用户程序目录下
* README.md: C/C++ SDK开发手册。
* QT\_README.md: C++ QT项目接入手册。

SDK不提供debug版本的动态链接库供开发者调试，如果遇到问题请联系技术支持或在线客服。

### 快速接入SDK

前往[Windows(PC) SDK Getting Started](http://dev.netease.im/docs/product/通用/新手接入/即时通讯/WindowsGettingStarted "target=_blank")

### SDK C++封装层类讲解

SDK C++封装层代码在nim\_cpp\_sdk\下，主要封装了以下核心类：

* nim::Client: 全局管理功能：主要包括SDK初始化/清理、客户端登录/注销/重连/掉线/多点登录/把其他端踢下线等功能
* nim::DataSync: 数据同步接口：提供注册监听数据同步结果的接口
* nim::Friend: 好友功能：主要包括添加、删除好友、通过验证，拒绝好友请求、获取好友列表等功能
* nim::Global: 全局接口：提供SDK分配的内存的释放的相关接口
* nim::User: 用户特殊关系管理功能：主要包括设置对方消息静音和取消静音，把对方加入黑名单和从黑名单移除
* nim::Talk: 聊天功能：主要包括发送消息、接受消息等功能
* nim::Team: 群功能：主要包括查询群信息、查询群成员信息、加人、踢人、转移群主、设置管理员、接受入群邀请等功能
* nim::VChat: 音视频功能：主要包括初始化/清理、发起会话、设置通话模式、会话控制、结束会话等功能
* nim::SystemMsg: 系统消息和自定义通知功能：主要包括注册接收系统消息、发送自定义通知，删除查询系统消息等功能
* nim::Session: 会话列表管理功能：主要包括查询会话列表，删除会话列表等功能
* nim::MsgLog: 消息历史功能（不包含系统消息）：主要包括查询消息，设置消息读取状态，删除消息和导出消息到本地等功能。
* nim::NOS: NOS云服务功能：主要包括资源文件的上传和下载功能，支持断点续传。
* nim::Rts:	RTS会话功能：主要包括发起RTS会话，接收会话请求，监听会话，会话控制和结束会话等功能。
* nim::Tool: 提供的一些工具接口，主要包括获取SDK里app account对应的app data目录、计算md5、语音转文字等
* nim::User: 用户信息托管：提供基础的用户信息托管服务。
* nim_chatroom::ChatRoom: 聊天室服务
* nim_audio::Audio: 语音播放功能
* nim_http::HttpRequest: Http上传下载功能

此外，每个类都包含一个对应Helper文件，如nim\_cpp\_client.h对应nim\_client\_helper.h，主要包含接口需要的辅助方法和数据结构的定义。

## 接入SDK C++封装层
### 文件包含目录

引入SDK时包含目录包含到nim_sdk目录即可，以im demo 的custom_app_sdk工程为例，如下图
    
<div align="center"><img width="954" height="608" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUyXzVmYmFhMDk2LTU5OWQtNGE3Yy05ODhiLTAyZWM1ZDI4OWFmMQ%3D%3D?createTime=1562682851"/></div>

### c++封装层引入解决方案

C++封装层的工程文件在nim_sdk/src/nim/、nim_sdk/src/nim_chatroom/目录下，可以直接添加到解决方案中，以im demo为例如下图
<div align="center"><img width="368" height="319" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUzX2IzMTAxMjA1LWIzNzktNDQ1OS04Yzk0LTBlZDZmNjdkYTEwYw%3D%3D?createTime=1562683553"/></div>


### 静态库引入

C++封装层(静态库方式)缺省的输出目录为nim_sdk/libs/x86/md(mt)/、nim_sdk/libs/x64/md(mt)/，在库管理器中可以根据选择的运行时库指定附加依库目录到libs相应的目录并指定相应的静态库到附加依赖项中，以im demo 的custom_app_sdk工程为例，如下图
<div align="center"><img width="949" height="604" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUyX2Y1MGE2YzU1LTg4MWEtNDZjOC1hYWYzLWY3OWVjMGRhY2I0OA%3D%3D?createTime=1562683204"/></div>

### C++动态库的使用方式
C++封装层(静态库方式)缺省的输出目录为nim_sdk/bin/x86_dlls/、nim_sdk/bin/x64_dlls/,当以动态库的方式使用c++封装层时，可以将生成后的nim_sdk_cpp_wrapper_dll.dll/nim_sdk_cpp_wrapper_dll_d.dll、nim_chatroom_sdk_cpp_wrapper_dll.dll/nim_chatroom_sdk_cpp_wrapper_dll_d.dll拷贝到指定目录(例如exe的输出目录),以im demo的custom_app_sdk工程为例，如下图
<div align="center"><img width="951" height="604" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUzX2JiOTU5MzIzLTcwZGYtNDdjMS1iNjFkLWYwM2FjNWQ4OWZlYg%3D%3D?createTime=1562684550"/></div>

### C++封装层依赖库编译
C++封装层依赖库(depend_lib)预先生成了vs2013运行时库为md(mdd)/mt(mtd),debug/release版本的静态库，如果开发者需要不同vs版本(不同的平台工具集)的可静态库,以打开nim_sdk/src/cpp_sdk/depend_lib/cpp_wrapper_util_md.sln(cpp_wrapper_util_mt.sln)，修改cpp_wrapper工程的平台工具集来生成相应的版本.

### SDK回调应用层的异步实现
SDK在回调应用层时，如果应用层没有进行异步处理，可能会阻塞SDK内部线程，发生SDK没有响应、断线等问题，为了避免这种情况的发生，应用层在接收到SDK的回调时最好转为异步。SDK实现了指定异步回调的接口

	/** @fn void SetCallbackFunction(const ChatRoom::SDKClosure& callback)
  	* 当以动态库使用SDK时 设置SDK回调方法，为了不阻塞SDK线程，在回调中应该把任务抛到应用层的线程中
  	* @param[in] callback	  回调方法
  	* @return void 无返回值
  	*/
	static void SetCallbackFunction(const SDKClosure& callback);
以 im demo为例，其使用方法如下

    nim::Client::SetCallbackFunction([](const StdClosure & task) {
		nbase::ThreadManager::PostTask(ThreadId::kThreadUI, task);
	});

**导入后注意调整平台工作集（属性-配置属性-常规），运行库（属性-配置属性-C/C++），附加包含目录（属性-配置属性-C/C++-常规），附加依赖项/附加库目录（属性-配置属性-库管理器）等。**