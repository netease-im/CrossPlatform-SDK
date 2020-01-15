//
//  NIMSDKTalkModel.m
//  Samples iOS
//
//  Created by dudu on 2019/11/25.
//

#import "NIMSDKTalkModel.h"

@implementation NIMSDKMessageSetting

-(instancetype)init
{
    if (self = [super init]) {
        _antiSpamUsingYidun = -1;
        _teamMsgUnreadCount = -1;
    }
    return self;
}

-(id)copyWithZone:(NSZone *)zone
{
    
    NIMSDKMessageSetting* setting = [[[self class] allocWithZone:zone] init];
    setting.resendFlag = [self.resendFlag copy];
    setting.serverHistorySaved= [self.serverHistorySaved copy];
    setting.roaming = [self.roaming copy];
    setting.selfSync = [self.selfSync copy];
    setting.needPush = [self.needPush copy];
    setting.pushNeedBadge = [self.pushNeedBadge copy];
    setting.pushNeedPrefix = [self.pushNeedPrefix copy];
    setting.routable = [self.routable copy];
    setting.needOffline = [self.needOffline copy];
    setting.pushPayload = [self.pushPayload copy];
    setting.pushContent = [self.pushContent copy];
    setting.serverExt = [self.serverExt copy];
    setting.localExt = [self.localExt copy];
    setting.isForcePush = [self.isForcePush copy];
    setting.forcePushIDs = [self.forcePushIDs copy];
    setting.forcePushContent = [self.forcePushContent copy];
    setting.antiSpamEnable = [self.antiSpamEnable copy];
    setting.antiSpamContent = [self.antiSpamContent copy];
    setting.antiApamBizID = [self.antiApamBizID copy];
    setting.antiSpamUsingYidun = self.antiSpamUsingYidun;
    setting.clientAntiSpamHitting = [self.clientAntiSpamHitting copy];
    setting.teamMsgNeedAck = [self.teamMsgNeedAck copy];
    setting.teamMsgAckSent = [self.teamMsgAckSent copy];
    setting.teamMsgUnreadCount = self.teamMsgUnreadCount;
    return setting;
}

@end

/** @brief P2P和群组消息 */
@implementation NIMSDKIMMessage

-(instancetype)init
{
    if (self = [super init]) {
        
    }
    return self;
}

-(id)copyWithZone:(NSZone *)zone
{
    NIMSDKIMMessage *message = [[[self class] allocWithZone:zone] init];
    message.sessionType = self.sessionType;
    message.receiverAccid = [self.receiverAccid copy];
    message.senderAccid = [self.senderAccid copy];
    message.timetag = self.timetag;
    message.content = [self.content copy];
    message.type = self.type;
    message.attach = [self.attach copy];
    message.clientMsgId = self.clientMsgId;
    message.msgSetting= [self.msgSetting copy];
    message.localResPath = self.localResPath;
    message.localTalkId = self.localTalkId;
    message.localResId = self.localResId;
    message.status = self.status;
    message.subStatus = self.subStatus;
    return message;
}

-(NSString *)description
{
    return [NSString stringWithFormat:@"sender:%@,receiver:%@,type:%ld,msgId:%@,content:%@,attach:%@",
            _senderAccid,_receiverAccid,_type,_clientMsgId,_content,_attach];
}

+(instancetype)createIMMessage:(NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(NSString*)msgID
    content:(NSString*)content
    setting:(NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag
{
    NIMSDKIMMessage* message = [[[self class] alloc] init];
    if (message) {
        message.receiverAccid = receiver;
        message.sessionType = type;
        message.type = NIMSDKMessageTypeText;
        message.content = content;
        message.clientMsgId = msgID;
        message.msgSetting = setting;
        message.localTalkId = receiver;
        message.timetag = timetag;
    }
    
    return message;
}

+(instancetype)createIMMessage:(NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(NSString*)msgID
    attach:(NIMSDKIMFile*)attach
    filePath:(NSString*)path
    setting:(NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag
{
    NIMSDKIMMessage* message = [[[self class] alloc] init];
    if (message) {
        message.receiverAccid = receiver;
        message.sessionType = type;
        if ([attach isKindOfClass:[NIMSDKIMVideo class]]) {
            message.type = NIMSDKMessageTypeVideo;
        }
        else if ([attach isKindOfClass:[NIMSDKIMAudio class]])
        {
            message.type = NIMSDKMessageTypeAudio;
        }
        else if ([attach isKindOfClass:[NIMSDKIMImage class]])
        {
            message.type = NIMSDKMessageTypeImage;
        }
        else if ([attach isKindOfClass:[NIMSDKIMFile class]])
        {
            message.type = NIMSDKMessageTypeFile;
        }
        else if ([attach isKindOfClass:[NIMSDKIMLocation class]])
        {
            message.type = NIMSDKMessageTypeLocation;
        }
        message.attach = attach;
        message.clientMsgId = msgID;
        message.msgSetting = setting;
        message.localResPath = path;
        message.localTalkId = receiver;
        message.timetag = timetag;
    }
    
    return message;
}


+(instancetype)createIMMessage:(NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(NSString*)msgID
    tipcontent:(NSString*)content
    setting:(NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag
    {
        NIMSDKIMMessage* message = [[[self class] alloc] init];
        if (message) {
            message.receiverAccid = receiver;
            message.sessionType = type;
            message.type = NIMSDKMessageTypeTips;
            message.content = content;
            message.clientMsgId = msgID;
            message.msgSetting = setting;
            message.localTalkId = receiver;
            message.timetag = timetag;
        }
        
        return message;
    }

+(instancetype)createIMMessage:(NSString*)receiver
    sessionType:(NIMSDKSessionType)type
    messageId:(NSString*)msgID
    content:(NSString*)content
    robot:(NIMSDKIMBotRobot*)robot
    setting:(NIMSDKMessageSetting*)setting
    timetag:(NSInteger)timetag
    {
        NIMSDKIMMessage* message = [[[self class] alloc] init];
        if (message) {
            message.receiverAccid = receiver;
            message.sessionType = type;
            message.type = NIMSDKMessageTypeRobot;
            message.content = content;
            message.attach = robot;
            message.clientMsgId = msgID;
            message.msgSetting = setting;
            message.localTalkId = receiver;
            message.timetag = timetag;
        }
        
        return message;
    }

@end
/** @brief P2P和群组消息 */
@implementation NIMSDKIMReceivedMessage

-(instancetype)init
{
    if (self = [super init]) {
        
    }
    return self;
}
@end

/** @brief 文件消息附件 */
@implementation NIMSDKIMFile


@end

/** @brief 图片消息附件 */
@implementation NIMSDKIMImage


@end

/** @brief 位置消息附件 */
@implementation NIMSDKIMLocation


@end

/** @brief 语音消息附件 */
@implementation NIMSDKIMAudio


@end

/** @brief 小视频消息附件 */
@implementation NIMSDKIMVideo


@end

/** @brief 波特机器人消息附件 */
@implementation NIMSDKIMBotRobot

    
@end

@implementation NIMSDKBroadcastMessage


@end


@implementation NIMSDKSendMessageResult

-(NSString *)description
{
    return [NSString stringWithFormat:@"code:%ld,sessionID:%@,msgId:%@",(long)_rescode,_sessionID,_msgID];
}

@end

@implementation NIMSDKRecallMessageNotification



@end
