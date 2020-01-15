//
//  NSDictionary+ext.m
//  Samples iOS
//
//  Created by dudu on 2019/11/21.
//

#import "NSDictionary+ext.h"

@implementation NSDictionary (ext)
- (NSInteger)integerValueForKey:(id)key {
    id value = [self notNullValueForKey:key];
    return value == nil ? 0 : [value integerValue];
}

- (int)intValueForKey:(id)key {
    id value = [self notNullValueForKey:key];
    return value == nil ? 0 : [value intValue];
}


- (long long)longlongValueForKey:(id)key {
    id value = [self notNullValueForKey:key];
    return value == nil ? 0 : [value longLongValue];
}

- (BOOL)boolValueForKey:(id)key {
    id value = [self notNullValueForKey:key];
    return value == nil ? NO : [value boolValue];
}

- (float)floatValueForKey:(id)key {
    id value = [self notNullValueForKey:key];
    return value == nil ? NO : [value floatValue];
}

- (NSString *)stringValueForKey:(id)key {
    return [self notNullValueForKey:key];
}

- (NSArray *)arrayValueForKey:(id)key {
    id value = [self notNullValueForKey:key];
    if(![value isKindOfClass:[NSArray class]]) {
        return nil;
    }
    return value;
}

- (NSMutableArray*)mutableArrayValueForKey:(NSString *)key {
    id value = [self notNullValueForKey:key];
    if(![value isKindOfClass:[NSMutableArray class]]) {
        return nil;
    }
    return value;
}

- (NSDictionary *)dictionaryValueForKey:(id)key {
    id value = [self notNullValueForKey:key];
    if(![value isKindOfClass:[NSDictionary class]]) {
        return nil;
    }
    return value;
}

+ (NSData *)toJsonData:(id)theData
{
    NSError *error = nil;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:theData
                                                       options:NSJSONWritingPrettyPrinted
                                                         error:&error];
    
    if ([jsonData length] > 0 && error == nil){
        return jsonData;
    }
    return nil;
}

+ (id)toDictionary:(NSString *)json
{
    if (json == nil || [json isKindOfClass:[NSNull class]] || [json length] == 0){
        return nil;
    }
    NSData* data =  [json dataUsingEncoding:NSUTF8StringEncoding];
    NSError* error = nil;
    id obj = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:&error];
    if (error != nil) {
        return nil;
    }
    
    return obj;
}

#pragma mark 判断是否null
- (BOOL)isNullValue:(id)value {
    return [value isEqual:[NSNull null]];
}

- (id)notNullValueForKey:(id)key {
    id value = [self objectForKey:key];
    if([self isNullValue:value]) {
        return nil;
    }
    return value;
}
@end
