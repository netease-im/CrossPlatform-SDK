//
//  NIMMulticastDelegate.m
//  NIMKit
//
//  Created by amao on 5/20/14.
//  Copyright (c) 2014 amao. All rights reserved.
//

#import "NIMMulticastDelegate.h"

@interface NIMDelegateNode : NSObject
@property (nonatomic,weak)  id  nodeDelegate;
+ (NIMDelegateNode *)node:(id)delegate;
@end

@implementation NIMDelegateNode
+ (NIMDelegateNode *)node:(id)delegate
{
    NIMDelegateNode *instance = [[NIMDelegateNode alloc] init];
    instance.nodeDelegate = delegate;
    return instance;
}
@end


@interface NIMMulticastDelegate ()
{
    NSMutableArray *_delegateNodes;
}

@end

@implementation NIMMulticastDelegate

- (id)init
{
    if (self = [super init])
    {
        _delegateNodes = [[NSMutableArray alloc] init];
    }
    return self;
}

- (void)dealloc {}

#pragma mark - Delegate增/删
- (void)addDelegate:(id)delegate
{
    [self removeDelegate:delegate];
    NIMDelegateNode *node = [NIMDelegateNode node:delegate];
    [_delegateNodes addObject:node];
}

- (void)removeDelegate:(id)delegate
{
    NSMutableIndexSet *indexs = [NSMutableIndexSet indexSet];
    for (NSUInteger i = 0; i < [_delegateNodes count]; i ++)
    {
        NIMDelegateNode *node = [_delegateNodes objectAtIndex:i];
        if (node.nodeDelegate == delegate)
        {
            [indexs addIndex:i];
        }
    }
    
    if ([indexs count])
    {
        [_delegateNodes removeObjectsAtIndexes:indexs];
    }
}

- (void)removeAllDelegates
{
    [_delegateNodes removeAllObjects];
}

#pragma mark - Selector相关方法
- (NSUInteger)count
{
    return [_delegateNodes count];
}

- (NSUInteger)countForSelector:(SEL)aSelector
{
    NSUInteger count = 0;
    for (NIMDelegateNode *node in _delegateNodes)
    {
        if ([node.nodeDelegate respondsToSelector:aSelector])
        {
            count++;
        }
    }
    return count;
}

- (BOOL)hasDelegateThatRespondsToSelector:(SEL)aSelector
{
    BOOL hasSelector = NO;
    for (NIMDelegateNode *node in _delegateNodes)
    {
        if ([node.nodeDelegate respondsToSelector:aSelector])
        {
            hasSelector = YES;
            break;
        }
    }
    return hasSelector;
}


#pragma mark - 消息转发
- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector
{
	for (NIMDelegateNode *node in _delegateNodes)
	{
		NSMethodSignature *method = [node.nodeDelegate methodSignatureForSelector:aSelector];
        if (method)
        {
            return method;
        }
	}
	//如果发现没有可以响应当前方法的Node,就返回一个空方法
    //否则会引起崩溃
	return [[self class] instanceMethodSignatureForSelector:@selector(doNothing)];
}

- (void)forwardInvocation:(NSInvocation *)invocation
{
    SEL selector = [invocation selector];
    BOOL hasNilDelegate = NO;
    NSMutableArray *invokeDelegates = [[NSMutableArray alloc] init];
    
    for (NIMDelegateNode *node in _delegateNodes)
    {
        id nodeDelegate = node.nodeDelegate;
        
        if (nodeDelegate == nil)
        {
            hasNilDelegate = YES;
        }
        else if ([nodeDelegate respondsToSelector:selector])
        {
            [invokeDelegates addObject:nodeDelegate];
        }
    }
    
    for (id nodeDelegate in invokeDelegates) {
        [invocation invokeWithTarget:nodeDelegate];
    }

    if (hasNilDelegate)
    {
        [self removeDelegate:nil];
    }
}

- (void)doesNotRecognizeSelector:(SEL)aSelector {}

- (void)doNothing {}



@end
