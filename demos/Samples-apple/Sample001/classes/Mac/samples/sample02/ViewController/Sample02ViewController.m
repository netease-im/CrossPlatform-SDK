//
//  Sample02ViewController.m
//  Samples Mac
//
//  Created by dudu on 2020/1/6.
//

#import "Sample02ViewController.h"
#import "ChatroomView.h"
#import "Sample02Adaptor.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface Sample02ViewController ()
@property (nonatomic,strong) ChatroomView* subView;
@property (nonatomic,strong) Sample02Adaptor* adaptor;
@end

@implementation Sample02ViewController

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

-(void)setup
{
    [super setup];
    
    _adaptor = [[Sample02Adaptor alloc] init];
}

-(void)setupSubViews
{
    _subView = [[ChatroomView alloc] initWithFrame:self.view.bounds];
    
    [self.view addSubview:_subView];
    
    [super setupSubViews];
    
    
    _adaptor.delegate = _subView;
    _subView.sample02Delegate = _adaptor;
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
