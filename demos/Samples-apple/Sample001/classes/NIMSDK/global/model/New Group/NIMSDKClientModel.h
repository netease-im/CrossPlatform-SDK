//
//  NIMSDKClientModel.h
//  Samples iOS
//
//  Created by dudu on 2019/11/25.
//

#import <Foundation/Foundation.h>
#import "NIMSDKClientDefine.h"
#import "NIMSDKResCode.h"

/** @brief 多端登陆客户端信息 */
@interface NIMSDKOtherClientPres : NSObject

@property (nonatomic,strong) NSString *appAccount;            /**< 第三方账号 */

@property (nonatomic,assign) NIMSDKClientType clientType;        /**< 客户端类型, 见NIMClientType */

@property (nonatomic,strong) NSString *clientOS;                /**< 登录系统类型,比如ios 6.0.1 */

@property (nonatomic,strong) NSString *macAddress;            /**< 登录设备的mac地址 */

@property (nonatomic,strong) NSString *deviceID;                /**< 设备id，uuid */

@property (nonatomic,assign) NSInteger loginTimetag;            /**< 本次登陆时间, 精度到ms */

@property (nonatomic,strong) NSString *customData;            /**< 自定义字段>*/

@end

/** @brief 登录结果回调信息 */
@interface NIMSDKLoginRessult : NSObject

@property (nonatomic,assign) NIMSDKResCode resCode;                /**< 返回的错误码NIMResCode */

@property (nonatomic,assign) BOOL relogin;                        /**< 是否为重连过程 */

@property (nonatomic,assign) NIMSDKLoginStep    loginStep;        /**< 登录步骤NIMLoginStep */

@property (nonatomic,strong) NSArray *otherClients;    /**< 其他端的在线状态列表，登录成功才会返回这部分内容 */

@property (nonatomic,assign) BOOL retrying;/**< SDK是否在重试，如果为false，开发者需要检查登录步骤和错误码，明确问题后调用手动重连接口进行登录操作 */

@end

/** @brief 被踢结果回调信息 */
@interface NIMSDKKickoutResult : NSObject

@property (nonatomic,assign) NIMSDKClientType clientType;            /**< int, 客户端类型NIMClientType */

@property (nonatomic,assign) NIMSDKKickReason kickReason;            /**< 返回的被踢原因NIMKickReason */

@end

/** @brief 多端登录回调信息 */
@interface NIMSDKMultiSpotLoginResult : NSObject

@property (nonatomic,assign) NIMSDKMultiSpotNotifyType    notifyType;            /**< NIMMultiSpotNotifyType 多点登录通知类型 */

@property (nonatomic,strong) NSArray *otherClients;        /**< 其他端的在线状态列表 */

@end

/** @brief 踢人结果回调信息 */
@interface NIMSDKKickOtherResult : NSObject

@property (nonatomic,assign) NIMSDKResCode resCode;                    /**< 返回的错误码NIMResCode */

@property (nonatomic,strong) NSArray *deviceIDs;        /**< 设备id，uuid */

@end
