//
//  MessageView.m
//  Samples Mac
//
//  Created by dudu on 2019/12/13.
//

#import "MessageView.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface MessageView ()
@property (nonatomic,strong)NSButton* sendeMsgButton;
@property(nonatomic,strong)NSTextField* receivedMsgTextFiled;
@end

@implementation MessageView

-(instancetype)initWithFrame:(NSRect)frameRect
{
    if (self = [super initWithFrame:frameRect]) {
        [self setup];
        [self setupSubViews];
        [self layoutSubViews];
    }
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

-(void)setup
{
    
}

-(void)setupSubViews
{
    _sendeMsgButton = [[NSButton alloc] initWithFrame:NSMakeRect(0, 0, 0, 0)];
    [_sendeMsgButton setBezelStyle:NSBezelStyleRegularSquare];
    [_sendeMsgButton setTitle:@"发送测试消息"];
    [_sendeMsgButton setTarget:self];
    [_sendeMsgButton setAction:@selector(onClicked:)];
        
    [self addSubview:_sendeMsgButton];
    
    _receivedMsgTextFiled = [[NSTextField alloc] initWithFrame:NSMakeRect(0, 0, 0, 200)];
    _receivedMsgTextFiled.lineBreakMode = NSLineBreakByCharWrapping;
    _receivedMsgTextFiled.focusRingType = NSFocusRingTypeNone;
    
    [self addSubview:_receivedMsgTextFiled];
//    
//    self.wantsLayer = YES;
//    CALayer* layer = [CALayer layer];
//    layer.backgroundColor = [NSColor redColor].CGColor;
//    
//    [self setLayer:layer];
}

-(void)layoutSubViews
{
    [_sendeMsgButton makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self).offset(10);
        make.centerX.mas_equalTo(self.centerX);
        make.width.mas_equalTo(@(120));
        make.height.mas_equalTo(@(30));
    }];
    
    
    [_receivedMsgTextFiled makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.sendeMsgButton.bottom).offset(10);
        make.left.mas_equalTo(self).offset(10);
        make.right.mas_equalTo(self).offset(-10);
        make.height.mas_greaterThanOrEqualTo(@(300));
    }];
    
}

-(void)onClicked:(NSButton*)button
{
    if ([_messageDelegate respondsToSelector:@selector(onSendClicked)]) {
        [_messageDelegate onSendClicked];
    }
}

- (void)updateReceivedMsg:(NSString *)msg
{
    if (_receivedMsgTextFiled != nil) {
        [_receivedMsgTextFiled setStringValue:msg ];
    }
}

@end
