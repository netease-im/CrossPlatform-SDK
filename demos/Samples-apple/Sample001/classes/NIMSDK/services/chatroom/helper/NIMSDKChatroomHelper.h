//
//  NIMSDKChatroomHelper.h
//  Samples
//
//  Created by dudu on 2019/12/30.
//

#ifndef NIMSDKChatroomHelper_h
#define NIMSDKChatroomHelper_h

#import <Foundation/Foundation.h>
#import "NIMSDKChatroomModel.h"
#import "nim_chatroom_cpp.h"

#ifdef __cplusplus
extern "C" {
#endif

NIMSDKChatRoomInfo* convertNIMSDKChatRoomInfo(const nim_chatroom::ChatRoomInfo& info);
NIMSDKChatRoomMemberInfo* convertNIMSDKChatRoomMemberInfo(const nim_chatroom::ChatRoomMemberInfo& info);

#ifdef __cplusplus
}
#endif

#endif /* NIMSDKChatroomHelper_h */
