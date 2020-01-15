//
//  NIMSDKAVChatDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKAVChatDefine_h
#define NIMSDKAVChatDefine_h

/** @enum NIMSDKAVChatSessionType 音视频通话状态通知类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatSessionType)
{
    NIMSDKAVChatSessionTypeStartRes        = 1,        /**< 创建通话结果 */
    NIMSDKAVChatSessionTypeInviteNotify    = 2,        /**< 通话邀请 */
    NIMSDKAVChatSessionTypeCalleeAckRes    = 3,        /**< 确认通话，接受拒绝结果 */
    NIMSDKAVChatSessionTypeCalleeAckNotify    = 4,        /**< 确认通话，接受拒绝通知 */
    NIMSDKAVChatSessionTypeControlRes        = 5,        /**< NIMSDKAVChatControlType 结果 */
    NIMSDKAVChatSessionTypeControlNotify    = 6,        /**< NIMSDKAVChatControlType 通知 */
    NIMSDKAVChatSessionTypeConnect            = 7,        /**< 通话中链接状态通知 */
    NIMSDKAVChatSessionTypePeopleStatus    = 8,        /**< 通话中成员状态 */
    NIMSDKAVChatSessionTypeNetStatus        = 9,        /**< 通话中网络状态 */
    NIMSDKAVChatSessionTypeHangupRes        = 10,        /**< 通话挂断结果 */
    NIMSDKAVChatSessionTypeHangupNotify    = 11,        /**< 通话被挂断通知 */
    NIMSDKAVChatSessionTypeSyncAckNotify    = 12,        /**< 通话接听挂断同步通知 */
    NIMSDKAVChatSessionTypeMp4Notify        = 13,        /**< 通知MP4录制状态，包括开始录制和结束录制 */
    NIMSDKAVChatSessionTypeInfoNotify        = 14,        /**< 通知实时音视频数据状态 */
    NIMSDKAVChatSessionTypeVolumeNotify    = 15,        /**< 通知实时音频发送和混音的音量状态 */
    NIMSDKAVChatSessionTypeAuRecordNotify  = 16,        /**< 通知音频录制状态，包括开始录制和结束录制 */
    NIMSDKAVChatSessionTypeLiveState        = 17,        /**< 通知直播推流的服务器状态 */
    NIMSDKAVChatSessionTypePubSubNotify    = 18,        /**< 通知订阅相关通知 */
};

/** @enum NIMSDKAVChatControlType 音视频通话控制类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatControlType)
{
    NIMSDKAVChatControlOpenAudio             = 1,    /**< 打开音频 */
    NIMSDKAVChatControlCloseAudio            = 2,    /**< 关闭音频 */
    NIMSDKAVChatControlOpenVideo             = 3,    /**< 打开视频 */
    NIMSDKAVChatControlCloseVideo            = 4,    /**< 关闭视频 */
    NIMSDKAVChatControlAudioToVideo          = 5,    /**< 请求从音频切换到视频 */
    NIMSDKAVChatControlAgreeAudioToVideo     = 6,    /**< 同意从音频切换到视频 */
    NIMSDKAVChatControlRejectAudioToVideo    = 7,    /**< 拒绝从音频切换到视频 */
    NIMSDKAVChatControlVideoToAudio          = 8,    /**< 从视频切换到音频 */
    NIMSDKAVChatControlBusyLine              = 9,    /**< 占线 */
    NIMSDKAVChatControlCamaraNotAvailable    = 10,   /**< 告诉对方自己的摄像头不可用 */
    NIMSDKAVChatControlEnterBackground       = 11,   /**< 告诉对方自已处于后台 */
    NIMSDKAVChatControlReceiveStartNotifyFeedback = 12,   /**< 告诉发送方自己已经收到请求了（用于通知发送方开始播放提示音） */
    NIMSDKAVChatControlMp4StartRecord        = 13,   /**< 告诉发送方自己开始录制 */
    NIMSDKAVChatControlMp4StopRecord            = 14,   /**< 告诉发送方自己结束录制 */
};

/** @enum NIMSDKAVChatMode 音视频通话类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatMode)
{
    NIMSDKAVChatModeAudio    =    1,    /**< 语音通话模式 */
    NIMSDKAVChatModeVideo    =    2    /**< 视频通话模式 */
};

/** @enum NIMSDKAVChatVideoQuality 视频通话分辨率，最终长宽比不保证 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatVideoQuality)
{
    NIMSDKAVChatVideoQualityNormal        = 0,        /**< 视频默认分辨率 480x320*/
    NIMSDKAVChatVideoQualityLow        = 1,        /**< 视频低分辨率 176x144*/
    NIMSDKAVChatVideoQualityMedium        = 2,        /**< 视频中分辨率 352x288*/
    NIMSDKAVChatVideoQualityHigh        = 3,        /**< 视频高分辨率 480x320*/
    NIMSDKAVChatVideoQualitySuper        = 4,        /**< 视频超高分辨率 640x480*/
    NIMSDKAVChatVideoQuality540p        = 5,        /**< 介于720P与480P之间的类型，默认 960*540 */
    NIMSDKAVChatVideoQuality720p        = 6,        /**< 用于桌面分享级别的分辨率1280x720，需要使用高清摄像头并指定对应的分辨率，或者自定义通道传输 */
};

/** @enum NIMSDKAVChatVideoFrameRate 视频通话帧率，实际帧率因画面采集频率和机器性能限制可能达不到期望值 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatVideoFrameRate)
{
    NIMSDKAVChatVideoFrameRateNormal    = 0,        /**< 视频通话帧率默认值,最大取每秒15帧 */
    NIMSDKAVChatVideoFrameRate5        = 1,        /**< 视频通话帧率 最大取每秒5帧 */
    NIMSDKAVChatVideoFrameRate10        = 2,        /**< 视频通话帧率 最大取每秒10帧 */
    NIMSDKAVChatVideoFrameRate15        = 3,        /**< 视频通话帧率 最大取每秒15帧 */
    NIMSDKAVChatVideoFrameRate20        = 4,        /**< 视频通话帧率 最大取每秒20帧 */
    NIMSDKAVChatVideoFrameRate25        = 5,        /**< 视频通话帧率 最大取每秒25帧 */
};

/** @enum NIMSDKAVChatVideoEncodeMode 视频编码策略  */
typedef NS_ENUM(NSInteger, NIMSDKAVChatVideoEncodeMode)
{
    NIMSDKAVChatVEModeNormal        = 0,        /**< 默认值，清晰优先 */
    NIMSDKAVChatVEModeFramerate    = 1,        /**< 流畅优先 */
    NIMSDKAVChatVEModeQuality        = 2,        /**< 清晰优先 */
    NIMSDKAVChatVEModeScreen        = 3,        /**< 屏幕共享场景调控策略，sdk不会根据网络调整分辨率 */
};

/** @enum NIMSDKAVChatVideoFrameScaleType 视频画面长宽比，裁剪时不改变横竖屏，如4：3，代表宽高横屏4：3或者竖屏3：4  */
typedef NS_ENUM(NSInteger, NIMSDKAVChatVideoFrameScaleType)
{
    NIMSDKAVChatVideoFrameScaleNone    = 0,            /**< 默认，不裁剪 */
    NIMSDKAVChatVideoFrameScale1x1        = 1,            /**< 裁剪成1：1的形状 */
    NIMSDKAVChatVideoFrameScale4x3        = 2,            /**< 裁剪成4：3的形状，如果是 */
    NIMSDKAVChatVideoFrameScale16x9    = 3,            /**< 裁剪成16：9的形状 */
};

/** @enum NIMSDKAVChatMp4RecordCode mp4录制状态 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatMp4RecordCode)
{
    NIMSDKAVChatMp4RecordClose                = 0,        /**< MP4结束 */
    NIMSDKAVChatMp4RecordVideoSizeError    = 1,        /**< MP4结束，视频画面大小变化 */
    NIMSDKAVChatMp4RecordOutDiskSpace        = 2,        /**< MP4结束，磁盘空间不足 */
    NIMSDKAVChatMp4RecordThreadBusy        = 3,        /**< MP4结束，录制线程繁忙 */
    NIMSDKAVChatMp4RecordCreate            = 200,        /**< MP4文件创建 */
    NIMSDKAVChatMp4RecordExsit                = 400,        /**< MP4文件已经存在 */
    NIMSDKAVChatMp4RecordCreateError        = 403,        /**< MP4文件创建失败 */
    NIMSDKAVChatMp4RecordInvalid            = 404,        /**< 通话不存在 */
};

/** @enum NIMSDKAVChatAudioRecordCode 音频录制状态 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatAudioRecordCode)
{
    NIMSDKAVChatAudioRecordClose            = 0,        /**< 录制正常结束 */
    NIMSDKAVChatAudioRecordOutDiskSpace    = 2,        /**< 录制结束，磁盘空间不足 */
    NIMSDKAVChatAudioRecordCreate            = 200,        /**< 文件创建成功 */
    NIMSDKAVChatAudioRecordExsit            = 400,        /**< 已经存在 */
    NIMSDKAVChatAudioRecordCreateError        = 403,        /**< 文件创建失败 */
    NIMSDKAVChatAudioRecordInvalid            = 404,        /**< 通话不存在 */
};

/** @enum NIMSDKAVChatVideoSplitMode 主播设置的直播分屏模式  */
typedef NS_ENUM(NSInteger, NIMSDKAVChatVideoSplitMode)
{
    NIMSDKAVChatSplitBottomHorFloating        = 0,            /**< 底部横排浮窗 */
    NIMSDKAVChatSplitTopHorFloating        = 1,            /**< 顶部横排浮窗 */
    NIMSDKAVChatSplitLatticeTile            = 2,            /**< 平铺 */
    NIMSDKAVChatSplitLatticeCuttingTile    = 3,            /**< 裁剪平铺 */
    NIMSDKAVChatSplitCustomLayout            = 4,            /**< 自定义布局 */
    NIMSDKAVChatSplitAudioLayout            = 5,            /**< 纯音频布局 */
};



/** @enum NIMSDKAVChatLiveStateCode 直播时的状态码。服务器定时更新，一些存在时间短的状态会获取不到  */
typedef NS_ENUM(NSInteger, NIMSDKAVChatLiveStateCode)
{
    NIMSDKAVChatLiveStateInitial            = 500,
    NIMSDKAVChatLiveStateLayoutError        = 501,        /**< 主播设置定制布局，布局参数错误 */
    NIMSDKAVChatLiveStateStartConnecting    = 502,        /**< 开始连接 */
    NIMSDKAVChatLiveStateConnectted        = 503,        /**< 连接成功 */
    NIMSDKAVChatLiveStateConnectFail        = 504,        /**< 连接失败 */
    NIMSDKAVChatLiveStatePushing            = 505,        /**< 推流中 */
    NIMSDKAVChatLiveStatePushFail            = 506,        /**< 互动直播推流失败 */
    NIMSDKAVChatLiveStateInnerError        = 507,        /**< 内部错误 */
    NIMSDKAVChatLiveStatePeopleLimit        = 508,        /**< 人数超出限制 */
};


/** @enum NIMSDKAVChatAudioMode 音频模式  */
typedef NS_ENUM(NSInteger, NIMSDKAVChatAudioMode)
{
    NIMSDKAVChatAdModeDefault        = 0,        /**< 默认值，此时参考NIMSDKAVChatAudioHighRate */
    NIMSDKAVChatAdModeNormal        = 1,        /**< 窄带，NIMSDKAVChatAudioHighRate无效 */
    NIMSDKAVChatAdModeHighVoip        = 2,        /**< 高清语音，NIMSDKAVChatAudioHighRate无效 */
    NIMSDKAVChatAdModeHighMusic    = 3,        /**< 高清音乐，NIMSDKAVChatAudioHighRate无效 */
};

/** @enum NIMSDKAVChatSessionStatus 音视频通话成员变化类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatSessionStatus)
{
    NIMSDKAVChatSessionStatusJoined           = 0,    /**< 成员进入 */
    NIMSDKAVChatSessionStatusLeaved           = 1,    /**< 成员退出 */
};

/** @enum NIMSDKAVChatUserLeftType 成员退出类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatUserLeftType)
{
    NIMSDKAVChatUserLeftTimeout    = -1,        /**< 成员超时掉线 */
    NIMSDKAVChatUserLeftNormal        = 0,        /**< 成员离开 */
};

/** @enum NIMSDKAVChatSessionNetStat 音视频通话网络变化类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatSessionNetStat)
{
    NIMSDKAVChatNetStatusVideoClose            = -1,    /**< 网络状态极差，视频强制关闭 */
    NIMSDKAVChatSessionNetStatGood            = 0,    /**< 网络状态较好 */
    NIMSDKAVChatSessionNetStatPoor         = 1,    /**< 网络状态较差 */
    NIMSDKAVChatSessionNetStatBad            = 2,    /**< 网络状态很差 */
};

/** @enum NIMSDKAVChatConnectErrorCode 音视频服务器连接状态类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatConnectErrorCode) {
    NIMSDKAVChatConnectDisconn                = 0,        /**< 断开连接 */
    NIMSDKAVChatConnectStartFail            = 1,        /**< 启动失败 */
    NIMSDKAVChatConnectTimeout                = 101,        /**< 超时 */
    NIMSDKAVChatConnectMeetingModeError    = 102,        /**< 会议模式错误 */
    NIMSDKAVChatConnectRtmpModeError        = 103,        /**< rtmp用户加入非rtmp频道 */
    NIMSDKAVChatConnectRtmpNodesError        = 104,        /**< 超过频道最多rtmp人数限制 */
    NIMSDKAVChatConnectRtmpHostError        = 105,        /**< 已经存在一个主播 */
    NIMSDKAVChatConnectRtmpCreateError        = 106,        /**< 需要旁路直播, 但频道创建者非主播 */
    NIMSDKAVChatJoinServerValidError        = 107,        /**< 服务器验证内部错误 */
    NIMSDKAVChatJoinChannelClosed            = 108,        /**< 频道已经关闭 */
    NIMSDKAVChatConnectSuccess                = 200,        /**< 成功 */
    NIMSDKAVChatConnectLayoutError            = 208,        /**< 主播自定义布局错误 */
    NIMSDKAVChatConnectInvalidParam        = 400,        /**< 错误参数 */
    NIMSDKAVChatConnectDesKey                = 401,        /**< 密码加密错误 */
    NIMSDKAVChatConnectInvalidRequst        = 417,        /**< 错误请求 */
    NIMSDKAVChatConnectServerUnknown        = 500,        /**< 服务器内部错误 */
    NIMSDKAVChatConnectLogout                = 1001,        /**< 退出 */
    NIMSDKAVChatChannelStartFail            = 11000,    /**< 发起失败 */
    NIMSDKAVChatChannelDisconnected        = 11001,    /**< 断开连接 */
    NIMSDKAVChatVersionSelfLow                = 11002,    /**< 本人SDK版本太低不兼容 */
    NIMSDKAVChatVersionRemoteLow            = 11003,    /**< 对方SDK版本太低不兼容 */
    NIMSDKAVChatLocalChannelClosed            = 11004,    /**< 通道被关闭 */
    NIMSDKAVChatLocalChannelKicked            = 11005,    /**< 账号被踢 */
};


/** @enum NIMSDKAVChatNetDetectType 探测类型  */
typedef NS_ENUM(NSInteger, NIMSDKAVChatNetDetectType)
{
    NIMSDKAVChatNetDetectTypeAudio        = 0,        /**< 默认值，音频探测 */
    NIMSDKAVChatNetDetectTypeVideo        = 1,        /**< 视频探测 */
};

/** @enum NIMSDKAVChatNetDetectVideoQuality 视频探测类型  */
typedef NS_ENUM(NSInteger, NIMSDKAVChatNetDetectVideoQuality)
{
    NIMSDKAVChatNDVideoQualityDefault    = 0,         /**< 480P */
    NIMSDKAVChatNDVideoQualityLow        = 1,        /**< 176*144 */
    NIMSDKAVChatNDVideoQualityMedium    = 2,         /**< 352*288 */
    NIMSDKAVChatNDVideoQualityHigh        = 3,         /**< 480*320 */
    NIMSDKAVChatNDVideoQuality480p        = 4,        /**< 640*480 */
    NIMSDKAVChatNDVideoQuality540p        = 5,        /**< 960*540 */
    NIMSDKAVChatNDVideoQuality720p        = 6,        /**< 1280*720 */
};

/** @enum NIMMainPictureOptCode 房间主画面设置返回码 */
typedef NS_ENUM(NSInteger, NIMMainPictureOptCode)
{
    NIMSDKAVChatMainPictureOptSucess        = 200,        /**< 操作成功 */
    NIMSDKAVChatMainPictureOptAuthError        = 401,        /**< 认证错误*/
    NIMSDKAVChatMainPictureOptRoomNotExist    = 404,        /**< 房间不存在 */
    NIMSDKAVChatMainPictureOptUidNotExist    = 405,        /**< 房间下的uid不存在 */
    NIMSDKAVChatMainPictureOptDataError        = 417,        /**< 请求数据不对 */
    NIMSDKAVChatMainPictureOptError            = 500,        /**< 内部错误*/
    NIMSDKAVChatMainPictureOptServerError    = 600,        /**< 服务器内部错误 */
    NIMSDKAVChatMainPictureOptInvalid        = 11403,    /**< 无效的操作 */
};

/** @enum NIMSDKAVChatServRecordType 服务器录制模式，用于指定本人数据录制选择 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatServRecordType)
{
    NIMSDKAVChatServRecordMixedSingle    = 0,    /**< 服务器录制混录并带单人文件 */
    NIMSDKAVChatServRecordMixed        = 1,    /**< 服务器录制只混录 */
    NIMSDKAVChatServRecordSingle        = 2,    /**< 服务器录制只录本人单人文件 */
};

/** @enum NIMSDKAVChatPubSubNotifyType 订阅及发布相关通知类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatPubSubNotifyType)
{
    NIMSDKAVChatNotifyPublishVideoRet            = 0,    /**< 本地视频发布操作的结果返回通知 */
    NIMSDKAVChatNotifyUnpublishVideoRet        = 1,    /**< 本地取消视频发布操作的结果返回通知 */
    NIMSDKAVChatNotifyRemotePublishVideo        = 2,    /**< 远端视频发布通知 */
    NIMSDKAVChatNotifyRemoteUnpublishVideo        = 3,    /**< 远端视频停止发布通知 */
    NIMSDKAVChatNotifySubscribeVideoRet        = 4,    /**< 本地订阅远端视频操作的结果返回通知 */
    NIMSDKAVChatNotifyUnsubscribeVideoRet        = 5,    /**< 本地取消订阅远端视频操作的结果返回通知 */
    NIMSDKAVChatNotifySubscribeAudioRet        = 6,    /**< 本地订阅远端音频操作的结果返回通知 */
    NIMSDKAVChatNotifyUnsubscribeAudioRet        = 7,    /**< 本地取消订阅远端音频操作的结果返回通知 */
};

/** @enum NIMSDKAVChatPublishVideoStreamMode 发布视频流模式 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatPublishVideoStreamMode)
{
    NIMSDKAVChatPublishVideoSingleStream       = 0,    /**< 发布单流模式（默认） */
    NIMSDKAVChatPublishVideoDualStream         = 1,    /**< 发布双流模式 */
};
/** @enum NIMSDKAVChatPublishVideoSimulcastRes 视频流类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatPublishVideoSimulcastRes)
{
    NIMSDKAVChatPublishVideoSimulcastResHigh   = 0,  /**< 高分辨率视频流 */
    NIMSDKAVChatPublishVideoSimulcastResLow    = 2,  /**< 低分辨率视频流 */
};

/** @enum NIMSDKAVChatPubSubErrorCode 订阅及发布相关通知类型 */
typedef NS_ENUM(NSInteger, NIMSDKAVChatPubSubErrorCode)
{
    NIMSDKAVChatPSErrCodeSuccess        = 0,    /**< 成功 */
    NIMSDKAVChatPSErrCodeFail            = -1,    /**< 失败 */
    NIMSDKAVChatPSErrCodeViewerMode    = -200,    /**< 发布操作失败，当前为观众模式 */
    NIMSDKAVChatPSErrCodeAudioMode        = -300,    /**< 视频发布操作失败，当前为音频模式 */
    NIMSDKAVChatPSErrCodeOptBusy        = -400,    /**< 操作繁忙 */
    NIMSDKAVChatPSErrCodeAutoMode        = -500,    /**< 模式互斥 （当前是自动发布） */
    NIMSDKAVChatPSErrCodeForbid        = -600,    /**< 操作无效，对点对模式不支持订阅相关功能 */
    NIMSDKAVChatPSErrCodeSubscribed    = -700, /**< 操作无效，视频类型冲突，需要取消之前订阅的流 */
};

#endif /* NIMSDKAVChatDefine_h */
