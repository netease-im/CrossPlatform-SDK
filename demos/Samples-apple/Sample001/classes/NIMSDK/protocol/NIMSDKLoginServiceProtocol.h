//
//  NIMSDKLoginProtocol.h
//  Samples iOS
//
//  Created by dudu on 2019/11/20.
//

#import <Foundation/Foundation.h>
#import "NIMSDKClientModel.h"
#import "NIMSDKServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^NIMLoginResultBlock)(NIMSDKLoginRessult* _Nullable result);
typedef void(^NIMLogoutBlock)(NIMSDKResCode result);

@protocol NIMSDKLoginServiceProtocol <NIMSDKServiceProtocol>

-(BOOL)setup:(NSString*)appkey appDataPath:(NSString*)appDataPath sdkConfig:(nullable NSString*)config;

-(BOOL)loginWithAccount:(NSString*)account token:(NSString*)token Appkey:(NSString*)appkey result:(nullable NIMLoginResultBlock)block;


-(void)updatePushToken:(NSString*)deviceToken withCerName:(nullable NSString*)cerName;

-(BOOL)logout:(NIMSDKLogoutType)type result:(nullable NIMLogoutBlock)block;
@end

NS_ASSUME_NONNULL_END
