//
//  NIMLoginView.h
//  Samples Mac
//
//  Created by dudu on 2019/12/10.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LoginViewDetegate <NSObject>

@optional
-(void)loginClicked;

@end

@interface LoginView : NSView
@property (nonatomic,weak) id<LoginViewDetegate> delegate;

@property (nonatomic,strong) NSString* account;
@property (nonatomic,strong) NSString* token;

@property (nonatomic,strong) NSButton *loginButton;

@property (nonatomic,strong) NSTextField *accountTextField;
@property (nonatomic,strong) NSTextField *passwordTextField;
@end

NS_ASSUME_NONNULL_END
