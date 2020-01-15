//
//  SessionView.m
//  Samples iOS
//
//  Created by dudu on 2019/11/27.
//

#import "SessionView.h"
#import "NIMDispatch.h"
#import "SVProgressHUD.h"
#import "UIView+Toast.h"

#define MAS_SHORTHAND
#import "Masonry.h"


@interface SessionView ()
@property (nonatomic,strong) UIButton* sendMessageButton;

@property (nonatomic,strong) UIButton* enterChatroomButton;

@property (nonatomic,strong) UIButton* exitChatroomButton;

@property (nonatomic,strong) UIButton* openApnsButton;

@property (nonatomic,strong) UIButton* closeApnsButton;
@end

@implementation SessionView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

-(instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self setupSubviews];
    }
    return self;
}

-(void)setupSubviews
{
    _sendMessageButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _sendMessageButton.tag = 0;
    _sendMessageButton.frame = CGRectMake(40, 100, 240, 40);
    [_sendMessageButton setTitle:@"testMessageSend" forState:UIControlStateNormal];
    [_sendMessageButton addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    

    _sendMessageButton.backgroundColor = [UIColor redColor];
    [_sendMessageButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    
    _enterChatroomButton.backgroundColor = [UIColor redColor];
    [_enterChatroomButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    
    _enterChatroomButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _enterChatroomButton.tag = 1;
    _enterChatroomButton.frame = CGRectMake(40, 200, 240, 40);
    [_enterChatroomButton setTitle:@"testEnterChatroom" forState:UIControlStateNormal];
    [_enterChatroomButton addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    
    _enterChatroomButton.backgroundColor = [UIColor redColor];
    [_enterChatroomButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];

    
    _exitChatroomButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _exitChatroomButton.tag = 2;
    _exitChatroomButton.frame = CGRectMake(40, 200, 240, 40);
    [_exitChatroomButton setTitle:@"testExitChatroom" forState:UIControlStateNormal];
    [_exitChatroomButton addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    
    _exitChatroomButton.backgroundColor = [UIColor redColor];
    [_exitChatroomButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    
    _openApnsButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _openApnsButton.tag = 3;
    _openApnsButton.frame = CGRectMake(40, 200, 240, 40);
    [_openApnsButton setTitle:@"testOpenApns" forState:UIControlStateNormal];
    [_openApnsButton addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    
    _openApnsButton.backgroundColor = [UIColor redColor];
    [_openApnsButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    
    _closeApnsButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _closeApnsButton.tag = 4;
    _closeApnsButton.frame = CGRectMake(40, 200, 240, 40);
    [_closeApnsButton setTitle:@"testCloseApns" forState:UIControlStateNormal];
    [_closeApnsButton addTarget:self action:@selector(onButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    
    _closeApnsButton.backgroundColor = [UIColor redColor];
    [_closeApnsButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];


    //self.view.backgroundColor = [UIColor redColor];
    
    [self addSubview:_sendMessageButton];
    [self addSubview:_enterChatroomButton];
    [self addSubview:_exitChatroomButton];
    [self addSubview:_openApnsButton];
    [self addSubview:_closeApnsButton];
}

-(void)layoutSubviews
{
    [_sendMessageButton makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.left).offset(50);
        make.top.equalTo(self.top).offset(100);
        make.size.mas_equalTo(CGSizeMake(120, 40));
    }];
    
    [_enterChatroomButton makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.left).offset(50);
        make.top.equalTo(self.top).offset(150);
        make.size.mas_equalTo(CGSizeMake(120, 40));
    }];
    
    [_exitChatroomButton makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.left).offset(50);
        make.top.equalTo(self.top).offset(200);
        make.size.mas_equalTo(CGSizeMake(120, 40));
    }];
    
    [_openApnsButton makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.left).offset(50);
        make.top.equalTo(self.top).offset(250);
        make.size.mas_equalTo(CGSizeMake(120, 40));
    }];
    
    [_closeApnsButton makeConstraints:^(MASConstraintMaker *make) {
        make.left.equalTo(self.left).offset(50);
        make.top.equalTo(self.top).offset(300);
        make.size.mas_equalTo(CGSizeMake(120, 40));
    }];
}

-(void)onButtonClicked:(UIButton*)button
{
    NSInteger tag = [self tagByUIButtion:button];
    if ([_delegate respondsToSelector:@selector(onClicked:)]) {
        [_delegate onClicked:tag];
    }    
}

-(NSInteger)tagByUIButtion:(UIButton*)button
{
    NSInteger tag = button.tag;
//    if (button == _sendMessageButton) {
//        tag = 0;
//    }
//    else if(button == _chatroomButton){
//        tag = 1;
//    }
//
    return tag;
}
@end
    
