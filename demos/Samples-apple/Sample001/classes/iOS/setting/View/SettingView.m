//
//  SettingView.m
//  Samples iOS
//
//  Created by dudu on 2019/11/26.
//

#import "SettingView.h"
#import "NIMDispatch.h"
#import "SVProgressHUD.h"
#import "UIView+Toast.h"

#define MAS_SHORTHAND
#import "Masonry.h"

@interface SettingView ()

@end

@implementation SettingView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

-(instancetype)init
{
    if (self = [super init]) {
       [self setSubViews];
    }
    
    return self;
}

-(instancetype)initWithFrame:(CGRect)frame
{
    if (self = [super initWithFrame:frame]) {
        [self setSubViews];
    }
    
    return self;
}

-(void)setSubViews
{
    _logoutButton = [UIButton buttonWithType:UIButtonTypeSystem];
    _logoutButton.frame = CGRectMake(40, 200, 240, 60);
    [_logoutButton setTitle:@"注销" forState:UIControlStateNormal];
    [_logoutButton addTarget:self action:@selector(OnLogoutClicked:) forControlEvents:UIControlEventTouchUpInside];

    _logoutButton.backgroundColor = [UIColor redColor];
    [_logoutButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];

    //self.view.backgroundColor = [UIColor redColor];
    [self addSubview:_logoutButton];
    
    
}

-(void)layoutSubviews
{
    [_logoutButton makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.equalTo(self.centerX);
        make.centerY.equalTo(self.centerY);
        make.size.mas_equalTo(CGSizeMake(160, 80));
    }];
}


#pragma mark - event

-(void)OnLogoutClicked:(UIButton*)button
{
    if([_delegate respondsToSelector:@selector(logoutClicked)]){
        
        [_delegate performSelector:@selector(logoutClicked)];
    }
    
}

@end
