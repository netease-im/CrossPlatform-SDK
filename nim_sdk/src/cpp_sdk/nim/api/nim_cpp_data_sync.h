﻿/** @file nim_cpp_data_sync.h
  * @brief 数据同步
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @date 2015/09/23
  */

#ifndef _NIM_SDK_CPP_DATASYNC_H_
#define _NIM_SDK_CPP_DATASYNC_H_

#include <string>
#include <functional>
#include "public_define/nim_sdk_define_include.h"
#include "src/cpp_sdk/nim/nim_sdk_cpp_wrapper_dll.h"
/**
* @namespace nim
* @brief namespace nim
*/
namespace nim
{
/** @class DataSync
  * @brief NIM SDK提供的数据同步相关接口
  */
class NIM_SDK_CPPWRAPPER_DLL_API DataSync
{

public:
	typedef std::function<void(nim::NIMDataSyncType sync_type, nim::NIMDataSyncStatus status, const std::string &data_sync_info)> DataSyncCallback;	/**< 数据同步通知回调模板 */
	
public:
	/** @fn static void RegCompleteCb(const DataSyncCallback& cb)
	* (全局回调)注册数据同步完成的回调函数
	* @param[in] cb 数据同步完成的回调函数
	* @return void 无返回值
	*/
	static void RegCompleteCb(const DataSyncCallback& cb);

	/** @fn void UnregDataSyncCb()
	* 反注册DataSync提供的所有回调
	* @return void 无返回值
	*/
	static void UnregDataSyncCb();

};

} 

#endif //_NIM_SDK_CPP_DATASYNC_H_