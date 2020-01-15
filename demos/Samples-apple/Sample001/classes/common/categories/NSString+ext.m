//
//  NSString+ext.m
//  Samples iOS
//
//  Created by dudu on 2019/11/21.
//

#import "NSString+ext.h"
#import <CommonCrypto/CommonCryptor.h>
#import <CommonCrypto/CommonDigest.h>

@implementation NSString (ext)
+ (BOOL)isEmptyOrNull:(NSString *)input
{
    if (input == nil || [input isKindOfClass:[NSNull class]])
        return YES;
    return input.length == 0;
}
-(NSString*)md5
{
    const char *cStr = [self UTF8String];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(cStr, (CC_LONG)strlen(cStr), result);
    NSMutableString *md5 = [[NSMutableString alloc] init];
    for (NSInteger i = 0; i < CC_MD5_DIGEST_LENGTH; i++) {
        NSString *hex = [NSString stringWithFormat:@"%02x", result[i]];
        [md5 appendString:hex];
    }
    return md5;
}
@end
