//
//  LoginViewController.m
//  Samples Mac
//
//  Created by dudu on 2019/12/9.
//

#import "NIMLoginViewController.h"
#import <AppKit/AppKit.h>
#import "NIMLoginView.h"


#define MAS_SHORTHAND
#import "Masonry.h"

#import "NIMSDK.h"
#import "NSString+ext.h"
#import "NIMLoginManager.h"
#import "CurrentUser.h"
#import "NIMAppUtils.h"

@interface LoginViewController ()<LoginViewDetegate>
@property (nonatomic,strong)LoginView* loginView;
@end

@implementation LoginViewController

-(instancetype)initWithNibName:(NSNibName)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    if (self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]) {
        [self loadView];
        [self setup];
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}

-(void)loadView
{
    if (_loginView == nil) {
        
        _loginView = [[LoginView alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
        _loginView.delegate = self;
        [self setView:_loginView];
    }
}

-(void)setup
{
    NIMLoginData* loginData = [NIMLoginManager sharedManager].currentLoginData;
    if (loginData) {
        _loginView.account = loginData.account;
        _loginView.token = loginData.token;
    }
}

-(void)loginClicked
{
    if (![_loginView.account length] || ! [_loginView.token length]) {
           NSLog(@"帐号或密码不能为空");
           return;
       }
    
       NSString *appKey = [NIMSDK shared].appKey;
    [[NSApplication sharedApplication].mainWindow setIgnoresMouseEvents:YES];
       [[NIMSDK shared].loginService loginWithAccount:_loginView.account token:[_loginView.token md5] Appkey:appKey result:^(NIMSDKLoginRessult * _Nullable result) {
                  
           NIMSDKResCode res_code = result.resCode;
           NIMSDKLoginStep login_step = result.loginStep;
           
           if (res_code != NIMSDKResSuccess || login_step == NIMSDKLoginStepLogin) {
               [[NSApplication sharedApplication].mainWindow setIgnoresMouseEvents:NO];
           }
           if (res_code == NIMSDKResSuccess && login_step == NIMSDKLoginStepLogin) {
               //登录成功保存数据
               [[CurrentUser shared] setAccout:self.loginView.account];
                [[CurrentUser shared] setPassword:self.loginView.token];
               NIMLoginData* loginData = [[NIMLoginData alloc] init];
               loginData.account = [CurrentUser shared].accout;
               loginData.token = [CurrentUser shared].password;
               
               [[NIMLoginManager sharedManager] setCurrentLoginData:loginData];
               
               [AppUtils setupRooterViewController:YES];
           }
       }];
}

@end
