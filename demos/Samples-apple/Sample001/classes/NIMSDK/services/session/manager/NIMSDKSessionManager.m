//
//  NIMSDKSessionManager.m
//  Samples iOS
//
//  Created by dudu on 2019/11/26.
//

#import "NIMSDKSessionManager.h"
#import "NIMSDKSessionImpl.h"
#import "NIMSDKSessionImpl+callbacks.h"

@interface NIMSDKSessionManager ()

@property (nonatomic,strong)NIMSDKSessionImpl* sessionImpl;

@end

@implementation NIMSDKSessionManager

#pragma mark - service protocol
-(void)setup
{
    _sessionImpl = [[NIMSDKSessionImpl alloc] init];
}

-(void)cleanup
{
    _sessionImpl = nil;
}

#pragma mark - session service protocol

-(void)addDelegate:(id<NIMSDKSessionDelegate>)delegate
{
    if (_sessionImpl) {
        [_sessionImpl addDelegate:delegate];
    }
}

-(void)removeDelegate:(id<NIMSDKSessionDelegate>)delegate
{
    if (_sessionImpl) {
        [_sessionImpl removeDelegate:delegate];
    }
}

-(BOOL)sendMessage:(NIMSDKIMMessage *)message
{
    if (_sessionImpl == nil || message == nil) {
        return NO;
    }
    
    return [_sessionImpl sendMessage:message];
}

- (BOOL)setBadgeCountBlock:(BadgeCountBlock)block
{
    if (_sessionImpl == nil) {
        return NO;
    }
    
    [_sessionImpl setBadgeCountBlock:block];
    return YES;
}
@end
