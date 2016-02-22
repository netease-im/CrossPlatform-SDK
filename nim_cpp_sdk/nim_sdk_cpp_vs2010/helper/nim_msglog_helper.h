/** @file nim_msglog_helper.h
  * @brief msglog 辅助方法和数据结构定义
  * @copyright (c) 2015-2016, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/10/22
  */

#ifndef _NIM_SDK_CPP_MSGLOG_HELPER_H_
#define _NIM_SDK_CPP_MSGLOG_HELPER_H_

#include <string>
#include <list>
#include <functional>
#include "json.h"
#include "nim_talk_helper.h"

/**
* @namespace nim
* @brief namespace nim
*/
namespace nim
{

/** @brief 查询到消息历史结果 */
struct QueryMsglogResult
{
	int count_;						/**< 消息数 */
	std::list<IMMessage> msglogs_;	/**< 消息 */

	/** 构造函数 */
	QueryMsglogResult() : count_(0) {}
};

/** @fn bool ParseMsglogs(const std::string& msgs_json, QueryMsglogResult& res)
  * @brief 解析查询到的消息历史结果
  * @param[in] msgs_json 查询到的消息历史(Json Value数据字符串)
  * @param[out] res 消息历史结果
  * @return bool 解析成功 或失败
  */
bool ParseMsglogs(const std::string& msgs_json, QueryMsglogResult& res);

} //namespace nim

#endif //_NIM_SDK_CPP_MSGLOG_HELPER_H_