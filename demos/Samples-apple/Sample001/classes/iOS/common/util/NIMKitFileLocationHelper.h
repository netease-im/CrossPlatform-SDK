//
//  NIMKitFileLocationHelper.h
//  NIMKit
//
//  Created by chris on 2016/11/12.
//  Copyright © 2016年 NetEase. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NIMKitFileLocationHelper : NSObject

+ (nonnull NSString *)getAppDocumentPath;

+ (nonnull NSString *)getAppTempPath;

+ (nonnull NSString *)userDirectory:(nonnull NSString *)userID;

+ (nullable NSString *)genFilenameWithExt:(nonnull NSString *)ext;


@end
