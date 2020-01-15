//
//  NIMSDKSessionDefine.h
//  Samples iOS
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKSessionDefine_h
#define NIMSDKSessionDefine_h

/** @enum NIMSDKSessionType 会话类型 */
typedef NS_ENUM(NSInteger, NIMSDKSessionType)
{
    NIMSDKSessionTypeP2P            = 0,            /**< 个人，即点对点 */
    NIMSDKSessionTypeTeam            = 1,            /**< 群组 */
    NIMSDKSessionTypeSuperTeam    = 5,            /**< 超大群组 */
};

/** @enum NIMSDKSessionCommand 会话操作命令 */
typedef NS_ENUM(NSInteger, NIMSDKSessionCommand)
{
    NIMSDKSessionCommandAdd                = 0,    /**< 添加会话项 */
    NIMSDKSessionCommandRemove            = 1,    /**< 删除单个会话项 */
    NIMSDKSessionCommandRemoveAll            = 2,    /**< 删除所有会话项 */
    NIMSDKSessionCommandRemoveAllP2P        = 3,    /**< 删除所有点对点的会话项 */
    NIMSDKSessionCommandRemoveAllTeam        = 4,    /**< 删除所有群的会话项 */
    NIMSDKSessionCommandMsgDeleted        = 5,    /**< 单个会话项的消息已删除 */
    NIMSDKSessionCommandAllMsgDeleted        = 6,    /**< 所有会话项的消息已删除 */
    NIMSDKSessionCommandAllP2PMsgDeleted    = 7,    /**< 所有点对点会话项的消息已删除 */
    NIMSDKSessionCommandAllTeamMsgDeleted    = 8,    /**< 所有群会话项的消息已删除 */
    NIMSDKSessionCommandUpdate            = 9,    /**< 更新会话项 */
    NIMSDKSessionCommandRemoveAllSuperTeam = 10,    /**< 删除所有超大群的会话项 */
    NIMSDKSessionCommandAllSuperTeamMsgDeleted = 11,    /**< 所有超大群会话项的消息已删除 */

};



#endif /* NIMSDKSessionDefine_h */
