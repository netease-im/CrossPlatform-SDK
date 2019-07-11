﻿/** @file nim_session_helper.cpp
  * @brief Session 辅助方法和数据结构定义
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @date 2015/10/22
  */

#include "src/cpp_sdk/nim/helper/nim_session_helper.h"

namespace nim
{
bool ParseSession(const std::string& session_json, SessionData& session)
{
	nim_cpp_wrapper_util::Json::Value values;
	nim_cpp_wrapper_util::Json::Reader reader;
	if (reader.parse(session_json, values) && values.isObject())
	{
		ParseSession(values, session);
		return true;
	}
	return false;
}

void ParseSession(const nim_cpp_wrapper_util::Json::Value& session_json, SessionData& session)
{
	session.id_ = session_json[kNIMSessionId].asString();
	session.type_ = (NIMSessionType)session_json[kNIMSessionType].asUInt();
	session.unread_count_ = session_json[kNIMSessionUnreadCount].asUInt();
	session.command_ = (NIMSessionCommand)session_json[kNIMSessionCommand].asUInt();
	session.msg_id_ = session_json[kNIMSessionMsgClientID].asString();
	session.msg_sender_accid_ = session_json[kNIMSessionMsgFromAccount].asString();
	session.msg_timetag_ = session_json[kNIMSessionMsgTime].asUInt64();
	session.msg_type_ = (NIMMessageType)session_json[kNIMSessionMsgType].asUInt();
	session.msg_content_ = session_json[kNIMSessionMsgBody].asString();
	session.msg_attach_ = session_json[kNIMSessionMsgAttach].asString();
	session.msg_status_ = (NIMMsgLogStatus)session_json[kNIMSessionMsgStatus].asUInt();
	session.msg_sub_status_ = (NIMMsgLogSubStatus)session_json[kNIMSessionMsgSubStatus].asUInt();
	session.last_updated_msg_ = session_json[kNIMSessionLastUpdatedMsg].asBool();
	session.placed_on_top_ = session_json[kNIMSessionOnTop].asBool();
	session.extend_data_ = session_json[kNIMSessionExtendedData].asString();
	session.is_robot_session_ = session_json[kNIMSessionRobotFlag].asBool();
}

bool ParseSessionList(const std::string& sessions_json, SessionDataList& session_list)
{
	nim_cpp_wrapper_util::Json::Value values;
	nim_cpp_wrapper_util::Json::Reader reader;
	if (reader.parse(sessions_json, values) && values.isObject())
	{
		session_list.count_ = values[kNIMSessionListCount].asUInt();
		session_list.unread_count_ = values[kNIMSessionListUnreadCount].asUInt();
		nim_cpp_wrapper_util::Json::Value sessions = values[kNIMSessionListContent];
		int len = sessions.size();
		for (int i = 0; i < len; i++)
		{
			SessionData session;
			ParseSession(sessions[i], session);
			session_list.sessions_.push_back(session);
		}
		return true;
	}
	return false;
}

}