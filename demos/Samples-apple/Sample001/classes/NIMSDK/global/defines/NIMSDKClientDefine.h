//
//  NIMSDKClientDefine.h
//  Samples
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKClientDefine_h
#define NIMSDKClientDefine_h


/** @enum NIMSDKLoginState 登录状态 */
typedef NS_ENUM(NSInteger, NIMSDKLoginState)
{
    NIMSDKLoginStateLogin               = 1,        /**< 登录状态*/
    NIMSDKLoginStateUnLogin             = 2,        /**< 未登录状态*/
};

/** @enum NIMSDKLogoutType Logout类型 */

typedef NS_ENUM(NSInteger, NIMSDKLogoutType)
{
    
    NIMSDKLogoutChangeAccout            = 1,    /**< 注销/切换帐号（返回到登录界面）*/
    NIMSDKLogoutKickout                 = 2,    /**< 被踢（返回到登录界面）*/
    NIMSDKLogoutAppExit                 = 3,    /**< 程序退出*/
    NIMSDKLogoutRelogin                 = 4,    /**< 重连操作，包括保存密码时启动程序伪登录后的重连操作以及掉线后的重连操作（帐号未变化）*/
};

/** @enum NIMSDKKickReason 被踢原因 */
typedef NS_ENUM(NSInteger, NIMSDKKickReason)
{
    NIMSDKKickReasonSameGeneric             =   1,  /**< 互斥类型的客户端互踢*/
    NIMSDKKickReasonServerKick              =   2,  /**< 服务器端发起踢客户端指令*/
    NIMSDKKickReasonKickBySelfOtherClient   =   3,  /**< 被自己的其他端踢掉*/
};

/** @enum NIMSDKClientType 客户端类型 */
typedef NS_ENUM(NSInteger, NIMSDKClientType)
{
    NIMSDKClientTypeDefault                 = 0,  /**< Default, unset*/
    NIMSDKClientTypeAndroid                 = 1,  /**< Android*/
    NIMSDKClientTypeiOS                     = 2,  /**< iOS*/
    NIMSDKClientTypePCWindows               = 4,  /**< PC Windows*/
    NIMSDKClientTypeWeb                     = 16, /**< Web*/
    NIMSDKClientTypeRestAPI                 = 32, /**< RestAPI*/
    NIMSDKClientTypeMacOS                   = 64, /**< Mac*/
};

/** @enum NIMSDKLoginStep 登录步骤 */
typedef NS_ENUM(NSInteger, NIMSDKLoginStep)
{
    NIMSDKLoginStepLinking                  = 0,    /**< 正在连接*/
    NIMSDKLoginStepLink                     = 1,    /**< 连接服务器*/
    NIMSDKLoginStepLogining                 = 2,    /**< 正在登录*/
    NIMSDKLoginStepLogin                    = 3,    /**< 登录验证*/
};

/** @enum NIMSDKMultiSpotNotifyType 多点登录通知类型 */
typedef NS_ENUM(NSInteger, NIMSDKMultiSpotNotifyType)
{
    NIMSDKMultiSpotNotifyTypeImIn           = 2,        /**< 通知其他在线端自己登录了*/
    NIMSDKMultiSpotNotifyTypeImOut          = 3,        /**< 通知其他在线端自己退出*/
};


#endif /* NIMSDKClientDefine_h */
