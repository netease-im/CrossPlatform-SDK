//
//  Sample01ViewController.m
//  Samples Mac
//
//  Created by dudu on 2019/12/13.
//

#import "Sample01ViewController.h"
#import "NIMDispatch.h"
#import "MessageView.h"
#import "Sample01Adaptor.h"

#define MAS_SHORTHAND
#import "Masonry.h"


@interface Sample01ViewController ()
@property (nonatomic,strong) MessageView* subView;
@property (nonatomic,strong) Sample01Adaptor* adaptor;
@end

@implementation Sample01ViewController

- (instancetype)init
{
    self = [super init];
    if (self) {
        [self setup];
        [self setupSubViews];
        [self layoutSubViews];
    }
    return self;
}

-(instancetype)initWithFrame:(NSRect)frameRect
{
    self = [super init];
    if (self) {
        [self setup];
        [self setupSubViews];
        [self layoutSubViews];
        self.view.frame = frameRect;
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
}

-(void)viewWillAppear
{
    
}

-(void)viewWillDisappear
{
    
}

-(void)setup
{
    [super setup];
    
    _adaptor = [[Sample01Adaptor alloc] init];
}

-(void)setupSubViews
{
    _subView = [[MessageView alloc] initWithFrame:self.view.bounds];
    
    [self.view addSubview:_subView];
    
    [super setupSubViews];
    
    
    _adaptor.mv = _subView;
    _subView.messageDelegate = _adaptor;
}

-(void)layoutSubViews
{
    [super layoutSubViews];
    
    [_subView makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.view.centerX);
        make.centerY.mas_equalTo(self.view.centerY);
        make.size.mas_equalTo(self.view);
    }];
    
}

@end
