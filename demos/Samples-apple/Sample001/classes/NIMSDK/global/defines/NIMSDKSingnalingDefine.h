//
//  NIMSDKSingnalingDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKSingnalingDefine_h
#define NIMSDKSingnalingDefine_h



/** @enum NIMSDKSignalingType
*    @brief 频道类型
*/
typedef NS_ENUM(NSInteger, NIMSDKSignalingType)
{
    NIMSDKSignalingTypeAudio         = 1,        /**< 音频类型 */
    NIMSDKSignalingTypeVideo         = 2,        /**< 视频类型 */
    NIMSDKSignalingTypeCustom        = 3,        /**< 自定义 */
};

/** @enum NIMSDKSignalingEventType
*    @brief 频道事件，包含在线，同步，离线等
*/
typedef NS_ENUM(NSInteger, NIMSDKSignalingEventType) 
{
    NIMSDKSignalingEventTypeClose            = 1, /**< 返回NIMSDKSignalingNotifyInfoClose，支持在线、离线通知 */
    NIMSDKSignalingEventTypeJoin             = 2, /**< 返回NIMSDKSignalingNotifyInfoJoin，支持在线、离线通知 */
    NIMSDKSignalingEventTypeInvite           = 3, /**< 返回NIMSDKSignalingNotifyInfoInvite，支持在线、离线通知 */
    NIMSDKSignalingEventTypeCancelInvite     = 4, /**< 返回NIMSDKSignalingNotifyInfoCancelInvite，支持在线、离线通知 */
    NIMSDKSignalingEventTypeReject           = 5, /**< 返回NIMSDKSignalingNotifyInfoReject，支持在线、多端同步、离线通知 */
    NIMSDKSignalingEventTypeAccept           = 6, /**< 返回NIMSDKSignalingNotifyInfoAccept，支持在线、多端同步、离线通知 */
    NIMSDKSignalingEventTypeLeave            = 7, /**< 返回NIMSDKSignalingNotifyInfoLeave，支持在线、离线通知 */
    NIMSDKSignalingEventTypeCtrl             = 8, /**< 返回NIMSDKSignalingNotifyInfoControl，支持在线通知 */
};

#endif /* NIMSDKSingnalingDefine_h */
