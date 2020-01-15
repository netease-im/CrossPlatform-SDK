//
//  SettingView.h
//  Samples iOS
//
//  Created by dudu on 2019/11/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SettingViewDetegate <NSObject>

@optional

-(void)logoutClicked;

@end

@interface SettingView : UIControl

@property (nonatomic,weak) id<SettingViewDetegate> delegate;

@property (nonatomic,strong)UIButton* logoutButton;

@end

NS_ASSUME_NONNULL_END
