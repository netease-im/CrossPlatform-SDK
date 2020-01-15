//
//  NIMSDKChatroomModel.m
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import "NIMSDKChatroomModel.h"

@implementation NIMSDKChatRoomEnterInfo



@end

@implementation NIMSDKChatRoomInfo

-(instancetype)init
{
    if (self = [super init]) {
        _queueLevel = 1;
    }
    
    return self;
}


-(NSString *)description
{
    NSString* content = [NSString stringWithFormat:@"roomID:%@,name:%@,announcement:%@,creatorId:%@,validFlag:%@,onlineCount:%@,muteAll:%@",@(_roomID),_name,_announcement,_creatorId,@(_validFlag),@(_onlineCount),@(_muteAll)];
    
    return content;
}

@end


@implementation NIMSDKChatRoomMemberInfo

-(instancetype)init
{
    if (self = [super init]) {
        _type = -2;
        _state = NIMSDKChatRoomOnlineStateOffline;
        _guestFlag = NIMSDKChatRoomGuestFlagGuest;
        _blacklist = NO;
        _muted = NO;
        _valid = NO;
        _updateTimetag = 0;
        _tempMuted = NO;
        _tempMutedDuration = 0;
        _enterTimetag = 0;
    }
    
    return self;
}

-(NSString *)description
{
    NSString* content = [NSString stringWithFormat:@"roomID:%@,accountId:%@,type:%@,nick:%@,level:%@",@(_roomID),_accountId,@(_type),_nick,@(_level)];
    
    return content;
}

@end

@implementation NIMSDKChatRoomEnterResult

-(NSString *)description
{
    NSString* content = [NSString stringWithFormat:@"code:%@,roomID:%@,step:%@,roomInfo:%@,myInfo:%@",@(_resCode),@(_roomID),@(_step),[_roomInfo description],[_myInfo description]];
    
    return content;
}
@end

@implementation NIMSDKChatRoomExitResult

-(NSString *)description
{
    NSString* content = [NSString stringWithFormat:@"code:%@,roomID:%@,reason:%@",@(_resCode),@(_roomID),@(_reason)];
    
    return content;
}

@end
