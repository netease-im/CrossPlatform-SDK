//
//  NIMSDKSysMsgDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKSysMsgDefine_h
#define NIMSDKSysMsgDefine_h

/** @enum NIMSDKSysMsgStatus 系统消息状态 */
typedef NS_ENUM(NSInteger, NIMSDKSysMsgStatus)
{
    NIMSDKSysMsgStatusNone              = 0,        /**< 默认,未读 */
    NIMSDKSysMsgStatusPass              = 1,        /**< 收到消息,通过 */
    NIMSDKSysMsgStatusDecline           = 2,        /**< 收到消息,拒绝 */
    NIMSDKSysMsgStatusRead              = 3,        /**< 收到消息,已读 */
    NIMSDKSysMsgStatusDeleted           = 4,        /**< 已删 */
    NIMSDKSysMsgStatusInvalid           = 5,        /**< 已失效 */
};

/** @enum NIMSDKSysMsgType 系统消息内容类型 */
typedef NS_ENUM(NSInteger, NIMSDKSysMsgType)
{
    NIMSDKSysMsgTypeTeamApply                   = 0,        /**< 申请入群  */
    NIMSDKSysMsgTypeTeamReject                  = 1,        /**< 拒绝入群申请 */
    NIMSDKSysMsgTypeTeamInvite                  = 2,        /**< 邀请进群 NIMSDKSysMsgKeyAttach : {"team_info":team_info, "attach" : ""} attach为可选字段，作为应用自定义扩展字段,解析前需要判断有没有这个字段, 群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』) */
    NIMSDKSysMsgTypeTeamInviteReject            = 3,        /**< 拒绝邀请 */
    NIMSDKSysMsgTypeFriendAdd                   = 5,        /**< 加好友, NIMSDKSysMsgKeyAttach: {"vt":verifyType} */
    NIMSDKSysMsgTypeFriendDel                   = 6,        /**< 删除好友 */
    NIMSDKSysMsgTypeCustomP2PMsg                = 100,        /**< 点对点透传消息（透传消息的内容放到NIMSDKSysMsgKeyAttach）,SDK对该类消息不计入未读数, 即使NIMSDKSysMsgKeyPushNeedBadge为1 */
    NIMSDKSysMsgTypeCustomTeamMsg               = 101,        /**< 群透传消息（透传消息的内容放到NIMSDKSysMsgKeyAttach）,SDK对该类消息不计入未读数, 即使NIMSDKSysMsgKeyPushNeedBadge为1 */
    NIMSDKSysMsgTypeCustomSuperTeamMsg          = 103,        /**< 超大群透传消息（透传消息的内容放到NIMSDKSysMsgKeyAttach）,SDK对该类消息不计入未读数, 即使NIMSDKSysMsgKeyPushNeedBadge为1 */
    NIMSDKSysMsgTypeUnknown                     = 1000,        /**< 未知类型，本地使用，发送时勿使用，作为默认 */
};

#endif /* NIMSDKSysMsgDefine_h */
