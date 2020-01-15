//
//  Sample01Adaptor.m
//  Samples Mac
//
//  Created by dudu on 2019/12/13.
//

#import "Sample01Adaptor.h"
#import "NIMSDK.h"
#import "NSString+ext.h"

@interface Sample01Adaptor ()<NIMSDKSessionDelegate>

@end

@implementation Sample01Adaptor

-(instancetype)init
{
    if(self = [super init]){
        [self setup];
    }
    return self;
}
-(void)setup
{
    [[NIMSDK shared].sessionService addDelegate:self];
}

-(void)dealloc{
    [[NIMSDK shared].sessionService removeDelegate:self];
}
-(void)onSendClicked
{
    NSTimeInterval now = [[NSDate date] timeIntervalSince1970];
    NSString* nowTimetag = [NSString stringWithFormat:@"%@",@(now)];
    NSString* content = @"这是一条测试消息";
    NIMSDKMessageSetting* messageSetting;
    NIMSDKIMMessage* message = [NIMSDKIMMessage createIMMessage:@"supercaowei" sessionType:NIMSDKSessionTypeP2P messageId:[nowTimetag md5] content:content setting:messageSetting timetag:0];
    [[NIMSDK shared].sessionService sendMessage:message];
    
}


#pragma mark

-(void)onSendMessageAckResult:(NIMSDKSendMessageResult*)result
{
    NSLog(@"%@", [result description]);
    
    [_mv updateReceivedMsg:[result description]];
  
}
-(void)onReceivedMessages:(NSArray<NIMSDKIMReceivedMessage*>*)messages
{
    for (NIMSDKIMReceivedMessage* msg in messages) {
        NSLog(@"%@", [msg description]);
        [_mv updateReceivedMsg:[msg description]];
    }
}

@end
