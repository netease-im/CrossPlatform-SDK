//
//  SettingViewController.m
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import "SettingViewController.h"
#import "SettingView.h"
#import "SVProgressHUD.h"
#import "UIView+Toast.h"
#import "NIMSDK.h"
#import "AppUtils.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface SettingViewController ()<SettingViewDetegate>
@property (nonatomic,strong)SettingView* settingView;
@end

@implementation SettingViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self setupSubviews];
    [self layoutSubviews];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

-(void)setupSubviews
{
    _settingView = [[SettingView alloc] initWithFrame:self.view.bounds];
    _settingView.delegate = self;
    [self.view addSubview:_settingView];
}

-(void)layoutSubviews
{
    [_settingView makeConstraints:^(MASConstraintMaker *make) {
        make.size.equalTo(self.view);
        make.centerX.equalTo(self.view);
        make.centerY.equalTo(self.view);
    }];
}

#pragma mark - setting view protocol
-(void)logoutClicked
{
    [SVProgressHUD showWithStatus:@"正在注销..."];
    [[NIMSDK shared].loginService logout:NIMSDKLogoutChangeAccout result:^(NIMSDKResCode result) {
        [SVProgressHUD dismiss];
        if (result == NIMSDKResSuccess) {
            
            [AppUtils setupRooterViewController:NO];
        }
        else
        {
            [[[UIApplication sharedApplication].delegate window].rootViewController.view makeToast:[NSString stringWithFormat:@"注销失败，错误码:%ld",result] duration:2.0 position:CSToastPositionCenter];
        }
    }];
    
}

@end
