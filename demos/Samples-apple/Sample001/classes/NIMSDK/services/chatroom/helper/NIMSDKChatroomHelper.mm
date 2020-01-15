//
//  NIMSDKChatroomHelper.m
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#import "NIMSDKChatroomHelper.h"
#import "NSDictionary+ext.h"

#ifdef __cplusplus
extern "C" {
#endif

NIMSDKChatRoomInfo* convertNIMSDKChatRoomInfo(const nim_chatroom::ChatRoomInfo& info)
{
    NIMSDKChatRoomInfo* roomInfo = [[NIMSDKChatRoomInfo alloc] init];
    roomInfo.roomID = (NSInteger)info.id_;
    roomInfo.creatorId = [NSString stringWithUTF8String:info.creator_id_.c_str()];
    roomInfo.name = [NSString stringWithUTF8String:info.name_.c_str()];
    if (!info.announcement_.empty()) {
        roomInfo.announcement = [NSString stringWithUTF8String:info.announcement_.c_str()];
    }
    
    if (!info.broadcast_url_.empty()) {
        roomInfo.broadcastUrl = [NSString stringWithUTF8String:info.broadcast_url_.c_str()];
    }
    
    roomInfo.validFlag = (NSInteger)info.valid_flag_;
    
    if (!info.ext_.empty()) {
        roomInfo.ext = [NSDictionary toDictionary:[NSString stringWithUTF8String:info.ext_.c_str()]];
    }
    
    roomInfo.onlineCount = (NSInteger)info.online_count_;
    roomInfo.muteAll = (NSInteger)info.mute_all_;
    roomInfo.queueLevel = (NSInteger)info.queuelevel;
    
    return roomInfo;
}
NIMSDKChatRoomMemberInfo* convertNIMSDKChatRoomMemberInfo(const nim_chatroom::ChatRoomMemberInfo& info)
{
    
    NIMSDKChatRoomMemberInfo* memberInfo = [[NIMSDKChatRoomMemberInfo alloc] init];
    
    memberInfo.roomID = (NSInteger)info.room_id_;
    memberInfo.accountId = [NSString stringWithUTF8String:info.account_id_.c_str()];
    memberInfo.type = (NSInteger)info.type_;
    memberInfo.level = (NSInteger)info.level_;
    if (!info.nick_.empty()) {
        memberInfo.nick = [NSString stringWithUTF8String:info.nick_.c_str()];
    }
    if (!info.avatar_.empty()) {
        memberInfo.avatar = [NSString stringWithUTF8String:info.avatar_.c_str()];
    }
    
    if (!info.ext_.empty()) {
        memberInfo.ext = [NSDictionary toDictionary:[NSString stringWithUTF8String:info.ext_.c_str()]];
    }
    
    memberInfo.state = (NIMSDKChatRoomOnlineState)info.state_;
    memberInfo.guestFlag = (NIMSDKChatRoomGuestFlag)info.guest_flag_;
    memberInfo.enterTimetag = (NSInteger)info.enter_timetag_;
    memberInfo.blacklist = info.is_blacklist_;
    memberInfo.muted = info.is_muted_;
    memberInfo.valid = info.is_valid_;
    memberInfo.updateTimetag = (NSInteger)info.update_timetag_;
    memberInfo.tempMuted = info.temp_muted_;
    memberInfo.tempMutedDuration = (NSInteger)info.temp_muted_duration_;
    
    return memberInfo;
}
    
    
#ifdef __cplusplus
}
#endif
