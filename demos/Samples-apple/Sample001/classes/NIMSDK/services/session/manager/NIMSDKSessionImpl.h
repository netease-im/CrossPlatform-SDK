//
//  NIMSDKSessionImpl.h
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//

#import <Foundation/Foundation.h>
#import "NIMSDKTalkModel.h"
#import "NIMMulticastDelegate.h"
#import "NIMSDKSessionServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface NIMSDKSessionImpl : NSObject


-(id<NIMSDKSessionDelegate>) delegate;
-(void)addDelegate:(id<NIMSDKSessionDelegate>)delegate;
-(void)removeDelegate:(id<NIMSDKSessionDelegate>)delegate;

-(BOOL)sendMessage:(NIMSDKIMMessage*)message;

@property (nonatomic,strong,nullable)BadgeCountBlock badgeCountBlock;

@end

NS_ASSUME_NONNULL_END
