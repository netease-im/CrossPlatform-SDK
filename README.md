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
* x64_dlls：存放64位Dll的文件夹
* x86_dlls：存放32位Dll的文件夹
* nim.dll： SDK核心功能模块；放在用户程序目录下
* nim_audio.dll： 负责语音录制和播放；放在用户程序目录下
* nim\_tools\_http.dll： 负责通用的http传输；nim.dll加载了此模块，需要放在用户程序目录下
* nrtc.dll： 负责视频聊天功能；放在用户程序目录下
* nrtc\_audio\_process.dll： 负责音频处理；放在用户程序目录下
* nim\_audio\_hook.dll： 负责辅助采集播放器音频，由nrtc.dll调用；放在用户程序目录下，x64位暂时不提供该Dll。
* nim_conf： SDK版本相关；放在用户程序目录下
* nim\_c\_sdk： IM C 接口说明以及SDK所有定义的头文件（*_def.h头文件用户自己决定放在合适位置）。
* nim\_chatroom\_c\_sdk: 聊天室 C 接口说明以及SDK所有定义的头文件（*_def.h头文件用户自己决定放在合适位置）。
* nim\_sdk\_cpp\_vs2010：IM C接口的C++封装层，包括工程文件，工程文件为VS2010创建，用户添加进自己的工程后可根据开发环境升级该工程文件。
* nim\_chatroom\_cpp\_vs2010：聊天室C接口的C++封装层，包括工程文件，工程文件为VS2010创建，用户添加进自己的工程后可根据开发环境升级该工程文件。
* nim\_tools\_c\_sdk：SDK工具类（语音录制播放和Http）C接口说明以及所有定义的头文件（*_def.h头文件用户自己决定放在合适位置）。
* nim\_tools\_cpp\_sdk：SDK工具类（语音录制播放和Http）C接口的C++封装层。

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
### 添加SDK C++封装层
在nim\_cpp\_sdk\\nim\_sdk\_cpp_vs2010下包含nim\_sdk\_cpp\_lib.vcxproj项目文件，该工程是基于Visual Studio 2010开发，开发者可以通过解决方案右键添加已有项目将该项目文件添加到自己的工程，如果开发者已有解决方案的开发环境高于VS2010，请在导入的同时升级SDK项目，导入后编辑需要引用到SDK API的项目，在属性-通用属性-框架和引用中添加SDK项目为新的引用。当然开发者也可以仅仅将提供的SDK静态库添加到自己的工程，但是这里还是建议开发者将源码引入到自己的工程，方便扩展和调试。

### 添加所需的第三方库
SDK C++项目文件依赖第三方库jsoncpp，我们随包提供了基于vs2010编译的jsoncpp\_d.lib和jsoncpp.lib(nim\_cpp\_sdk\\nim\_sdk\_cpp\_vs2010\\libs)，同时为了方便vs其他版本的开发者使用，也附带了jsoncpp的源码(nim\_cpp\_sdk\\nim\_sdk\_cpp_vs2010\\third\_party)，开发者可以根据需要编译不同版本的json库(解决方案文件在nim\_cpp\_sdk\\nim\_sdk\_cpp\_vs2010\\third\_party\\jsoncpp\\makefiles\\msvc2010)，编译第三方库的时候要注意属性-C/C++/代码生成选项卡中的运行库要与主程序的运行库保持一致。

当然，开发者也可以使用自己熟悉的json有关的第三方库，如果使用其他第三方库，需要手工调整C++ SDK源码中引用到jsoncpp对象的代码。

添加完第三方库后，还需要设置工程属性中，C/C++-常规中，附加包含目录添加第三方库的头文件路径(nim\_cpp\_sdk\\nim\_sdk\_cpp\_vs2010\\third\_party\\jsoncpp\\include)，这样方便在代码中包含json所需的头文件。

**导入后注意调整平台工作集（属性-配置属性-常规），运行库（属性-配置属性-C/C++），附加包含目录（属性-配置属性-C/C++-常规），附加依赖项/附加库目录（属性-配置属性-库管理器）等。**