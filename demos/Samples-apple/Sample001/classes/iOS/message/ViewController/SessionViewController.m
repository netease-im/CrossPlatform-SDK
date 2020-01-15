//
//  SessionViewController.m
//  Sample01
//
//  Created by dudu on 2019/11/12.
//

#import "SessionViewController.h"
#import "SessionView.h"
#import "SVProgressHUD.h"
#import "UIView+Toast.h"
#import "NIMSDK.h"
#import "AppUtils.h"
#import "NSString+ext.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface SessionViewController ()<SessionViewDetegate,NIMSDKSessionDelegate,NIMSDKChatroomDelegate>
@property (nonatomic,strong) SessionView* messageView;
@end

#define TEST_CHATROOM_ID 3003

@implementation SessionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self setup];
    [self setupSubviews];
    [self layoutSubviews];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

-(void)setup
{
    [[NIMSDK shared].sessionService addDelegate:self];
    [[NIMSDK shared].chatroomService addDelegate:self];
}

-(void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear: animated];
    
    [[NIMSDK shared].sessionService removeDelegate:self];
    [[NIMSDK shared].chatroomService removeDelegate:self];
}

-(void)setupSubviews
{
    _messageView = [[SessionView alloc] initWithFrame:self.view.bounds];
    _messageView.delegate = self;
    [self.view addSubview:_messageView];
}

-(void)layoutSubviews
{
    [_messageView makeConstraints:^(MASConstraintMaker *make) {
        make.size.equalTo(self.view);
        make.centerX.equalTo(self.view);
        make.centerY.equalTo(self.view);
    }];
}

#pragma mark - session view delegate

-(void)onClicked:(NSInteger)tag
{
    if (tag == 0) {
        [self testSendMessage];
    }
    else if(tag == 1){
        
        [self testEnterChatroom];
    }
    else if(tag == 2){
        
        [self testExitChatroom];
    }
    else if(tag == 3){
        
        [self testOpenApns];
    }
    else if(tag == 4){
        
        [self testCloseApns];
    }
    
}

-(void)testSendMessage
{
    NSTimeInterval now = [[NSDate now] timeIntervalSince1970];
    NSString* nowTimetag = [NSString stringWithFormat:@"%@",@(now)];
    NSString* content = @"这是一条测试消息";
    NIMSDKMessageSetting* messageSetting;
    NIMSDKIMMessage* message = [NIMSDKIMMessage createIMMessage:@"supercaowei" sessionType:NIMSDKSessionTypeP2P messageId:[nowTimetag md5] content:content setting:messageSetting timetag:0];
    [[NIMSDK shared].sessionService sendMessage:message];
    
}

-(void)testEnterChatroom
{
    [[NIMSDK shared].chatroomService RequestTokenWithRoomID:TEST_CHATROOM_ID result:^(NIMSDKResCode code, NSInteger roomID, NSString * _Nullable token) {
        
        if (code == NIMSDKResSuccess) {
            NIMSDKChatRoomEnterInfo* info =[[NIMSDKChatRoomEnterInfo alloc] init];
            info.nick = @"这是一个昵称";
            [[NIMSDK shared].chatroomService EnterWithRoomID:roomID token:token enterInfo:info];
        }
    }];
    
}

-(void)testExitChatroom
{
    [[NIMSDK shared].chatroomService ExitWithRoomID:TEST_CHATROOM_ID];
    
}

-(void)testOpenApns
{
    NSString* deviceToken = [NIMSDK shared].deviceToken;
    NSString* cerName = [NIMSDK shared].apnsCername;
    if (deviceToken == nil || cerName == nil) {
        return;
    }
    [[NIMSDK shared].loginService updatePushToken:deviceToken withCerName:cerName];
    
}

-(void)testCloseApns
{
    
    NSString* deviceToken = [NIMSDK shared].deviceToken;
    if (deviceToken == nil ) {
        return;
    }
    [[NIMSDK shared].loginService updatePushToken:deviceToken withCerName:nil];
    
}

#pragma mark - evnets

-(void)onSendMessageAckResult:(NIMSDKSendMessageResult*)result
{
    NSLog(@"result.rescode : %@,result.msgTimetag : %@,result.msgID : %@,result.sessionID:%@",
          @(result.rescode),@(result.msgTimetag),result.msgID,result.sessionID);
    
    
    [self showToast:[NSString stringWithFormat:@"result.rescode : %@,result.msgTimetag : %@,result.msgID : %@,result.sessionID:%@",@(result.rescode),@(result.msgTimetag),result.msgID,result.sessionID]];
}
-(void)onReceivedMessages:(NSArray<NIMSDKIMReceivedMessage*>*)messages
{
    for (NIMSDKIMReceivedMessage* messgae in messages) {
        
        [self showToast:[messgae description]];
    }
    
}


-(void)onChatroomEnter:(NIMSDKChatRoomEnterResult*)result
{
    [self showToast:[result description]];    
}

-(void)onChatroomExit:(NIMSDKChatRoomExitResult*)result
{    
    NSString* content = [NSString stringWithFormat:@"code:%@--roomID:%@--reason:%@",@(result.resCode),@(result.roomID),@(result.reason)];
    
    [self showToast:[result description]];
    
}

-(void)showToast:(nonnull NSString*)content
{
    [[[UIApplication sharedApplication].delegate window].rootViewController.view makeToast:content duration:2.0 position:CSToastPositionCenter];
}
@end
