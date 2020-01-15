//
//  NIMSDKChatroomImpl+callbacks.m
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import "NIMSDKChatroomImpl+callbacks.h"
#import "nim_chatroom_cpp.h"
#import "NIMSDKChatroomHelper.h"
#import "NIMDispatch.h"

@implementation NIMSDKChatroomImpl (callbacks)

-(void)setupCallbacks
{
    __weak typeof(self) weakSelf = self;
    nim_chatroom::ChatRoom::RegEnterCb([weakSelf](int64_t room_id, const nim_chatroom::NIMChatRoomEnterStep step, int error_code, const nim_chatroom::ChatRoomInfo& info, const nim_chatroom::ChatRoomMemberInfo& my_info)
    {
        @autoreleasepool {
            __strong typeof(weakSelf) strongSelf = weakSelf;
            
            NIMSDKChatRoomEnterResult* result = [[NIMSDKChatRoomEnterResult alloc] init];

            result.resCode = (NIMSDKResCode)error_code;
            result.roomID = (NSInteger)room_id;
            result.step = (NIMSDKChatRoomEnterStep)step;
            result.roomInfo = convertNIMSDKChatRoomInfo(info);
            result.myInfo = convertNIMSDKChatRoomMemberInfo(my_info);
            
            nim_main_async(^{
                [strongSelf notifyEnter: result];
            });
        }
    });
    
    nim_chatroom::ChatRoom::RegExitCb([weakSelf](int64_t room_id, int error_code, nim_chatroom::NIMChatRoomExitReason exit_reason){
        
        @autoreleasepool {
            __strong typeof(weakSelf) strongSelf = weakSelf;
            
            NIMSDKChatRoomExitResult* result = [[NIMSDKChatRoomExitResult alloc] init];
            result.roomID = (NSInteger)room_id;
            result.reason = (NIMSDKChatRoomExitReason)exit_reason;
            result.resCode = (NIMSDKResCode)error_code;
            
            
             nim_main_async(^{
                 [strongSelf notifyExit: result];
             });
        }
        
    });
    
}
-(void)cleanupCallbacks
{
    nim_chatroom::ChatRoom::UnregChatroomCb();
}

-(void)notifyEnter:(NIMSDKChatRoomEnterResult*)result
{
   [self.delegate onChatroomEnter:result];
}

-(void)notifyExit:(NIMSDKChatRoomExitResult*)result
{
    [self.delegate onChatroomExit:result];
}
@end
