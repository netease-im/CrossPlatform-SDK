//
//  NIMSDKUserDefine.h
//  Samples
//
//  Created by dudu on 2019/11/22.
//

#ifndef NIMSDKUserDefine_h
#define NIMSDKUserDefine_h

/** @enum NIMSDKUserSpecialRelationshipChangeType 用户特殊关系数据变更类型 */
typedef NS_ENUM(NSInteger, NIMSDKUserSpecialRelationshipChangeType)
{
    NIMSDKUserSpecialRelationshipChangeTypeMarkBlack               = 1,    /**< 添加删除黑名单 */
    NIMSDKUserSpecialRelationshipChangeTypeMarkMute                = 2,    /**< 添加删除静音名单 */
    NIMSDKUserSpecialRelationshipChangeTypeSyncMuteAndBlackList    = 3,    /**< 同步黑名单和静音名单 */
};

#endif /* NIMSDKUserDefine_h */
