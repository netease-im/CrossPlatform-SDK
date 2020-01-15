//
//  NIMSDKMessageLogDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKMessageLogDefine_h
#define NIMSDKMessageLogDefine_h

#import "NIMSDKSessionDefine.h"

/** @enum NIMSDKMsglogQuerySource 消息历史查询来源 */
typedef NS_ENUM(NSInteger, NIMSDKMsglogQuerySource)
{
    NIMSDKMsglogQuerySourceLocal      = 0,            /**< 本地查询*/
    NIMSDKMsglogQuerySourceServer     = 1,            /**< 云端查询*/
};

/** @enum NIMSDKMessageType Message Type */
typedef NS_ENUM(NSInteger, NIMSDKMessageType)
{
    NIMSDKMessageTypeText      = 0,            /**< 文本类型消息*/
    NIMSDKMessageTypeImage     = 1,            /**< 图片类型消息*/
    NIMSDKMessageTypeAudio     = 2,            /**< 声音类型消息*/
    NIMSDKMessageTypeVideo     = 3,            /**< 视频类型消息*/
    NIMSDKMessageTypeLocation  = 4,            /**< 位置类型消息*/
    NIMSDKMessageTypeNotification    = 5,        /**< 系统类型通知（包括入群出群通知等） NIMNotificationId*/
    NIMSDKMessageTypeFile         = 6,            /**< 文件类型消息*/
    NIMSDKMessageTypeTips         = 10,            /**< 提醒类型消息,Tip内容根据格式要求填入消息结构中的NIMSDKMsgKeyServerExt字段*/
    NIMSDKMessageTypeRobot     = 11,            /**< 波特机器人消息*/
    NIMSDKMessageTypeCustom    = 100,            /**< 自定义消息*/

    NIMSDKMessageTypeUnknown     = 1000,        /**< 未知类型消息，本地使用，发送时勿使用，作为默认值*/
};

/** @enum NIMSDKMessageFeature 消息种类 */
typedef NS_ENUM(NSInteger, NIMSDKMessageFeature)
{
    NIMSDKMessageFeatureDefault    = 0,            /**< 默认*/
    NIMSDKMessageFeatureLeaveMsg    = 1,            /**< 离线消息*/
    NIMSDKMessageFeatureRoamMsg    = 2,            /**< 漫游消息*/
    NIMSDKMessageFeatureSyncMsg    = 3,            /**< 同步消息*/
    NIMSDKMessageFeatureCustomizedMsg    = 4,        /**< 透传消息*/
};

/** @enum NIMSDKMsglogStatus 消息状态 */
typedef NS_ENUM(NSInteger, NIMSDKMsglogStatus)
{
    NIMSDKMsgLogStatusNone        = 0,            /**< 默认,不能当查询条件,意义太多*/
    NIMSDKMsgLogStatusUnread        = 1,            /**< 收到消息,未读*/
    NIMSDKMsgLogStatusRead        = 2,            /**< 收到消息,已读*/
    NIMSDKMsgLogStatusDeleted        = 3,            /**< 已删*/
    NIMSDKMsgLogStatusSending        = 4,            /**< 发送中*/
    NIMSDKMsgLogStatusSendFailed    = 5,            /**< 发送失败*/
    NIMSDKMsgLogStatusSent        = 6,            /**< 已发送*/
    NIMSDKMsgLogStatusReceipt        = 7,            /**< 对方已读发送的内容*/
    NIMSDKMsgLogStatusDraft        = 8,            /**< 草稿*/
    NIMSDKMsgLogStatusSendCancel    = 9,            /**< 发送取消*/
    NIMSDKMsgLogStatusRefused = 10, /**< 被对方拒绝,比如被对方加入黑名单等等*/
};

/** @enum NIMSDKNotificationId 通知类型 */
typedef NS_ENUM(NSInteger, NIMSDKNotificationId)
{
    NIMSDKNotificationIdTeamInvite            = 0,            /**< 普通群拉人，{"ids":["a1", "a2"],"user_namecards":["namecard1", "namecard2"], "attach" : ""} attach为可选字段，作为应用自定义扩展字段,解析前需要判断有没有这个字段 */
    NIMSDKNotificationIdTeamKick                = 1,            /**< 普通群踢人，{"ids":["a1", "a2"],"user_namecards":["namecard1", "namecard2"], "attach" : ""} attach为可选字段，作为应用自定义扩展字段,解析前需要判断有没有这个字段 */
    NIMSDKNotificationIdTeamLeave                = 2,            /**< 退出群，{"id" : "a1","user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdTeamUpdate            = 3,            /**< 群信息更新，{"team_info":team_info,"user_namecards":["namecard1", "namecard2"]} //群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)*/
    NIMSDKNotificationIdTeamDismiss            = 4,            /**< 群解散，{"user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdTeamApplyPass            = 5,            /**< 高级群申请加入成功，{"id":"a1","user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdTeamOwnerTransfer        = 6,            /**< 高级群移交群主，{"id":"a1", "leave" : bool,"user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdTeamAddManager        = 7,            /**< 增加管理员，{"ids":["a1","a2"],"user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdTeamRemoveManager        = 8,            /**< 删除管理员，{"ids":["a1","a2"],"user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdTeamInviteAccept        = 9,            /**< 高级群接受邀请进群，{"id":"a1","user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdTeamMuteMember        = 10,            /**< 禁言/解禁群成员，{"user_namecards":["namecard1", "namecard2"],"team_info":team_info,"id":"a1","mute":1-禁言,0-解禁} */

    NIMSDKNotificationIdNetcallMiss            = 101,            /**< 未接电话,{"calltype":1,"channel":6146078138783760761,"from":"id1","ids":["id1","id2"],"time":1430995380471}*/
    NIMSDKNotificationIdNetcallBill            = 102,            /**< 话单,{"calltype":2,"channel":6146077129466446197,"duration":8,"ids":["id1","id2"],"time":1430995117398}*/
    
    //服务器在线同步协议返回的结果
    NIMSDKNotificationIdTeamSyncCreate        = 1000,            /**< 创建群 {"team_info" : team_info} //群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)*/
    NIMSDKNotificationIdTeamMemberChanged        = 1001,            /**< 群成员变更{"team_member" : team_member_info} //群组成员信息（不包括自己）(Keys SEE MORE `nim_team_def.h` 『群组成员信息 Json Keys』)*/
    NIMSDKNotificationIdTeamSyncUpdateMemberProperty    = 1002,    /**< 同步通知：修改群成员属性（可能是自己的或别人的）{"team_member" : team_member_info} //目前只需NIMSDKTeamUserKeyNick和NIMSDKTeamUserKeyBits (Keys SEE MORE `nim_team_def.h` 『群组成员信息 Json Keys』)*/

    //本地发起的操作通知APP上层
    NIMSDKNotificationIdLocalCreateTeam        = 2000,            /**< 本地操作创建群 {"ids" : ["a1", "a2"]}*/
    NIMSDKNotificationIdLocalApplyTeam        = 2001,            /**< 本地操作申请加入群 {}*/
    NIMSDKNotificationIdLocalRejectApply        = 2002,            /**< 本地操作拒绝申请 {"id":"a1"}*/
    NIMSDKNotificationIdLocalRejectInvite        = 2003,            /**< 本地操作拒绝邀请 {"id":"a1"}*/
    NIMSDKNotificationIdLocalUpdateMemberProperty    = 2004,        /**< 本地操作更新群成员属性  {"team_member" : team_member_info} */
    NIMSDKNotificationIdLocalUpdateOtherNick    = 2005,            /**< 本地操作更新他人nickname {}*/
    NIMSDKNotificationIdLocalGetTeamInfo        = 2006,            /**< 本地操作获取群信息 {"team_info":team_info} //群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)*/
    NIMSDKNotificationIdLocalGetTeamList        = 2007,            /**< 本地操作获取群成员信息结束*/
    NIMSDKNotificationIdLocalMuteMember        = 2008,            /**< 本地操作对群成员禁言 {"id":"a1", "mute":1-禁言,0-解禁} */
    NIMSDKNotificationIdLocalMute                = 2009,            /**< 本地操作对群禁言 {} */
    NIMSDKNotificationIdLocalGetTeamMsgUnreadCount = 2010,    /**< 获取群消息未读数 {[{"client_msg_id":"", "count":int, "read_accid":"当前已读成员的accid"},...]}*/
    NIMSDKNotificationIdLocalGetTeamMsgUnreadList = 2011,        /**< 获取群消息未读列表 {"client_msg_id":"", "read":["id1",...], "unread":["id2",...]}*/

    //Netcall本地操作通知
    NIMSDKNotificationIdLocalNetcallReject    = 3103,            /**< 拒绝电话,{"calltype":1,"channel":6146078138783760761,"from":"id1","ids":["id1","id2"],"time":1430995380471}*/
    NIMSDKNotificationIdLocalNetcallNoResponse= 3104,            /**< 无应答，未接通电话,{"calltype":1,"channel":6146078138783760761,"from":"id1","ids":["id1","id2"],"time":1430995380471}*/
    NIMSDKNotificationIdLocalNetcallCanceled = 3105,    /**< 未接通前主叫方挂断，{"calltype":1,"channel":6146078138783760761,"from":"id1","ids":["id1","id2"],"time":1430995380471}*/

    NIMSDKNotificationIdSuperTeamInvite = 401,            /**< 超大群拉人，{"ids":["a1", "a2"],"user_namecards":["namecard1", "namecard2"], "attach" : ""} attach为可选字段，作为应用自定义扩展字段,解析前需要判断有没有这个字段 */
    NIMSDKNotificationIdSuperTeamKick = 402,            /**< 超大群踢人，{"ids":["a1", "a2"],"user_namecards":["namecard1", "namecard2"], "attach" : ""} attach为可选字段，作为应用自定义扩展字段,解析前需要判断有没有这个字段 */
    NIMSDKNotificationIdSuperTeamLeave = 403,            /**< 退出超大群，{"id" : "a1","user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdSuperTeamUpdate = 404,            /**< 超大群群信息更新，{"team_info":team_info,"user_namecards":["namecard1", "namecard2"]} //群组信息(Keys SEE MORE `nim_team_def.h` 『群组信息 Json Keys』)*/
    NIMSDKNotificationIdSuperTeamDismiss = 405,            /**< 超大群解散，{"user_namecards":["namecard1", "namecard2"]}*/
    NIMSDKNotificationIdSuperTeamOwnerTransfer = 406,    /**< 超大群移交群主，{"id":"a1","uinfos":["uinfo1", "uinfo2"]}*/
    NIMSDKNotificationIdSuperTeamAddManager = 407,    /**< 超大群增加管理员，{"ids":["a1","a2"],"uinfos":["uinfo1", "uinfo2"]}*/
    NIMSDKNotificationIdSuperTeamRemoveManager = 408,    /**< 超大群删除管理员，{"ids":["a1","a2"],"uinfos":["uinfo1", "uinfo2"]}*/
    NIMSDKNotificationIdSuperTeamMuteMember = 409,    /**< 超大群禁言/解禁群成员，{"uinfos":["uinfo1", "uinfo2"],“tinfo”:tinfo,"id":"a1","mute":1-禁言,0-解禁}*/
};

/** @enum NIMSDKMsglogSubStatus 消息子状态 */
typedef NS_ENUM(NSInteger, NIMSDKMsglogSubStatus)
{
    NIMSDKMsgLogSubStatusNone                 = 0,            /**< 默认状态*/

    //这二个标志适用于所有
    NIMSDKMsgLogSubStatusNotPlaying           = 20,            /**< 未播放*/
    NIMSDKMsgLogSubStatusPlayed               = 21,            /**< 已播放*/
};
 
/** @导出/导入云端备份操作类型 */
typedef NS_ENUM(NSInteger, NIMSDKLogsBackupRemoteOperate)
{
    NIMSDKLogsBackupRemoteOperate_Export = 0,    /**< 导出*/
    NIMSDKLogsBackupRemoteOperate_Import = 1    /**< 导入*/
};
/** @导出/导入云端备份操作结果 */
typedef NS_ENUM(NSInteger, NIMSDKLogsBackupRemoteState)
{
    NIMSDKLogsBackupRemoteState_Begin = -2,/**< 定义开始*/
    NIMSDKLogsBackupRemoteState_UnDef,                /**< 未定义*/
    NIMSDKLogsBackupRemoteState_UserCanceled = 5,        /**< 已取消*/
    NIMSDKLogsBackupRemoteState_SDKError,            /**< SDK 已出错*/
    //导入状态
    NIMSDKLogsBackupRemoteState_IMP_NoBackup,/**<没有备份文件*/
    NIMSDKLogsBackupRemoteState_IMP_SyncFromSrvError,/**<查询备份失败一般是网络错误*/
    NIMSDKLogsBackupRemoteState_IMP_DownloadBackupFailed,/**<下载备份文件出错*/
    NIMSDKLogsBackupRemoteState_IMP_RAWError,/**<解密/解压出来的源文件格式错误*/
    NIMSDKLogsBackupRemoteState_IMP_ParseRAWError,/**<解析源文件格式错误*/
    NIMSDKLogsBackupRemoteState_IMP_LocalDBFailed, /**<导入本地DB出错    */
    //导出状态
    NIMSDKLogsBackupRemoteState_EXP_LocalDBFailed,/**<打开本地DB失败*/
    NIMSDKLogsBackupRemoteState_EXP_RAWError,/**<导出到源文件失败*/
    NIMSDKLogsBackupRemoteState_EXP_UploadBackupFailed,/**<上传备份文件出错*/
    NIMSDKLogsBackupRemoteState_EXP_SyncToSrvError,/**<同步到服务器出错一般是网络错误*/

    NIMSDKLogsBackupRemoteState_Done,                /**< 完成*/
    NIMSDKLogsBackupRemoteState_Done_NoLogs,/**<完成，但未导出任何记录*/
    NIMSDKLogsBackupRemoteState_End,/**<定义结束*/
    NIMSDKLogsBackupRemoteState_FinalState_Begin = NIMSDKLogsBackupRemoteState_UserCanceled,/**<是否已是最终状态的一个标识，可以判断state是否为终态(state >= NIMSDKLogsBackupRemoteState_FinalState_Begin)*/
    
};

/** @enum NIMSDKMsglogSearchDirection 消息历史查询方向 */
typedef NS_ENUM(NSInteger, NIMSDKMsglogSearchDirection)
{
    NIMSDKMsglogForward = 0,    /**< 以时间点为准向前搜索 */
    NIMSDKMsglogBackward = 1,    /**< 以时间点为准向后搜索 */
};

/** @enum NIMSDKMsglogQueryRange 消息历史的检索范围 */
typedef NS_ENUM(NSInteger, NIMSDKMsglogQueryRange)
{
    NIMSDKMsgLogQueryRangeP2P                 =  NIMSDKSessionTypeP2P,    /**< 指定的个人（点对点会话）（注意：暂不支持指定多个人的检索！）*/
    NIMSDKMsgLogQueryRangeTeam = NIMSDKSessionTypeTeam,    /**< 指定的群组（注意：暂不支持指定多个群组的检索！）*/
    NIMSDKMsgLogQueryRangeSuperTeam = NIMSDKSessionTypeSuperTeam,    /**< 指定的超大群组（注意：暂不支持指定多个群组的检索！）*/

    NIMSDKMsgLogQueryRangeAll                    = 100,                    /**< 全部*/
    NIMSDKMsgLogQueryRangeAllP2P                = 101,                    /**< 所有个人会话*/
    NIMSDKMsgLogQueryRangeAllTeam = 102,                    /**< 所有群组*/
    NIMSDKMsgLogQueryRangeAllSuperTeam = 103,                    /**< 所有超大群组*/
    NIMSDKMsgLogQueryRangeUnknown                = 200,                    /**< 未知（如指定个人和群组的集合）（注意：暂不支持指定个人和群组的混合检索！）*/
};


#endif /* NIMSDKMessageLogDefine_h */
