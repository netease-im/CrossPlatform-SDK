//
//  LoginView.h
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LoginViewDetegate <NSObject>

@optional
-(void)loginClicked;

@end

@interface LoginView : UIControl

@property (nonatomic,weak) id<LoginViewDetegate> delegate;

@property (nonatomic,strong) NSString* account;
@property (nonatomic,strong) NSString* token;

@property (nonatomic,strong) UIButton *loginButton;

@property (nonatomic,strong) UITextField *accountTextField;
@property (nonatomic,strong) UITextField *passwordTextField;
@end

NS_ASSUME_NONNULL_END
