//
//  NIMSDKSubscribeEventDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKSubscribeEventDefine_h
#define NIMSDKSubscribeEventDefine_h

/** @enum NIMSDKEventBroadcastType 事件广播类型 */
typedef NS_ENUM(NSInteger, NIMSDKEventBroadcastType)
{
    NIMSDKEventBroadcastTypeOnline    = 1, /**< 仅在线 */
    NIMSDKEventBroadcastTypeAll        = 2, /**< 在线和离线 */
};

/** @enum NIMSDKEventSyncType 事件同步类型 */
typedef NS_ENUM(NSInteger, NIMSDKEventSyncType)
{
    NIMSDKEventSyncTypeNoSelf            = 0, /**< 事件不同步给自己其他端 */
    NIMSDKEventSyncTypeSelf            = 1, /**< 事件同步给自己其他端 */
};

/** @enum NIMSDKEventSubscribeSyncEventType 订阅的事件的同步类型 */
typedef NS_ENUM(NSInteger, NIMSDKEventSubscribeSyncEventType)
{
    NIMSDKEventSubscribeSyncTypeUnSync = 0, /**< 订阅后不同步最新事件 */
    NIMSDKEventSubscribeSyncTypeSync     = 1, /**< 订阅后立即同步最新事件 */
};

/** @enum NIMSDKEventType 服务器预定义的事件类型 */
typedef NS_ENUM(NSInteger, NIMSDKEventType)
{
    NIMSDKEventTypeOnlineState        = 1, /**< 在线状态事件(客户端可发送) */
    NIMSDKEventTypeSyncEvent            = 2, /**< 同步“订阅事件”事件(客户端不可发送) */
    NIMSDKEventTypeCustom                = 100000, /**< 服务器保留1～99999的事件类型，客户端自定义事件类型需大于99999 */
};

/** @enum NIMSDKEventOnlineStateValue 在线状态事件值 */
typedef NS_ENUM(NSInteger, NIMSDKEventOnlineStateValue)
{
    NIMSDKEventOnlineStateValueLogin            = 1, /**< 登录 */
    NIMSDKEventOnlineStateValueLogout            = 2, /**< 登出 */
    NIMSDKEventOnlineStateValueDisconnect        = 3, /**< 断开连接 */
    NIMSDKEventOnlineStateValueCustom            = 10000, /**< 在线状态事件服务器保留1～9999的事件值，客户端自定义事件值需大于9999 */
    NIMSDKEventOnlineStateValueUpdateConfig    = NIMSDKEventOnlineStateValueCustom + 1    /**< 自己的其他端更新了自己端的multi_config信息 */
};


#endif /* NIMSDKSubscribeEventDefine_h */
