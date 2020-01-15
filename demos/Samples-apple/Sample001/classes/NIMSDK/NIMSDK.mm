//
//  NIMSDK.m
//  Samples iOS
//
//  Created by dudu on 2019/11/20.
//

#import "NIMSDK.h"
#import "NIMKitFileLocationHelper.h"
#import "NIMSDKLoginManager.h"
#import "NIMSDKSessionManager.h"
#import "NIMSDKChatroomManager.h"


@interface NIMSDK ()
{
    NSMutableDictionary* _services;
}
@end

@implementation NIMSDK

+(instancetype)shared
{
    static NIMSDK *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[NIMSDK alloc] init];
    });
    return instance;
}

-(instancetype)init
{
    if (self = [super init]) {
        _appKey = @"45c6af3c98409b18a84451215d0bdd6e";
        _apnsCername = @"ENTERPRISE"; //release下有效，对应云信后台配置的s证书名称
    }
    
    return self;
}

-(void)dealloc
{
    
}

#pragma mark -
-(void)addDelegate:(id)delegate forType:(NIMSDKDelegateType)type
{
    id service = [self serviceByType:type];
    if ([service respondsToSelector:@selector(addDelegate:)]) {
        [service performSelector:@selector(addDelegate:) withObject:delegate];
    }
}

-(void)removeDelegate:(id)delegate forType:(NIMSDKDelegateType)type
{
    id service = [self serviceByType:type];
    if ([service respondsToSelector:@selector(removeDelegate:)]) {
        [service performSelector:@selector(removeDelegate:) withObject:delegate];
    }
}

-(id)serviceByType:(NIMSDKDelegateType)type
{
    Class clazz = nil;
    switch (type) {
        case NIMSDKDelegateTypeLogin:
            clazz = [NIMSDKLoginManager class];
            break;
        case NIMSDKDelegateTypeSession:
            clazz = [NIMSDKSessionManager class];
            break;
        case NIMSDKDelegateTypeChatroom:
            clazz = [NIMSDKChatroomManager class];
        default:
            break;
    }
    return [self serviceByClass:clazz];
}

#pragma mark - setup
-(void)setup
{
    [self setupServices];
}

-(void)setupServices
{
    NSArray* array =@[
                      [NIMSDKLoginManager class],
                      [NIMSDKSessionManager class],
                      [NIMSDKChatroomManager class],
                      ];
    _services = [[NSMutableDictionary alloc] init];
    for (Class clz in array) {
        id obj = [[clz alloc] init];
        [_services setObject:obj forKey:NSStringFromClass(clz)];
    }
        
    [self setupLoginService];
    
    for (id<NIMSDKServiceProtocol> service in _services.allValues) {
        if ([service isKindOfClass:[NIMSDKLoginManager class]]) {
            continue;
        }
        
        if ([service respondsToSelector:@selector(setup)]) {
            [service performSelector:@selector(setup)];
        }
    }
}

-(void)setupLoginService
{
    NSString * documentPath = [NIMKitFileLocationHelper getAppDocumentPath];
    [self.loginService setup:_appKey appDataPath:documentPath sdkConfig:nil];
}

-(void)cleanup
{
    for (id<NIMSDKServiceProtocol> service in [_services.allValues.reverseObjectEnumerator allObjects]) {
        
        if ([service respondsToSelector:@selector(cleanup)]) {
            [service performSelector:@selector(cleanup)];
        }
    }
    [_services removeAllObjects];
}

#pragma mark - protocol
-(id<NIMSDKLoginServiceProtocol>)loginService
{
    return [self serviceByClass:[NIMSDKLoginManager class]];
}

-(id<NIMSDKSessionServiceProtocol>)sessionService
{
    return [self serviceByClass:[NIMSDKSessionManager class]];
}

-(id<NIMSDKChatroomServiceProtocol>)chatroomService
{
    return [self serviceByClass:[NIMSDKChatroomManager class]];
}

#pragma mark - private
- (id)serviceByClass:(Class)cls
{
    NSString* key = NSStringFromClass(cls);
    return _services[key];
}
@end
