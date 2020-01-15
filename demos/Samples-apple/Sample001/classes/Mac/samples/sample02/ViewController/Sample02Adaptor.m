//
//  Sample02Adaptor.m
//  Samples Mac
//
//  Created by dudu on 2020/1/6.
//

#import "Sample02Adaptor.h"
#import "NIMSDK.h"
#import "NIMSDKChatroomServiceProtocol.h"

@interface Sample02Adaptor ()<NIMSDKChatroomDelegate>

@end

@implementation Sample02Adaptor

-(instancetype)init
{
    if(self = [super init]){
        [[NIMSDK shared].chatroomService addDelegate:self];
    }
    
    return  self;
}
-(void)dealloc
{
    [[NIMSDK shared].chatroomService removeDelegate:self];
}
#pragma mark - NESample02Delegate protocol

- (void)onEnterClicked:(NSNumber*)roomID
{
    if (roomID == nil) {
        NSLog(@"param invalid : %@",roomID);
        return;
    }
   [[NIMSDK shared].chatroomService RequestTokenWithRoomID:[roomID integerValue] result:^(NIMSDKResCode code, NSInteger roomID, NSString * _Nullable token) {
        
        if (code == NIMSDKResSuccess) {
            NIMSDKChatRoomEnterInfo* info =[[NIMSDKChatRoomEnterInfo alloc] init];
            info.nick = @"这是一个昵称";
            [[NIMSDK shared].chatroomService EnterWithRoomID:roomID token:token enterInfo:info];
        }
    }];
}

-(void)onExitClicked:(NSNumber*)roomID
{
    if (roomID == nil) {
        NSLog(@"param invalid : %@",roomID);
        return;
    }
    [[NIMSDK shared].chatroomService ExitWithRoomID:[roomID integerValue]];
}

#pragma mark - NIMSDKChatroomDelegate protocol

- (void)onChatroomEnter:(NIMSDKChatRoomEnterResult *)result
{
    if ([_delegate respondsToSelector:@selector(showResult:)]) {
        [_delegate performSelector:@selector(showResult:) withObject:[result description]];
    }
}

- (void)onChatroomExit:(NIMSDKChatRoomExitResult *)result
{
    if ([_delegate respondsToSelector:@selector(showResult:)]) {
        [_delegate performSelector:@selector(showResult:) withObject:[result description]];
    }
}


@end
