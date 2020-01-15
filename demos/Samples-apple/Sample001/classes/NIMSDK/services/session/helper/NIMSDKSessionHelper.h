//
//  NIMSessionHelper.h
//  Samples
//
//  Created by dudu on 2019/11/27.
//

#ifndef NIMSessionHelper_h
#define NIMSessionHelper_h

#import "NIMSDKTalkModel.h"
#import "nim_cpp_talk.h"

#ifdef __cplusplus
extern "C" {
#endif

BOOL transformJsonValue(NSDictionary* dict,nim_cpp_wrapper_util::Json::Value& value);
NSDictionary* convertJsonValue(const nim_cpp_wrapper_util::Json::Value& value);
BOOL transformNIMIMMessage(NIMSDKIMMessage* message,nim::IMMessage& msg);
BOOL convertNIMIMMessage(const nim::IMMessage& msg,NIMSDKIMMessage* message);
BOOL transformNIMIMMessageSetting(NIMSDKMessageSetting* messageSetting,nim::MessageSetting& setting);
BOOL convertNIMSDKIMMessageSetting(const nim::MessageSetting& messageSetting,NIMSDKMessageSetting* setting);
NSString* transformNIMMessageAttach(NSObject* attach);
NSObject* convertNIMSDKMessageAttach(nim::NIMMessageType type, const std::string& attach);
#ifdef __cplusplus
}
#endif



#endif /* NIMSessionHelper_h */
