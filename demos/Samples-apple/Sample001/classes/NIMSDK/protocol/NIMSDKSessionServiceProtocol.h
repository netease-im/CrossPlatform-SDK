//
//  NIMSDKSessionProtocol.h
//  Samples iOS
//
//  Created by dudu on 2019/11/26.
//

#import <Foundation/Foundation.h>
#import "NIMSDKTalkModel.h"
#import "NIMSDKServiceProtocol.h"


NS_ASSUME_NONNULL_BEGIN

typedef int(^BadgeCountBlock)(void);

@protocol NIMSDKSessionDelegate <NSObject>

@optional
-(void)onSendMessageAckResult:(NIMSDKSendMessageResult*)result;
-(void)onReceivedMessages:(NSArray<NIMSDKIMReceivedMessage*>*)messages;

@end

@protocol NIMSDKSessionServiceProtocol <NIMSDKServiceProtocol>

-(void)addDelegate:(id<NIMSDKSessionDelegate>)delegate;
-(void)removeDelegate:(id<NIMSDKSessionDelegate>)delegate;


-(BOOL)sendMessage:(NIMSDKIMMessage*)message;

-(BOOL)setBadgeCountBlock:(BadgeCountBlock)block;

@end

NS_ASSUME_NONNULL_END
