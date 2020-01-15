//
//  NIMSDKSessionImpl+callbacks.m
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//

#import "NIMSDKSessionImpl+callbacks.h"
#import "NIMSDKSessionHelper.h"
#import "NIMDispatch.h"
#import "nim_cpp_talk.h"
#import "nim_cpp_session.h"

@implementation NIMSDKSessionImpl (callbacks)
-(void)setupCallbacks
{
    __weak typeof(self) weakSelf = self;
    nim::Talk::RegSendMsgCb([weakSelf](const nim::SendMessageArc& ack_result)
    {
        @autoreleasepool {
            __strong typeof(weakSelf) strongSelf = weakSelf;
            NIMSDKSendMessageResult* result = [[NIMSDKSendMessageResult alloc] init];
            result.msgID = [NSString stringWithUTF8String:ack_result.msg_id_.c_str()];
            result.msgTimetag = ack_result.msg_timetag_;
            result.rescode = (NIMSDKResCode)ack_result.rescode_;
            result.sessionID = [NSString stringWithUTF8String:ack_result.talk_id_.c_str()];
            nim_main_async(^{
                [strongSelf notifySendMessageResult:result];
            });
        }
    });
    
    nim::Talk::RegReceiveCb([weakSelf](const nim::IMMessage& msg){
        
        @autoreleasepool {
            __strong typeof(weakSelf) strongSelf = weakSelf;
            NIMSDKIMReceivedMessage* message = [[NIMSDKIMReceivedMessage alloc] init];
            convertNIMIMMessage(msg,message);
            nim_main_async(^{
                [strongSelf notifyReceivedMessages:@[message]];
            });
        }
    });
    
    nim::Talk::RegReceiveMessagesCb([weakSelf](const std::list<nim::IMMessage>& msgs){
        @autoreleasepool {
            __strong typeof(weakSelf) strongSelf = weakSelf;
            NSMutableArray* messages = [[NSMutableArray alloc] initWithCapacity:msgs.size()];
            for (auto& msg : msgs) {
                NIMSDKIMReceivedMessage* message = [[NIMSDKIMReceivedMessage alloc] init];
                convertNIMIMMessage(msg,message);
                [messages addObject:message];
            }
            nim_main_async(^{
                [strongSelf notifyReceivedMessages:messages];
            });
        }
    });
    
    nim::Session::RegBadgeCountCb([weakSelf](const std::string& json_ext)->int32_t
    {
        @autoreleasepool {
            
            if (weakSelf.badgeCountBlock == nil) {
                return -1;
            }
            return weakSelf.badgeCountBlock();
        };
    });
}

-(void)cleanupCallbacks
{
    nim::Talk::UnregTalkCb();
    nim::Session::UnregSessionCb();
}


-(void)notifySendMessageResult:(NIMSDKSendMessageResult *)result
{
    [self.delegate onSendMessageAckResult:result];
}
-(void)notifyReceivedMessages:(NSArray *)messages
{
    [self.delegate onReceivedMessages:messages];
}
@end
