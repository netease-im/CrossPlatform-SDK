/** @file nim_talk_helper.h
  * @brief Talk 辅助方法和数据结构定义
  * @copyright (c) 2015, NetEase Inc. All rights reserved
  * @author Oleg
  * @date 2015/10/16
  */

#ifndef _NIM_SDK_CPP_TALK_HELPER_H_
#define _NIM_SDK_CPP_TALK_HELPER_H_

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

#include "nim_talk_def.h"
#include "nim_session_def.h"
#include "nim_msglog_def.h"
#include "nim_res_code_def.h"

/** @struct P2P和群组消息 */
struct IMMessage
{
public:
	NIMResCode	rescode_;						/**< 错误码 */
	NIMMessageFeature	feature_;				/**< 消息属性 */

public:
	NIMSessionType session_type_;				/**< 会话类型 */
	std::string	   receiver_accid_;				/**< 接收者ID */
	std::string    sender_accid_;				/**< 发送者ID */
	__int64		   timetag_;					/**< 消息时间戳（毫秒） */
	std::string	   content_;					/**< 消息内容 */
	NIMMessageType type_;						/**< 消息类型 */
	std::string	   attach_;						/**< 消息附件 */
	std::string	   client_msg_id_;				/**< 消息ID（客户端） */
	bool		   resend_flag_;				/**< 重发标记 */
	bool		   support_cloud_history_;		/**< 是否支持云端存储 */
	bool		   support_roam_msg_;			/**< 是否支持消息漫游 */
	bool		   support_sync_msg_;			/**< 是否支持消息多端同步 */

public:
	std::string	   local_res_path_;				/**< 媒体文件本地绝对路径（客户端） */
	std::string	   local_talk_id_;				/**< 会话ID（客户端） */
	std::string	   local_res_id_;				/**< 媒体文件ID（客户端） */
	NIMMsgLogStatus	status_;					/**< 消息状态（客户端） */
	NIMMsgLogSubStatus	sub_status_;			/**< 消息子状态（客户端） */

public:
	int			   readonly_sender_client_type_;	/**< 发送者客户端类型（只读） */
	std::string	   readonly_sender_device_id_;		/**< 发送者客户端设备ID（只读） */
	std::string	   readonly_sender_nickname_;		/**< 发送者昵称（只读） */
	__int64		   readonly_server_id_;				/**< 消息ID（服务器，只读） */

	/** 构造函数 */
	IMMessage() : resend_flag_(false)
				, support_cloud_history_(true)
				, support_roam_msg_(true)
				, support_sync_msg_(true)
				, readonly_sender_client_type_(0) 
				, readonly_server_id_(0)
				, feature_(kNIMMessageFeatureDefault)
				, session_type_(kNIMSessionTypeP2P)
				, timetag_(0)
				, status_(nim::kNIMMsgLogStatusNone)
				, sub_status_(nim::kNIMMsgLogSubStatusNone) {}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string		ToJsonString(bool use_to_send) const
	{
		Json::Value values;
		values[kNIMMsgKeyToType] = session_type_;
		values[kNIMMsgKeyToAccount] = receiver_accid_;
		values[kNIMMsgKeyFromAccount] = sender_accid_;
		values[kNIMMsgKeyTime] = timetag_;
		values[kNIMMsgKeyType] = type_;
		values[kNIMMsgKeyBody] = content_;
		values[kNIMMsgKeyAttach] = attach_;
		values[kNIMMsgKeyClientMsgid] = client_msg_id_;
		values[kNIMMsgKeyResendFlag] = resend_flag_ ? 1 : 0;
		values[kNIMMsgKeyHistorySave] = support_cloud_history_ ? 1 : 0;
		values[kNIMMsgKeyMsgRoaming] = support_roam_msg_ ? 1 : 0;
		values[kNIMMsgKeyMsgSync] = support_sync_msg_ ? 1 : 0;
		values[kNIMMsgKeyLocalFilePath] = local_res_path_;
		values[kNIMMsgKeyLocalTalkId] = receiver_accid_;
		values[kNIMMsgKeyLocalResId] = local_res_id_;
		values[kNIMMsgKeyLocalLogStatus] = status_;
		values[kNIMMsgKeyLocalLogSubStatus] = sub_status_;

		if (!use_to_send)
		{
			values[kNIMMsgKeyFromClientType] = readonly_sender_client_type_;
			values[kNIMMsgKeyFromDeviceId] = readonly_sender_device_id_;
			values[kNIMMsgKeyFromNick] = readonly_sender_nickname_;
			values[kNIMMsgKeyServerMsgid] = readonly_server_id_;
		}
		return values.toStyledString();
	}
};

/** @struct 文件消息附件 */
struct IMFile
{
	std::string	md5_;				/**< 文件内容MD5 */
	__int64		size_;				/**< 文件大小 */
	std::string url_;				/**< 上传云端后得到的文件下载地址 */
	std::string display_name_;		/**< 用于显示的文件名称 */
	std::string file_extension_;	/**< 文件扩展名 */

	/** 构造函数 */
	IMFile() : size_(0) {}

	/** @fn std::string ToJsonString(Json::Value &attach) const
	  * @brief 组装Json Value字符串
	  * @param[in] attach Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString(Json::Value &attach) const
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

		return attach.toStyledString();
	}

	/** @fn std::string ToJsonString() const
	  * @brief 组装Json Value字符串
	  * @return string Json Value字符串 
      */
	std::string ToJsonString() const
	{
		Json::Value attach;
		attach[kNIMFileMsgKeyDisplayName] = display_name_;

		return ToJsonString(attach);
	}
};

/** @struct 图片消息附件 */
struct IMImage : IMFile
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
		Json::Value attach;
		attach[kNIMImgMsgKeyWidth] = width_;
		attach[kNIMImgMsgKeyHeight] = height_;
		attach[kNIMImgMsgKeyDisplayName] = display_name_;

		return __super::ToJsonString(attach);
	}
};

/** @struct 位置消息附件 */
struct IMLocation
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
		Json::Value attach;
		attach[kNIMLocationMsgKeyTitle] = description_;
		attach[kNIMLocationMsgKeyLatitude] = latitude_;
		attach[kNIMLocationMsgKeyLongitude] = longitude_;

		return attach.toStyledString();
	}
};

/** @struct 语音消息附件 */
struct IMAudio : IMFile
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
		Json::Value attach;
		attach[kNIMAudioMsgKeyDisplayName] = display_name_;

		return __super::ToJsonString(attach);
	}
};

/** @struct 小视频消息附件 */
struct IMVideo : IMFile
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
		Json::Value attach;
		attach[kNIMVideoMsgKeyWidth] = width_;
		attach[kNIMVideoMsgKeyHeight] = height_;
		attach[kNIMVideoMsgKeyDuration] = duration_;

		return __super::ToJsonString(attach);
	}
};

/** @fn bool ParseMessage(const std::string& msg_json, IMMessage& message)
  * @brief 解析消息
  * @param[in] msg_json 消息(Json Value数据字符串)
  * @param[out] message 消息
  * @return bool 解析成功或失败 
  */
bool ParseMessage(const std::string& msg_json, IMMessage& message);

/** @fn bool ParseReceiveMessage(const std::string& msg_json, IMMessage& message)
  * @brief 解析消息
  * @param[in] msg_json 消息(Json Value数据字符串)
  * @param[out] message 消息
  * @return bool 解析成功或失败 
  */
bool ParseReceiveMessage(const std::string& msg_json, IMMessage& message);

/** @fn bool ParseReceiveMessage(const Json::Value& msg_json, IMMessage& message)
  * @brief 解析消息
  * @param[in] msg_json 消息(Json Value数据)
  * @param[out] message 消息
  * @return void 
  */
void ParseMessage(const Json::Value& msg_json, IMMessage& message);

} //namespace nim

#endif //_NIM_SDK_CPP_TALK_HELPER_H_