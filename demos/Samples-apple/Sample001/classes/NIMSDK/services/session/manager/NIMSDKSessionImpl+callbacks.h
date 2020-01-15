//
//  NIMSDKSessionImpl+callbacks.h
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//


#import "NIMSDKSessionImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface NIMSDKSessionImpl (callbacks)

-(void)setupCallbacks;
-(void)cleanupCallbacks;
-(void)notifySendMessageResult:(NIMSDKSendMessageResult*)result;
-(void)notifyReceivedMessages:(NSArray*)messages;
@end

NS_ASSUME_NONNULL_END
