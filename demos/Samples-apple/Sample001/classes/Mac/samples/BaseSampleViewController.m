//
//  BaseSampleViewController.m
//  Samples Mac
//
//  Created by dudu on 2019/12/13.
//

#import "BaseSampleViewController.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface BaseSampleViewController ()
@property(nonatomic,strong)NSButton* backButton;
@end

@implementation BaseSampleViewController

-(instancetype)init
{
    if (self = [super init]) {
        [self loadView];
    }
    
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}

-(void)loadView
{
    [self setView:[[NSView alloc] init]];
    CALayer* layer = [[CALayer alloc] init];
    layer.backgroundColor = [NSColor redColor].CGColor;
    [self.view.layer addSublayer:layer];
}

-(void)setup
{
    
}

-(void)setupSubViews
{
    _backButton = [[NSButton alloc] initWithFrame:NSMakeRect(0, 0, 0, 0)];
    [_backButton setBezelStyle:NSBezelStyleRegularSquare];
    [_backButton setTitle:@"返回"];
    [_backButton setTarget:self];
    [_backButton setAction:@selector(OnClicked:)];
    
    _backButton.layer.backgroundColor = [NSColor redColor].CGColor;
    
    [self.view addSubview:_backButton];
}

-(void)layoutSubViews
{
    [_backButton makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(self.view).offset(5);
        make.top.mas_equalTo(self.view).offset(5);
        make.width.mas_equalTo(@(50));
        make.height.mas_equalTo(@(20));
    }];
}

-(void)OnClicked:(NSButton*)button
{
    if(_backClick){
        _backClick(self);
    }
    
}

@end
