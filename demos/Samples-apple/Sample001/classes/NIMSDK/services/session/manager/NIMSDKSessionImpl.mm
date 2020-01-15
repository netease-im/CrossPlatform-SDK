//
//  NIMSDKSessionImpl.m
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//

#import "NIMSDKSessionImpl.h"
#import "NIMSDKSessionImpl+callbacks.h"
#import "NIMSDKSessionHelper.h"
#import "nim_cpp_talk.h"
#import "nim_cpp_user.h"

@interface NIMSDKSessionImpl ()
{
    NIMMulticastDelegate *_delegate;
}
@end

@implementation NIMSDKSessionImpl

-(instancetype)init
{
    if (self = [super init]) {
        _delegate = [[NIMMulticastDelegate alloc] init];
        [self setupCallbacks];
    }
    
    return self;
}

-(void)dealloc
{
    [self cleanupCallbacks];
}

#pragma mark - register callbacks
-(id<NIMSDKSessionDelegate>)delegate
{
    return (id<NIMSDKSessionDelegate>)_delegate;
}


-(void)addDelegate:(id<NIMSDKSessionDelegate>)delegate
{
    [_delegate addDelegate:delegate];
}
-(void)removeDelegate:(id<NIMSDKSessionDelegate>)delegate
{
    [_delegate removeDelegate:delegate];
}


#pragma mark - api
-(BOOL)sendMessage:(NIMSDKIMMessage *)message
{
    nim::User::UpdatePushToken("","",0);

    nim::IMMessage msg;
    BOOL success = transformNIMIMMessage(message,msg);
    if (!success) {
        return NO;
    }
    std::string send_msg = msg.ToJsonString(true);
    nim::Talk::SendMsg(send_msg);
    return success;
}



@end
