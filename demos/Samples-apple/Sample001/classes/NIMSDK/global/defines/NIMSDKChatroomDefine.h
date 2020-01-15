//
//  NIMSDKChatroomDefine.h
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#ifndef NIMSDKChatroomDefine_h
#define NIMSDKChatroomDefine_h


/** @enum NIMSDKChatRoomMsgType 聊天室消息类型*/
typedef NS_ENUM(NSInteger,NIMSDKChatRoomMsgType)
{
    NIMSDKChatRoomMsgTypeText = 0,        /**< 文本类型消息*/
    NIMSDKChatRoomMsgTypeImage = 1,        /**< 图片类型消息*/
    NIMSDKChatRoomMsgTypeAudio = 2,        /**< 声音类型消息*/
    NIMSDKChatRoomMsgTypeVideo = 3,        /**< 视频类型消息*/
    NIMSDKChatRoomMsgTypeLocation = 4,    /**< 位置类型消息*/
    NIMSDKChatRoomMsgTypeNotification = 5,/**< 活动室通知*/
    NIMSDKChatRoomMsgTypeFile = 6,        /**< 文件类型消息*/
    NIMSDKChatRoomMsgTypeRobot = 11,        /**< 波特机器人消息*/

    NIMSDKChatRoomMsgTypeTips = 10,        /**< 提醒类型消息*/
    NIMSDKChatRoomMsgTypeCustom = 100,    /**< 自定义消息*/

    NIMSDKChatRoomMsgTypeUnknown = 1000,    /**< 未知类型消息，作为默认值*/
};

/** @enum NIMSDKChatRoomClientType 聊天室消息来源端 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomClientType)
{
    NIMSDKChatRoomClientTypeDefault = 0,        /**< default,unset*/
    NIMSDKChatRoomClientTypeAndroid = 1,        /**< android*/
    NIMSDKChatRoomClientTypeiOS = 2,        /**< iOS*/
    NIMSDKChatRoomClientTypePCWindows = 4,        /**< PC*/
    NIMSDKChatRoomClientTypeWindowsPhone = 8,        /**< WindowsPhone*/
    NIMSDKChatRoomClientTypeWeb = 16,    /**< Web*/
    NIMSDKChatRoomClientTypeRestAPI = 32,    /**< RestAPI*/
    NIMSDKChatRoomClientTypeMacOS = 64,    /**< Mac*/
};

/** @enum NIMSDKChatRoomExitReason 聊天室离开原因 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomExitReason)
{
    NIMSDKChatRoomExitReasonExit = 0,    /**< 自行退出,重登前需要重新请求进入 */
    NIMSDKChatRoomExitReasonRoomInvalid = 1,    /**< 聊天室已经被解散,重登前需要重新请求进入 */
    NIMSDKChatRoomExitReasonKickByManager = 2,    /**< 被管理员踢出,重登前需要重新请求进入 */
    NIMSDKChatRoomExitReasonKickByMultiSpot = 3,    /**< 多端被踢 */
    NIMSDKChatRoomExitReasonIllegalState = 4,    /**< 当前链接状态异常 */
    NIMSDKChatRoomExitReasonBeBlacklisted = 5,    /**< 被加黑了 */
};

/** @enum NIMSDKChatRoomLoginState 登录状态 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomLoginState)
{
    NIMSDKChatRoomLoginStateLogin = 1,        /**< 登录状态*/
    NIMSDKChatRoomLoginStateUnLogin = 2,        /**< 未登录状态*/
};

/** @enum NIMSDKChatRoomOnlineState 在线状态 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomOnlineState)
{
    NIMSDKChatRoomOnlineStateOffline = 0, /**<不在线 */
    NIMSDKChatRoomOnlineStateOnline = 1, /**<在线 */
};

/** @enum NIMSDKChatRoomGuestFlag 成员类型 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomGuestFlag)
{
    NIMSDKChatRoomGuestFlagNoGuest = 0, /**< 非游客 */
    NIMSDKChatRoomGuestFlagGuest = 1, /**< 游客 */
};

/** @enum NIMSDKChatRoomGetMemberType 查询成员的成员类型 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomGetMemberType)
{
    NIMSDKChatRoomGetMemberTypeSolid = 0, /**< 固定成员,固定成员,包括创建者,管理员,普通等级用户,受限用户(禁言+黑名单),即使非在线也可以在列表中看到,有数量限制*/
    NIMSDKChatRoomGetMemberTypeTemp = 1, /**< 非固定成员,非固定成员,又称临时成员,只有在线时才能在列表中看到,数量无上限*/
};

/** @enum NIMSDKChatRoomMemberAttribute 设置成员的成员身份 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomMemberAttribute)
{
    NIMSDKChatRoomMemberAttributeAdminister = 1, /**< 管理员,operator必须是创建者 */
    NIMSDKChatRoomMemberAttributeNomalMember = 2, /**< 普通成员,operator必须是创建者或管理员 */
    NIMSDKChatRoomMemberAttributeBlackList = -1, /**< 黑名单,operator必须是创建者或管理员 */
    NIMSDKChatRoomMemberAttributeMuteList = -2, /**< 禁言,operator必须是创建者或管理员 */
};

typedef NS_ENUM(NSInteger, NIMSDKChatRoomNotificationId)
{
    NIMSDKChatRoomNotificationIdMemberIn = 301, /**< 成员进入聊天室*/
    NIMSDKChatRoomNotificationIdMemberExit = 302, /**< 成员离开聊天室*/
    NIMSDKChatRoomNotificationIdAddBlack = 303, /**< 成员被加黑*/
    NIMSDKChatRoomNotificationIdRemoveBlack = 304, /**< 成员被取消黑名单*/
    NIMSDKChatRoomNotificationIdAddMute = 305, /**< 成员被设置禁言*/
    NIMSDKChatRoomNotificationIdRemoveMute = 306, /**< 成员被取消禁言*/
    NIMSDKChatRoomNotificationIdAddManager = 307, /**< 设置为管理员*/
    NIMSDKChatRoomNotificationIdRemoveManager = 308, /**< 取消管理员*/
    NIMSDKChatRoomNotificationIdAddFixed = 309, /**< 成员设定为固定成员*/
    NIMSDKChatRoomNotificationIdRemoveFixed = 310, /**< 成员取消固定成员*/
    NIMSDKChatRoomNotificationIdClosed = 311, /**< 聊天室被关闭了*/
    NIMSDKChatRoomNotificationIdInfoUpdated = 312, /**< 聊天室信息被更新了*/
    NIMSDKChatRoomNotificationIdMemberKicked = 313, /**< 成员被踢了*/
    NIMSDKChatRoomNotificationIdMemberTempMute = 314, /**< 临时禁言*/
    NIMSDKChatRoomNotificationIdMemberTempUnMute = 315, /**< 主动解除临时禁言*/
    NIMSDKChatRoomNotificationIdMyRoleUpdated = 316, /**< 成员主动更新了聊天室内的角色信息(仅指nick/avator/ext)*/
    NIMSDKChatRoomNotificationIdQueueChanged = 317, /**< 麦序队列中有变更 "ext" : {"_e":"OFFER", "key":"element_key", "content":"element_value"}*/
    NIMSDKChatRoomNotificationIdRoomMuted = 318, /**< 聊天室被禁言了,只有管理员可以发言,其他人都处于禁言状态*/
    NIMSDKChatRoomNotificationIdRoomDeMuted = 319, /**< 聊天室解除全体禁言状态*/
    NIMSDKChatRoomNotificationIdQueueBatchChanged = 320, /**< 麦序队列中有批量变更，发生在元素提交者离开聊天室或者从聊天室异常掉线时*/
};

/** @enum NIMSDKChatRoomLinkCondition 聊天室链接情况，一般都是有本地网路情况引起 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomLinkCondition)
{
    NIMSDKChatRoomLinkConditionAlive = 0,    /**< 链接正常*/
    NIMSDKChatRoomLinkConditionDeadAndRetry = 1,    /**< 链接失败,sdk尝试重链*/
    NIMSDKChatRoomLinkConditionDead = 2,    /**< 链接失败,开发者需要重新申请聊天室进入信息*/
};

/** @enum NIMSDKChatRoomEnterStep 聊天室进入状态 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomEnterStep)
{
    NIMSDKChatRoomEnterStepInit = 1,    /**< 本地服务初始化*/
    NIMSDKChatRoomEnterStepServerConnecting = 2,    /**< 服务器连接中*/
    NIMSDKChatRoomEnterStepServerConnectOver = 3,    /**< 服务器连接结束,连接结果见error_code*/
    NIMSDKChatRoomEnterStepRoomAuthing = 4,    /**< 聊天室鉴权中*/
    NIMSDKChatRoomEnterStepRoomAuthOver = 5,    /**< 聊天室鉴权结束,鉴权结果见error_code, error_code非408则需要开发者重新请求聊天室进入信息*/
};

/** @enum NIMSDKChatRoomProxyType 代理类型 */
typedef NS_ENUM(NSInteger, NIMSDKChatRoomProxyType)
{
    NIMSDKChatRoomProxyNone = 0,    /**< 不使用代理*/
    NIMSDKChatRoomProxyHttp11 = 1,    /**< HTTP 1.1 Proxy（暂不支持）*/
    NIMSDKChatRoomProxySocks4 = 4,    /**< Socks4 Proxy*/
    NIMSDKChatRoomProxySocks4a = 5,    /**< Socks4a Proxy*/
    NIMSDKChatRoomProxySocks5 = 6,    /**< Socks5 Proxy*/
};

#endif /* NIMSDKChatroomDefine_h */
