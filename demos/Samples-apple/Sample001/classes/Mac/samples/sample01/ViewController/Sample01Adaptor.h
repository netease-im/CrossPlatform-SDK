//
//  Sample01Adaptor.h
//  Samples Mac
//
//  Created by dudu on 2019/12/13.
//

#import <Foundation/Foundation.h>
#import "MessageView.h"

NS_ASSUME_NONNULL_BEGIN

@interface Sample01Adaptor : NSObject<MessageViewDelegate>
@property(nonatomic,weak)id<MessageViewProtocol> mv;
@end

NS_ASSUME_NONNULL_END
