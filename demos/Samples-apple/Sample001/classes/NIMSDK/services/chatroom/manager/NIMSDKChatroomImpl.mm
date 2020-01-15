//
//  NIMSDKChatroomImpl.m
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import "NIMSDKChatroomImpl.h"
#import "NIMSDKChatroomImpl+callbacks.h"
#import "NIMMulticastDelegate.h"
#import "NSString+ext.h"
#import "NIMDispatch.h"
#import "nim_chatroom_cpp.h"
#import "nim_cpp_plugin_in.h"

@interface NIMSDKChatroomImpl ()
{
    NIMMulticastDelegate *_delegate;
}
@end

@implementation NIMSDKChatroomImpl

-(instancetype)init
{
    if (self = [super init]) {
        _delegate = [[NIMMulticastDelegate alloc] init];
        [self setup];
    }
    
    return self;
}

-(void)dealloc
{
    [self cleanup];
}

-(void)setup
{
    nim_chatroom::ChatRoom::Init("");
    [self setupCallbacks];
}

-(void)cleanup
{
    [self cleanupCallbacks];
    nim_chatroom::ChatRoom::Cleanup();
}

#pragma mark - register callbacks
-(id<NIMSDKChatroomDelegate>)delegate
{
    return (id<NIMSDKChatroomDelegate>)_delegate;
}


-(void)addDelegate:(id<NIMSDKChatroomDelegate>)delegate
{
    [_delegate addDelegate:delegate];
}
-(void)removeDelegate:(id<NIMSDKChatroomDelegate>)delegate
{
    [_delegate removeDelegate:delegate];
}


-(BOOL)RequestTokenWithRoomID:(NSInteger)roomID result:(ChatroomRequestTokenResult)block
{
    nim::PluginIn::ChatRoomRequestEnterAsync((int64_t)roomID, [roomID,block](int error_code, const std::string& result)
    {
        @autoreleasepool {
            nim_main_sync(^{

                if (block != nil) {
                    block((NIMSDKResCode)error_code,roomID,result.empty() ? nil : [NSString stringWithUTF8String:result.c_str()]);
                }
            });
        }
    });
    
    return YES;
}

-(BOOL)EnterWithRoomID:(NSInteger)roomID token:(NSString*)token  enterInfo:(NIMSDKChatRoomEnterInfo*)info
{
    if ([NSString isEmptyOrNull: token]) {
        return NO;
    }
    bool ret = nim_chatroom::ChatRoom::Enter(roomID, [token UTF8String]);
    
    return ret ? YES : NO;
}

-(void)ExitWithRoomID:(NSInteger)roomID
{
    nim_chatroom::ChatRoom::Exit(roomID);
}
@end
