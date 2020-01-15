//
//  NIMSDKLoginManager.m
//  Samples iOS
//
//  Created by dudu on 2019/11/20.
//

#import "NIMSDKLoginManager.h"
#import "NSString+ext.h"
#import "NIMDispatch.h"
#import "NIMSDKLoginHelper.h"

#import "nim_cpp_client.h"
#import "nim_cpp_user.h"

@interface NIMSDKLoginManager ()
{
    nim::SDKConfig _sdkConfig;
}
@end

@implementation NIMSDKLoginManager

#pragma mark - init

-(instancetype)init
{
    if (self = [super init]) {
    }
    return self;
}

-(void)dealloc
{
    NSLog(@"%s",__func__);
}

#pragma mark - setup
-(BOOL)setup:(NSString *)appkey appDataPath:(NSString *)appDataPath sdkConfig :(NSString *)config
{
    [self setup];
    NSLog(@"%s",__func__);
    bool init = nim::Client::Init([appkey UTF8String], [appDataPath UTF8String], "", _sdkConfig);
    
//    NIMLoginResultBlock block = ^(NSDictionary* _Nullable result){
//        NSLog(@"block");
//    };
//
//     __weak typeof(self) weakSelf = self;
//    //void* cf_self = (__bridge void*)weakSelf;
//    auto cb = [weakSelf,block]()
//    {
//        @autoreleasepool {
//            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//
//                //NIMSDKLoginManager* service = (__bridge NIMSDKLoginManager*)cf_self;
//                [weakSelf cleanup];
//
//                block(nil);
//            });
//        }
//
//    };
//    cb();
    
    NSLog(@"%s - nim::Client::Init %@",__func__,init ? @"successed" : @"failed");
    return init;
}
-(void)setup
{
    NSLog(@"%s",__func__);
}
-(void)cleanup
{
    NSLog(@"%s",__func__);
    nim::Client::Cleanup2();
}

#pragma mark - register callbacks

#pragma mark - login
-(BOOL)loginWithAccount:(NSString *)account token:(NSString *)token Appkey:(NSString *)appkey result:(NIMLoginResultBlock)block
{
    if ([NSString isEmptyOrNull:account] || [NSString isEmptyOrNull:token] || [NSString isEmptyOrNull:appkey]) {
        return false;
    }
    __weak typeof(self) weakSelf = self;
    auto callback = [weakSelf,block](const nim::LoginRes& res)
    {
        @autoreleasepool {
            __strong typeof(weakSelf) strongSelf = weakSelf;
            nim_main_sync(^{

                NIMSDKLoginRessult *result = [[NIMSDKLoginRessult alloc] init];
                result.resCode = (NIMSDKResCode)res.res_code_;
                result.loginStep = (NIMSDKLoginStep)res.login_step_;
                result.relogin = res.relogin_;
                result.retrying = res.retrying_;
                
                if (res.other_clients_.size() > 0) {
                    NSMutableArray *clients = [[NSMutableArray alloc] init];
                    for (nim::OtherClientPres c : res.other_clients_) {

                        NIMSDKOtherClientPres *client = convertNIMSDKOtherClientPres(c);
                        [clients addObject:client];
                    }
                    
                    result.otherClients = clients;
                }
                
                block(result);
            });
        }
        
    };
    bool ret = nim::Client::Login([appkey UTF8String], [account UTF8String], [token UTF8String], callback);
    return ret;
}

-(void)updatePushToken:(NSString*)deviceToken withCerName:(nullable NSString*)cerName;
{
    if (deviceToken == nil) {
        NSLog(@"ERROR : deviceToken is nil!!");
        return;
    }
    
    NSString *token = [deviceToken stringByReplacingOccurrencesOfString:@"-" withString:@""];
    
    std::string cer_name = [NSString isEmptyOrNull: cerName]? "" : [cerName UTF8String];
    nim::User::UpdatePushToken(cer_name, [token UTF8String], 0);
    
}

-(BOOL)logout:(NIMSDKLogoutType)type result:(nullable NIMLogoutBlock)block
{
      __weak typeof(self) weakSelf = self;
      auto callback = [weakSelf,block](nim::NIMResCode res_code)
      {
          @autoreleasepool {
              __strong typeof(weakSelf) strongSelf = weakSelf;
              nim_main_sync(^{
                  block((NIMSDKResCode)res_code);
              });
          }          
      };
      nim::Client::Logout((nim::NIMLogoutType)type, callback);
      return YES;
}

@end
