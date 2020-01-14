﻿/** @file nim_nos_helper.h
  * @brief NOS数据结构定义
  * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
  * @date 2016/12/16
  */
#if !defined(WIN32)
#include <pthread.h>
#endif
#include "src/cpp_sdk/nim/helper/nim_nos_helper.h"
#include "include/depend_lib/include/nim_json_util.h"
namespace nim
{
	const int32_t NIM_SDK_CPPWRAPPER_DLL_API InitNosConfigParam::kMINSURVIVALTIME = 60 * 60 * 24;
	void InitNosResult::FromJsonString(const std::string& json_data)
	{
		nim_cpp_wrapper_util::Json::Value json_value;
		if (nim_cpp_wrapper_util::Json::Reader().parse(json_data, json_value))
		{
			if (json_value.isMember(kNIMNosInitConfigSucceed) && json_value[kNIMNosInitConfigSucceed].isArray())
			{
				auto it = json_value[kNIMNosInitConfigSucceed].begin();
				while (it != json_value[kNIMNosInitConfigSucceed].end())
				{
					this->success_req_tags_.emplace_back(it->asString());
					it++;
				}
			}
			if (json_value.isMember(kNIMNosInitConfigIgnore) && json_value[kNIMNosInitConfigIgnore].isArray())
			{
				auto it = json_value[kNIMNosInitConfigIgnore].begin();
				while (it != json_value[kNIMNosInitConfigIgnore].end())
				{
					this->ignore_req_tags_.emplace_back(it->asString());
					it++;
				}
			}
			if (json_value.isMember(kNIMNosInitConfigFailure) && json_value[kNIMNosInitConfigFailure].isArray())
			{
				auto it = json_value[kNIMNosInitConfigFailure].begin();
				while (it != json_value[kNIMNosInitConfigFailure].end())
				{
					if(it->isMember(kNIMNosUploadTagName) && it->isMember(kNIMNosInitConfigErrcode))
						failure_req_tags_.insert(std::make_pair((*it)[kNIMNosUploadTagName].asString(), (*it)[kNIMNosInitConfigErrcode].asInt()));
					it++;
				}
			}
		}
	}
bool ParseUploadResult( const std::string& url, const std::string& json, UploadMediaResult& res )
{
	res.url_ = url;

	nim_cpp_wrapper_util::Json::Value values;
	nim_cpp_wrapper_util::Json::Reader reader;
	if (reader.parse(json, values) && values.isObject())
	{
		if (values.isMember(kNIMNosCallId))
			res.call_id_ = values[kNIMNosCallId].asString();
		res.res_id_ = values[kNIMNosResId].asString();
	}

	return true;	
}

bool ParseDownloadResult( const std::string& file_path, const std::string& call_id, const std::string& res_id, DownloadMediaResult& res )
{
	res.file_path_ = file_path;
	res.call_id_ = call_id;
	res.res_id_ = res_id;
	return true;
}

bool ParseProgressData( const std::string& json, ProgressData& res )
{
	nim_cpp_wrapper_util::Json::Value values;
	nim_cpp_wrapper_util::Json::Reader reader;
	if (reader.parse(json, values) && values.isObject())
	{
		res.res_id_ = values[kNIMNosResId].asString();
	}

	return true;
}

}
