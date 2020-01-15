//
//  NIMSDKServiceProtocol.h
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NIMSDKServiceProtocol <NSObject>

@optional

-(void)setup;
-(void)cleanup;

@end

NS_ASSUME_NONNULL_END
