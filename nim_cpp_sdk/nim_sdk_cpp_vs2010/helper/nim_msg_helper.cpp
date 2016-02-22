/** @file nim_msg_helper.cpp
  * @brief Message 通用辅助方法和数据结构定义
  * @copyright (c) 2015-2016, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/10/20
  */

#include "nim_msg_helper.h"

namespace nim
{
#include "nim_talk_def.h"

bool ParseSendMessageArc(const std::string& arc_json, SendMessageArc& arc)
{
	Json::Value values;
	Json::Reader reader;
	if (reader.parse(arc_json, values) && values.isObject())
	{
		arc.rescode_ = (NIMResCode)values[kNIMSendArcKeyRescode].asUInt();
		arc.msg_id_ = values[kNIMSendArcKeyMsgId].asString();
		arc.talk_id_ = values[kNIMSendArcKeyTalkId].asString();
		return true;
	}
	return false;
}

}
