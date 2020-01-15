//
//  NIMSDKGlobalDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKGlobalDefine_h
#define NIMSDKGlobalDefine_h

/** @enum NIMSDKLogLevels NIM SDK log级别，级别越高，log越详细 */
typedef NS_ENUM(NSInteger, NIMSDKLogLevels)
{
    NIMSDKLogLevelFatal = 1,    /**< SDK Fatal级别Log*/
    NIMSDKLogLevelError = 2,    /**< SDK Error级别Log*/
    NIMSDKLogLevelWarn = 3,    /**< SDK Warn级别Log*/
    NIMSDKLogLevelApp = 5,    /**< SDK应用级别Log，正式发布时为了精简sdk log，可采用此级别*/
    NIMSDKLogLevelPro = 6,    /**< SDK调试过程级别Log，更加详细，更有利于开发调试*/
};

/** @enum NIMSDKExceptions 异常 */
typedef NS_ENUM(NSInteger, NIMSDKExceptions)
{
    NIMSDKExceptionSpaceEmpty = 1,    /**< 当前数据目录所在盘符空间紧张或用完, log: {"free_space" : %lf, "message":""}, free_space单位M*/
};


/** @enum NIMSDKProxyDetectStep 代理测试步骤 */
typedef NS_ENUM(NSInteger, NIMSDKProxyDetectStep)
{
    NIMSDKProxyDetectStepAllComplete            = 5,    /**< 探测代理有效性结束*/
};
/** @enum NIMSDKProxyType 代理类型 */
typedef NS_ENUM(NSInteger, NIMSDKProxyType)
{
    NIMSDKProxyNone        = 0,    /**< 不使用代理*/
    NIMSDKProxyHttp11        = 1,    /**< HTTP 1.1 Proxy（暂不支持）*/
    NIMSDKProxySocks4        = 4,    /**< Socks4 Proxy*/
    NIMSDKProxySocks4a    = 5,    /**< Socks4a Proxy*/
    NIMSDKProxySocks5        = 6,    /**< Socks5 Proxy*/
    NIMSDKProxyNrtc        = 10,    /**< 云信音视频私有代理，只在nim_vchat_set_proxy中有效 */
};

#endif /* NIMSDKGlobalDefine_h */
