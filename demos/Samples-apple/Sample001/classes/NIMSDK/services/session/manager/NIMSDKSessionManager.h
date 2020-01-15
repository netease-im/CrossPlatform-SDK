//
//  NIMSDKSessionManager.h
//  Samples iOS
//
//  Created by dudu on 2019/11/26.
//

#import <Foundation/Foundation.h>
#import "NIMSDKSessionServiceProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface NIMSDKSessionManager : NSObject<NIMSDKSessionServiceProtocol>

-(void)setup;
-(void)cleanup;
@end

NS_ASSUME_NONNULL_END
