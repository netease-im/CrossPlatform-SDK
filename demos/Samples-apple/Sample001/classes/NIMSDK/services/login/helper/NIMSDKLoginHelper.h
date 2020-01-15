//
//  NIMSDKLoginHelper.h
//  Samples
//
//  Created by dudu on 2019/11/21.
//

#ifndef NIMSDKLoginHelper_h
#define NIMSDKLoginHelper_h


#import <Foundation/Foundation.h>
#import "NIMSDKClientModel.h"
#import "nim_cpp_client.h"

#ifdef __cplusplus
extern "C" {
#endif

NIMSDKOtherClientPres* convertNIMSDKOtherClientPres(nim::OtherClientPres& other_client_pres);

#ifdef __cplusplus
}
#endif

#endif /* NIMSDKLoginHelper_h */
