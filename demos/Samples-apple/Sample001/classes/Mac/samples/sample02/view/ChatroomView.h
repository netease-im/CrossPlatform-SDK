//
//  ChatroomView.h
//  Samples Mac
//
//  Created by dudu on 2020/1/6.
//

#import <Cocoa/Cocoa.h>
#import "NESample02Protocol.h"
#import "NESample02Delegate.h"

NS_ASSUME_NONNULL_BEGIN


@interface ChatroomView : NSView<NESample02Protocol>

@property (nonatomic,weak) id<NESample02Delegate> sample02Delegate;

@end

NS_ASSUME_NONNULL_END
