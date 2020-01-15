//
//  SessionView.h
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SessionViewDetegate <NSObject>

@optional

-(void)onClicked:(NSInteger)tag;

@end

@interface SessionView : UIControl

@property (nonatomic,weak) id<SessionViewDetegate> delegate;
@end

NS_ASSUME_NONNULL_END
