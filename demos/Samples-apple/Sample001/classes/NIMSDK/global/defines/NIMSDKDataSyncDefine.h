//
//  NIMSDKDataSyncDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKDataSyncDefine_h
#define NIMSDKDataSyncDefine_h

/** @enum NIMSDKDataSyncType 数据同步类型 */
typedef NS_ENUM(NSInteger, NIMSDKDataSyncType)
{
    NIMSDKDataSyncTypeUnreadMsg                 = 2,        /**< 未读消息同步*/
    NIMSDKDataSyncTypeTeamInfo                  = 3,        /**< 所有群的信息同步, json_attachment为同步到的team_info json array*/
    NIMSDKDataSyncTypeRoamMsg                   = 7,        /**< 漫游消息同步,每个会话同步到漫游消息都会触发该类通知*/
    NIMSDKDataSyncTypeSuperTeamInfo             = 22,        /**< 所有群的信息同步, json_attachment为同步到的team_info json array*/
    NIMSDKDataSyncTypeTeamUserList              = 1000,        /**< 群成员列表同步, json_attachment为同步到的tid*/
    NIMSDKDataSyncTypeAllTeamUserList           = 1001,        /**< 所有群的成员列表同步完毕, json_attachment为空*/
    NIMSDKDataSyncTypeSuperTeamUserList         = 1010,        /**< 超大群成员列表同步, json_attachment为同步到的tid*/
    NIMSDKDataSyncTypeAllSuperTeamUserList      = 1011,        /**< 所有超大群的成员列表同步完毕, json_attachment为空*/

};

/** @enum NIMSDKDataSyncStatus 数据同步状态 */
typedef NS_ENUM(NSInteger, NIMSDKDataSyncStatus)
{
    NIMSDKDataSyncStatusComplete                = 1,        /**< 同步完成*/
};
#endif /* NIMSDKDataSyncDefine_h */
