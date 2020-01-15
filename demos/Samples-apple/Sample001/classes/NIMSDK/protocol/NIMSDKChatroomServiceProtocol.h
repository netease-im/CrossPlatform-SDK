//
//  NIMSDKChatroomServiceProtocol.h
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import "NIMSDKServiceProtocol.h"
#import "NIMSDKChatroomModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^ChatroomRequestTokenResult)(NIMSDKResCode code,NSInteger roomID,NSString* _Nullable token);

@protocol NIMSDKChatroomDelegate <NSObject>

@optional

-(void)onChatroomEnter:(NIMSDKChatRoomEnterResult*)result;

-(void)onChatroomExit:(NIMSDKChatRoomExitResult*)result;

@end

@protocol NIMSDKChatroomServiceProtocol <NIMSDKServiceProtocol>

-(void)addDelegate:(id<NIMSDKChatroomDelegate>)delegate;
-(void)removeDelegate:(id<NIMSDKChatroomDelegate>)delegate;


-(void)RequestTokenWithRoomID:(NSInteger)roomID result:(ChatroomRequestTokenResult)block;

-(BOOL)EnterWithRoomID:(NSInteger)roomID token:(NSString*)token  enterInfo:(NIMSDKChatRoomEnterInfo*)info;

-(void)ExitWithRoomID:(NSInteger)roomID;

@end

NS_ASSUME_NONNULL_END
