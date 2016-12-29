/** @file nim_cpp_global.cpp
  * @brief NIM SDK提供的一些全局接口
  * @copyright (c) 2015-2016, NetEase Inc. All rights reserved
  * @author towik, Oleg, Harrison
  * @date 2015/2/1
  */

#include "nim_cpp_global.h"
#include "nim_sdk_util.h"
#include "nim_client_def.h"
#include "nim_string_util.h"

namespace nim
{
#ifdef NIM_SDK_DLL_IMPORT
typedef	void (*nim_global_free_str_buf)(char *str);
typedef	void (*nim_global_free_buf)(void *data);
typedef void (*nim_global_set_proxy)(NIMProxyType, const char*, int, const char*, const char*);
typedef void(*nim_global_reg_sdk_log_cb)(const char *json_extension, nim_sdk_log_cb_func cb, const void *user_data);
//typedef void(*nim_global_net_detect)(NIMNetDetectType type, const char *app_key, const char *json_extension, nim_global_net_detect_cb_func cb, const void *user_data);
#else
#include "nim_global.h"
#endif


//static void CallbackNetDetect(int rescode, const char *json_params, const void *user_data)
//{
//	if (user_data != nullptr)
//	{
//		NetDetectCbInfo res;
//		res.res_code_ = rescode;
//		Json::Reader reader;
//		Json::Value values;
//		if (reader.parse(PCharToString(json_params), values) && values.isObject())
//		{
//			res.loss_ = values[kNIMNetDetectLoss].asInt();
//			res.rtt_max_ = values[kNIMNetDetectRttmax].asInt();
//			res.rtt_min_ = values[kNIMNetDetectRttmin].asInt();
//			res.rtt_avg_ = values[kNIMNetDetectRttavg].asInt();
//			res.rtt_mdev_ = values[kNIMNetDetectRttmdev].asInt();
//			res.expand_info_ = values[kNIMNetDetectDetail].asString();
//		}
//		Global::NetDetectCallback *cb = (Global::NetDetectCallback *)user_data;
//		(*cb)(rescode, res);
//		delete cb;
//	}
//}

void Global::FreeStrBuf(char *str)
{
	return NIM_SDK_GET_FUNC(nim_global_free_str_buf)(str);
}

void Global::FreeBuf(void *data)
{
	return NIM_SDK_GET_FUNC(nim_global_free_buf)(data);
}

void Global::SetProxy(NIMProxyType type, const std::string& host, int port, const std::string& user, const std::string& password)
{
	return NIM_SDK_GET_FUNC(nim_global_set_proxy)(type, host.c_str(), port, user.c_str(), password.c_str());
}

static void CallbackSDKLog(int log_level, const char *log, const void *user_data)
{
	Global::SDKLogCallback* cb = (Global::SDKLogCallback*)user_data;
	if (cb != nullptr)
	{
		std::string a;
		a.append(log);
		(*cb)(log_level, a);
	}
	//delete cb;
}
void Global::SetSDKLogCallback(const std::string&json_extension, const SDKLogCallback& callback)
{
	SDKLogCallback* cb_pointer = nullptr;
	if (callback)
	{
		cb_pointer = new SDKLogCallback(callback);
	}
	NIM_SDK_GET_FUNC(nim_global_reg_sdk_log_cb)(json_extension.c_str(), &CallbackSDKLog, cb_pointer);
}
//void Global::NetDetect(NIMNetDetectType type, const std::string& app_key, NetDetectCallback cb)
//{
//	NetDetectCallback* cb_pointer = nullptr;
//	if (cb)
//	{
//		cb_pointer = new NetDetectCallback(cb);
//	}
//	NIM_SDK_GET_FUNC(nim_global_net_detect)(type, app_key.c_str(), "", CallbackNetDetect, cb_pointer);
//}
}