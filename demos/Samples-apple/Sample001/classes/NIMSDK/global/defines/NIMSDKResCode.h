//
//  NIMSDKResCode.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKResCode_h
#define NIMSDKResCode_h


typedef NS_ENUM(NSInteger, NIMSDKResCode) {
    //通用错误码
    NIMSDKResError                      = 0,        /**< 错误 */
    NIMSDKResSuccess                    = 200,        /**< 没有错误，一切正常 */
    NIMSDKResVersionError               = 201,        /**< 客户端版本不正确 */
    NIMSDKResUidPassError               = 302,        /**< 用户名或密码错误 */
    NIMSDKResForbidden                  = 403,        /**< 禁止操作 */
    NIMSDKResNotExist                   = 404,        /**< 请求的目标（用户或对象）不存在 */
    NIMSDKResNoModify                   = 406,        /**< 数据自上次查询以来未发生变化（用于增量更新） */
    NIMSDKResTimeoutError               = 408,        /**< 请求过程超时 */
    NIMSDKResParameterError             = 414,        /**< 参数错误 */
    NIMSDKResConnectionError            = 415,        /**< 网络连接出现错误 */
    NIMSDKResFrequently                 = 416,        /**< 操作太过频繁 */
    NIMSDKResExist                      = 417,        /**< 对象已经存在/重复操作 */
    NIMSDKResOverrun                    = 419,        /**< 超限 */
    NIMSDKResAccountBlock               = 422,        /**< 帐号被禁用 */
    NIMSDKResUnknownError               = 500,        /**< 未知错误，或者不方便告诉你 */
    NIMSDKResServerDataError            = 501,        /**< 服务器数据错误 */
    NIMSDKResTooBuzy                    = 503,        /**< 服务器太忙 */
    NIMSDKResExceedLimit                = 508,        /**< 超过配置有效期 */
    NIMSDKResInvalid                    = 509,        /**< 协议无效, 不允许访问的协议 */
    //群错误码
    NIMSDKResTeamECountLimit            = 801,        /**< 已达到人数限制 */
    NIMSDKResTeamENAccess               = 802,        /**< 没有权限 */
    NIMSDKResTeamENotExist              = 803,        /**< 群不存在 */
    NIMSDKResTeamEMemberNotExist        = 804,        /**< 用户不在兴趣组里面 */
    NIMSDKResTeamErrType                = 805,        /**< 群类型不对 */
    NIMSDKResTeamLimit                  = 806,        /**< 创建群数量限制 */
    NIMSDKResTeamUserStatusErr          = 807,        /**< 群成员状态不对 */
    NIMSDKResTeamApplySuccess           = 808,        /**< 申请成功 */
    NIMSDKResTeamAlreadyIn              = 809,        /**< 已经在群里 */
    NIMSDKResTeamInviteSuccess          = 810,        /**< 邀请成功 */
    NIMSDKResForcePushCountLimit        = 811,        /**< 强推列表账号数量超限 */
    NIMSDKResTeamMemberLimit            = 813,        /**< 操作成功，但部分成员的群数量超限 */
    //数据解编错误代码
    NIMSDKResInvalidProtocol            = 997,        /**< 协议已失效 */
    NIMSDKResEUnpacket                  = 998,        /**< 解包错误 */
    NIMSDKResEPacket                    = 999,        /**< 打包错误 */
    //
    NIMSDKResInBlack                    = 7101,        /**< 被接收方加入黑名单 SDK版本大于2.5.0支持*/

    //独立信令错误代码
    NIMSDKResRoomNotExists                  = 10404,    /**< 房间不存在 */
    NIMSDKResRoomHasExists                  = 10405,    /**< 房间已存在 */
    NIMSDKResRoomMemberNotExists            = 10406,    /**< 不在房间内 */
    NIMSDKResRoomMemberHasExists            = 10407,    /**< 已经在房间内 */
    NIMSDKResRoomInviteNotExists            = 10408,    /**< 邀请不存在或已过期 */
    NIMSDKResRoomInviteHasReject            = 10409,    /**< 邀请已经拒绝 */
    NIMSDKResRoomInviteHasAccept            = 10410,    /**< 邀请已经接受了 */
    NIMSDKResPeerNIMSDKOffline              = 10201,    /**< 对方云信不在线 */
    NIMSDKResPeerPushOffline                = 10202,    /**< 对方推送亦不可达 */
    NIMSDKResRoomUidConflict                = 10417,    /**< uid冲突 */
    NIMSDKResRoomMemberExceed               = 10419,    /**< 房间人数超限 */
    NIMSDKResRoomMemberHasExistsOtherClient = 10420,    /**< 已经在房间内（自己的其他端） */

    //客户端自定义的错误号
    NIMSDKLocalRes                          = 10000,        /**< 值大于该错误号的都是客户端自定义的错误号。不能随意更改其值！ */
    NIMSDKResRoomLocalNeedRequestAgain      = 10001,    /**< 客户端本地错误号，需要重新向IM服务器获取进入聊天室权限 */
    NIMSDKLocalResNetworkError              = 10010,    /**< 客户端本地错误号，本地网络错误，需要检查本地网络 */

    //客户端自定义的消息错误号
    NIMSDKLocalResMsgNosUploadCancel        = 10200,        /**< (发送文件消息或者stop_upload_ex)HTTP upload to NOS上传暂停 */
    NIMSDKLocalResMsgNosDownloadCancel      = 10206,        /**< (收到文件消息或者stop_download_ex)HTTP download from NOS下载暂停 */
    NIMSDKLocalResMsgNosDownloadCheckError  = 10207,    /**< 收到文件消息，NOS下载完成后本地文件检查错误，一般为下载的文件大小与文件信息不符 */
    NIMSDKLocalResMsgFileNotExist           = 10404,        /**< 本地资源不存在 */
    NIMSDKLocalResParameterError            = 10414,        /**< 本地错误码，参数错误，(收到消息，资源下载地址无效，无法下载) */
    NIMSDKLocalResExist                     = 10417,        /**< 本地错误码，对象已经存在/重复操作，(收到消息，本地资源已存在，不需要重复下载) */
    NIMSDKLocalResParaError                 = 10450,        /**< 调用api，传入的参数有误 */
    NIMSDKLocalResMsgSendNosError           = 10502,        /**< 发送消息，上传NOS失败 */
    NIMSDKLocalResExceedLimit               = 10508,        /**< 本地错误码,超过配置有效期或者所需参数不存在 */
    NIMSDKLocalResCheckMsgDBFailed          = 10600,        /**< 导入消息历史时验证身份和加密密钥不通过 */
    NIMSDKLocalResImportMsgDBFailed         = 10601,        /**< 导入消息历史时写记录失败 */
    NIMSDKLocalResTMembersSyncUndone        = 10602,        /**< 群成员尚同步完成 */
    //客户端自定义的RTS错误号
    NIMSDKLocalResRtsError                  = 11100,        /**< rts会话 未知错误 */
    NIMSDKLocalResRtsIdNotExist             = 11101,        /**< rts会话 id不存在 */
    NIMSDKLocalResRtsVChatExist             = 11417,        /**< rts会话 音视频已存在 */
    NIMSDKLocalResRtsStatusError            = 11501,        /**< rts会话 通道状态不正确 */
    NIMSDKLocalResRtsChannelNotExist        = 11510,        /**< rts会话 通道不存在 */

    NIMSDKResRoomLinkError                  = 13001,        /**< 主链接错误 */
    NIMSDKResRoomError                      = 13002,        /**< 聊天室状态异常 */
    NIMSDKResRoomBlackBeOut                 = 13003,        /**< 黑名单用户禁止进入 */
    NIMSDKResRoomBeMuted                    = 13004,        /**< 被禁言 */
    NIMSDKResRoomAllMuted                   = 13006,        /**< 聊天室处于整体禁言状态,只有管理员能发言 */

    //客户端自定义的api调用问题
    NIMSDKLocalResAPIErrorInitUndone        = 20000,        /**< 还未初始化或初始化未正常完成 */
    NIMSDKLocalResAPIErrorLoginUndone       = 20001,        /**< 还未登陆或登录未完成 */
    NIMSDKLocalResAPIErrorLogined           = 20002,        /**< 已经登录 */
    NIMSDKLocalResAPIErrorVersionError      = 20003,        /**< SDK版本不对，可能会引发其他问题 */
    NIMSDKLocalResAPIErrorChatroomMixError  = 20004,        /**< 聊天室模式混用错误，不支持同时以登陆状态和匿名状态登陆聊天室 */
};


#endif /* NIMSDKResCode_h */
