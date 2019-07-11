﻿/** @file nim_friend_helper.cpp
  * @brief SDK好友辅助方法
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @date 2015/10/20
  */

#include "src/cpp_sdk/nim/helper/nim_friend_helper.h"

namespace nim
{
bool ParseFriendsProfile(const std::string& friends_profile_json, std::list<FriendProfile>& profiles)
{
	nim_cpp_wrapper_util::Json::Value values;
	nim_cpp_wrapper_util::Json::Reader reader;
	if (reader.parse(friends_profile_json, values) && values.isObject() && values[kNIMFriendKey].isArray())
	{
		nim_cpp_wrapper_util::Json::Value friends = values[kNIMFriendKey];
		int len = friends.size();
		for (int i = 0; i < len; i++)
		{
			FriendProfile profile;
			ParseFriendProfile(friends[i], profile);
			profiles.push_back(profile);
		}

		return true;
	}
	return false;
}

bool ParseFriendProfile(const std::string& friend_profile_json, FriendProfile& profile)
{
	nim_cpp_wrapper_util::Json::Value values;
	nim_cpp_wrapper_util::Json::Reader reader;
	if (reader.parse(friend_profile_json, values) && values.isObject())
	{
		ParseFriendProfile(values, profile);
		return true;
	}
	return false;
}

void ParseFriendProfile(const nim_cpp_wrapper_util::Json::Value& friend_profile_json, FriendProfile& profile)
{
	profile.SetAccId(friend_profile_json[kNIMFriendKeyAccid].asString());
	profile.SetRelationship((NIMFriendFlag)friend_profile_json[kNIMFriendKeyFlag].asUInt());
	profile.SetPassiveRelationship((NIMFriendFlag)friend_profile_json[kNIMFriendKeyBeFlag].asUInt());
	profile.SetSource((NIMFriendSource)friend_profile_json[kNIMFriendKeySource].asUInt());
	profile.SetAlias(friend_profile_json[kNIMFriendKeyAlias].asString());
	profile.SetBits(friend_profile_json[kNIMFriendKeyBits].asUInt64());
	nim_cpp_wrapper_util::Json::Value ext;
	nim_cpp_wrapper_util::Json::Reader reader;
	if (reader.parse(friend_profile_json[kNIMFriendKeyEx].asString(), ext) && ext.isObject())
		profile.SetEx(ext);
	profile.SetCreateTimetag(friend_profile_json[kNIMFriendKeyCreateTime].asUInt64());
	profile.SetUpdateTimetag(friend_profile_json[kNIMFriendKeyUpdateTime].asUInt64());
	profile.SetServerEx(friend_profile_json[kNIMFriendServerEx].asString());
}

}