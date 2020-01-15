//
//  NIMSDKNosDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKNosDefine_h
#define NIMSDKNosDefine_h

/** @enum NIMSDKNosInitConfigResultType NOS初始化错误码  */
typedef NS_ENUM(NSInteger, NIMSDKNosInitConfigResultType)
{
    NIMSDKNosInitConfResTypeTagCountOF      = 0,    /**< 自定义tag数量超过最大数量 */
    NIMSDKNosInitConfResTypeSuccess,            /**< 所有tag初始成功 */
    NIMSDKNosInitConfResTypePartSuccessful,    /**< 部分tag初始化成功，失败的tag及错误码可以解析json_result来取得 */
    NIMSDKNosInitConfResTypeFailure,                    /**< 所有tag初始化失败 */
};

/** @enum NIMNosUploadType NOS扩展类型  */
typedef NS_ENUM(NSInteger, NIMSDKNosUploadType)
{
    NIMSDKNosUploadTypeNormal               = 0,            /**< 普通文件上传 */
    NIMSDKNosUploadTypeDocTrans             = 1,            /**< 文档转换上传 */
};

#endif /* NIMSDKNosDefine_h */
