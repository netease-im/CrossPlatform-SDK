//
//  NIMSDKToolDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKToolDefine_h
#define NIMSDKToolDefine_h

/** @enum NIMSDKAppDataType AppData类型 */
typedef NS_ENUM(NSInteger, NIMSDKAppDataType)
{
    NIMSDKAppDataTypeUnknownOtherRes    = 0,    /**< 其他资源文件（除了消息历史文件和已知类型之外的消息数据缓存文件） */
    NIMSDKAppDataTypeImage            = 1,    /**< 图片消息文件 */
    NIMSDKAppDataTypeAudio            = 2,    /**< 语音消息文件 */
    NIMSDKAppDataTypeVideo            = 3,    /**< 视频消息文件 */
};

#endif /* NIMSDKToolDefine_h */
