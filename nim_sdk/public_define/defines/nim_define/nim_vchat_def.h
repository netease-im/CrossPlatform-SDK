﻿/** @file nim_vchat_def.h
  * @brief 音视频 接口相关的常量函数等定义头文件
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @author gq
  * @date 2015/5/5
  */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_VCHAT_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_VCHAT_DEF_H_

#include "public_define/nim_util_include.h"

#ifdef __cplusplus
extern"C"
{
#endif
/** @enum NIMVideoChatSessionType 音视频通话状态通知类型 */
enum NIMVideoChatSessionType{
	kNIMVideoChatSessionTypeStartRes		= 1,		/**< 创建通话结果 */
	kNIMVideoChatSessionTypeInviteNotify	= 2,		/**< 通话邀请 */
	kNIMVideoChatSessionTypeCalleeAckRes	= 3,		/**< 确认通话，接受拒绝结果 */
	kNIMVideoChatSessionTypeCalleeAckNotify	= 4,		/**< 确认通话，接受拒绝通知 */
	kNIMVideoChatSessionTypeControlRes		= 5,		/**< NIMVChatControlType 结果 */
	kNIMVideoChatSessionTypeControlNotify	= 6,		/**< NIMVChatControlType 通知 */
	kNIMVideoChatSessionTypeConnect			= 7,		/**< 通话中链接状态通知 */
	kNIMVideoChatSessionTypePeopleStatus	= 8,		/**< 通话中成员状态 */
	kNIMVideoChatSessionTypeNetStatus		= 9,		/**< 通话中网络状态 */
	kNIMVideoChatSessionTypeHangupRes		= 10,		/**< 通话挂断结果 */
	kNIMVideoChatSessionTypeHangupNotify	= 11,		/**< 通话被挂断通知 */
	kNIMVideoChatSessionTypeSyncAckNotify	= 12,		/**< 通话接听挂断同步通知 */
	kNIMVideoChatSessionTypeMp4Notify		= 13,		/**< 通知MP4录制状态，包括开始录制和结束录制 */
	kNIMVideoChatSessionTypeInfoNotify		= 14,		/**< 通知实时音视频数据状态 */
	kNIMVideoChatSessionTypeVolumeNotify	= 15,		/**< 通知实时音频发送和混音的音量状态 */
	kNIMVideoChatSessionTypeAuRecordNotify  = 16,		/**< 通知音频录制状态，包括开始录制和结束录制 */
	kNIMVideoChatSessionTypeLiveState		= 17,		/**< 通知直播推流的服务器状态 */
	kNIMVideoChatSessionTypePubSubNotify	= 18,		/**< 通知订阅相关通知 */
};

/** @enum NIMVChatControlType 音视频通话控制类型 */
enum NIMVChatControlType
{
	kNIMTagControlOpenAudio             = 1,    /**< 打开音频 */
	kNIMTagControlCloseAudio            = 2,    /**< 关闭音频 */
	kNIMTagControlOpenVideo             = 3,    /**< 打开视频 */
	kNIMTagControlCloseVideo            = 4,    /**< 关闭视频 */
	kNIMTagControlAudioToVideo          = 5,    /**< 请求从音频切换到视频 */
	kNIMTagControlAgreeAudioToVideo     = 6,    /**< 同意从音频切换到视频 */
	kNIMTagControlRejectAudioToVideo    = 7,    /**< 拒绝从音频切换到视频 */
	kNIMTagControlVideoToAudio          = 8,    /**< 从视频切换到音频 */
	kNIMTagControlBusyLine              = 9,    /**< 占线 */
	kNIMTagControlCamaraNotAvailable    = 10,   /**< 告诉对方自己的摄像头不可用 */
	kNIMTagControlEnterBackground       = 11,   /**< 告诉对方自已处于后台 */
	kNIMTagControlReceiveStartNotifyFeedback = 12,   /**< 告诉发送方自己已经收到请求了（用于通知发送方开始播放提示音） */
	kNIMTagControlMp4StartRecord		= 13,   /**< 告诉发送方自己开始录制 */
	kNIMTagControlMp4StopRecord			= 14,   /**< 告诉发送方自己结束录制 */
};

/** @enum NIMVideoChatMode 音视频通话类型 */
enum NIMVideoChatMode{
	kNIMVideoChatModeAudio	=	1,	/**< 语音通话模式 */
	kNIMVideoChatModeVideo	=	2	/**< 视频通话模式 */
};

/** @enum NIMVChatVideoQuality 视频通话分辨率，最终长宽比不保证 */
enum NIMVChatVideoQuality {
	kNIMVChatVideoQualityNormal		= 0,		/**< 视频默认分辨率 480x320*/
	kNIMVChatVideoQualityLow		= 1,		/**< 视频低分辨率 176x144*/
	kNIMVChatVideoQualityMedium		= 2,		/**< 视频中分辨率 352x288*/
	kNIMVChatVideoQualityHigh		= 3,		/**< 视频高分辨率 480x320*/
	kNIMVChatVideoQualitySuper		= 4,		/**< 视频超高分辨率 640x480*/
	kNIMVChatVideoQuality720p		= 5,		/**< 用于桌面分享级别的分辨率1280x720，需要使用高清摄像头并指定对应的分辨率，或者自定义通道传输 */
	kNIMVChatVideoQuality540p		= 6,		/**< 介于720P与480P之间的类型，默认 960*540 */
};

/** @enum NIMVChatVideoFrameRate 视频通话帧率，实际帧率因画面采集频率和机器性能限制可能达不到期望值 */
enum NIMVChatVideoFrameRate {
	kNIMVChatVideoFrameRateNormal	= 0,		/**< 视频通话帧率默认值,最大取每秒15帧 */
	kNIMVChatVideoFrameRate5		= 1,		/**< 视频通话帧率 最大取每秒5帧 */
	kNIMVChatVideoFrameRate10		= 2,		/**< 视频通话帧率 最大取每秒10帧 */
	kNIMVChatVideoFrameRate15		= 3,		/**< 视频通话帧率 最大取每秒15帧 */
	kNIMVChatVideoFrameRate20		= 4,		/**< 视频通话帧率 最大取每秒20帧 */
	kNIMVChatVideoFrameRate25		= 5,		/**< 视频通话帧率 最大取每秒25帧 */
};

/** @enum NIMVChatVideoEncodeMode 视频编码策略  */
enum NIMVChatVideoEncodeMode
{
	kNIMVChatVEModeNormal		= 0,		/**< 默认值，清晰优先 */
	kNIMVChatVEModeFramerate	= 1,		/**< 流畅优先 */
	kNIMVChatVEModeQuality		= 2,		/**< 清晰优先 */
	kNIMVChatVEModeScreen		= 3,		/**< 屏幕共享场景调控策略，sdk不会根据网络调整分辨率 */
};

/** @enum NIMVChatVideoFrameScaleType 视频画面长宽比，裁剪时不改变横竖屏，如4：3，代表宽高横屏4：3或者竖屏3：4  */
enum NIMVChatVideoFrameScaleType {
	kNIMVChatVideoFrameScaleNone	= 0,			/**< 默认，不裁剪 */
	kNIMVChatVideoFrameScale1x1		= 1,			/**< 裁剪成1：1的形状 */
	kNIMVChatVideoFrameScale4x3		= 2,			/**< 裁剪成4：3的形状，如果是 */
	kNIMVChatVideoFrameScale16x9	= 3,			/**< 裁剪成16：9的形状 */
};

/** @enum NIMVChatMp4RecordCode mp4录制状态 */
enum NIMVChatMp4RecordCode {
	kNIMVChatMp4RecordClose				= 0,		/**< MP4结束 */
	kNIMVChatMp4RecordVideoSizeError	= 1,		/**< MP4结束，视频画面大小变化 */
	kNIMVChatMp4RecordOutDiskSpace		= 2,		/**< MP4结束，磁盘空间不足 */
	kNIMVChatMp4RecordThreadBusy		= 3,		/**< MP4结束，录制线程繁忙 */
	kNIMVChatMp4RecordCreate			= 200,		/**< MP4文件创建 */
	kNIMVChatMp4RecordExsit				= 400,		/**< MP4文件已经存在 */
	kNIMVChatMp4RecordCreateError		= 403,		/**< MP4文件创建失败 */
	kNIMVChatMp4RecordInvalid			= 404,		/**< 通话不存在 */
};

/** @enum NIMVChatAudioRecordCode 音频录制状态 */
enum NIMVChatAudioRecordCode {
	kNIMVChatAudioRecordClose			= 0,		/**< 录制正常结束 */
	kNIMVChatAudioRecordOutDiskSpace	= 2,		/**< 录制结束，磁盘空间不足 */
	kNIMVChatAudioRecordCreate			= 200,		/**< 文件创建成功 */
	kNIMVChatAudioRecordExsit			= 400,		/**< 已经存在 */
	kNIMVChatAudioRecordCreateError		= 403,		/**< 文件创建失败 */
	kNIMVChatAudioRecordInvalid			= 404,		/**< 通话不存在 */
};

/** @enum NIMVChatVideoSplitMode 主播设置的直播分屏模式  */
enum NIMVChatVideoSplitMode {
	kNIMVChatSplitBottomHorFloating		= 0,			/**< 底部横排浮窗 */
	kNIMVChatSplitTopHorFloating		= 1,			/**< 顶部横排浮窗 */
	kNIMVChatSplitLatticeTile			= 2,			/**< 平铺 */
	kNIMVChatSplitLatticeCuttingTile	= 3,			/**< 裁剪平铺 */
	kNIMVChatSplitCustomLayout			= 4,			/**< 自定义布局 */
	kNIMVChatSplitAudioLayout			= 5,			/**< 纯音频布局 */
};



/** @enum NIMVChatLiveStateCode 直播时的状态码。服务器定时更新，一些存在时间短的状态会获取不到  */
enum NIMVChatLiveStateCode
{
	kNIMVChatLiveStateInitial			= 500,
	kNIMVChatLiveStateLayoutError		= 501,		/**< 主播设置定制布局，布局参数错误 */
	kNIMVChatLiveStateStartConnecting	= 502,		/**< 开始连接 */
	kNIMVChatLiveStateConnectted		= 503,		/**< 连接成功 */
	kNIMVChatLiveStateConnectFail		= 504,		/**< 连接失败 */
	kNIMVChatLiveStatePushing			= 505,		/**< 推流中 */
	kNIMVChatLiveStatePushFail			= 506,		/**< 互动直播推流失败 */
	kNIMVChatLiveStateInnerError		= 507,		/**< 内部错误 */
	kNIMVChatLiveStatePeopleLimit		= 508,		/**< 人数超出限制 */
};


/** @enum NIMVChatAudioMode 音频模式  */
enum NIMVChatAudioMode
{
	kNIMVChatAdModeDefault		= 0,		/**< 默认值，为kNIMVChatAdModeHighVoip */
	kNIMVChatAdModeNormal		= 1,		/**< 窄带  */
	kNIMVChatAdModeHighVoip		= 2,		/**< 高清语音 */
	kNIMVChatAdModeHighMusic	= 3,		/**< 高清音乐 */
};

/** @enum NIMVideoChatSessionStatus 音视频通话成员变化类型 */
enum NIMVideoChatSessionStatus{
    kNIMVideoChatSessionStatusJoined           = 0,	/**< 成员进入 */
    kNIMVideoChatSessionStatusLeaved           = 1,	/**< 成员退出 */
};

/** @enum NIMVideoChatUserLeftType 成员退出类型 */
enum NIMVideoChatUserLeftType{
	kNIMVChatUserLeftTimeout	= -1,		/**< 成员超时掉线 */
	kNIMVChatUserLeftNormal		= 0,		/**< 成员离开 */
};

/** @enum NIMVideoChatSessionNetStat 音视频通话网络变化类型 */
enum NIMVideoChatSessionNetStat{
	kNIMVChatNetStatusVideoClose			= -1,	/**< 网络状态极差，视频强制关闭 */
    kNIMVideoChatSessionNetStatGood			= 0,	/**< 网络状态较好 */
    kNIMVideoChatSessionNetStatPoor         = 1,	/**< 网络状态较差 */
    kNIMVideoChatSessionNetStatBad			= 2,	/**< 网络状态很差 */
};

/** @enum NIMVChatConnectErrorCode 音视频服务器连接状态类型 */
enum NIMVChatConnectErrorCode{
	kNIMVChatConnectDisconn				= 0,		/**< 断开连接 */
	kNIMVChatConnectStartFail			= 1,		/**< 启动失败 */
    kNIMVChatConnectTimeout				= 101,		/**< 超时 */
	kNIMVChatConnectMeetingModeError	= 102,		/**< 会议模式错误 */
	kNIMVChatConnectRtmpModeError		= 103,		/**< rtmp用户加入非rtmp频道 */
	kNIMVChatConnectRtmpNodesError		= 104,		/**< 超过频道最多rtmp人数限制 */
	kNIMVChatConnectRtmpHostError		= 105,		/**< 已经存在一个主播 */
	kNIMVChatConnectRtmpCreateError		= 106,		/**< 需要旁路直播, 但频道创建者非主播 */
	kNIMVChatJoinServerValidError		= 107,		/**< 服务器验证内部错误 */
	kNIMVChatJoinChannelClosed			= 108,		/**< 频道已经关闭 */
    kNIMVChatConnectSuccess				= 200,		/**< 成功 */
	kNIMVChatConnectLayoutError			= 208,		/**< 主播自定义布局错误 */
    kNIMVChatConnectInvalidParam		= 400,		/**< 错误参数 */
	kNIMVChatConnectDesKey				= 401,		/**< 密码加密错误 */
    kNIMVChatConnectInvalidRequst		= 417,		/**< 错误请求 */
    kNIMVChatConnectServerUnknown		= 500,		/**< 服务器内部错误 */
	kNIMVChatConnectLogout				= 1001,		/**< 退出 */
	kNIMVChatChannelStartFail			= 11000,	/**< 发起失败 */
	kNIMVChatChannelDisconnected		= 11001,	/**< 断开连接 */
	kNIMVChatVersionSelfLow				= 11002,	/**< 本人SDK版本太低不兼容 */
	kNIMVChatVersionRemoteLow			= 11003,	/**< 对方SDK版本太低不兼容 */
	kNIMVChatLocalChannelClosed			= 11004,	/**< 通道被关闭 */
	kNIMVChatLocalChannelKicked			= 11005,	/**< 账号被踢 */
};


/** @enum NIMNetDetectType 探测类型  */
enum NIMNetDetectType
{
	kNIMNetDetectTypeAudio		= 0,		/**< 默认值，音频探测 */
	kNIMNetDetectTypeVideo		= 1,		/**< 视频探测 */
};

/** @enum NIMNetDetectVideoQuality 视频探测类型  */
enum NIMNetDetectVideoQuality
{
	kNIMNDVideoQualityDefault	= 0, 		/**< 480P */
	kNIMNDVideoQualityLow		= 1,		/**< 176*144 */
	kNIMNDVideoQualityMedium	= 2, 		/**< 352*288 */
	kNIMNDVideoQualityHigh		= 3, 		/**< 480*320 */
	kNIMNDVideoQuality480p		= 4,		/**< 640*480 */
	kNIMNDVideoQuality720p		= 5,		/**< 1280*720 */
	kNIMNDVideoQuality540p		= 6,		/**< 960*540 */
};

/** @enum NIMMainPictureOptCode 房间主画面设置返回码 */
enum NIMMainPictureOptCode
{
	kNIMMainPictureOptSucess		= 200,		/**< 操作成功 */
	kNIMMainPictureOptAuthError		= 401,		/**< 认证错误*/
	kNIMMainPictureOptRoomNotExist	= 404,		/**< 房间不存在 */
	kNIMMainPictureOptUidNotExist	= 405,		/**< 房间下的uid不存在 */
	kNIMMainPictureOptDataError		= 417,		/**< 请求数据不对 */
	kNIMMainPictureOptError			= 500,		/**< 内部错误*/
	kNIMMainPictureOptServerError	= 600,		/**< 服务器内部错误 */
	kNIMMainPictureOptInvalid		= 11403,	/**< 无效的操作 */
};

/** @enum NIMVChatServRecordType 服务器录制模式，用于指定本人数据录制选择 */
enum NIMVChatServRecordType
{
	kNIMVChatServRecordMixedSingle	= 0,	/**< 服务器录制混录并带单人文件 */
	kNIMVChatServRecordMixed		= 1,	/**< 服务器录制只混录 */
	kNIMVChatServRecordSingle		= 2,	/**< 服务器录制只录本人单人文件 */
};

/** @enum NIMVChatPubSubNotifyType 订阅及发布相关通知类型 */
enum NIMVChatPubSubNotifyType
{
	kNIMVChatNotifyPublishVideoRet			= 0,	/**< 本地视频发布操作的结果返回通知 */
	kNIMVChatNotifyUnpublishVideoRet		= 1,	/**< 本地取消视频发布操作的结果返回通知 */
	kNIMVChatNotifyRemotePublishVideo		= 2,	/**< 远端视频发布通知 */
	kNIMVChatNotifyRemoteUnpublishVideo		= 3,	/**< 远端视频停止发布通知 */
	kNIMVChatNotifySubscribeVideoRet		= 4,	/**< 本地订阅远端视频操作的结果返回通知 */
	kNIMVChatNotifyUnsubscribeVideoRet		= 5,	/**< 本地取消订阅远端视频操作的结果返回通知 */
	kNIMVChatNotifySubscribeAudioRet		= 6,	/**< 本地订阅远端音频操作的结果返回通知 */
	kNIMVChatNotifyUnsubscribeAudioRet		= 7,	/**< 本地取消订阅远端音频操作的结果返回通知 */
};

/** @enum NIMVChatPublishVideoStreamMode 发布视频流模式 */
enum NIMVChatPublishVideoStreamMode
{
	kNIMVChatPublishVideoSingleStream       = 0,	/**< 发布单流模式（默认） */
	kNIMVChatPublishVideoDualStream         = 1,	/**< 发布双流模式 */
};
/** @enum NIMVChatPublishVideoSimulcastRes 视频流类型 */
enum NIMVChatPublishVideoSimulcastRes
{
	kNIMVChatPublishVideoSimulcastResHigh   = 0,  /**< 高分辨率视频流 */
	kNIMVChatPublishVideoSimulcastResLow    = 2,  /**< 低分辨率视频流 */
};

/** @enum NIMVChatPubSubErrorCode 订阅及发布相关通知类型 */
enum NIMVChatPubSubErrorCode
{
	kNIMVChatPSErrCodeSuccess		= 0,	/**< 成功 */
	kNIMVChatPSErrCodeFail			= -1,	/**< 失败 */
	kNIMVChatPSErrCodeViewerMode	= -200,	/**< 发布操作失败，当前为观众模式 */
	kNIMVChatPSErrCodeAudioMode		= -300,	/**< 视频发布操作失败，当前为音频模式 */
	kNIMVChatPSErrCodeOptBusy		= -400,	/**< 操作繁忙 */
	kNIMVChatPSErrCodeAutoMode		= -500,	/**< 模式互斥 （当前是自动发布） */
	kNIMVChatPSErrCodeForbid		= -600,	/**< 操作无效，对点对模式不支持订阅相关功能 */
	kNIMVChatPSErrCodeSubscribed    = -700, /**< 操作无效，视频类型冲突，需要取消之前订阅的流 */
};

/** @enum NIMVChatServerSubscribeFallbackStrategy 服务器在下行弱网的时候切流策略 */
enum NIMVChatServerSubscribeFallbackStrategy {
	kNIMVChatSteamFallbackStrategyDisabled  = 0,  /**< 禁用服务器弱网切流策略 */
	kNIMVChatSteamFallbackStrategyAudioOnly = 2,  /**< 默认策略允许服务器切小流、关视频 */
};

/** @name 初始化 内容Json key for nim_vchat_init
* @{
*/
static const char *kNIMVChatServerSettingPath	= "server_setting_path";		/**< string 服务器配置文件路径 */
/** @}*/ //初始化 内容Json key

/** @name 网络探测 内容Json key for nim_vchat_net_detect
  * @{
  */
static const char *kNIMNetDetectAppKey		= "app_key";		/**< string 用户的app key */
static const char *kNIMNetDetectTimeLimit	= "time";			/**< int32 毫秒级的探测时长限制 */
static const char *kNIMNetDetectType		= "type";			/**< int32 探测类型NIMNetDetectType */
static const char *kNIMNetDetectQualityType = "quality_type";	/**< int32 kNIMNetDetectTypeVideo时有效，默认为0，视频探测类型NIMNetDetectVideoQuality */
/** @}*/ //网络探测 内容Json key

/** @name 网络探测回调 内容Json key for nim_vchat_opt_cb_func
  * @{
  */
static const char *kNIMNetDetectTaskId		= "task_id";		/**< uint64 任务id */
static const char *kNIMNetDetectLoss		= "loss";			/**< int 丢包率百分比 */
static const char *kNIMNetDetectRttmax		= "rttmax";			/**< int rtt 最大值 */
static const char *kNIMNetDetectRttmin		= "rttmin";			/**< int rtt 最小值 */
static const char *kNIMNetDetectRttavg		= "rttavg";			/**< int rtt 平均值 */
static const char *kNIMNetDetectRttmdev		= "rttmdev";		/**< int rtt 偏差值 mdev */
static const char *kNIMNetDetectDetail		= "detailinfo";		/**< string 扩展信息 */
/** @}*/ //网络探测回调 内容Json key

/** @name json extension params for start join or ack accept
  * @{
  */
static const char *kNIMVChatUids			= "uids";			/**< StrArray 帐号, ack无效 */
static const char *kNIMVChatSessionId		= "session_id";		/**< string 发起会话的标识id，将在创建通话及结束通话时有效，帮助针对无channelid的情况下进行映射 */
static const char* kNIMVChatTimeout			= "time_out";/**< bool 是呼叫超时 true 是，false 否 */
static const char *kNIMVChatCustomVideo		= "custom_video";	/**< int 是否用自主的视频数据 >0表示是 */
static const char *kNIMVChatCustomAudio		= "custom_audio";	/**< int 是否用自主的音频数据 >0表示是 */
static const char *kNIMVChatRecord			= "record";			/**< int 是否需要录制音频数据 >0表示是 （需要服务器配置支持，本地录制直接调用接口函数） */
static const char *kNIMVChatVideoRecord		= "video_record";	/**< int 是否需要录制视频数据 >0表示是 （需要服务器配置支持，本地录制直接调用接口函数）*/
static const char *kNIMVChatRecordType		= "record_type";	/**< int 服务器录制模式NIMVChatServRecordType，默认为0 （需要服务器配置支持，并且开kNIMVChatRecord，kNIMVChatVideoRecord其中一个）*/
static const char *kNIMVChatRHostSpeaker	= "r_host_speaker";	/**< int 服务器混录时指定本人主画面，默认为0, 非0表示打开（需要服务器配置支持，及录制模式打开混录，并且为多人中的第一个主画面配置）*/
static const char *kNIMVChatMaxVideoRate	= "max_video_rate";	/**< int 视频发送编码码率 >=100000 <=5000000有效 */
static const char *kNIMVChatVideoQuality	= "video_quality";	/**< int 视频聊天分辨率选择 NIMVChatVideoQuality */
static const char *kNIMVChatVideoFrameRate	= "frame_rate";		/**< int 视频画面帧率 NIMVChatVideoFrameRate */
static const char *kNIMVChatAudioMode		= "audio_mode";		/**< int 音频模式选择 NIMVChatAudioMode*/
static const char *kNIMVChatRtmpUrl			= "rtmp_url";		/**< string 直播推流地址(加入多人时有效)，非空代表主播旁路直播， kNIMVChatBypassRtmp决定是否开始推流 */
static const char *kNIMVChatBypassRtmp		= "bypass_rtmp";	/**< int 是否旁路推流（如果rtmpurl为空是连麦观众，非空是主播的推流控制）， >0表示是 */
static const char *kNIMVChatRtmpRecord		= "rtmp_record";	/**< int 是否开启服务器对直播推流录制（需要开启服务器能力）， >0表示是 */
static const char *kNIMVChatSplitMode		= "split_mode";		/**< int 主播控制的直播推流时的分屏模式，见NIMVChatVideoSplitMode */
static const char *kNIMVChatCustomLayout	= "custom_layout";	/**< string 自定义布局，当主播选择kNIMVChatSplitCustomLayout或kNIMVChatSplitAudioLayout模式时生效 */
static const char *kNIMVChatPushEnable		= "push_enable";	/**< int 是否需要推送 >0表示是 默认是 */
static const char *kNIMVChatNeedBadge		= "need_badge";		/**< int 是否需要角标计数 >0表示是 默认是 */
static const char *kNIMVChatNeedFromNick	= "need_nick";		/**< int 是否需要推送昵称 >0表示是 默认是 */
static const char *kNIMVChatApnsPayload		= "payload";		/**< string JSON格式,推送payload */
static const char *kNIMVChatSound			= "sound";			/**< string 推送声音 */
static const char *kNIMVChatKeepCalling		= "keepcalling";	/**< int, 是否强制持续呼叫（对方离线也会呼叫）,1表示是，0表示否。默认是 */
//无效已经默认支持 static const char *kNIMVChatWebrtc			= "webrtc";			/**< int, 是否支持webrtc互通,1表示是，0表示否。默认否，无需要不要开启 */
static const char *kNIMVChatVEncodeMode		= "v_encode_mode";	/**< int, 使用的视频编码策略NIMVChatVideoEncodeMode， 默认kNIMVChatVEModeNormal */
static const char *kNIMVChatServerSubscribeFallbackStrategy		   = "server_sub_fb_stategy";	/**< int,服务器在下行弱网的时候切流策略NIMVChatServerSubscribeFallbackStrategy， 默认kNIMVChatSteamFallbackStrategyAudioOnly */

/** @}*/ //json extension params

/** @name json extension params for nim_vchat_cb_func
  * @{
  */
static const char *kNIMVChatUid				          = "uid";				/**< string 帐号 */
static const char *kNIMVChatStatus			          = "status";				/**< int 状态 */
static const char *kNIMVChatRecordAddr		          = "record_addr";		/**< string 录制地址（服务器开启录制时有效） */
static const char *kNIMVChatRecordFile		          = "record_file";		/**< string 服务器音频录制文件名（服务器开启录制时有效） */
static const char *kNIMVChatVideoRecordFile           = "video_record_file";	/**< string 服务器视频录制文件名（服务器开启录制时有效） */
static const char *kNIMVChatType			          = "type";				/**< int 状态 */
static const char *kNIMVChatTime			          = "time";				/**< int64 时间 单位毫秒 */
static const char *kNIMVChatAccept			          = "accept";				/**< int 是否接受 >0表示接受 */
static const char *kNIMVChatClient			          = "client";				/**< int 客户端类型 NIMClientType见nim_client_def.h */
static const char *kNIMVChatMp4Start		          = "mp4_start";			/**< key Mp4写入数据开始 kNIMVChatMp4File kNIMVChatTime(本地时间点) */
static const char *kNIMVChatMp4Close		          = "mp4_close";			/**< key 结束Mp4录制，返回时长及原因 kNIMVChatStatus(NIMVChatMp4RecordCode) kNIMVChatTime(时长) kNIMVChatMp4File */
static const char *kNIMVChatMp4File			          = "mp4_file";			/**< string mp4录制地址 */
static const char *kNIMVChatAuRecordStart	          = "audio_record_start";	/**< key 音频录制写入数据开始 kNIMVChatFile kNIMVChatTime */
static const char *kNIMVChatAuRecordClose	          = "audio_record_close";	/**< key 结束音频录制，返回时长及原因 kNIMVChatStatus(NIMVChatAudioRecordCode) kNIMVChatTime kNIMVChatFile */
static const char *kNIMVChatFile			          = "file";				/**< string 文件地址 */
static const char *kNIMVChatCustomInfo		          = "custom_info";		/**< string 自定义数据 */
static const char *kNIMVChatVideo			          = "video";				/**< key 视频 */
static const char *kNIMVChatAudio			          = "audio";				/**< key 音频 */
static const char *kNIMVChatStaticInfo		          = "static_info";		/**< key 音视频实时状态 */
static const char *kNIMVChatFPS				          = "fps";				/**< int 每秒帧率或者每秒发包数 */
static const char *kNIMVChatKBPS			          = "KBps";				/**< int 每秒流量，单位为“千字节” */
static const char *kNIMVChatLostRate		          = "lost_rate";			/**< int 丢包率，单位是百分比 */
static const char *kNIMVChatRtt				          = "rtt";				/**< int rtt 网络延迟 */
static const char *kNIMVChatAudioVolume		          = "audio_volume";		/**< key 音频实时音量通知，包含发送的音量kNIMVChatSelf和接收音量kNIMVChatReceiver，kNIMVChatStatus的音量值是pcm的平均值最大为int16_max */
static const char *kNIMVChatSelf			          = "self";				/**< key 本人信息 */
static const char *kNIMVChatReceiver		          = "receiver";			/**< key 接收信息 */
static const char *kNIMVChatLiveState		          = "live_state";			/**< key 直播状态 kNIMVChatStatus(NIMVChatLiveStateCode) */
static const char *kNIMVChatMp4AudioType	          = "mp4_audio";			/**< int mp4录制时音频情况，0标识只录制当前成员，1标识录制通话全部混音（等同音频文件录制的声音） */
static const char *kNIMVChatMp4Recode		          = "mp4_recode";			/**< bool mp4录制时重新编码开关 */
static const char *kNIMVChatMp4Width		          = "mp4_width";			/**< int 录制的mp4的宽度，默认为0，小于16无效，无效时取视频默认大小*/
static const char *kNIMVChatMp4Height		          = "mp4_height";			/**< int 录制的mp4的高度，默认为0，小于16无效，无效时取视频默认大小*/
static const char *kNIMVChatTrafficStatRX	          = "trafficstat_rx";		/**< uint64 下行流量（字节） */
static const char *kNIMVChatTrafficStatTX	          = "trafficstat_tx";		/**< uint64 上行流量（字节） */
static const char *kNIMVChatVideoSimulcastResList     = "video_simulcast_res_list"; /**< json array 订阅发布视频分辨率类型列表*/

/** @name json extension params for nim_vchat_create_room
  * @{
  */
static const char *kNIMVChatRoomConfig                = "room_config";	     /**< key 房间配置 */
static const char *kNIMVChatRTMPTasks                 = "rtmpTasks";         /**< array 推流参数配置,可以配置多个 */
static const char *kNIMVChatRTMPTaskID                = "taskId";            /**< 必填 string 推流任务ID */
static const char *kNIMVChatRTMPURL                   = "streamUrl";         /**< 必填 string 推流地址 */
static const char *kNIMVChatRTMPLayoutMode            = "layoutMode";        /**< 必填 int 连麦方式 */
static const char *kNIMVChatRTMPLayoutPara            = "layoutPara";        /**< 选填 string 自定义布局参数，仅对kNIMVChatSplitCustomLayout,kNIMVChatSplitAudioLayout模式有效 */
static const char *kNIMVChatRTMPRecord                = "record";            /**< 选填 bool 推流参数配置 */
static const char *kNIMVChatRTMPMainScreenAccid       = "accid";             /**< 选填 string 指定主屏显示的帐号 */


/** @}*/ //json extension params

/** @typedef void (*nim_vchat_cb_func)(NIMVideoChatSessionType type, int64_t channel_id, int code, const char *json_extension, const void *user_data)
  * NIM VChat 	音视频通话中状态返回回调接口   \n
  * 			根据NIMVideoChatSessionType的具体参数说明如下： \n
  * 			kNIMVideoChatSessionTypeStartRes,			//创建通话结果 code=200成功，json 返回kNIMVChatSessionId \n
  * 			kNIMVideoChatSessionTypeInviteNotify,		//通话邀请 code无效,json 返回kNIMVChatUid发起者，kNIMVChatType对应NIMVideoChatMode, kNIMVChatTime, kNIMVChatCustomInfo \n
  * 			kNIMVideoChatSessionTypeCalleeAckRes,		//确认通话，接受拒绝结果 json 无效 code: 200:成功 9103 : 已经在其他端接听 / 拒绝过这通电话 \n
  * 			kNIMVideoChatSessionTypeCalleeAckNotify,	//确认通话，接受拒绝通知 code=无效，json 返回kNIMVChatUid对方，kNIMVChatType对应NIMVideoChatMode, kNIMVChatAccept \n
  * 			kNIMVideoChatSessionTypeControlRes,			//NIMVChatControlType 结果  code=200成功，json 返回kNIMVChatType对应NIMVChatControlType \n
  * 			kNIMVideoChatSessionTypeControlNotify,		//NIMVChatControlType 通知	code=无效，json 返回kNIMVChatUid对方，kNIMVChatType对应NIMVChatControlType \n
  * 			kNIMVideoChatSessionTypeConnect,			//通话中链接状态通知 code对应NIMVChatConnectErrorCode， 非200均失败并底层结束 \n
  *															//					code=1001,代表通话注销结果，带通话本地时长（kNIMVChatTime）及数据量（kNIMVChatTrafficStatRX kNIMVChatTrafficStatTX）\n
  * 			kNIMVideoChatSessionTypePeopleStatus,		//通话中成员状态 code对应NIMVideoChatSessionStatus, json返回kNIMVChatUid，如果是离开带kNIMVChatStatus对应NIMVideoChatUserLeftType \n
  * 			kNIMVideoChatSessionTypeNetStatus,			//通话中网络状态 code对应NIMVideoChatSessionNetStat, json返回kNIMVChatUid \n
  * 			kNIMVideoChatSessionTypeHangupRes,			//通话主动结果 code=200成功，json无效 \n
  * 			kNIMVideoChatSessionTypeHangupNotify,		//通话被挂断通知 code无效，json无效 \n
  * 			kNIMVideoChatSessionTypeSyncAckNotify,		//其他端接听挂断后的同步通知 json 返回 kNIMVChatTime，kNIMVChatType对应NIMVideoChatMode，kNIMVChatAccept，kNIMVChatClient  \n
  *				kNIMVideoChatSessionTypeMp4Notify			//windows(pc)有效.通知MP4录制状态，包括开始录制和结束录制， code无效，json(其他成员的录制通知带uid，自己的不带) 返回如下 \n
  *															//	MP4开始 	{"mp4_start":{ "mp4_file": "d:\\test.mp4", "time": 14496477000000, "uid":"id123" }} \n
  *															//	MP4结束 	{"mp4_close":{ "mp4_file": "d:\\test.mp4", "time": 120000, "status": 0, "uid":"id123" }} \n
  *				kNIMVideoChatSessionTypeAuRecordNotify		//windows(pc)有效.通知音频录制状态，包括开始录制和结束录制 code无效，json 返回如下 \n
  *															//	录制开始 	{"audio_record_start":{ "file": "d:\\test.aac", "time": 14496477000000 }} \n
  *															//	录制结束 	{"audio_record_close":{ "file": "d:\\test.aac", "time": 120000, "status": 0 }} \n
  *				kNIMVideoChatSessionTypeInfoNotify			//实时状态		{"static_info":{"rtt":20, "video": {"fps":20, "KBps":200, "lost_rate":5, "width":1280,"height":720}, "audio": {"fps":17, "KBps":3", lost_rate":3 }}} \n
  *				kNIMVideoChatSessionTypeVolumeNotify		//音量状态 		{"audio_volume":{ "self": {"status":600}, "receiver": [{"uid":"id123","status":1000},{"uid":"id456","status":222}] }} \n
  *				kNIMVideoChatSessionTypeLiveState			//windows(pc)有效.直播状态		{"live_state":{"status":505 }} \n
  *				kNIMVideoChatSessionTypePubSubNotify		//订阅及发布相关的通知，code返回(NIMVChatPubSubErrorCode),json包含kNIMVChatType(NIMVChatPubSubNotifyType) 远端视频额外带有kNIMVChatUid 本端订阅发布操作、远端发布带有kNIMVChatVideoSimulcastResList\n
  * @param[out] type NIMVideoChatSessionType
  * @param[out] channel_id 通话的通道id
  * @param[out] code 结果类型或错误类型
  * @param[out] json_extension Json string 扩展
  * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  *
  */
typedef void (*nim_vchat_cb_func)(enum NIMVideoChatSessionType type, int64_t channel_id, int code, const char *json_extension, const void *user_data);


/** @typedef void (*nim_vchat_mp4_record_opt_cb_func)(bool ret, int code, const char *file, int64_t time, const char *json_extension, const void *user_data)
  * NIM MP4操作回调，实际的开始录制和结束都会在nim_vchat_cb_func中返回
  * @param[out] ret 结果代码，true表示成功
  * @param[out] code 对应NIMVChatMp4RecordCode，用于获得失败时的错误原因
  * @param[out] file 文件路径
  * @param[out] time 录制结束时有效，对应毫秒级的录制时长
  * @param[out] json_extension Json string 无效扩展字段
  * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_vchat_mp4_record_opt_cb_func)(bool ret, int code, const char *file, int64_t time, const char *json_extension, const void *user_data);

/** @typedef void (*nim_vchat_audio_record_opt_cb_func)(bool ret, int code, const char *file, __int64 time, const char *json_extension, const void *user_data)
  * NIM 音频录制操作回调，实际的开始录制和结束都会在nim_vchat_cb_func中返回
  * @param[out] ret 结果代码，true表示成功
  * @param[out] code 对应NIMVChatAudioRecordCode，用于获得失败时的错误原因
  * @param[out] file 文件路径
  * @param[out] time 录制结束时有效，对应毫秒级的录制时长
  * @param[out] json_extension Json string 无效扩展字段
  * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_vchat_audio_record_opt_cb_func)(bool ret, int code, const char *file, int64_t time, const char *json_extension, const void *user_data);


/** @typedef void (*nim_vchat_opt_cb_func)(bool ret, int code, const char *json_extension, const void *user_data)
  * NIM 操作回调，通用的操作回调接口
  * @param[out] ret 结果代码，true表示成功
  * @param[out] code 暂时无效
  * @param[out] json_extension Json string 扩展字段
  * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_vchat_opt_cb_func)(bool ret, int code, const char *json_extension, const void *user_data);

/** @typedef void (*nim_vchat_opt2_cb_func)(int code, int64_t channel_id, const char *json_extension, const void *user_data)
  * NIM 操作回调，通用的操作回调接口
  * @param[out] code 结果代码，code==200表示成功
  * @param[out] channel_id 通道id
  * @param[out] json_extension Json string 扩展字段kNIMVChatSessionId，加入多人的返回中带有kNIMVChatCustomInfo
  * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
  * @return void 无返回值
  */
typedef void (*nim_vchat_opt2_cb_func)(int code, int64_t channel_id, const char *json_extension, const void *user_data);

/** @typedef void(*nim_vchat_rate_callback)(bool ret, int response_code,const char *json_extension,const void *user_data);
 * 用户反馈回调
 * @param[out] ret	反馈结果
 * @param[out] response_code HTTP错误码
 * @param[out] json_extension	json数据
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void(*nim_vchat_rate_callback)(bool ret, int response_code,const char *json_extension,const void *user_data);

#ifdef __cplusplus
};
#endif //__cplusplus
#endif //NIM_SDK_DLL_EXPORT_HEADERS_NIM_VCHAT_DEF_H_