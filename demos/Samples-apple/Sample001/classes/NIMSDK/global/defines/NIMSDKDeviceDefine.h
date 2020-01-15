//
//  NIMSDKDeviceDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKDeviceDefine_h
#define NIMSDKDeviceDefine_h

/** @enum NIMSDKDeviceType 设备类型 */
typedef NS_ENUM(NSInteger, NIMSDKDeviceType)
{
    NIMSDKDeviceTypeAudioIn                = 0,    /**< 麦克风设备 */
    NIMSDKDeviceTypeAudioOut                = 1,    /**< 听筒设备用于播放本地采集音频数据，麦克风试音 */
    NIMSDKDeviceTypeAudioOutChat            = 2,    /**< 听筒设备用于通话音频数据（nim_vchat_start_device和nim_vchat_end_device中使用） */
    NIMSDKDeviceTypeVideo                    = 3,    /**< 摄像头 */
    NIMSDKDeviceTypeSoundcardCapturer        = 4,    /**< 声卡声音采集，得到的数据混音到发送的通话声音中(此模式使用条件苛刻不建议使用) */
    NIMSDKDeviceTypeAudioHook                = 5,    /**< 伴音，启动第三方播放器并获取音频数据（只允许存在一个进程钩子）,只混音到发送的通话声音中 */
};

/** @enum NIMSDKDeviceVideoSubType 视频格式类型 */
typedef NS_ENUM(NSInteger, NIMSDKDeviceVideoSubType)
{
    NIMSDKDeviceVideoSubTypeARGB    = 0,    /**< 32位位图格式 存储 (B,G,R,A)... */
    NIMSDKDeviceVideoSubTypeRGB        = 1,    /**< 24位位图格式 存储 (B,G,R)... */
    NIMSDKDeviceVideoSubTypeI420    = 2,    /**< YUV格式，存储 yyyyyyyy...uu...vv... */
};

/** @enum NIMSDKDeviceStatus 设备状态类型 */
typedef NS_ENUM(NSInteger, NIMSDKDeviceStatus)
{
    NIMSDKDeviceStatusNoChange    = 0x0,    /**< 设备没有变化 */
    NIMSDKDeviceStatusChange        = 0x1,    /**< 设备有变化 */
    NIMSDKDeviceStatusWorkRemove    = 0x2,    /**< 工作设备被移除 */
    NIMSDKDeviceStatusReset        = 0x4,    /**< 设备重新启动 */
    NIMSDKDeviceStatusStart        = 0x8,    /**< 设备开始工作 */
    NIMSDKDeviceStatusEnd            = 0x10,    /**< 设备停止工作 */
};

/** @enum NIMSDKDeviceAudioDataCbType 音频数据监听类型 */
typedef NS_ENUM(NSInteger, NIMSDKDeviceAudioDataCbType)
{
    NIMSDKDeviceAudioDataCbTypeHook            = 1,    /**< 实时返回伴音数据，伴音数据保留原始的格式，伴音不再混音到通话数据中，如果还需要可以通过伴音数据通道再回传 */
    NIMSDKDeviceAudioDataCbTypeHookAndMic    = 2,    /**< 定时返回伴音和麦克风、声卡的混音数据，允许重采样（json中带NIMSDKDeviceSampleRate和NIMSDKDeviceVolumeWork），返回单声道数据 */
};

#endif /* NIMSDKDeviceDefine_h */
