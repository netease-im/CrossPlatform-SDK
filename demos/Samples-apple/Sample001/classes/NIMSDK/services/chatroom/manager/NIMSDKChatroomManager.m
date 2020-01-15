//
//  NIMSDKChatroomManager.m
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import "NIMSDKChatroomManager.h"
#import "NIMSDKChatroomImpl.h"
#import "NIMDispatch.h"

@interface NIMSDKChatroomManager()

@property (nonatomic,strong) NIMSDKChatroomImpl* chatroomImpl;

@end

@implementation NIMSDKChatroomManager

#pragma mark - service protocol
-(void)setup
{
    _chatroomImpl = [[NIMSDKChatroomImpl alloc] init];
}

-(void)cleanup
{
    _chatroomImpl = nil;
}

#pragma mark - chatroom service protocol

- (void)addDelegate:(nonnull id<NIMSDKChatroomDelegate>)delegate {
    if(_chatroomImpl){
        [_chatroomImpl addDelegate:delegate];
    }
}

- (void)removeDelegate:(nonnull id<NIMSDKChatroomDelegate>)delegate {
    if (_chatroomImpl) {
        [_chatroomImpl removeDelegate:delegate];
    }
}

-(void)RequestTokenWithRoomID:(NSInteger)roomID result:(ChatroomRequestTokenResult)block
{
    if (!_chatroomImpl) {
        NSLog(@"_chatroomImpl is nil ");
        return;
    }
    
    [_chatroomImpl RequestTokenWithRoomID:roomID result:block];
}

-(BOOL)EnterWithRoomID:(NSInteger)roomID token:(NSString*)token  enterInfo:(NIMSDKChatRoomEnterInfo*)info
{
    if (!_chatroomImpl) {
        NSLog(@"_chatroomImpl is nil ");
        return NO;
    }
    
    return [_chatroomImpl EnterWithRoomID:roomID token:token enterInfo:info];
}

-(void)ExitWithRoomID:(NSInteger)roomID
{
    if (!_chatroomImpl) {
        NSLog(@"_chatroomImpl is nil ");
        return;
    }
    
    [_chatroomImpl ExitWithRoomID:roomID];
}

@end
