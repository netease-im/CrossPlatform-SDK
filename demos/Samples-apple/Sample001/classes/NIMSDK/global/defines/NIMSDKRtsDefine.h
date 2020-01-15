//
//  NIMSDKRtsDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKRtsDefine_h
#define NIMSDKRtsDefine_h

/** @enum NIMSDKRtsChannelType rts通道类型 */
typedef NS_ENUM(NSInteger, NIMSDKRtsChannelType)
{
    NIMSDKRtsChannelTypeNone    = 0,    /**< 无通道 */
    NIMSDKRtsChannelTypeTcp    = 1,    /**< tcp通道 */
    NIMSDKRtsChannelTypeUdp    = 2,    /**< udp通道 暂不支持 */
    NIMSDKRtsChannelTypeVchat    = 4,    /**< 音视频通道*/
};

/** @enum NIMSDKRtsMemberStatus 成员变化类型 */
typedef NS_ENUM(NSInteger, NIMSDKRtsMemberStatus)
{
    NIMSDKRtsMemberStatusJoined           = 0,    /**< 成员进入 */
    NIMSDKRtsMemberStatusLeaved           = 1,    /**< 成员退出 */
};
/** @enum NIMSDKRtsMemberLeftType 成员退出类型 */
typedef NS_ENUM(NSInteger, NIMSDKRtsMemberLeftType)
{
    NIMSDKRtsMemberLeftTimeout    = -1,        /**< 成员超时掉线 */
    NIMSDKRtsMemberLeftNormal        = 0,        /**< 成员离开 */
};

/** @enum NIMSDKRtsVideoChatMode 音视频通话类型 */
typedef NS_ENUM(NSInteger, NIMSDKRtsVideoChatMode)
{
    NIMSDKRtsVideoChatModeAudio    =    1,    /**< 语音通话模式 */
    NIMSDKRtsVideoChatModeVideo    =    2    /**< 视频通话模式 */
};

/** @enum NIMSDKRtsConnectStatus 音视频服务器连接状态类型 */
typedef NS_ENUM(NSInteger, NIMSDKRtsConnectStatus)
{
    NIMSDKRtsConnectStatusDisconn            = 0,    /**< 断开连接 */
    NIMSDKRtsConnectStatusStartFail        = 1,    /**< 启动失败 */
    NIMSDKRtsConnectStatusTimeout            = 101,    /**< 超时 */
    NIMSDKRtsConnectStatusSuccess            = 200,    /**< 成功 */
    NIMSDKRtsConnectStatusInvalidParam    = 400,    /**< 错误参数 */
    NIMSDKRtsConnectStatusDesKey            = 401,    /**< 密码加密错误 */
    NIMSDKRtsConnectStatusInvalidRequst    = 417,    /**< 错误请求 */
    NIMSDKRtsConnectStatusServerUnknown    = 500,    /**< 服务器内部错误 */
    NIMSDKRtsConnectStatusLogout            = 1001,    /**< 退出 */
};


#endif /* NIMSDKRtsDefine_h */
