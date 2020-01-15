//
//  NSString+ext.h
//  Samples iOS
//
//  Created by dudu on 2019/11/21.
//

#import <Foundation/Foundation.h>

@interface NSString (ext)
+(BOOL)isEmptyOrNull:(NSString *)input;

-(NSString*)md5;
@end

