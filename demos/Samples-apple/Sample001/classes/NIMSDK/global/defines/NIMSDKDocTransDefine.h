//
//  NIMSDKDocTransDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKDocTransDefine_h
#define NIMSDKDocTransDefine_h

/** @enum NIMSDKDocTranscodingFileType 转码源文件格式 */
typedef NS_ENUM(NSInteger, NIMSDKDocTranscodingFileType)
{
    NIMSDKDocTranscodingFileTypePPT    = 1,    /**< ppt */
    NIMSDKDocTranscodingFileTypePPTX    = 2,    /**< pptx */
    NIMSDKDocTranscodingFileTypePDF    = 3,    /**< pdf */
};


/** @enum NIMSDKDocTranscodingImageType 转码目标图像文件类型 */
typedef NS_ENUM(NSInteger, NIMSDKDocTranscodingImageType)
{
    NIMSDKDocTranscodingImageTypeJPG    = 10,    /**< 转码为 jpg 图片 */
    NIMSDKDocTranscodingImageTypePNG    = 11,    /**< 转码为 png 图片 */
};


/** @enum NIMSDKDocTranscodingQuality 转码图像清晰度 */
typedef NS_ENUM(NSInteger, NIMSDKDocTranscodingQuality)
{
    NIMSDKDocTranscodingQualityHigh        = 1,    /**< 高清转码质量 */
    NIMSDKDocTranscodingQualityMedium        = 2,    /**< 中等转码质量 */
    NIMSDKDocTranscodingQualityLow        = 3,    /**< 低清转码质量 */
};

/** @enum NIMSDKDocContinueUploadState 续传过程状态 */
typedef NS_ENUM(NSInteger, NIMSDKDocContinueUploadState)
{
    NIMSDKDocContinueUploadNone        = 0,    /**< 没有进行过上传 */
    NIMSDKDocContinueUploading        = 1,    /**< 文件续传中 */
    NIMSDKDocContinueUploadFailed        = 2,    /**< 文件续传失败 */
    NIMSDKDocContinueUploadCompleted    = 3,    /**< 文件续传完成 */
};

/** @enum NIMSDKDocTranscodingState 转码过程状态 */
typedef NS_ENUM(NSInteger, NIMSDKDocTranscodingState)
{
    NIMSDKDocTranscodingStatePreparing    = 1,    /**< 转码准备中 */
    NIMSDKDocTranscodingStateOngoing        = 2,    /**< 转码进行中 */
    NIMSDKDocTranscodingStateTimeout        = 3,    /**< 转码超时 */
    NIMSDKDocTranscodingStateCompleted    = 4,    /**< 转码完成 */
    NIMSDKDocTranscodingStateFailed        = 5,    /**< 转码失败 */
};

/** @enum NIMSDKDocTranscodingFailFlag 转码失败原因 */
typedef NS_ENUM(NSInteger, NIMSDKDocTranscodingFailFlag)
{
    NIMSDKDocTransFailFlagSuccess            = 0,    /**< 正常 */
    NIMSDKDocTransFailFlagNotExist        = 2,    /**< 找不到文件 */
    NIMSDKDocTransFailFlagFileTypeErr        = 3,    /**< 文件类型错误 */
    NIMSDKDocTransFailFlagRequstErr        = 4,    /**< 转码请求出现异常 */
    NIMSDKDocTransFailFlagLinkErr            = 5,    /**< 转码服务器连接错误 */
    NIMSDKDocTransFailFlagServerErr        = 6,    /**< 转码服务器内部错误 */
    NIMSDKDocTransFailFlagPicErr            = 7,    /**< 文档转码图片出错 */
    NIMSDKDocTransFailFlagQualityErr        = 8,    /**< 图片质量处理错误 */
    NIMSDKDocTransFailFlagPageLimit        = 9,    /**< 页数超限 */
    NIMSDKDocTransFailFlagNosErr            = 10,    /**< nos回调错误 */
    NIMSDKDocTransFailFlagDocParseErr        = 11,    /**< 文档解析出错 */
    NIMSDKDocTransFailFlagUnknown            = 100,    /**< 表示未知错误 */
};

#endif /* NIMSDKDocTransDefine_h */
