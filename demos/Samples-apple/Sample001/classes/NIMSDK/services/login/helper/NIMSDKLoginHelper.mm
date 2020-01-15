//
//  NIMSDKLoginHelper.m
//  Samples iOS
//
//  Created by dudu on 2019/11/21.
//

#import "NIMSDKLoginHelper.h"


#ifdef __cplusplus
extern "C" {
#endif

NIMSDKOtherClientPres* convertNIMSDKOtherClientPres(nim::OtherClientPres& other_client_pres)
{
    NIMSDKOtherClientPres *client = [[NIMSDKOtherClientPres alloc] init];
    client.appAccount = [NSString stringWithUTF8String:other_client_pres.app_account_.c_str()];
    client.clientType = (NIMSDKClientType)other_client_pres.client_type_;
    client.clientOS = [NSString stringWithUTF8String:other_client_pres.client_os_.c_str()];

    client.deviceID = [NSString stringWithUTF8String:other_client_pres.device_id_.c_str()];
    client.macAddress = [NSString stringWithUTF8String:other_client_pres.mac_address_.c_str()];
    client.loginTimetag =  other_client_pres.login_time_;
    client.customData = [NSString stringWithUTF8String:other_client_pres.custom_data_.c_str()];
    
    return client;
}
    
#ifdef __cplusplus
}
#endif
