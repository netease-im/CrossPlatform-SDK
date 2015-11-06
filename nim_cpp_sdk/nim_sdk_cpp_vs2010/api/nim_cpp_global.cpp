/** @file nim_cpp_global.cpp
  * @brief NIM SDK提供的一些全局接口
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author towik, Oleg
  * @date 2015/2/1
  */

#include "nim_cpp_global.h"
#include "nim_sdk_helper.h"

namespace nim
{

typedef	void (*nim_global_free_str_buf)(char *str);
typedef	void (*nim_global_free_buf)(void *data);

void Global::FreeStrBuf(char *str)
{
	return NIM_SDK_GET_FUNC(nim_global_free_str_buf)(str);
}

void Global::FreeBuf(void *data)
{
	return NIM_SDK_GET_FUNC(nim_global_free_buf)(data);
}

}