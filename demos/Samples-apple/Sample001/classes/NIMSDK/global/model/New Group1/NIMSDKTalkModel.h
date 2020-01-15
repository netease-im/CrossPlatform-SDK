//
//  NIMSDKTalkModel.h
//  Samples iOS
//
//  Created by dudu on 2019/11/25.
//

#import <Foundation/Foundation.h>
#import "NIMSDKResCode.h"
#import "NIMSDKClientDefine.h"
#import "NIMSDKTalkDefine.h"
#import "NIMSDKMessageLogDefine.h"
#import "NIMSDKSessionDefine.h"


@class NIMSDKIMFile;
@class NIMSDKIMImage;
@class NIMSDKIMAudio;
@class NIMSDKIMVideo;
@class NIMSDKIMLocation;
@class NIMSDKIMBotRobot;

/** @brief 消息属性设置 */
@interface NIMSDKMessageSetting : NSObject<NSCopying>

@property (nonatomic,strong) NSNumber *resendFlag;            /**< 该消息是否为重发状态 */

@property (nonatomic,strong) NSNumber *serverHistorySaved;    /**< 该消息是否存储云端历史 */

@property (nonatomic,strong) NSNumber *roaming;                /**< 该消息是否支持漫游 */

@property (nonatomic,strong) NSNumber *selfSync;                /**< 该消息是否支持发送者多端同步 */

@property (nonatomic,strong) NSNumber *needPush;                 /**< 是否需要推送 */

@property (nonatomic,strong) NSNumber *pushNeedBadge;        /**< 是否要做消息计数 */

@property (nonatomic,strong) NSNumber *pushNeedPrefix;        /**< 需要推送昵称 */

@property (nonatomic,strong) NSNumber *routable;                /**< 是否要抄送 */

@property (nonatomic,strong) NSNumber *needOffline;            /**< 是否支持离线消息 */

@property (nonatomic,strong) NSDictionary *pushPayload;            /**< 第三方自定义的推送属性，长度2048 */

@property (nonatomic,strong) NSString *pushContent;            /**< 自定义推送文案，长度限制200字节 */

@property (nonatomic,strong) NSDictionary *serverExt;            /**< 第三方扩展字段, 长度限制1024 */

@property (nonatomic,strong) NSString *localExt;                /**< 本地扩展字段, 格式不限，长度限制1024 */

@property (nonatomic,strong) NSNumber *isForcePush;            /**< 群组消息强推开关，强推全员设置true并强推列表为空 */

@property (nonatomic,strong) NSArray *forcePushIDs;    /**< 群组消息强推列表 */

@property (nonatomic,strong) NSString *forcePushContent;    /**< 群组消息强推文本 */

@property (nonatomic,strong) NSNumber *antiSpamEnable;        /**< 是否需要过易盾反垃圾 */

@property (nonatomic,strong) NSString *antiSpamContent;        /**< (可选)开发者自定义的反垃圾字段,长度限制5000 */

@property (nonatomic,strong) NSString *antiApamBizID;        /**< (可选)用户配置的对某些单条消息另外的反垃圾的业务ID*/

@property (nonatomic,assign) NSInteger antiSpamUsingYidun;    /**< int,  (可选) 单条消息是否使用易盾反垃圾
                                                                   0:(在开通易盾的情况下)不过易盾反垃圾而是通用反垃圾 其他都是按照原来的规则*/
@property (nonatomic,strong) NSNumber *clientAntiSpamHitting;    /**< (可选) 是否命中客户端反垃圾*/

@property (nonatomic,strong) NSNumber *teamMsgNeedAck;        /** 群消息是否需要已读业务，0：不需要，1：需要*/

@property (nonatomic,strong) NSNumber *teamMsgAckSent;        /**< 是否已经发送群消息已读回执 */

@property (nonatomic,assign) NSInteger teamMsgUnreadCount;            /**< 群消息未读数 */

@end

/** @brief P2P和群组消息 */
@interface NIMSDKIMMessage : NSObject<NSCopying>

@property (nonatomic,assign) NIMSDKSessionType sessionType;         /**< 会话类型 */

@property (nonatomic,strong) NSString *receiverAccid;               /**< 接收者ID */

@property (nonatomic,strong) NSString *senderAccid;                 /**< 发送者ID */

@property (nonatomic,assign) NSInteger timetag;                     /**< 消息时间戳（毫秒） */

@property (nonatomic,strong) NSString *content;                     /**< 消息内容,长度限制5000 */

@property (nonatomic,assign) NIMSDKMessageType  type;               /**< 消息类型 */

@property (nonatomic,strong) NSObject *attach;                      /**< 消息附件 */

@property (nonatomic,strong) NSString *clientMsgId;                 /**< 消息ID（客户端） */

@property (nonatomic,strong) NIMSDKMessageSetting *msgSetting;      /**< 消息属性设置 */

@property (nonatomic,strong) NSString *localResPath;                /**< 媒体文件本地绝对路径（客户端） */

@property (nonatomic,strong) NSString *localTalkId;                 /**< 会话ID（客户端） */

@property (nonatomic,strong) NSString *localResId;                  /**< 媒体文件ID（客户端） */

@property (nonatomic,assign) NIMSDKMsglogStatus status;             /**< 消息状态（客户端） */

@property (nonatomic,assign) NIMSDKMsglogSubStatus subStatus;       /**< 消息子状态（客户端） */

/// 创建普通消息
/// @param receiver 接收者id
/// @param type 会话类型
/// @param msgID 消息id
/// @param content 消息内容
/// @param setting 消息设置
/// @param timetag 消息时间戳 默认填0
+(nullable instancetype)createIMMessage:(nonnull NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(nonnull NSString*)msgID
    content:(nonnull NSString*)content
    setting:(nonnull NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag;

+(nullable instancetype)createIMMessage:(nonnull NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(nonnull NSString*)msgID
    attach:(nonnull NIMSDKIMFile*)attach
    filePath:(nullable NSString*)path
    setting:(nonnull NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag;

+(nullable instancetype)createIMMessage:(nonnull NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(nonnull NSString*)msgID
    tipcontent:(nonnull NSString*)content
    setting:(nonnull NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag;

+(nullable instancetype)createIMMessage:(nonnull NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(nonnull NSString*)msgID
    content:(nullable NSString*)content
    robot:(nonnull NIMSDKIMBotRobot*)robot
    setting:(nonnull NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag;


@end

/** @brief P2P和群组消息 */
@interface NIMSDKIMReceivedMessage : NIMSDKIMMessage

@property (nonatomic,assign) NIMSDKResCode rescode;                        /**< 错误码 */

@property (nonatomic,assign) NIMSDKMessageFeature feature;                /**< 消息属性 */

@property (nonatomic,assign) NIMSDKClientType readonlySenderClientType;    /**< 发送者客户端类型（只读） */

@property (nonatomic,strong) NSString *readonlySenderDeviceId;        /**< 发送者客户端设备ID（只读） */

@property (nonatomic,strong) NSString *readonlySenderNickname;        /**< 发送者昵称（只读） */

@property (nonatomic,assign) NSInteger readonlyServerId;                /**< 消息ID（服务器，只读） */

@end

/** @brief 文件消息附件 */
@interface NIMSDKIMFile : NSObject

@property (nonatomic,strong) NSString *md5;                /**< 文件内容MD5 */

@property (nonatomic,assign) NSInteger size;                /**< 文件大小 */

@property (nonatomic,strong) NSString *url;                /**< 上传云端后得到的文件下载地址 */

@property (nonatomic,strong) NSString *displayName;        /**< 用于显示的文件名称 */

@property (nonatomic,strong) NSString *fileExtension;    /**< 文件扩展名 */

@property (nonatomic,strong) NSString *msgAttachmentTag;    /**< string, (可选)发送含有附件的消息时使用的场景标签(可参见nos删除策略) ,Audio Image Video File 或者可以被SDK解析到本地文件路径的自定义消息*/

@end

/** @brief 图片消息附件 */
@interface NIMSDKIMImage : NIMSDKIMFile

@property (nonatomic,assign) NSInteger width;            /**< 图片宽度 */

@property (nonatomic,assign) NSInteger height;        /**< 图片高度 */

@end

/** @brief 位置消息附件 */
@interface NIMSDKIMLocation : NSObject

@property (nonatomic,strong) NSString *desc;        /**< 位置描述内容 */

@property (nonatomic,assign) double latitude;            /**< 位置纬度 */

@property (nonatomic,assign) double longitude;            /**< 位置经度 */

@end

/** @brief 语音消息附件 */
@interface NIMSDKIMAudio : NIMSDKIMFile

@property (nonatomic,assign) NSInteger duration;            /**< 语音时长 */

@end

/** @brief 小视频消息附件 */
@interface NIMSDKIMVideo : NIMSDKIMFile

@property (nonatomic,assign) NSInteger duration;            /**< 视频时长 */

@property (nonatomic,assign) NSInteger width;                /**< 视频画面宽度 */

@property (nonatomic,assign) NSInteger height;            /**< 视频画面高度 */

@end

/** @brief 波特机器人消息附件 */
@interface NIMSDKIMBotRobot : NSObject

@property (nonatomic,assign) BOOL outMsg;                /**< 是否为机器人回复，是:true，不是:false，默认false */

@property (nonatomic,strong) NSString *robotAccid;        /**< 机器人云信ID */

@property (nonatomic,strong) NSDictionary *sentParam;        /**< 给机器人发送时需要填的字段，字段内容定义可见Demo源码或参考波特开发文档 */
    
@property (nonatomic,strong) NSString *relatedMsgId;    /**< 机器人回复时带的字段，表示该条回复相关联的消息ID */

@property (nonatomic,strong) NSString *robotMsgFlag;    /**< 机器人回复时带的字段，表示该条回复类型，类型定义可见Demo源码或参考波特开发文档*/

@property (nonatomic,strong) NSDictionary *robotMsgContent;    /**< 机器人回复时带的字段，表示该条回复内容，字段内容定义可见Demo源码或参考波特开发文档 */
    
@end

@interface NIMSDKBroadcastMessage : NSObject

@property (nonatomic,strong) NSString *body;

@property (nonatomic,assign) NSInteger time;

@property (nonatomic,assign) NSInteger msgId;

@property (nonatomic,strong) NSString *fromId;

@end


/** @brief 发送消息回执 */
@interface NIMSDKSendMessageResult : NSObject

@property (nonatomic,strong) NSString *sessionID;    /**< 会话ID */
@property (nonatomic,strong) NSString *msgID;    /**< 消息ID */
@property (nonatomic,assign) NIMSDKResCode rescode;    /**< 错误码 */
@property (nonatomic,assign) NSInteger msgTimetag;    /**< 消息时间戳 */
@end

/** @brief 消息撤回通知 */
@interface NIMSDKRecallMessageNotification : NSObject

@property (nonatomic,strong) NSString *fromId;    /**< 消息发送方ID */
@property (nonatomic,strong) NSString *toId;        /**< 消息接收方ID */
@property (nonatomic,strong) NSString *msgId;    /**< 客户端消息ID */
@property (nonatomic,strong) NSString *notify;    /**< 自定义通知文案 */
@property (nonatomic,strong) NSString *fromNick; /**< 消息发送方昵称 */
@property (nonatomic,strong) NSString *operatorId; /**< 消息的操作者，比哪谁撤消了消息 */
@property (nonatomic,assign) NIMSDKSessionType sessionType;    /**< 会话类型 */
@property (nonatomic,assign) NSInteger notifyTimetag;    /**< 通知时间戳 */
@property (nonatomic,assign) NIMSDKMessageFeature notifyFeature;    /**< 通知的种类 */
@property (nonatomic,assign) BOOL msglogExist;        /**< 客户端消息本地是否存在 */
@property (nonatomic,assign) NSInteger msglogTimetag;    /**< 撤回的消息的消息时间戳 */

@end
