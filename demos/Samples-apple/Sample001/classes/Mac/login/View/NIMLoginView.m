//
//  NIMLoginView.m
//  Samples Mac
//
//  Created by dudu on 2019/12/10.
//

#import "NIMLoginView.h"
#import "NIMDispatch.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface LoginView ()<NSTextFieldDelegate>

@end

@implementation LoginView

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}
-(instancetype)init
{
    if (self = [super init] ) {
        [self setupSubviews];
        [self layoutSubviews];
    }
    return self;
}
-(instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame] ) {
        [self setupSubviews];
        [self layoutSubviews];
    }
    
    return self;
}
-(void)setupSubviews
{
    [self.layer setBackgroundColor:[NSColor whiteColor].CGColor];
    //_loginButton = [NSButton buttonWithTitle:@"登录" target:self action:@selector(OnClicked:)];
    _loginButton = [[NSButton alloc] initWithFrame:NSMakeRect(40, 200, 240, 60)];
    [_loginButton setBezelStyle:NSBezelStyleRegularSquare];
    [_loginButton setTitle:@"登录"];
    [_loginButton setTarget:self];
    [_loginButton setAction:@selector(OnClicked:)];
    _loginButton.frame = CGRectMake(40, 200, 240, 60);
    
    _loginButton.layer.backgroundColor = [NSColor redColor].CGColor;
    
    [self addSubview:_loginButton];
    
    _accountTextField = [[NSTextField alloc] initWithFrame:CGRectMake(0, 0,200,100)];
    _accountTextField.focusRingType = NSFocusRingTypeNone;
    [_accountTextField setPlaceholderString:@"账号"];
    _accountTextField.bezelStyle = NSTextFieldRoundedBezel;
    _accountTextField.delegate = self;
    [self addSubview:_accountTextField];
    
    
    _passwordTextField = [[NSTextField alloc] initWithFrame:CGRectMake(0, 0,200,100)];
    _passwordTextField.focusRingType = NSFocusRingTypeNone;
    [_passwordTextField setPlaceholderString:@"密码"];
    _passwordTextField.bezelStyle = NSTextFieldRoundedBezel;
    //_passwordTextField.keyboardType = UIKeyboardTypeNumbersAndPunctuation;
    _passwordTextField.delegate = self;
    [self addSubview:_passwordTextField];
    
   // [_subview addTarget:self action:@selector(subviewTouchUpInside:) forControlEvents:UIControlEventTouchUpInside];
    
//    UITapGestureRecognizer *recognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(touchView:)];
//    [recognizer setNumberOfTapsRequired:1];
//    [recognizer setNumberOfTouchesRequired:1];
//    [self addGestureRecognizer:recognizer];
    
}

-(void)layoutSubviews
{
    [self makeConstraints:^(MASConstraintMaker *make) {
        make.size.equalTo(self);
        make.centerX.equalTo(self);
        make.centerY.equalTo(self);
    }];
    [_accountTextField makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.centerX);
        make.left.mas_greaterThanOrEqualTo(self).offset(100);
        make.right.mas_greaterThanOrEqualTo(self).offset(100);
        make.height.equalTo(@(60));
        make.bottom.equalTo(self.centerY).offset(-100);
        make.width.lessThanOrEqualTo(@(600));
    }];
    
    
    [_passwordTextField makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.centerX);
        make.left.mas_equalTo(self.accountTextField);
        make.right.mas_equalTo(self.accountTextField);
        make.height.equalTo(self.accountTextField);
        make.top.mas_equalTo(self.accountTextField.bottom).offset(40);
        
    }];
    
    
    [_loginButton makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.centerX);
        make.size.mas_equalTo(CGSizeMake(160, 80));
        make.top.greaterThanOrEqualTo(self.passwordTextField.bottom).offset(50);
        //make.bottom.greaterThanOrEqualTo(self.view.bottom).offset(-50);
    }];
    
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
#pragma mark - hidden keyboard
-(void)hiddenKeyBoard
{
    [_accountTextField resignFirstResponder];
    [_passwordTextField resignFirstResponder];
}

-(void)OnClicked:(NSButton*)button
{
    [self hiddenKeyBoard];
    if ([_delegate respondsToSelector:@selector(loginClicked)]) {
        [_delegate performSelector:@selector(loginClicked)];
    }
}

-(void)setAccount:(NSString *)account
{
    //_account = account;
    [_accountTextField setStringValue:account];
}

-(void)setToken:(NSString *)token
{
    //_token = token;
    [_passwordTextField setStringValue:token];
}

-(NSString *)account
{
    
    return _accountTextField ? _accountTextField.stringValue : nil;
}

-(NSString *)token
{
    return _passwordTextField ? _passwordTextField.stringValue : nil;
    
}

//#pragma mark - UITextFieldDelegate
//
//
//
//-(BOOL)textFieldShouldReturn:(UITextField *)textField
//{
//    [textField resignFirstResponder];
//    return YES;
//}
//
//#pragma view touch
//- (void)touchView:(UIGestureRecognizer *)gest{
//    [self hiddenKeyBoard];
//}

@end
