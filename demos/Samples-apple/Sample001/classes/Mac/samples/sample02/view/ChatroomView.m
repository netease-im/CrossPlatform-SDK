//
//  ChatroomView.m
//  Samples Mac
//
//  Created by dudu on 2020/1/6.
//

#import "ChatroomView.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface ChatroomView ()

@property (nonatomic,strong)NSButton* enterButton;

@property (nonatomic,strong)NSButton* exitButton;

@property (nonatomic,strong)NSTextField* roomTextField;

@property (nonatomic,strong)NSTextField* displayTextField;

@end

@implementation ChatroomView

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
}

-(instancetype)initWithFrame:(NSRect)frameRect
{
    if (self = [super initWithFrame:frameRect]) {
        [self setup];
        [self setupSubViews];
        [self layoutSubViews];
    }
    
    return self;
}
-(void)setup
{
    
}

-(void)setupSubViews
{
    _enterButton = [[NSButton alloc] initWithFrame:NSMakeRect(0, 0, 0, 0)];
    [_enterButton setBezelStyle:NSBezelStyleRegularSquare];
    [_enterButton setTitle:@"进入房间"];
    [_enterButton setTarget:self];
    [_enterButton setAction:@selector(onEnterClicked:)];
        
    [self addSubview:_enterButton];
    
    _exitButton = [[NSButton alloc] initWithFrame:NSMakeRect(0, 0, 0, 0)];
    [_exitButton setBezelStyle:NSBezelStyleRegularSquare];
    [_exitButton setTitle:@"退出房间"];
    [_exitButton setTarget:self];
    [_exitButton setAction:@selector(onExitClicked:)];
        
    [self addSubview:_exitButton];
    
    _displayTextField = [[NSTextField alloc] initWithFrame:NSMakeRect(0, 0, 0, 200)];
    _displayTextField.lineBreakMode = NSLineBreakByCharWrapping;
    _displayTextField.focusRingType = NSFocusRingTypeNone;
    
    [self addSubview:_displayTextField];
    
    _roomTextField = [[NSTextField alloc] initWithFrame:NSMakeRect(0, 0, 0, 200)];
    _roomTextField.lineBreakMode = NSLineBreakByCharWrapping;
    _roomTextField.focusRingType = NSFocusRingTypeNone;
    [_roomTextField setPlaceholderString:@"Room ID"];
    
    [self addSubview:_roomTextField];
//
//    self.wantsLayer = YES;
//    CALayer* layer = [CALayer layer];
//    layer.backgroundColor = [NSColor redColor].CGColor;
//
//    [self setLayer:layer];
}

-(void)layoutSubViews
{
    [_roomTextField makeConstraints:^(MASConstraintMaker *make) {
           make.top.mas_equalTo(self).offset(10);
           make.centerX.mas_equalTo(self.centerX);
           make.width.mas_equalTo(@(120));
           make.height.mas_equalTo(@(30));
       }];
    
    [_enterButton makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.roomTextField.bottom).offset(10);
        make.centerX.mas_equalTo(self.centerX).offset(-80);
        make.width.mas_equalTo(@(120));
        make.height.mas_equalTo(@(30));
    }];
    
    [_exitButton makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.roomTextField.bottom).offset(10);
        make.centerX.mas_equalTo(self.centerX).offset(80);
        make.width.mas_equalTo(@(120));
        make.height.mas_equalTo(@(30));
    }];
    
    
    [_displayTextField makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(self.enterButton.bottom).offset(10);
        make.left.mas_equalTo(self).offset(10);
        make.right.mas_equalTo(self).offset(-10);
        make.height.mas_greaterThanOrEqualTo(@(300));
    }];
    
}

-(void)onEnterClicked:(NSButton*)button
{
    NSInteger roomID = [_roomTextField.stringValue integerValue];
    
    if ([_sample02Delegate respondsToSelector:@selector(onEnterClicked:)]) {
        [_sample02Delegate performSelector:@selector(onEnterClicked:) withObject:@(roomID)];
    }
}

-(void)onExitClicked:(NSButton*)button
{
    NSInteger roomID = [_roomTextField.stringValue integerValue];
    if ([_sample02Delegate respondsToSelector:@selector(onExitClicked:)]) {
        [_sample02Delegate performSelector:@selector(onExitClicked:) withObject:@(roomID)];
    }
}

#pragma mark -

- (void)showResult:(NSString *)result
{
    if (result == nil) {
        return;
    }
    NSMutableString *mutableString = [[_displayTextField stringValue] mutableCopy];
    [mutableString insertString:@"\r\n\r\n" atIndex:0];
    [mutableString insertString:result atIndex:0];
    [_displayTextField setStringValue:mutableString];
}


@end
