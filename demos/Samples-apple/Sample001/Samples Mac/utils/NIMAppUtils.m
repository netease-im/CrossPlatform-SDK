//
//  AppUtils.m
//  Samples Mac
//
//  Created by dudu on 2019/12/10.
//

#import "NIMAppUtils.h"
#import "NIMLoginViewController.h"
#import "MainViewController.h"

@implementation AppUtils
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/
+(void)setupRooterViewController:(BOOL)mainViewController
{
    NSWindow* window =  [NSApplication sharedApplication].mainWindow;
    if (mainViewController) {
        window.contentViewController = [[MainViewController alloc] initWithNibName:nil bundle:nil];
        [window setContentSize:NSMakeSize(800, 600)];
        [window center];
    }
    else
    {
        LoginViewController *loginController = [[LoginViewController alloc] init];
        window.contentViewController = loginController;
        
    }
}
@end
