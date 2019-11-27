# Windows c++封装层接入指南

## 快速接入

前往[Windows(PC) SDK Getting Started](http://dev.netease.im/docs/product/通用/新手接入/即时通讯/WindowsGettingStarted "target=_blank")

## 文件包含目录

引入SDK时包含目录包含到nim_sdk目录即可，以im demo 的custom_app_sdk工程为例，如下图
    
<div align="center"><img width="954" height="608" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUyXzVmYmFhMDk2LTU5OWQtNGE3Yy05ODhiLTAyZWM1ZDI4OWFmMQ%3D%3D?createTime=1562682851"/></div>

## c++封装层引入解决方案

C++封装层的工程文件在nim_sdk/src/nim/、nim_sdk/src/nim_chatroom/目录下，可以直接添加到解决方案中，以im demo为例如下图
<div align="center"><img width="368" height="319" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUzX2IzMTAxMjA1LWIzNzktNDQ1OS04Yzk0LTBlZDZmNjdkYTEwYw%3D%3D?createTime=1562683553"/></div>


## 静态库引入

C++封装层(静态库方式)缺省的输出目录为nim_sdk/libs/x86/md(mt)/、nim_sdk/libs/x64/md(mt)/，在库管理器中可以根据选择的运行时库指定附加依库目录到libs相应的目录并指定相应的静态库到附加依赖项中，以im demo 的custom_app_sdk工程为例，如下图
<div align="center"><img width="949" height="604" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUyX2Y1MGE2YzU1LTg4MWEtNDZjOC1hYWYzLWY3OWVjMGRhY2I0OA%3D%3D?createTime=1562683204"/></div>

## C++动态库的使用方式
C++封装层(静态库方式)缺省的输出目录为nim_sdk/bin/x86_dlls/、nim_sdk/bin/x64_dlls/,当以动态库的方式使用c++封装层时，可以将生成后的nim_sdk_cpp_wrapper_dll.dll/nim_sdk_cpp_wrapper_dll_d.dll、nim_chatroom_sdk_cpp_wrapper_dll.dll/nim_chatroom_sdk_cpp_wrapper_dll_d.dll拷贝到指定目录(例如exe的输出目录),以im demo的custom_app_sdk工程为例，如下图
<div align="center"><img width="951" height="604" src="https://nim-nosdn.netease.im/MTAxMTAwMg%3D%3D%2FbmltYV8xOTQzNjk4MF8xNTYyNjgyODQyNjUzX2JiOTU5MzIzLTcwZGYtNDdjMS1iNjFkLWYwM2FjNWQ4OWZlYg%3D%3D?createTime=1562684550"/></div>

## C++封装层依赖库编译
C++封装层依赖库(depend_lib)预先生成了vs2013运行时库为md(mdd)/mt(mtd),debug/release版本的静态库，如果开发者需要不同vs版本(不同的平台工具集)的可静态库,以打开nim_sdk/src/cpp_sdk/depend_lib/cpp_wrapper_util_md.sln(cpp_wrapper_util_mt.sln)，修改cpp_wrapper工程的平台工具集来生成相应的版本.

**导入后注意调整平台工作集（属性-配置属性-常规），运行库（属性-配置属性-C/C++），附加包含目录（属性-配置属性-C/C++-常规），附加依赖项/附加库目录（属性-配置属性-库管理器）等。**

## SDK回调应用层的异步实现

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