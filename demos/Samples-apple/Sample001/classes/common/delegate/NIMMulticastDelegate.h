//
//  NIMMulticastDelegate.h
//  NIM
//
//  Created by dudu on 2018/9/14.
//

#import <Foundation/Foundation.h>

@interface NIMMulticastDelegate : NSObject
- (void)addDelegate:(id)delegate;
- (void)removeDelegate:(id)delegate;
- (void)removeAllDelegates;

- (NSUInteger)count;
- (NSUInteger)countForSelector:(SEL)aSelector;
- (BOOL)hasDelegateThatRespondsToSelector:(SEL)aSelector;
@end
