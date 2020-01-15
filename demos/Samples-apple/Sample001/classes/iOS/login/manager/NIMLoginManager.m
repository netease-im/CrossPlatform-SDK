//
//  NIMLoginManager.m
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import "NIMLoginManager.h"
#import "NIMKitFileLocationHelper.h"


#define NIMAccount      @"account"
#define NIMToken        @"token"

@interface NIMLoginData () <NSCoding>

@end

@implementation NIMLoginData

-(instancetype)initWithCoder:(NSCoder *)coder
{
    if (self = [super init]) {
        _account = [coder decodeObjectForKey:NIMAccount];
        _token = [coder decodeObjectForKey:NIMToken];
    }
    
    return self;
}

-(void)encodeWithCoder:(NSCoder *)coder
{
    if ([_account length]) {
        [coder encodeObject:_account forKey:NIMAccount];
    }
    
    if ([_token length]) {
        [coder encodeObject:_token forKey:NIMToken];
    }
}
@end

@interface NIMLoginManager ()
@property (nonatomic,strong) NSString* filepath;
@end

@implementation NIMLoginManager

+(instancetype)sharedManager
{
    static NIMLoginManager *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        NSString *filepath = [[NIMKitFileLocationHelper getAppDocumentPath] stringByAppendingPathComponent:@"nim_sample_login_data"];
        instance = [[NIMLoginManager alloc] initWithPath:filepath];
    });
    return instance;
}

- (instancetype)initWithPath:(NSString *)filepath
{
    if (self = [super init])
    {
        _filepath = filepath;
        [self readData];
    }
    return self;
}


- (void)setCurrentLoginData:(NIMLoginData *)currentLoginData
{
    _currentLoginData = currentLoginData;
    [self saveData];
}

//从文件中读取和保存用户名密码,建议上层开发对这个地方做加密,DEMO只为了做示范,所以没加密
- (void)readData
{
    NSString *filepath = [self filepath];
    if ([[NSFileManager defaultManager] fileExistsAtPath:filepath])
    {
        id object = [NSKeyedUnarchiver unarchiveObjectWithFile:filepath];
        _currentLoginData = [object isKindOfClass:[NIMLoginData class]] ? object : nil;
    }
}

- (void)saveData
{
    NSData *data = [NSData data];
    if (_currentLoginData && [_currentLoginData.account length] && [_currentLoginData.token length] )
    {
        data = [NSKeyedArchiver archivedDataWithRootObject:_currentLoginData];
    }
    [data writeToFile:[self filepath] atomically:YES];
}


@end
