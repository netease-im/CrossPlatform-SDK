//
//  NESample02Delegate.h
//  Samples Mac
//
//  Created by dudu on 2020/1/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NESample02Delegate <NSObject>

@optional

-(void)onEnterClicked:(NSNumber*)roomID;

-(void)onExitClicked:(NSNumber*)roomID;

@end

NS_ASSUME_NONNULL_END
