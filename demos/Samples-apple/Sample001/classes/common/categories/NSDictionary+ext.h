//
//  NSDictionary+ext.h
//  Samples iOS
//
//  Created by dudu on 2019/11/21.
//


#import <Foundation/Foundation.h>


@interface NSDictionary (ext)
/**
 从字典里取NSInteger(内带判空)
 
 @param key 字典Key值
 @return NSInteger
 */
- (NSInteger)integerValueForKey:(id)key;

/**
 从字典里取int(内带判空)
 
 @param key 字典Key值
 @return int
 */
- (int)intValueForKey:(id)key;

/**
 从字典里取long long(内带判空)
 
 @param key 字典Key值
 @return long long
 */
- (long long)longlongValueForKey:(id)key;

/**
 从字典里取BOOL(内带判空)
 
 @param key 字典Key值
 @return BOOL
 */
- (BOOL)boolValueForKey:(id)key;

/**
 从字典里取float(内带判空)
 
 @param key 字典Key值
 @return float
 */
- (float)floatValueForKey:(id)key;

/**
 从字典里取字符串(内带判空)
 
 @param key 字典Key值
 @return NSString
 */
- (NSString *)stringValueForKey:(id)key;

/**
 从字典里取数组(内带判空)
 
 @param key 字典Key值
 @return NSArray
 */
- (NSArray *)arrayValueForKey:(id)key;

/**
 从字典里取可变数组(内带判空)
 
 @param key 字典Key值
 @return NSMutableArray
 */
- (NSMutableArray *)mutableArrayValueForKey:(NSString *)key;

/**
 从字典里取字典(内带判空)
 
 @param key 字典Key值
 @return NSDictionary
 */
- (NSDictionary *)dictionaryValueForKey:(id)key;

/**
 将NSArray或者NSDictionary转换为JSON

 @param theData 需要转换的对象
 @return 返回JSON NSData
 */
+ (NSData*)toJsonData:(id)theData;

/**
 将json字串解析为dictionary 或 array

 @param json json字串
 @return 返回NSDictionary 或者 NSArray
 */
+ (id)toDictionary:(NSString*)json;

@end

