//
//  NIMSDKTeamDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKTeamDefine_h
#define NIMSDKTeamDefine_h

/** @enum NIMSDKTeamBeInviteMode 被邀请人同意方式 */
typedef NS_ENUM(NSInteger, NIMSDKTeamBeInviteMode)
{
    NIMSDKTeamBeInviteModeNeedAgree    = 0,    /**< 需要同意 */
    NIMSDKTeamBeInviteModeNotNeedAgree= 1,    /**< 不需要同意 */
};

/** @enum NIMSDKTeamInviteMode 谁可以邀请他人入群 */
typedef NS_ENUM(NSInteger, NIMSDKTeamInviteMode)
{
    NIMSDKTeamInviteModeManager    = 0,    /**< 管理员 */
    NIMSDKTeamInviteModeEveryone  = 1,    /**< 所有人 */
};

/** @enum NIMSDKTeamUpdateInfoMode 谁可以修改群资料 */
typedef NS_ENUM(NSInteger, NIMSDKTeamUpdateInfoMode)
{
    NIMSDKTeamUpdateInfoModeManager    = 0,    /**< 管理员 */
    NIMSDKTeamUpdateInfoModeEveryone  = 1,    /**< 所有人 */
};

/** @enum NIMSDKTeamUpdateCustomMode 谁可以更新群自定义属性 */
typedef NS_ENUM(NSInteger, NIMSDKTeamUpdateCustomMode)
{
    NIMSDKTeamUpdateCustomModeManager    = 0,    /**< 管理员 */
    NIMSDKTeamUpdateCustomModeEveryone  = 1,    /**< 所有人 */
};

/** @enum NIMSDKTeamMuteType 群信息NIMSDKTeamInfoKeyMuteType的配置定义 */
typedef NS_ENUM(NSInteger, NIMSDKTeamMuteType)
{
    NIMSDKTeamMuteTypeNone            = 0,    /**< 不禁言 */
    NIMSDKTeamMuteTypeNomalMute        = 1,    /**< 普通成员禁言 */
    NIMSDKTeamMuteTypeAllMute            = 3,    /**< 全部禁言 */
};

/** @enum NIMSDKTeamBitsConfigMask 群组成员信息Bits属性NIMSDKTeamUserKeyBits的配置定义 */
typedef NS_ENUM(NSInteger, NIMSDKTeamBitsConfigMask)
{
    NIMSDKTeamBitsConfigMaskMuteNone        = 0,    /**< 开启提醒 bits 0000b*/
    NIMSDKTeamBitsConfigMaskMuteNotify    = 1,    /**< 关闭提醒 bits 0001b*/
    NIMSDKTeamBitsConfigMaskOnlyAdmin        = 2,    /**< 只接收管理员消息 bits 0010b 超大群当前不支持该选项*/
};

/** @enum NIMSDKTeamType 群组类型 */
typedef NS_ENUM(NSInteger, NIMSDKTeamType)
{
    NIMSDKTeamTypeNormal    = 0,    /**< 普通群 */
    NIMSDKTeamTypeAdvanced= 1,    /**< 高级群 */
};

/** @enum NIMSDKTeamUserType 群成员类型 */
typedef NS_ENUM(NSInteger, NIMSDKTeamUserType)
{
    NIMSDKTeamUserTypeNomal        = 0,        /**< 普通成员 */
    NIMSDKTeamUserTypeCreator        = 1,        /**< 创建者 */
    NIMSDKTeamUserTypeManager        = 2,        /**< 管理员 */
    NIMSDKTeamUserTypeApply        = 3,        /**< 申请加入用户 */
    NIMSDKTeamUserTypeLocalWaitAccept = 100,    /**< 本地记录等待正在入群的用户 */
};

/** @enum NIMSDKTeamJoinMode 群允许加入类型 */
typedef NS_ENUM(NSInteger, NIMSDKTeamJoinMode)
{
    NIMSDKTeamJoinModeNoAuth        = 0,        /**< 不用验证 */
    NIMSDKTeamJoinModeNeedAuth    = 1,        /**< 需要验证 */
    NIMSDKTeamJoinModeRejectAll    = 2,        /**< 拒绝所有人入群 */
};

#endif /* NIMSDKTeamDefine_h */
