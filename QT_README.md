以加载IM sdk为例

1. 将libs、 nim_c_sdk、 nim_chatroom_c_sdk、 nim_chatroom_cpp、 nim_sdk_cpp、 third_party目录拷贝到开发者解决方案目录下
1. 解决方案添加nim_sdk_cpp\nim_sdk_cpp_lib_vs2013.vcxproj
2. app project 引用nim_sdk_cpp_lib
3. app project 属性 常规 输出目录设置保证与SDK dll同级目录
4. app project 属性 C/C++ 附加包含目录增加

		..\nim_chatroom_c_sdk\util;..\nim_chatroom_c_sdk\include;..\nim_chatroom_cpp\util;..\nim_chatroom_cpp\helper;..\nim_chatroom_cpp\api;..\nim_chatroom_cpp;..\nim_sdk_cpp;..\nim_sdk_cpp\api;..\nim_sdk_cpp\helper;..\nim_sdk_cpp\util;..\nim_c_sdk\include;..\nim_c_sdk\util;..\third_party\jsoncpp\include\json;..\nim_tools_cpp_sdk\nim_http_cpp;..\nim_tools_cpp_sdk\nim_audio_cpp;

目录为相对路径，最终可能需要根据开发者解决方案的实际路径做调整

5. app project 属性 C/C++ 预处理器定义 增加 NIM\_WIN\_DESKTOP\_ONLY\_SDK