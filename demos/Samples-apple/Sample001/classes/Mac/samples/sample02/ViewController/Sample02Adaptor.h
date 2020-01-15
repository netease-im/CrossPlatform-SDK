//
//  Sample02Adaptor.h
//  Samples Mac
//
//  Created by dudu on 2020/1/6.
//

#import <Foundation/Foundation.h>
#import "NESample02Delegate.h"
#import "NESample02Protocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface Sample02Adaptor : NSObject<NESample02Delegate>

@property(nonatomic,weak)id<NESample02Protocol> delegate;

@end

NS_ASSUME_NONNULL_END
