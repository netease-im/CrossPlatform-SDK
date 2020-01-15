//
//  NIMMainTabBarController.m
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import "NIMMainTabBarController.h"

typedef NS_ENUM(NSInteger,NIMMainTabType)
{
    NIMMainTabTypeSession,
    NIMMainTabTypeSetting,
    NIMMainTabTypeMax
};

#define TabbarVC    @"vc"
#define TabbarTitle @"title"
#define TabbarImage @"image"
#define TabbarSelectedImage @"selectedImage"

@interface NIMMainTabBarController ()
@property (nonatomic,copy)  NSDictionary *configs;
@end

@implementation NIMMainTabBarController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self setup];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)viewWillAppear:(BOOL)animated{
    [super viewWillAppear:animated];
    [self setUpStatusBar];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    //会话界面发送拍摄的视频，拍摄结束后点击发送后可能顶部会有红条，导致的界面错位。
    self.view.frame = [UIScreen mainScreen].bounds;
}


#pragma mark - setup
-(void)setup
{
    [self setupNav];
    
}

-(void)setupNav
{
    NSMutableArray *vcArray = [[NSMutableArray alloc] init];
    [self.tabbars enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSDictionary *dict = [self vcInfoByTabType:[obj integerValue]];
        NSString *vcName = dict[TabbarVC];
        NSString *title = dict[TabbarTitle];
        NSString *imageNormal = dict[TabbarImage];
        NSString *imageSelected = dict[TabbarSelectedImage];
        
        Class clazz = NSClassFromString(vcName);
        UIViewController *vc = [[clazz alloc] initWithNibName:nil bundle:nil];
        vc.hidesBottomBarWhenPushed = NO;

        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
        nav.tabBarItem = [[UITabBarItem alloc] initWithTitle:title
                                                       image:[UIImage imageNamed:imageNormal]
                                               selectedImage:[UIImage imageNamed:imageSelected]];
        nav.tabBarItem.tag = idx;
        [vcArray addObject:nav];
    }];
    
    self.viewControllers = vcArray;
}

-(NSArray*)tabbars
{
    NSMutableArray* array = [[NSMutableArray alloc] init];
    for (NSInteger i = 0; i < NIMMainTabTypeMax; i++) {
        [array addObject:@(i)];
    }
    return array;
}

-(NSDictionary*)vcInfoByTabType:(NIMMainTabType)type
{
    if (_configs == nil)
    {
        _configs = @{
                     @(NIMMainTabTypeSession) : @{
                             TabbarVC           : @"SessionViewController",
                             TabbarTitle        : @"会话",
                             TabbarImage        : @"tool_message_n",
                             TabbarSelectedImage: @"tool_message_selected_n"
                             },
                     @(NIMMainTabTypeSetting)     : @{
                             TabbarVC           : @"SettingViewController",
                             TabbarTitle        : @"设置",
                             TabbarImage        : @"tool_me_n",
                             TabbarSelectedImage: @"tool_me_selected_n"
                             
                     }
            };

    }
    return _configs[@(type)];
    
}

- (void)setUpStatusBar{
    UIStatusBarStyle style = UIStatusBarStyleDefault;
    [[UIApplication sharedApplication] setStatusBarStyle:style
                                                animated:NO];
}
@end
