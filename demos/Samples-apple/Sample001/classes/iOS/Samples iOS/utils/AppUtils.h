//
//  AppUtils.h
//  Samples iOS
//
//  Created by dudu on 2019/11/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AppUtils : NSObject

+(void)setupRooterViewController:(BOOL)mainViewController;
+(NSString*)parseDeviceToken:(NSData*)deviceToken;
+(void)registerForRemoteNotifications;
+(void)unregisterForRemoteNotifications;
@end

NS_ASSUME_NONNULL_END
