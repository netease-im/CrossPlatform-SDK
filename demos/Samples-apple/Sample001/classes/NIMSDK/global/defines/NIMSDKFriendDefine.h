//
//  NIMSDKFriendDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKFriendDefine_h
#define NIMSDKFriendDefine_h

/** @enum NIMSDKFriendFlag 好友类型  */
typedef NS_ENUM(NSInteger, NIMSDKFriendFlag)
{
    NIMSDKFriendFlagNotFriend        = 0, /**< 陌生人 */
    NIMSDKFriendFlagNormal        = 1, /**< 普通好友 */
};

/** @enum NIMSDKFriendSource 好友来源 */
typedef NS_ENUM(NSInteger, NIMSDKFriendSource)
{
    NIMSDKFriendSourceDefault        = 0, /**< 默认 */
};

/** @enum NIMSDKFriendVerifyType 好友验证方式 */
typedef NS_ENUM(NSInteger, NIMSDKFriendVerifyType)
{
    kNIMVerifyTypeAdd        = 1, /**< 直接加好友 */
    kNIMVerifyTypeAsk        = 2, /**< 请求加好友 */
    kNIMVerifyTypeAgree        = 3, /**< 同意 */
    kNIMVerifyTypeReject    = 4, /**< 拒绝 */
};

/** @enum NIMSDKFriendChangeType 好友数据变化类型 */
typedef NS_ENUM(NSInteger, NIMSDKFriendChangeType)
{
    NIMSDKFriendChangeTypeRequest        = 1, /**< 加好友/处理好友请求 */
    NIMSDKFriendChangeTypeDel            = 2, /**< 删除好友 */
    NIMSDKFriendChangeTypeUpdate        = 3, /**< 更新好友 */
    NIMSDKFriendChangeTypeSyncList    = 5, /**< 好友列表同步与更新 */
};

#endif /* NIMSDKFriendDefine_h */
