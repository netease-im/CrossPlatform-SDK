//
//  NIMSDK.h
//  Samples iOS
//
//  Created by dudu on 2019/11/20.
//

#import <Foundation/Foundation.h>

#import "NIMSDKDelegateType.h"
#import "NIMSDKLoginServiceProtocol.h"
#import "NIMSDKSessionServiceProtocol.h"
#import "NIMSDKChatroomServiceProtocol.h"


@interface NIMSDK : NSObject

+(instancetype)shared;


-(void)setup;
-(void)cleanup;

-(void)addDelegate:(id)delegate forType:(NIMSDKDelegateType)type;
-(void)removeDelegate:(id)delegate forType:(NIMSDKDelegateType)type;

-(id<NIMSDKLoginServiceProtocol>)loginService;

-(id<NIMSDKSessionServiceProtocol>)sessionService;

-(id<NIMSDKChatroomServiceProtocol>)chatroomService;

@property (nonatomic,strong)NSString* appKey;
@property (nonatomic,strong)NSString* apnsCername;

@property (nonatomic,strong)NSString* deviceToken;
@end

