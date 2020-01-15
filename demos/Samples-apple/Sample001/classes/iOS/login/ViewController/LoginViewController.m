//
//  LoginViewController.m
//  Sample01
//
//  Created by dudu on 2019/11/11.
//

#import "LoginViewController.h"
#import "NIMDispatch.h"
#import "SVProgressHUD.h"
#import "UIView+Toast.h"
#import "LoginView.h"
#import "NIMLoginManager.h"
#import "CurrentUser.h"
#import "NIMMainTabBarController.h"
#import "NIMSDK.h"
#import "NSDictionary+ext.h"
#import "NSString+ext.h"
#import "AppUtils.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface LoginViewController ()<UITextFieldDelegate,LoginViewDetegate>
@property (nonatomic,strong) LoginView* subview;
@end

@implementation LoginViewController

- (void)viewDidLoad {
    [super viewDidLoad];
//    // Do any additional setup after loading the view from its nib.
    
    
    [self setupSubviews];
    [self layoutSubviews];
    [self setup];
}
-(void)viewWillLayoutSubviews
{
    [self layoutSubviews];
}

#pragma mark -
-(void)setup
{
    NIMLoginData* loginData = [NIMLoginManager sharedManager].currentLoginData;
    if (loginData) {
        _subview.account = loginData.account;
        _subview.token = loginData.token;
    }
    
}
-(void)setupSubviews
{
    
    _subview = [[LoginView alloc] initWithFrame:self.view.bounds];
    [_subview setDelegate:self];
    [self.view addSubview:_subview];
    
}

-(void)layoutSubviews
{
    [_subview makeConstraints:^(MASConstraintMaker *make) {
        make.size.equalTo(self.view);
        make.centerX.equalTo(self.view);
        make.centerY.equalTo(self.view);
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

#pragma mark - login view delegate
-(void)loginClicked
{
    if (![_subview.account length] || ! [_subview.token length]) {
        [self.view makeToast:@"帐号或密码不能为空"];
        return;
    }
    [SVProgressHUD setDefaultMaskType:SVProgressHUDMaskTypeBlack];
    [SVProgressHUD show];
    
    NSString *appKey = [NIMSDK shared].appKey;
    [[NIMSDK shared].loginService loginWithAccount:_subview.account token:[_subview.token md5] Appkey:appKey result:^(NIMSDKLoginRessult * _Nullable result) {
               
        NIMSDKResCode res_code = result.resCode;
        NIMSDKLoginStep login_step = result.loginStep;
        
        if (res_code != NIMSDKResSuccess || login_step == NIMSDKLoginStepLogin) {
            [SVProgressHUD dismiss];
        }
        if (res_code == NIMSDKResSuccess && login_step == NIMSDKLoginStepLogin) {
            //登录成功保存数据
            [[CurrentUser shared] setAccout:self.subview.account];
             [[CurrentUser shared] setPassword:self.subview.token];
            NIMLoginData* loginData = [[NIMLoginData alloc] init];
            loginData.account = [CurrentUser shared].accout;
            loginData.token = [CurrentUser shared].password;
            
            [[NIMLoginManager sharedManager] setCurrentLoginData:loginData];
            
            [AppUtils setupRooterViewController:YES];
        }
    }];
    
}
@end
