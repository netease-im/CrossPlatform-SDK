//
//  NIMLoginManager.h
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import <Foundation/Foundation.h>


@interface NIMLoginData : NSObject
@property (nonatomic,copy) NSString* account;
@property (nonatomic,copy) NSString* token;
@end

@interface NIMLoginManager : NSObject
+(instancetype) sharedManager;

@property (nonatomic,strong) NIMLoginData* currentLoginData;
@end


