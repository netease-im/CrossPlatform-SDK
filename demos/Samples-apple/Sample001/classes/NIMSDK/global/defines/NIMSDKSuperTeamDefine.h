//
//  NIMSDKSuperTeamDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKSuperTeamDefine_h
#define NIMSDKSuperTeamDefine_h

/** @enum NIMSDKSuperTeamBitsConfigMask 群组成员信息Bits属性NIMSDKSuperTeamUserKeyBits的配置定义 */
typedef NS_ENUM(NSInteger, NIMSDKSuperTeamBitsConfigMask)
{
    NIMSDKSuperTeamBitsConfigMaskMuteNotify    = 1,    /**< 关闭消息提醒0：开启提醒, 1：关闭提醒, */
    NIMSDKSuperTeamBitsConfigMaskOnlyAdmin        = 2,    /**< 只接收管理员消息0：开启提醒, 1：关闭提醒 */
};


/** @enum NIMSDKSuperTeamUserType 群成员类型 */
typedef NS_ENUM(NSInteger, NIMSDKSuperTeamUserType)
{
    NIMSDKSuperTeamUserTypeNomal        = 0,        /**< 普通成员 */
    NIMSDKSuperTeamUserTypeCreator        = 1,        /**< 创建者 */
    NIMSDKSuperTeamUserTypeManager        = 2,        /**< 管理员 */
    NIMSDKSuperTeamUserTypeApply        = 3,        /**< 申请加入用户 */
    NIMSDKSuperTeamUserTypeLocalWaitAccept = 100,    /**< 本地记录等待正在入群的用户 */
};

/** @enum NIMSDKSuperTeamJoinMode 群允许加入类型 */
typedef NS_ENUM(NSInteger, NIMSDKSuperTeamJoinMode)
{
    NIMSDKSuperTeamJoinModeNoAuth        = 0,        /**< 不用验证 */
    NIMSDKSuperTeamJoinModeNeedAuth    = 1,        /**< 需要验证 */
    NIMSDKSuperTeamJoinModeRejectAll    = 2,        /**< 拒绝所有人入群 */
};

#endif /* NIMSDKSuperTeamDefine_h */
