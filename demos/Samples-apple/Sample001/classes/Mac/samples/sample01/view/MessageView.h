//
//  MessageView.h
//  Samples Mac
//
//  Created by dudu on 2019/12/13.
//

#import <Cocoa/Cocoa.h>
#import "NIMSDKTalkModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MessageViewDelegate <NSObject>

@optional
-(void)onSendClicked;

@end

@protocol MessageViewProtocol <NSObject>

@optional
-(void)updateReceivedMsg:(NSString*)msg;

@end

@interface MessageView : NSView<MessageViewProtocol>

@property(nonatomic,weak) id<MessageViewDelegate> messageDelegate;
@end

NS_ASSUME_NONNULL_END
