﻿/** @file nim_talk_helper.h
  * @brief Talk 辅助方法和数据结构定义
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @date 2015/10/16
  */

#ifndef _NIM_SDK_CPP_TALK_HELPER_H_
#define _NIM_SDK_CPP_TALK_HELPER_H_

#include <string>
#include <list>
#include <functional>
#include "include/depend_lib/include/nim_json_util.h"
#include "src/cpp_sdk/nim/helper/nim_sdk_loader_helper.h"
#include "public_define/nim_sdk_define_include.h"
#include "src/cpp_sdk/nim/nim_sdk_cpp_wrapper_dll.h"
/**
* @namespace nim
* @brief namespace nim
*/
namespace nim
{

/** @brief 消息属性设置 */
struct NIM_SDK_CPPWRAPPER_DLL_API MessageSetting
{
	BoolStatus resend_flag_;			/**< 该消息是否为重发状态 */
	BoolStatus server_history_saved_;	/**< 该消息是否存储云端历史 */
	BoolStatus roaming_;				/**< 该消息是否支持漫游 */
	BoolStatus self_sync_;				/**< 该消息是否支持发送者多端同步 */
	BoolStatus need_push_; 				/**< 是否需要推送 */
	BoolStatus push_need_badge_;		/**< 是否要做消息计数 */
	BoolStatus push_need_prefix_;		/**< 需要推送昵称 */
	BoolStatus routable_;				/**< 是否要抄送 */
	BoolStatus need_offline_;			/**< 是否支持离线消息 */
	nim_cpp_wrapper_util::Json::Value push_payload_;			/**< 第三方自定义的推送属性，长度2048 */
	std::string push_content_;			/**< 自定义推送文案，长度限制200字节 */
	nim_cpp_wrapper_util::Json::Value server_ext_;			/**< 第三方扩展字段, 长度限制1024 */
	std::string local_ext_;				/**< 本地扩展字段, 格式不限，长度限制1024 */
	BoolStatus is_force_push_;			/**< 群组消息强推开关，强推全员设置true并强推列表为空 */
	std::list<std::string> force_push_ids_list_;	/**< 群组消息强推列表 */
	std::string force_push_content_;	/**< 群组消息强推文本 */
	BoolStatus anti_spam_enable_;		/**< 是否需要过易盾反垃圾 */
	std::string anti_spam_content_;		/**< (可选)开发者自定义的反垃圾字段,长度限制5000 */
	std::string anti_apam_biz_id_;		/**< (可选)用户配置的对某些单条消息另外的反垃圾的业务ID*/
	int anti_apam_using_yidun_;	/**< int,  (可选) 单条消息是否使用易盾反垃圾 0:(在开通易盾的情况下)不过易盾反垃圾而是通用反垃圾 其他都是按照原来的规则*/
	BoolStatus client_anti_spam_hitting_;	/**< (可选) 是否命中客户端反垃圾*/
	BoolStatus team_msg_need_ack_;		/** 群消息是否需要已读业务，0：不需要，1：需要*/
	BoolStatus team_msg_ack_sent_;		/**< 是否已经发送群消息已读回执 */
	int team_msg_unread_count_;			/**< 群消息未读数 */
	BoolStatus is_update_session_;			/**< (可选) 消息是否需要刷新到session服务，0:否，1:是；只有消息存离线的情况下，才会判断该参数，缺省：1*/
	/** 构造函数 */
	MessageSetting() : resend_flag_(BS_NOT_INIT)
		, server_history_saved_(BS_NOT_INIT)
		, roaming_(BS_NOT_INIT)
		, self_sync_(BS_NOT_INIT)
		, need_push_(BS_NOT_INIT)
		, push_need_badge_(BS_NOT_INIT)
		, push_need_prefix_(BS_NOT_INIT)
		, routable_(BS_NOT_INIT)
		, need_offline_(BS_NOT_INIT)
		, is_force_push_(BS_NOT_INIT)
		, anti_spam_enable_(BS_NOT_INIT)
		,anti_apam_biz_id_("")
		,anti_apam_using_yidun_(1)
		, client_anti_spam_hitting_(BS_NOT_INIT)
		, team_msg_need_ack_(BS_NOT_INIT)
		, team_msg_ack_sent_(BS_NOT_INIT)
		, team_msg_unread_count_(-1)
		, is_update_session_(BS_NOT_INIT){}

	/** @fn void ToJsonValue(nim_cpp_wrapper_util::Json::Value& message) const
	  * @brief 组装Json Value字符串
	  * @param[out] message 消息Json
	  * @return void
      */
	void ToJsonValue(nim_cpp_wrapper_util::Json::Value& message) const
	{
		if (server_history_saved_ != BS_NOT_INIT)
			message[kNIMMsgKeyHistorySave] = server_history_saved_;
		if (roaming_ != BS_NOT_INIT)
			message[kNIMMsgKeyMsgRoaming] = roaming_;
		if (self_sync_ != BS_NOT_INIT)
			message[kNIMMsgKeyMsgSync] = self_sync_;
		if (push_need_badge_ != BS_NOT_INIT)
			message[kNIMMsgKeyPushNeedBadge] = push_need_badge_;
		if (need_push_ != BS_NOT_INIT)
			message[kNIMMsgKeyPushEnable] = need_push_;
		if (push_need_prefix_ != BS_NOT_INIT)
			message[kNIMMsgKeyPushNeedPrefix] = push_need_prefix_;
		if (resend_flag_ != BS_NOT_INIT)
			message[kNIMMsgKeyResendFlag] = resend_flag_;
		if (routable_ != BS_NOT_INIT)
			message[kNIMMsgKeyMsgRoutable] = routable_;
		if (need_offline_ != BS_NOT_INIT)
			message[kNIMMsgKeySetMsgOffline] = need_offline_;
		if (!push_payload_.empty())
			message[kNIMMsgKeyPushPayload] = GetJsonStringWithNoStyled(push_payload_);
		if (!push_content_.empty())
			message[kNIMMsgKeyPushContent] = push_content_;
		if (!server_ext_.empty())
			message[kNIMMsgKeyServerExt] = GetJsonStringWithNoStyled(server_ext_);
		if (!local_ext_.empty())
			message[kNIMMsgKeyLocalExt] = local_ext_;
		if (is_force_push_ != BS_NOT_INIT)
			message[kNIMMsgKeyIsForcePush] = is_force_push_ == BS_TRUE ? 1 : 0;
		if (!force_push_content_.empty())
			message[kNIMMsgKeyForcePushContent] = force_push_content_;
		if (!force_push_ids_list_.empty())
		{
			std::string ids_json;
			StrListToJsonString(force_push_ids_list_, ids_json);
			message[kNIMMsgKeyForcePushList] = ids_json;
		}
		if (anti_spam_enable_ != BS_NOT_INIT)
			message[kNIMMsgKeyAntiSpamEnable] = anti_spam_enable_ == BS_TRUE ? 1 : 0;
		if (!anti_spam_content_.empty())
			message[kNIMMsgKeyAntiSpamContent] = anti_spam_content_;
		if(!anti_apam_biz_id_.empty())
			message[kNIMMsgKeyAntiSpamBizId] = anti_apam_biz_id_;
		message[kNIMMsgKeyAntiSpamUsingYiDun] = anti_apam_using_yidun_;
		if (client_anti_spam_hitting_ != BS_NOT_INIT)
			message[kNIMMsgKeyClientAntiSpam] = client_anti_spam_hitting_;
		if (team_msg_need_ack_ != BS_NOT_INIT)
			message[kNIMMsgKeyTeamMsgAck] = team_msg_need_ack_;
		if (team_msg_ack_sent_ != BS_NOT_INIT)
			message[kNIMMsgKeyLocalKeyTeamMsgAckSent] = team_msg_ack_sent_;
		if (team_msg_unread_count_ > -1)
			message[kNIMMsgKeyLocalKeyTeamMsgUnreadCount] = team_msg_unread_count_;		
		if (is_update_session_ != BS_NOT_INIT)
			message[kNIMMsgKeyIsUpdateSession] = is_update_session_;
	}

	/** @fn void ParseMessageSetting(const nim_cpp_wrapper_util::Json::Value& message)
	  * @brief 从Json Value解析出消息属性设置
	  * @param[in] message 消息Json
	  * @return void
      */
	void ParseMessageSetting(const nim_cpp_wrapper_util::Json::Value& message)
	{
		if (message.isMember(kNIMMsgKeyHistorySave))
			server_history_saved_ = message[kNIMMsgKeyHistorySave].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyMsgRoaming))
			roaming_ = message[kNIMMsgKeyMsgRoaming].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyMsgSync))
			self_sync_ = message[kNIMMsgKeyMsgSync].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyPushNeedBadge))
			push_need_badge_ = message[kNIMMsgKeyPushNeedBadge].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyPushEnable))
			need_push_ = message[kNIMMsgKeyPushEnable].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyPushNeedPrefix))
			push_need_prefix_ = message[kNIMMsgKeyPushNeedPrefix].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyResendFlag))
			resend_flag_ = message[kNIMMsgKeyResendFlag].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyMsgRoutable))
			routable_ = message[kNIMMsgKeyMsgRoutable].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeySetMsgOffline))
			need_offline_ = message[kNIMMsgKeySetMsgOffline].asInt() == 1 ? BS_TRUE : BS_FALSE;
		nim_cpp_wrapper_util::Json::Reader reader;
		if(message.isMember(kNIMMsgKeyServerExt) && !message[kNIMMsgKeyServerExt].asString().empty())
			if ((!reader.parse(message[kNIMMsgKeyServerExt].asString(), server_ext_) || !server_ext_.isObject())) {}
		if (message.isMember(kNIMMsgKeyPushPayload) && !message[kNIMMsgKeyPushPayload].asString().empty())
			if (!reader.parse(message[kNIMMsgKeyPushPayload].asString(), push_payload_) || !push_payload_.isObject()) {}
		local_ext_ = message[kNIMMsgKeyLocalExt].asString();
		push_content_ = message[kNIMMsgKeyPushContent].asString();
		if (message.isMember(kNIMMsgKeyIsForcePush))
			is_force_push_ = message[kNIMMsgKeyIsForcePush].asInt() == 1 ? BS_TRUE : BS_FALSE;
		force_push_content_ = message[kNIMMsgKeyForcePushContent].asString();
		if (message[kNIMMsgKeyForcePushList].isString())
		{
			nim_cpp_wrapper_util::Json::Value values;
			if (reader.parse(message[kNIMMsgKeyForcePushList].asString(), values) && values.isArray())
				JsonStrArrayToList(values, force_push_ids_list_);
			else
			{
				//assert(0);
			}
		}
		if (message.isMember(kNIMMsgKeyAntiSpamEnable))
			anti_spam_enable_ = message[kNIMMsgKeyAntiSpamEnable].asInt() == 1 ? BS_TRUE : BS_FALSE;
		anti_spam_content_ = message[kNIMMsgKeyAntiSpamContent].asString();
		if (message.isMember(kNIMMsgKeyClientAntiSpam))
			client_anti_spam_hitting_ = message[kNIMMsgKeyClientAntiSpam].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyTeamMsgAck))
			team_msg_need_ack_ = message[kNIMMsgKeyTeamMsgAck].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyLocalKeyTeamMsgAckSent))
			team_msg_ack_sent_ = message[kNIMMsgKeyTeamMsgAck].asInt() == 1 ? BS_TRUE : BS_FALSE;
		if (message.isMember(kNIMMsgKeyLocalKeyTeamMsgUnreadCount))
			team_msg_unread_count_ = message[kNIMMsgKeyLocalKeyTeamMsgUnreadCount].asUInt();		
		if (message.isMember(kNIMMsgKeyIsUpdateSession))
			is_update_session_ = message[kNIMMsgKeyIsUpdateSession].asBool() ? BS_TRUE : BS_FALSE;
	}
};

/** @brief P2P和群组消息 */
struct NIM_SDK_CPPWRAPPER_DLL_API IMMessageThreadInfo
{
	std::string reply_msg_from_account_;//被回复消息的消息发送者
	std::string reply_msg_to_account_;// 被回复消息的消息接受者，群的话是tid
	uint64_t reply_msg_time_;// 被回复消息的消息发送时间
	uint64_t reply_msg_id_server_;// 被回复消息的消息ID(serverId)
	std::string reply_msg_id_client_;// 被回复消息的消息ID(clientId)

	std::string thread_msg_from_account_;// thread消息的消息发送者
	std::string thread_msg_to_account_;// thread消息的消息接受者，群的话是tid
	uint64_t thread_msg_time_;// thread消息的消息发送时间
	uint64_t thread_msg_id_server_;// thread消息的消息ID(serverId)
	std::string thread_msg_id_client_;// thread消息的消息ID(clientId)
	int deleted_;// 消息是否已经被删除（可能是撤回，也可能是单向删除），查询thread消息历史时可能会有这个字段，大于0表示已经删除（目前撤回和单向删除都是1，未来可能区分）
	IMMessageThreadInfo() :
		reply_msg_from_account_(""),
		reply_msg_to_account_(""),
		reply_msg_time_(0),
		reply_msg_id_server_(0),
		reply_msg_id_client_(""),
		thread_msg_from_account_(""),
		thread_msg_to_account_(""),
		thread_msg_time_(0),
		thread_msg_id_server_(0),
		thread_msg_id_client_(""),
		deleted_(0) {}
};
struct NIM_SDK_CPPWRAPPER_DLL_API IMMessage
{
public:
	NIMResCode	rescode_;						/**< 错误码 */
	NIMMessageFeature	feature_;				/**< 消息属性 */

public:
	NIMSessionType	session_type_;				/**< 会话类型 */
	std::string		receiver_accid_;			/**< 接收者ID */
	std::string		sender_accid_;				/**< 发送者ID */
	int64_t			timetag_;					/**< 消息时间戳（毫秒） */
	std::string		content_;					/**< 消息内容,长度限制5000 */
	NIMMessageType	type_;						/**< 消息类型 */
	std::string		attach_;					/**< 消息附件 */
	std::string		client_msg_id_;				/**< 消息ID（客户端） */
	MessageSetting	msg_setting_;				/**< 消息属性设置 */

public:
	std::string	   local_res_path_;				/**< 媒体文件本地绝对路径（客户端） */
	std::string	   local_talk_id_;				/**< 会话ID（客户端） */
	std::string	   local_res_id_;				/**< 媒体文件ID（客户端） */
	NIMMsgLogStatus	status_;					/**< 消息状态（客户端） */
	NIMMsgLogSubStatus	sub_status_;			/**< 消息子状态（客户端） */
public:
	IMMessageThreadInfo thread_info_;
public:
	NIMClientType  readonly_sender_client_type_;	/**< 发送者客户端类型（只读） */
	std::string	   readonly_sender_device_id_;		/**< 发送者客户端设备ID（只读） */
	std::string	   readonly_sender_nickname_;		/**< 发送者昵称（只读） */
	int64_t		   readonly_server_id_;				/**< 消息ID（服务器，只读） */

	/** 构造函数 */
	IMMessage() : rescode_((NIMResCode)0)
				, feature_(kNIMMessageFeatureDefault)
				, readonly_sender_client_type_(kNIMClientTypeDefault) 
				, readonly_server_id_(0)
				, session_type_(kNIMSessionTypeP2P)
				, timetag_(0)
				, type_(kNIMMessageTypeUnknown)
				, status_(nim::kNIMMsgLogStatusNone)
				, sub_status_(nim::kNIMMsgLogSubStatusNone) {}

	/** 构造函数 */
	IMMessage(const std::string &json_msg) : rescode_((NIMResCode)0)
		, feature_(kNIMMessageFeatureDefault)
		, readonly_sender_client_type_(kNIMClientTypeDefault) 
		, readonly_server_id_(0)		
		, session_type_(kNIMSessionTypeP2P)
		, timetag_(0)
		, type_(kNIMMessageTypeUnknown)
		, status_(nim::kNIMMsgLogStatusNone)
		, sub_status_(nim::kNIMMsgLogSubStatusNone) 
	{
		nim_cpp_wrapper_util::Json::Value values;
		nim_cpp_wrapper_util::Json::Reader reader;
		if (reader.parse(json_msg, values) && values.isObject())
		{
			session_type_ = (NIMSessionType)values[kNIMMsgKeyToType].asUInt();
			receiver_accid_ = values[kNIMMsgKeyToAccount].asString();
			sender_accid_ = values[kNIMMsgKeyFromAccount].asString();
			readonly_sender_client_type_ = (NIMClientType)values[kNIMMsgKeyFromClientType].asUInt();
			readonly_sender_device_id_ = values[kNIMMsgKeyFromDeviceId].asString();
			readonly_sender_nickname_ = values[kNIMMsgKeyFromNick].asString();
			timetag_ = values[kNIMMsgKeyTime].asUInt64();

			type_ = (NIMMessageType)values[kNIMMsgKeyType].asUInt();
			content_ = values[kNIMMsgKeyBody].asString();
			attach_ = values[kNIMMsgKeyAttach].asString();
			client_msg_id_ = values[kNIMMsgKeyClientMsgid].asString();
			readonly_server_id_ = values[kNIMMsgKeyServerMsgid].asUInt64();

			local_res_path_ = values[kNIMMsgKeyLocalFilePath].asString();
			local_talk_id_ = values[kNIMMsgKeyLocalTalkId].asString();
			local_res_id_ = values[kNIMMsgKeyLocalResId].asString();
			status_ = (NIMMsgLogStatus)values[kNIMMsgKeyLocalLogStatus].asUInt();
			sub_status_ = (NIMMsgLogSubStatus)values[kNIMMsgKeyLocalLogSubStatus].asUInt();

			msg_setting_.ParseMessageSetting(values);
		}
	}

	/** @fn std::string ToJsonObject() const
	  * @brief 组装Json Object
	  * @return Json Object
      */
	nim_cpp_wrapper_util::Json::Value	ToJsonObject(bool use_to_send) const
	{
		nim_cpp_wrapper_util::Json::Value values;
		values[kNIMMsgKeyToType] = session_type_;
		values[kNIMMsgKeyToAccount] = receiver_accid_;
		values[kNIMMsgKeyFromAccount] = sender_accid_;
		values[kNIMMsgKeyTime] = timetag_;
		values[kNIMMsgKeyType] = type_;
		values[kNIMMsgKeyBody] = content_;
		values[kNIMMsgKeyAttach] = attach_;
		values[kNIMMsgKeyClientMsgid] = client_msg_id_;
		values[kNIMMsgKeyLocalFilePath] = local_res_path_;
		values[kNIMMsgKeyLocalTalkId] = local_talk_id_;
		values[kNIMMsgKeyLocalResId] = local_res_id_;
		values[kNIMMsgKeyLocalLogStatus] = status_;
		values[kNIMMsgKeyLocalLogSubStatus] = sub_status_;

		msg_setting_.ToJsonValue(values);

		if (!use_to_send)
		{
			values[kNIMMsgKeyFromClientType] = readonly_sender_client_type_;
			values[kNIMMsgKeyFromDeviceId] = readonly_sender_device_id_;
			values[kNIMMsgKeyFromNick] = readonly_sender_nickname_;
			values[kNIMMsgKeyServerMsgid] = readonly_server_id_;
		}
		//thread
		{
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyReplyMsgFromAccount] = thread_info_.reply_msg_from_account_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyReplyMsgToAccount] = thread_info_.reply_msg_to_account_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyReplyMsgTime] = thread_info_.reply_msg_time_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyReplyMsgIdServer] = thread_info_.reply_msg_id_server_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyReplyMsgIdClient] = thread_info_.reply_msg_id_client_;

			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyThreadMsgFromAccount] = thread_info_.thread_msg_from_account_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyThreadMsgToAccount] = thread_info_.thread_msg_to_account_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyThreadMsgTime] = thread_info_.thread_msg_time_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyThreadMsgIdServer] = thread_info_.thread_msg_id_server_;
			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyThreadMsgIdClient] = thread_info_.thread_msg_id_client_;

			values[kNIMMsgKeyThreadInfo][kNIMMsgKeyDeleted] = thread_info_.deleted_;
		}
		return values;
	}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string		ToJsonString(bool use_to_send) const
	{
		nim_cpp_wrapper_util::Json::Value values = ToJsonObject(use_to_send);
		return GetJsonStringWithNoStyled(values);
	}
};

/** @brief 文件消息附件 */
struct NIM_SDK_CPPWRAPPER_DLL_API IMFile
{
	std::string	md5_;				/**< 文件内容MD5 */
	int64_t		size_;				/**< 文件大小 */
	std::string url_;				/**< 上传云端后得到的文件下载地址 */
	std::string display_name_;		/**< 用于显示的文件名称 */
	std::string file_extension_;	/**< 文件扩展名 */
	std::string msg_attachment_tag_;	/**< string, (可选)发送含有附件的消息时使用的场景标签(可参见nos删除策略) ,Audio Image Video File 或者可以被SDK解析到本地文件路径的自定义消息*/
	/** 构造函数 */
	IMFile() : size_(0), msg_attachment_tag_(kNIMNosDefaultTagIM){}

	/** @fn std::string ToJsonString(nim_cpp_wrapper_util::Json::Value &attach) const
	  * @brief 组装Json Value字符串
	  * @param[in] attach Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString(nim_cpp_wrapper_util::Json::Value &attach) const
	{
		//以下客户端可以选填
		if (!display_name_.empty())
			attach[kNIMFileMsgKeyDisplayName] = display_name_;
		if (!file_extension_.empty())
			attach[kNIMFileMsgKeyExt] = file_extension_;
		if (!md5_.empty())
			attach[kNIMFileMsgKeyMd5] = md5_;
		if (size_ > 0)
			attach[kNIMFileMsgKeySize] = size_;
		if (!url_.empty())
			attach[kNIMMsgAttachKeyUrl] = url_;
		if(!msg_attachment_tag_.empty())
			attach[kNIMMsgAttachKeyTag] = msg_attachment_tag_;
		return GetJsonStringWithNoStyled(attach);
	}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString() const
	{
		nim_cpp_wrapper_util::Json::Value attach;
		attach[kNIMFileMsgKeyDisplayName] = display_name_;		
		return ToJsonString(attach);
	}
};

/** @brief 图片消息附件 */
struct NIM_SDK_CPPWRAPPER_DLL_API IMImage : IMFile
{
	int			width_;			/**< 图片宽度 */
	int			height_;		/**< 图片高度 */

	/** 构造函数 */
	IMImage() : width_(0), height_(0) {}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString() const
	{
		nim_cpp_wrapper_util::Json::Value attach;
		attach[kNIMImgMsgKeyWidth] = width_;
		attach[kNIMImgMsgKeyHeight] = height_;

		return IMFile::ToJsonString(attach);	//remove the Visual C++ __super keyword.
	}
};

/** @brief 位置消息附件 */
struct NIM_SDK_CPPWRAPPER_DLL_API IMLocation
{
	std::string	description_;		/**< 位置描述内容 */
	double		latitude_;			/**< 位置纬度 */
	double		longitude_;			/**< 位置经度 */

	/** 构造函数 */
	IMLocation() : latitude_(0), longitude_(0) {}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString() const
	{
		nim_cpp_wrapper_util::Json::Value attach;
		attach[kNIMLocationMsgKeyTitle] = description_;
		attach[kNIMLocationMsgKeyLatitude] = latitude_;
		attach[kNIMLocationMsgKeyLongitude] = longitude_;

		return GetJsonStringWithNoStyled(attach);
	}
};

/** @brief 语音消息附件 */
struct NIM_SDK_CPPWRAPPER_DLL_API IMAudio : IMFile
{
	int			duration_;			/**< 语音时长 */

	/** 构造函数 */
	IMAudio() : duration_(0) {}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString() const
	{
		nim_cpp_wrapper_util::Json::Value attach;
		attach[kNIMAudioMsgKeyDuration] = duration_;

		return IMFile::ToJsonString(attach);	//remove the Visual C++ __super keyword.
	}
};

/** @brief 小视频消息附件 */
struct NIM_SDK_CPPWRAPPER_DLL_API IMVideo : IMFile
{
	int			duration_;			/**< 视频时长 */
	int			width_;				/**< 视频画面宽度 */
	int			height_;			/**< 视频画面高度 */

	/** 构造函数 */
	IMVideo() : duration_(0), width_(0), height_(0) {}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString() const
	{
		nim_cpp_wrapper_util::Json::Value attach;
		attach[kNIMVideoMsgKeyWidth] = width_;
		attach[kNIMVideoMsgKeyHeight] = height_;
		attach[kNIMVideoMsgKeyDuration] = duration_;

		return IMFile::ToJsonString(attach);	//remove the Visual C++ __super keyword.
	}
};

/** @brief 波特机器人消息附件 */
struct NIM_SDK_CPPWRAPPER_DLL_API IMBotRobot
{
	bool	out_msg_;				/**< 是否为机器人回复，是:true，不是:false，默认false */
	std::string robot_accid_;		/**< 机器人云信ID */
	nim_cpp_wrapper_util::Json::Value sent_param_;		/**< 给机器人发送时需要填的字段，字段内容定义可见Demo源码或参考波特开发文档 */
	
	std::string related_msg_id_;	/**< 机器人回复时带的字段，表示该条回复相关联的消息ID */
	std::string robot_msg_flag_;	/**< 机器人回复时带的字段，表示该条回复类型，类型定义可见Demo源码或参考波特开发文档*/
	nim_cpp_wrapper_util::Json::Value robot_msg_content_;	/**< 机器人回复时带的字段，表示该条回复内容，字段内容定义可见Demo源码或参考波特开发文档 */
	
	/** 构造函数 */
	IMBotRobot() : out_msg_(false) {}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */	std::string ToJsonString() const
	{
		nim_cpp_wrapper_util::Json::Value attach;
		attach[kNIMBotRobotMsgKeyRobotID] = robot_accid_;
		attach[kNIMBotRobotSentMsgKeyParam] = sent_param_;

		return GetJsonStringWithNoStyled(attach);
	}
};

struct NIM_SDK_CPPWRAPPER_DLL_API BroadcastMessage
{
	std::string	body_;
	int64_t time_;
	int64_t id_;
	std::string from_id_;
};

/** @fn bool ParseMessage(const std::string& msg_json, IMMessage& message)
  * @brief 解析消息
  * @param[in] msg_json 消息(Json Value数据字符串)
  * @param[out] message 消息
  * @return bool 解析成功或失败 
  */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseMessage(const std::string& msg_json, IMMessage& message);

/** @fn bool ParseReceiveMessage(const std::string& msg_json, IMMessage& message)
  * @brief 解析消息
  * @param[in] msg_json 消息(Json Value数据字符串)
  * @param[out] message 消息
  * @return bool 解析成功或失败 
  */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseReceiveMessage(const std::string& msg_json, IMMessage& message);

/** @fn void ParseReceiveMessage(const nim_cpp_wrapper_util::Json::Value& msg_json_value, IMMessage& message)
  * @brief 解析消息
  * @param[in] msg_json_value 消息
  * @param[out] message 消息
  * @return bool 解析成功或失败 
  */
NIM_SDK_CPPWRAPPER_DLL_API void ParseReceiveMessage(const nim_cpp_wrapper_util::Json::Value& msg_json_value, IMMessage& message);

/** @fn void ParseMessage(const nim_cpp_wrapper_util::Json::Value& msg_json, IMMessage& message)
  * @brief 解析消息
  * @param[in] msg_json 消息(Json Value数据)
  * @param[out] message 消息
  * @return void 
  */
NIM_SDK_CPPWRAPPER_DLL_API void ParseMessage(const nim_cpp_wrapper_util::Json::Value& msg_json, IMMessage& message);

} //namespace nim

#endif //_NIM_SDK_CPP_TALK_HELPER_H_