//
//  CurrentUser.m
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import "CurrentUser.h"

@implementation CurrentUser
+(instancetype)shared
{
    static CurrentUser* instance;
    static dispatch_once_t onceToken;
    _dispatch_once(&onceToken, ^{
        instance = [[CurrentUser alloc] init];
    });
    
    return instance;
}
@end
