/** @file nim_msg_helper.h
  * @brief Message 通用辅助方法和数据结构定义
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/10/20
  */

#ifndef _NIM_SDK_CPP_MESSAGE_HELPER_H_
#define _NIM_SDK_CPP_MESSAGE_HELPER_H_

#include <string>
#include <list>
#include <functional>
#include "json.h"

/**
* @namespace nim
* @brief namespace nim
*/
namespace nim
{

#include "nim_res_code_def.h"

/** @struct 发送消息回执 */
struct SendMessageArc
{
	std::string talk_id_;	/**< 会话ID */
	std::string msg_id_;	/**< 消息ID */
	NIMResCode rescode_;	/**< 错误码 */
};

/** @fn bool ParseSendMessageArc(const std::string& arc_json, SendMessageArc& arc)
  * @brief 解析发送消息回执
  * @param[in] arc_json 发送消息回执(Json Value数据字符串)
  * @param[out] arc 发送消息回执
  * @return bool 解析成功 或失败
  */
bool ParseSendMessageArc(const std::string& arc_json, SendMessageArc& arc);

} //namespace nim

#endif //_NIM_SDK_CPP_MESSAGE_HELPER_H_