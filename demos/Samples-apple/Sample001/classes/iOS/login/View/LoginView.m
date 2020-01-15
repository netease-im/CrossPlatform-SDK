//
//  LoginView.m
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import "LoginView.h"
#import "NIMDispatch.h"
#import "SVProgressHUD.h"
#import "UIView+Toast.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface LoginView() <UITextFieldDelegate>

@end

@implementation LoginView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
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
    [self setBackgroundColor:[UIColor whiteColor]];
        
    _loginButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _loginButton.frame = CGRectMake(40, 200, 240, 60);
    [_loginButton setTitle:@"登录" forState:UIControlStateNormal];
    [_loginButton addTarget:self action:@selector(OnClicked:) forControlEvents:UIControlEventTouchUpInside];
    
    _loginButton.backgroundColor = [UIColor redColor];
    [_loginButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    
    //self.view.backgroundColor = [UIColor redColor];
    [self addSubview:_loginButton];
    
    _accountTextField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0,200,100)];
    _accountTextField.borderStyle = UITextBorderStyleRoundedRect;
    [_accountTextField setPlaceholder:@"账号"];
    _accountTextField.keyboardType = UIKeyboardTypeASCIICapable;
    _accountTextField.delegate = self;
    [self addSubview:_accountTextField];
    
    _accountTextField.borderStyle = UITextBorderStyleRoundedRect;
    
    _passwordTextField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0,200,100)];
    _passwordTextField.borderStyle = UITextBorderStyleRoundedRect;
    [_passwordTextField setPlaceholder:@"密码"];
    _passwordTextField.keyboardType = UIKeyboardTypeNumbersAndPunctuation;
    _passwordTextField.delegate = self;
    [self addSubview:_passwordTextField];
    
   // [_subview addTarget:self action:@selector(subviewTouchUpInside:) forControlEvents:UIControlEventTouchUpInside];
    
    UITapGestureRecognizer *recognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(touchView:)];
    [recognizer setNumberOfTapsRequired:1];
    [recognizer setNumberOfTouchesRequired:1];
    [self addGestureRecognizer:recognizer];
    
}

-(void)layoutSubviews
{
    [_accountTextField makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.equalTo(self.centerX);
        make.left.greaterThanOrEqualTo(self).offset(100);
        make.right.greaterThanOrEqualTo(self).offset(-100);
        make.height.equalTo(@(60));
        make.bottom.equalTo(self.centerY).offset(-100);
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

-(void)OnClicked:(UIButton*)button
{
    [self hiddenKeyBoard];
    if ([_delegate respondsToSelector:@selector(loginClicked)]) {
        [_delegate performSelector:@selector(loginClicked)];
    }
}

-(void)setAccount:(NSString *)account
{
    //_account = account;
    [_accountTextField setText:account];
}

-(void)setToken:(NSString *)token
{
    //_token = token;
    [_passwordTextField setText:token];
}

-(NSString *)account
{
    
    return _accountTextField ? _accountTextField.text : nil;
}

-(NSString *)token
{
    return _passwordTextField ? _passwordTextField.text : nil;
    
}

#pragma mark - UITextFieldDelegate

-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

#pragma view touch
- (void)touchView:(UIGestureRecognizer *)gest{
    [self hiddenKeyBoard];
}
@end
