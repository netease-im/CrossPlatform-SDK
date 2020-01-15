//
//  NIMSDKSessionHelper.m
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//

#import <Foundation/Foundation.h>
#import "NIMSDKSessionHelper.h"
#import "NSDictionary+ext.h"
#import "NSString+ext.h"

#ifdef __cplusplus
extern "C" {
#endif
    
BOOL transformJsonValue(NSDictionary* dict,nim_cpp_wrapper_util::Json::Value& value)
{
    @autoreleasepool {
        if ([dict count] == 0) {
            return NO;
        }
        NSData *data = [NSDictionary toJsonData:dict];
        if (data == nil) {
            return NO;
        }
        
        std::string json = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] UTF8String];
        if (!json.empty()) {
            nim_cpp_wrapper_util::Json::Reader reader;
            if (!reader.parse(json, value)){
                return NO;
            }
        }
        return YES;
    }
}
    
NSDictionary* convertJsonValue(const nim_cpp_wrapper_util::Json::Value& value)
{
    nim_cpp_wrapper_util::Json::FastWriter writer;
    std::string json = writer.write(value);
    
    return [NSDictionary toDictionary:[NSString stringWithUTF8String:json.c_str()]];
}

BOOL transformNIMIMMessage(NIMSDKIMMessage* message,nim::IMMessage& msg)
{
    if (message == nil) {
        return NO;
    }
    
    msg.receiver_accid_ = [message.receiverAccid UTF8String];
    msg.session_type_ = (nim::NIMSessionType)message.sessionType;
    
    msg.timetag_ = message.timetag;
    msg.type_ = (nim::NIMMessageType)message.type;
    if(message.senderAccid){
        msg.sender_accid_ = [message.senderAccid UTF8String];
    }
    if (message.content) {
        msg.content_ = [message.content UTF8String];
    }
    if (message.clientMsgId) {
        msg.client_msg_id_ = [message.clientMsgId UTF8String];
    }
    if (message.localTalkId) {
        msg.local_talk_id_ = [message.localTalkId UTF8String];
    }
    if (message.attach) {
        //msg.attach_ = transformNIMMessageAttach(message.attach);
        NSString* attach = transformNIMMessageAttach(message.attach);
        if (attach) {
            msg.attach_ = [attach UTF8String];
        }
    }
    
    if (message.msgSetting) {
        transformNIMIMMessageSetting(message.msgSetting, msg.msg_setting_);
    }
    
    if (message.localResId) {
        msg.local_res_id_ = [message.localResId UTF8String];
    }
    
    if (message.localResPath) {
        msg.local_res_path_ = [message.localResPath UTF8String];
    }
    
    msg.status_ = (nim::NIMMsgLogStatus)message.status;
    msg.sub_status_ = (nim::NIMMsgLogSubStatus)message.subStatus;
    
    return YES;
}
    
BOOL convertNIMIMMessage(const nim::IMMessage& msg,NIMSDKIMMessage* message)
{
    @autoreleasepool {
        message.receiverAccid = [NSString stringWithUTF8String:msg.receiver_accid_.c_str()];
         message.sessionType = (NIMSDKSessionType)msg.session_type_;
         message.timetag = msg.timetag_;
         message.type = (NIMSDKMessageType)msg.type_;

         if(!msg.sender_accid_.empty()){
            message.senderAccid = [NSString stringWithUTF8String:msg.sender_accid_.c_str()];
         }

         if(!msg.content_.empty()){
            message.content = [NSString stringWithUTF8String:msg.content_.c_str()];
         }
         if(!msg.client_msg_id_.empty()){
               message.clientMsgId = [NSString stringWithUTF8String:msg.client_msg_id_.c_str()];
         }
         if(!msg.local_talk_id_.empty()){
              message.localTalkId = [NSString stringWithUTF8String:msg.local_talk_id_.c_str()];
         }
        if(!msg.attach_.empty()){
             message.attach = convertNIMSDKMessageAttach(msg.type_,msg.attach_);
        }
         if (message.msgSetting == nil) {
             message.msgSetting = [[NIMSDKMessageSetting alloc] init];
         }
         convertNIMSDKIMMessageSetting(msg.msg_setting_,message.msgSetting);
         
         if(!msg.local_res_id_.empty()){
              message.localResId = [NSString stringWithUTF8String:msg.local_res_id_.c_str()];
         }
         
         if(!msg.local_res_path_.empty()){
              message.localResPath = [NSString stringWithUTF8String:msg.local_res_path_.c_str()];
         }
         message.status = (NIMSDKMsglogStatus)msg.status_;
         message.subStatus = (NIMSDKMsglogSubStatus)msg.sub_status_;
         
         if ([message isKindOfClass:[NIMSDKIMReceivedMessage class]]) {
             
             NIMSDKIMReceivedMessage* recvMsg = (NIMSDKIMReceivedMessage*)message;
             [recvMsg setRescode:(NIMSDKResCode)msg.rescode_];
             [recvMsg setFeature:(NIMSDKMessageFeature)msg.feature_];
             [recvMsg setReadonlySenderClientType:(NIMSDKClientType)msg.readonly_sender_client_type_];
             [recvMsg setReadonlySenderDeviceId:[NSString stringWithUTF8String:msg.readonly_sender_device_id_.c_str()]];
             [recvMsg setReadonlySenderNickname:[NSString stringWithUTF8String:msg.readonly_sender_nickname_.c_str()]];
             [recvMsg setReadonlyServerId:(NSInteger)msg.readonly_server_id_];
         }
         
         return YES;
    }
}
    
BOOL transformNIMIMMessageSetting(NIMSDKMessageSetting* messageSetting,nim::MessageSetting& setting)
{
    @autoreleasepool {
        setting.resend_flag_ = messageSetting.resendFlag == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.resendFlag.boolValue;
        setting.server_history_saved_ = messageSetting.serverHistorySaved == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.serverHistorySaved.boolValue;
        setting.roaming_ = messageSetting.roaming == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.roaming.boolValue;
        setting.self_sync_ = messageSetting.selfSync == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.selfSync.boolValue;
        setting.need_push_ = messageSetting.needPush == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.needPush.boolValue;
        setting.push_need_badge_ = messageSetting.pushNeedBadge == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.pushNeedBadge.boolValue;
        setting.push_need_prefix_ = messageSetting.pushNeedPrefix == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.pushNeedPrefix.boolValue;
        setting.routable_ = messageSetting.routable == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.routable.boolValue;
        setting.need_offline_ = messageSetting.needOffline == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.needOffline.boolValue;
        
        transformJsonValue(messageSetting.pushPayload, setting.push_payload_);
        
        if (![NSString isEmptyOrNull:messageSetting.pushContent]) {
            setting.push_content_ = [messageSetting.pushContent UTF8String];
        }

        transformJsonValue(messageSetting.serverExt, setting.server_ext_);
        
        if (![NSString isEmptyOrNull:messageSetting.localExt]) {
            setting.local_ext_ = [messageSetting.localExt UTF8String];
        }
        
        setting.is_force_push_ = messageSetting.isForcePush == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.isForcePush.boolValue;
        
        if (messageSetting.forcePushIDs) {
            for (NSString* uid in messageSetting.forcePushIDs) {
                setting.force_push_ids_list_.push_back([uid UTF8String]);
            }
        }
        if (![NSString isEmptyOrNull:messageSetting.forcePushContent]) {
            setting.force_push_content_ = [messageSetting.forcePushContent UTF8String];
        }

        setting.anti_spam_enable_ = messageSetting.antiSpamEnable == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.antiSpamEnable.boolValue;
        
        if (![NSString isEmptyOrNull:messageSetting.antiSpamContent]) {
            setting.anti_spam_content_ = [messageSetting.antiSpamContent UTF8String];
        }
        
        if (![NSString isEmptyOrNull:messageSetting.antiApamBizID]) {
            setting.anti_apam_biz_id_ = [messageSetting.antiApamBizID UTF8String];
        }
        
        setting.anti_apam_using_yidun_ = (int)messageSetting.antiSpamUsingYidun;
        setting.client_anti_spam_hitting_ = messageSetting.clientAntiSpamHitting == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.clientAntiSpamHitting.boolValue;
        setting.team_msg_need_ack_ = messageSetting.teamMsgNeedAck == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.teamMsgNeedAck.boolValue;
        setting.team_msg_ack_sent_ = messageSetting.teamMsgAckSent == nil ? BS_NOT_INIT : (BoolStatus)messageSetting.teamMsgAckSent.boolValue;
        setting.team_msg_unread_count_ = (int)messageSetting.teamMsgUnreadCount;
        return YES;
    }
}
BOOL convertNIMSDKIMMessageSetting(const nim::MessageSetting& messageSetting,NIMSDKMessageSetting* setting)
{
    @autoreleasepool {
        setting.resendFlag = messageSetting.resend_flag_ == BS_NOT_INIT ? nil : @(messageSetting.resend_flag_);
        setting.serverHistorySaved = messageSetting.server_history_saved_ == BS_NOT_INIT ? nil : @(messageSetting.server_history_saved_);
         setting.roaming = messageSetting.roaming_ == BS_NOT_INIT ? nil : @(messageSetting.roaming_);
        setting.selfSync = messageSetting.self_sync_ == BS_NOT_INIT ? nil : @(messageSetting.self_sync_);
        setting.needPush = messageSetting.need_push_ == BS_NOT_INIT ? nil : @(messageSetting.need_push_);
        setting.pushNeedBadge = messageSetting.push_need_badge_ == BS_NOT_INIT ? nil : @(messageSetting.push_need_badge_);
        setting.pushNeedPrefix = messageSetting.push_need_prefix_ == BS_NOT_INIT ? nil : @(messageSetting.push_need_prefix_);
        setting.routable = messageSetting.routable_ == BS_NOT_INIT ? nil : @(messageSetting.routable_);
        
        setting.needOffline = messageSetting.need_offline_ == BS_NOT_INIT ? nil : @(messageSetting.need_offline_);
       
        
        setting.pushPayload = convertJsonValue(messageSetting.push_payload_);
        
        if (!messageSetting.push_content_.empty()) {
            setting.pushContent = [NSString stringWithUTF8String:messageSetting.push_content_.c_str()];
        }
        
        setting.serverExt = convertJsonValue(messageSetting.server_ext_);

        if (!messageSetting.local_ext_.empty()) {
            setting.localExt = [NSString stringWithUTF8String:messageSetting.local_ext_.c_str()];
        }
        setting.isForcePush = messageSetting.is_force_push_ == BS_NOT_INIT ? nil : @(messageSetting.is_force_push_);
       
        if (!messageSetting.force_push_ids_list_.empty()) {
            NSMutableArray *array = [[NSMutableArray alloc] initWithCapacity:messageSetting.force_push_ids_list_.size()];
            for(auto& uid : messageSetting.force_push_ids_list_)
            {
                [array addObject:[NSString stringWithUTF8String:uid.c_str()]];
            }
        }
        if (!messageSetting.force_push_content_.empty()) {
            setting.forcePushContent = [NSString stringWithUTF8String:messageSetting.force_push_content_.c_str()];
        }
        setting.antiSpamEnable = messageSetting.anti_spam_enable_ == BS_NOT_INIT ? nil : @(messageSetting.anti_spam_enable_);

        if (!messageSetting.anti_spam_content_.empty()) {
            setting.antiSpamContent = [NSString stringWithUTF8String:messageSetting.anti_spam_content_.c_str()];
        }
        
        if (!messageSetting.anti_apam_biz_id_.empty()) {
            setting.antiApamBizID = [NSString stringWithUTF8String:messageSetting.anti_apam_biz_id_.c_str()];
        }
        
        setting.antiSpamUsingYidun = (NSInteger)messageSetting.anti_apam_using_yidun_;
        setting.clientAntiSpamHitting = messageSetting.client_anti_spam_hitting_ == BS_NOT_INIT ? nil : @(messageSetting.client_anti_spam_hitting_);
        setting.teamMsgNeedAck = messageSetting.team_msg_need_ack_ == BS_NOT_INIT ? nil : @(messageSetting.team_msg_need_ack_);
        setting.teamMsgAckSent = messageSetting.team_msg_ack_sent_ == BS_NOT_INIT ? nil : @(messageSetting.team_msg_ack_sent_);
        setting.teamMsgUnreadCount = (NSInteger)messageSetting.team_msg_unread_count_;
        return YES;
    }
    return YES;
}
    
NSString* transformNIMMessageAttach(NSObject* attach)
{
    @autoreleasepool {
        if (attach == nil) {
            return nil;
        }
        std::string json_attch;
        return [NSString stringWithUTF8String: json_attch.c_str()];
    }
}
NSObject* convertNIMSDKMessageAttach(nim::NIMMessageType type, const std::string& attach)
{
    @autoreleasepool {
        if (attach.empty()) {
               return nil;
           }
           id attchment = nil;
           nim::IMMessage msg;
           msg.attach_ = attach;
           msg.type_ = type;

           if (type == nim::kNIMMessageTypeImage) {
               nim::IMImage image;
               if (nim::Talk::ParseImageMessageAttach(msg, image)) {
                   attchment = [[NIMSDKIMImage alloc] init];
                   [attchment setMd5: [NSString stringWithUTF8String:image.md5_.c_str()]];
                   [attchment setSize:(NSInteger)image.size_];
                   [attchment setUrl: [NSString stringWithUTF8String:image.url_.c_str()]];
                   [attchment setDisplayName: [NSString stringWithUTF8String:image.display_name_.c_str()]];
                   [attchment setFileExtension: [NSString stringWithUTF8String:image.file_extension_.c_str()]];
                   [attchment setMsgAttachmentTag: [NSString stringWithUTF8String:image.msg_attachment_tag_.c_str()]];
                   [attchment setWidth:(NSInteger)image.width_];
                   [attchment setHeight:(NSInteger)image.height_];
               }
           }
           else if (type == nim::kNIMMessageTypeVideo) {
               nim::IMVideo video;
               if (nim::Talk::ParseVideoMessageAttach(msg, video)) {
                   attchment = [[NIMSDKIMVideo alloc] init];
                   [attchment setMd5: [NSString stringWithUTF8String:video.md5_.c_str()]];
                   [attchment setSize:(NSInteger)video.size_];
                   [attchment setUrl: [NSString stringWithUTF8String:video.url_.c_str()]];
                   [attchment setDisplayName: [NSString stringWithUTF8String:video.display_name_.c_str()]];
                   [attchment setFileExtension: [NSString stringWithUTF8String:video.file_extension_.c_str()]];
                   [attchment setMsgAttachmentTag: [NSString stringWithUTF8String:video.msg_attachment_tag_.c_str()]];
                   [attchment setWidth:(NSInteger)video.width_];
                   [attchment setHeight:(NSInteger)video.height_];
                   [attchment setDuration:(NSInteger)video.duration_];
               }
           }
           else if (type == nim::kNIMMessageTypeAudio) {
               nim::IMAudio audio;
               if (nim::Talk::ParseAudioMessageAttach(msg, audio)) {
                   attchment = [[NIMSDKIMAudio alloc] init];
                   [attchment setMd5: [NSString stringWithUTF8String:audio.md5_.c_str()]];
                   [attchment setSize:(NSInteger)audio.size_];
                   [attchment setUrl: [NSString stringWithUTF8String:audio.url_.c_str()]];
                   [attchment setDisplayName: [NSString stringWithUTF8String:audio.display_name_.c_str()]];
                   [attchment setFileExtension: [NSString stringWithUTF8String:audio.file_extension_.c_str()]];
                   [attchment setMsgAttachmentTag: [NSString stringWithUTF8String:audio.msg_attachment_tag_.c_str()]];
                   [attchment setDuration:(NSInteger)audio.duration_];
               }
           }
           else if (type == nim::kNIMMessageTypeFile) {
               nim::IMFile file;
               if (nim::Talk::ParseFileMessageAttach(msg, file)) {
                   attchment = [[NIMSDKIMFile alloc] init];
                   [attchment setMd5: [NSString stringWithUTF8String:file.md5_.c_str()]];
                   [attchment setSize:(NSInteger)file.size_];
                   [attchment setUrl: [NSString stringWithUTF8String:file.url_.c_str()]];
                   [attchment setDisplayName: [NSString stringWithUTF8String:file.display_name_.c_str()]];
                   [attchment setFileExtension: [NSString stringWithUTF8String:file.file_extension_.c_str()]];
                   [attchment setMsgAttachmentTag: [NSString stringWithUTF8String:file.msg_attachment_tag_.c_str()]];
               }
           }
           else if (type == nim::kNIMMessageTypeLocation) {
               nim::IMLocation location;
                if (nim::Talk::ParseLocationMessageAttach(msg, location)) {
                   attchment = [[NIMSDKIMLocation alloc] init];
                   [attchment setDesc: [NSString stringWithUTF8String:location.description_.c_str()]];
                   [attchment setLatitude:location.latitude_];
                   [attchment setLongitude:location.longitude_];
              }
           }
           else if (type == nim::kNIMMessageTypeRobot)
           {
               nim::IMBotRobot robot;
               if (nim::Talk::ParseBotRobotMessageAttach(msg, robot)) {
                   attchment = [[NIMSDKIMBotRobot alloc] init];
                   [attchment setOutMsg:robot.out_msg_];
                   [attchment setRobotAccid:[NSString stringWithUTF8String:robot.robot_accid_.c_str()]];
                   [attchment setRelatedMsgId:[NSString stringWithUTF8String:robot.related_msg_id_.c_str()]];
                   [attchment setRobotMsgFlag:[NSString stringWithUTF8String:robot.robot_msg_flag_.c_str()]];
                   if (robot.sent_param_.size() > 0) {
                       [attchment setSentParam:convertJsonValue(robot.sent_param_)];
                   }
                   if (robot.robot_msg_content_.size() > 0) {
                       [attchment setRobotMsgContent:convertJsonValue(robot.robot_msg_content_)];
                   }
               }
               
           }
           else
           {
               attchment = [NSString stringWithUTF8String:attach.c_str()];
           }
           return attchment;
    }
}
    

#ifdef __cplusplus
}
#endif
