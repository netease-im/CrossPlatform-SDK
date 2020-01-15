//
//  NIMSDKChatroomImpl+callbacks.h
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import "NIMSDKChatroomImpl.h"
#import "NIMSDKChatroomModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface NIMSDKChatroomImpl (callbacks)
-(void)setupCallbacks;
-(void)cleanupCallbacks;

-(void)notifyEnter:(NIMSDKChatRoomEnterResult*)result;

-(void)notifyExit:(NIMSDKChatRoomExitResult*)result;

@end

NS_ASSUME_NONNULL_END
