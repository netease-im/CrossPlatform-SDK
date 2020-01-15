//
//  NIMSDKChatroomModel.h
//  Samples
//
//  Created by dudu on 2019/12/30.
//
#import <Foundation/Foundation.h>
#import "NIMSDKChatroomDefine.h"
#import "NIMSDKResCode.h"

NS_ASSUME_NONNULL_BEGIN

/** @brief 聊天室登录信息*/
@interface NIMSDKChatRoomEnterInfo:NSObject

@property (nonatomic,strong,nullable) NSString* nick;                  /**< 设置进入聊天室后展示的昵称,选填 */

@property (nonatomic,strong,nullable) NSString* avatar;                /**< 设置进入聊天室后展示的头像,选填 */

@property (nonatomic,strong,nullable) NSDictionary* ext;               /**< 设置聊天室可用的扩展字段(),选填 */

@property (nonatomic,strong,nullable) NSDictionary* notifyExt;         /**< 设置进入聊天室通知开发者扩展字段,选填 */

@end


/** @brief 聊天室信息*/
@interface NIMSDKChatRoomInfo:NSObject

@property (nonatomic,assign) NSInteger roomID;                /**< 聊天室ID */

@property (nonatomic,strong) NSString *name;                /**< 聊天室名称 */

@property (nonatomic,strong) NSString *announcement;       /**< 聊天室公告 */

@property (nonatomic,strong) NSString * broadcastUrl;       /**< 视频直播拉流地址 */

@property (nonatomic,strong) NSString *creatorId;       /**< 聊天室创建者账号 */

@property (nonatomic,assign) NSInteger validFlag;       /**< 聊天室有效标记, 1:有效,0:无效 */

@property (nonatomic,strong) NSDictionary *ext;               /**< 第三方扩展字段, 必须为可以解析为json的非格式化的字符串, 长度4k */

@property (nonatomic,assign) NSInteger onlineCount;       /**< 在线人数 */

@property (nonatomic,assign) NSInteger muteAll;           /**< 聊天室禁言标志 1:禁言,0:非禁言*/

@property (nonatomic,assign) NSInteger queueLevel;         /**<int, 队列管理权限：0:所有人都有权限变更队列，1:只有主播管理员才能操作变更*/


@end


/** @brief 聊天室成员信息*/
@interface NIMSDKChatRoomMemberInfo:NSObject

@property (nonatomic,assign) NSInteger roomID;           /**<聊天室id */

@property (nonatomic,strong) NSString *accountId;       /**<成员账号 */

@property (nonatomic,assign) NSInteger type;               /**<成员类型, -2:未设置;-1:受限用户; 0:普通;1:创建者;2:管理员;3:临时用户,非固定成员;4:匿名非注册用户,非云信注册用户*/

@property (nonatomic,assign) NSInteger level;               /**<成员级别: >=0表示用户开发者可以自定义的级别*/

@property (nonatomic,strong) NSString *nick;               /**<聊天室内的昵称字段,预留字段, 可从Uinfo中取*/

@property (nonatomic,strong) NSString *avatar;           /**<聊天室内的头像,预留字段, 可从Uinfo中取icon*/

@property (nonatomic,strong) NSDictionary *ext;               /**<开发者扩展字段, 长度限制2k, 必须为可以解析为json的非格式化的字符串*/

@property (nonatomic,assign) NIMSDKChatRoomOnlineState state;       /**<成员是否处于在线状态, 仅特殊成员才可能离线, 对游客/匿名用户而言只能是在线*/

@property (nonatomic,assign) NIMSDKChatRoomGuestFlag    guestFlag;/**<是否是普通游客类型,0:不是游客,1:是游客; 游客身份在聊天室中没有持久化, 只有在线时才会有内存状态*/

@property (nonatomic,assign) NSInteger enterTimetag;       /**<进入聊天室的时间点,对于离线成员该字段为空*/

@property (nonatomic,assign) BOOL blacklist;       /**<是黑名单*/

@property (nonatomic,assign) BOOL muted;           /**<是禁言用户*/

@property (nonatomic,assign) BOOL valid;           /**<记录有效标记位*/

@property (nonatomic,assign) NSInteger updateTimetag;   /**<固定成员的记录更新时间,用于固定成员列表的排列查询*/

@property (nonatomic,assign) BOOL tempMuted;       /**<临时禁言*/

@property (nonatomic,assign) NSInteger tempMutedDuration;/**<临时禁言的解除时长,单位秒*/

@end

@interface NIMSDKChatRoomEnterResult : NSObject

@property (nonatomic,assign) NIMSDKResCode resCode;     /**<错误码 */

@property (nonatomic,assign) NSInteger roomID;           /**<聊天室id */

@property (nonatomic,assign) NIMSDKChatRoomEnterStep step; /**<聊天室进入状态*/

@property (nonatomic,strong) NIMSDKChatRoomInfo* roomInfo; /**<聊天室信息*/

@property (nonatomic,strong) NIMSDKChatRoomMemberInfo* myInfo; /**<本人在聊天室内的信息*/

@end

@interface NIMSDKChatRoomExitResult : NSObject

@property (nonatomic,assign) NIMSDKResCode resCode;     /**<错误码 */

@property (nonatomic,assign) NSInteger roomID;           /**<聊天室id */

@property (nonatomic,assign) NIMSDKChatRoomExitReason reason; /**<聊天室退出原因*/

@property (nonatomic,strong) NSDictionary* notifyExt; /**<聊天室退出通知附加信息*/

@end


NS_ASSUME_NONNULL_END
