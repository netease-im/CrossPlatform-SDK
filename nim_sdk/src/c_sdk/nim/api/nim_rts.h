﻿/** @file nim_rts.h
  * @brief 实时会话（数据通道） 接口头文件，如果需要用到音视频功能请使用音视频设备相关接口
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @author gq
  * @date 2015/6/30
  */

#ifndef NIM_SDK_DLL_API_NIM_RTS_H_
#define NIM_SDK_DLL_API_NIM_RTS_H_

#include "public_define/defines/nim_sdk_dll.h"
#include "public_define/defines/nim_define/nim_rts_def.h"

#ifdef __cplusplus
extern"C"
{
#endif

	/** @fn void nim_rts_set_proxy(enum NIMProxyType type, const char *host, int port, const char *user, const char *password)
	* 设置SDK白板的网络代理，暂时只支持socks5代理，全局代理接口也能设置音视频的代理，两接口没有优先级区别。不需要代理时，type设置为kNIMProxyNone，其余参数都传空字符串（端口设为0）。有些代理不需要用户名和密码，相应参数也传空字符串。
	* @param[in] type 代理类型，见NIMProxyType定义,其中音视频和白板暂时只支持kNIMProxySocks5代理
	* @param[in] host 代理地址
	* @param[in] port 代理端口
	* @param[in] user 代理用户名
	* @param[in] password 代理密码
	* @return void 无返回值
	*/
	NIM_SDK_DLL_API	void nim_rts_set_proxy(enum NIMProxyType type, const char *host, int port, const char *user, const char *password);

//发起相关
/** @fn void nim_rts_start(int channel_type, const char *uid, const char *json_extension, nim_rts_start_cb_func cb, const void *user_data)
  * NIM 创建rts会话，传入的JSON参数定义见nim_rts_def.h    
  * @param[in] channel_type 通道类型 如要tcp+音视频，则channel_type=kNIMRtsChannelTypeTcp|kNIMRtsChannelTypeVchat，同时整个SDK只允许一个音视频通道存在（包括vchat）
  * @param[in] uid 对方帐号
  * @param[in] json_extension Json string 扩展
  * @param[in] cb 结果回调见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  * @note 错误码	200:成功
  *				414:参数错误
  *				501:数据库失败
  *				509:通道失效
  *				514:服务不可用 
  *				11001:无可送达的被叫方,主叫方可直接挂断		
  */ 
NIM_SDK_DLL_API	void nim_rts_start(int channel_type, const char *uid, const char *json_extension, nim_rts_start_cb_func cb, const void *user_data);

/** @fn void nim_rts_set_start_notify_cb_func(nim_rts_start_notify_cb_func cb, const void *user_data)
  * NIM 设置收到会话邀请的通知的回调   
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  * @note 错误码	200:成功
  *				404:对象不存在，发起记录不存在
  *				509:通道失效
  */ 
NIM_SDK_DLL_API	void nim_rts_set_start_notify_cb_func(nim_rts_start_notify_cb_func cb, const void *user_data);

/** @fn void nim_rts_create_conf(const char *name, const char *custom_info, const char *json_extension, nim_rts_create_cb_func cb, const void *user_data)
  * NIM VCHAT 创建一个多人数据通道房间（后续需要主动调用加入接口进入房间）
  * @param[in] name 房间名
  * @param[in] custom_info 自定义的房间信息（加入房间的时候会返回）
  * @param[in] json_extension 无效扩展字段
  * @param[in] cb 结果回调见nim_rts_def.h，返回的json_extension无效
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  * @note 错误码	200:成功
  *				417:提示已经创建好频道
  */
NIM_SDK_DLL_API void nim_rts_create_conf(const char *name, const char *custom_info, const char *json_extension, nim_rts_create_cb_func cb, const void *user_data);

/** @fn void nim_rts_join_conf(const char *name, const char *json_extension, nim_rts_join_cb_func cb, const void *user_data)
  * NIM VCHAT 加入一个多人房间（进入房间后成员变化等，等同点对点nim_vchat_cb_func）
  * @param[in] name 房间名
  * @param[in] json_extension 扩展可选参数kNIMRtsDataRecord,kNIMRtsSessionId， 如{"data_record":1, "session_id":"b76e2b7ae065224499e4d7138d643961"}
  * @param[in] cb 结果回调见nim_rts_def.h，回调的json_extension若成功返回创建的kNIMRtsCustomInfo及kNIMRtsChannelId，如{"channel_id": 1231, "custom_info":"hello world" }
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  * @note 错误码	200:成功
  */
NIM_SDK_DLL_API void nim_rts_join_conf(const char *name, const char *json_extension, nim_rts_join_cb_func cb, const void *user_data);

/** @fn void nim_rts_ack(const char *session_id, int channel_type, bool accept, const char *json_extension, nim_rts_ack_res_cb_func cb, const void *user_data)
  * NIM 回复收到的邀请  
  * @param[in] session_id 会话id
  * @param[in] channel_type 通道类型,暂时无效
  * @param[in] accept 是否接受
  * @param[in] json_extension Json string 扩展
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_ack(const char *session_id, int channel_type, bool accept, const char *json_extension, nim_rts_ack_res_cb_func cb, const void *user_data);

/** @fn void nim_rts_set_ack_notify_cb_func(nim_rts_ack_notify_cb_func cb, const void *user_data)
  * NIM 设置收到对方回复的通知回调
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  * @note 错误码	200:成功
  *				509:失效
  */ 
NIM_SDK_DLL_API	void nim_rts_set_ack_notify_cb_func(nim_rts_ack_notify_cb_func cb, const void *user_data);

/** @fn void nim_rts_set_sync_ack_notify_cb_func(nim_rts_sync_ack_notify_cb_func cb, const void *user_data)
  * NIM 设置收到本人其他端回复的同步通知回调
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_set_sync_ack_notify_cb_func(nim_rts_sync_ack_notify_cb_func cb, const void *user_data);

//状态回调相关
/** @fn void nim_rts_set_connect_notify_cb_func(nim_rts_connect_notify_cb_func cb, const void *user_data)
  * NIM 设置监听通道连接状态回调
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_set_connect_notify_cb_func(nim_rts_connect_notify_cb_func cb, const void *user_data);

/** @fn void nim_rts_set_member_change_cb_func(nim_rts_member_change_cb_func cb, const void *user_data)
  * NIM 设置监听通道成员状态回调
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  * @note 错误码	200:成功
  */ 
NIM_SDK_DLL_API	void nim_rts_set_member_change_cb_func(nim_rts_member_change_cb_func cb, const void *user_data);

//控制接口
/** @fn void nim_rts_control(const char *session_id, const char *info, const char *json_extension, nim_rts_control_res_cb_func cb, const void *user_data)
  * NIM 会话控制（透传），点对点有效
  * @param[in] session_id 会话id
  * @param[in] info 透传数据
  * @param[in] json_extension 无效的扩展字段
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data 无效的扩展字段
  * @return void 无返回值
  */
NIM_SDK_DLL_API void nim_rts_control(const char *session_id, const char *info, const char *json_extension, nim_rts_control_res_cb_func cb, const void *user_data);

/** @fn void nim_rts_set_control_notify_cb_func(nim_rts_control_notify_cb_func cb, const void *user_data)
  * NIM 设置收到会话控制的通知回调
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_set_control_notify_cb_func(nim_rts_control_notify_cb_func cb, const void *user_data);

/** @fn void nim_rts_set_vchat_mode(const char *session_id, int mode, const char *json_extension)
  * NIM 设置音视频会话类型  
  * @param[in] session_id 会话id
  * @param[in] mode 见NIMRtsVideoChatMode
  * @param[in] json_extension 无效的扩展字段
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_set_vchat_mode(const char *session_id, int mode, const char *json_extension);

//结束相关
/** @fn void nim_rts_hangup(const char *session_id, const char *json_extension, nim_rts_hangup_res_cb_func cb, const void *user_data)
  * NIM 结束会话  
  * @param[in] session_id 会话id
  * @param[in] json_extension 无效的扩展字段
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_hangup(const char *session_id, const char *json_extension, nim_rts_hangup_res_cb_func cb, const void *user_data);

/** @fn void nim_rts_set_hangup_notify_cb_func(nim_rts_hangup_notify_cb_func cb, const void *user_data)
  * NIM 设置结束会话通知回调，多人的时候结束后对方无通知。
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_set_hangup_notify_cb_func(nim_rts_hangup_notify_cb_func cb, const void *user_data);

/** @fn void nim_rts_relogin(const char *session_id, int channel_type, const char *json_extension, nim_rts_opt_cb_func cb, const void *user_data)
  * NIM RTS 重连接口
  * @param[in] session_id 会话id
  * @param[in] channel_type 通道类型，暂时只支持白板类型
  * @param[in] json_extension 无效的扩展字段
  * @param[in] cb 见nim_rts_def.h，返回重连操作结果
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_relogin(const char *session_id, int channel_type, const char *json_extension, nim_rts_opt_cb_func cb, const void *user_data);

//数据相关
/** @fn void nim_rts_send_data(const char *session_id, int channel_type, const char *data, unsigned int size, const char *json_extension)
  * NIM 发送数据，暂时支持tcp通道，建议发送频率在20Hz以下，现在只支持50k的长度
  * @param[in] session_id 会话id
  * @param[in] channel_type 通道类型, kNIMRtsChannelTypeVchat通道如果要自定义数据调用nim_device.h中nim_vchat_custom_audio_data和nim_vchat_custom_video_data
  * @param[in] data 发送数据
  * @param[in] size data的数据长度，现在只支持50k的长度
  * @param[in] json_extension 可扩展kNIMRtsUid（指定发送某人，不填则群发）
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_send_data(const char *session_id, int channel_type, const char *data, unsigned int size, const char *json_extension);

/** @fn void nim_rts_set_rec_data_cb_func(nim_rts_rec_data_cb_func cb, const void *user_data)
  * NIM 设置监听数据接收回调, kNIMRtsChannelTypeVchat通道要监听音视频数据，调用nim_device.h中nim_vchat_set_audio_data_cb和nim_vchat_set_video_data_cb
  * @param[in] cb 见nim_rts_def.h
  * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
  * @return void 无返回值
  */ 
NIM_SDK_DLL_API	void nim_rts_set_rec_data_cb_func(nim_rts_rec_data_cb_func cb, const void *user_data);

#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_API_NIM_RTS_H_