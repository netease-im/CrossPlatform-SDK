//
//  NIMSDKChatroomImpl.h
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import <Foundation/Foundation.h>
#import "NIMSDKChatroomServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface NIMSDKChatroomImpl : NSObject

-(id<NIMSDKChatroomDelegate>) delegate;
-(void)addDelegate:(id<NIMSDKChatroomDelegate>)delegate;
-(void)removeDelegate:(id<NIMSDKChatroomDelegate>)delegate;

-(BOOL)RequestTokenWithRoomID:(NSInteger)roomID result:(ChatroomRequestTokenResult)block;

-(BOOL)EnterWithRoomID:(NSInteger)roomID token:(NSString*)token  enterInfo:(NIMSDKChatRoomEnterInfo*)info;

-(BOOL)ExitWithRoomID:(NSInteger)roomID;

@end

NS_ASSUME_NONNULL_END
