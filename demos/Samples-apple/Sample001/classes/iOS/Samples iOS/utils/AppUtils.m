//
//  AppUtils.m
//  Samples iOS
//
//  Created by dudu on 2019/11/26.
//

#import "AppUtils.h"
#import "LoginViewController.h"
#import "NIMMainTabBarController.h"
#import <UserNotifications/UserNotifications.h>

@implementation AppUtils

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
+(void)setupRooterViewController:(BOOL)mainViewController
{
    if (mainViewController) {
         [[UIApplication sharedApplication].delegate window].rootViewController = [[NIMMainTabBarController alloc] initWithNibName:nil bundle:nil];
    }
    else
    {
        LoginViewController *loginController = [[LoginViewController alloc] init];
        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:loginController];
        nav.navigationBar.translucent = YES;
        nav.navigationBarHidden = YES;
        [[UIApplication sharedApplication].delegate window].rootViewController = nav;
        
    }
}

+(NSString*)parseDeviceToken:(NSData*)deviceToken
{
  const unsigned *tokenBytes = [deviceToken bytes];
    NSString *token = [NSString stringWithFormat:@"%08x%08x%08x%08x%08x%08x%08x%08x",
                         ntohl(tokenBytes[0]), ntohl(tokenBytes[1]), ntohl(tokenBytes[2]),
                         ntohl(tokenBytes[3]), ntohl(tokenBytes[4]), ntohl(tokenBytes[5]),
                         ntohl(tokenBytes[6]), ntohl(tokenBytes[7])];
    
    return token;
    
}

+(void)registerForRemoteNotifications
{
    
    UIApplication *application = [UIApplication sharedApplication];
    CGFloat sysVersion = [[UIDevice currentDevice].systemVersion floatValue];
    if (sysVersion >= 10.0) {
        //iOS10特有
        if (@available(iOS 10.0, *)) {
            UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
            //center.delegate = delagate;
            [center requestAuthorizationWithOptions:(UNAuthorizationOptionAlert | UNAuthorizationOptionBadge | UNAuthorizationOptionSound) completionHandler:^(BOOL granted, NSError * _Nullable error) {
                if (granted) {
                    NSLog(@"remote notification 注册成功");
                    [center getNotificationSettingsWithCompletionHandler:^(UNNotificationSettings * _Nonnull settings) {
                        NSLog(@"%@", settings);
                    }];
                } else {
                    NSLog(@"注册失败");
                }
            }];
        }
    } else if (sysVersion > 8.0){
        //iOS8 - iOS10
        [application registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeSound | UIUserNotificationTypeBadge categories:nil]];
    } else {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
        //iOS8系统以下
        [application registerForRemoteNotificationTypes:UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound];
#pragma clang diagnostic pop
    }
    [[UIApplication sharedApplication] registerForRemoteNotifications];
}

+(void)unregisterForRemoteNotifications
{
    [[UIApplication sharedApplication] unregisterForRemoteNotifications];
}
@end
