//
//  CurrentUser.h
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import <Foundation/Foundation.h>

@interface CurrentUser : NSObject

+(instancetype) shared;
@property (nonatomic,copy) NSString* accout;
@property (nonatomic,copy) NSString* password;
@property (nonatomic,assign) BOOL logined;
@end


