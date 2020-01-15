//
//  AppDelegate.m
//  Samples Mac
//
//  Created by dudu on 2019/12/9.
//

#import "NIMAppDelegate.h"
#import "NIMLoginViewController.h"
#import "NIMAppUtils.h"
#import "NIMSDK.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    NSLog(@"%s",__func__);
    //NSWindow* window = [NSApplication sharedApplication].mainWindow ;
    _window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 800, 600) styleMask:NSWindowStyleMaskTitled|NSWindowStyleMaskMiniaturizable|NSWindowStyleMaskResizable|NSWindowStyleMaskClosable backing:NSBackingStoreRetained defer:NO];
    [self.window setMinSize:NSMakeSize(400, 600)];
    [self.window setTitle:@"云信"];
    [self.window center];
    [self setMainMenu];
    [self.window makeKeyWindow];
    //[self.window makeMainWindow];
    [[NSApplication sharedApplication] beginModalSessionForWindow:self.window];
    [AppUtils setupRooterViewController:NO];
    
    [[NIMSDK shared] setup];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
    NSLog(@"%s",__func__);
    [[NIMSDK shared] cleanup];
}


-(void)setMainMenu
{
    NSMenu* mainMenu = [[NSMenu alloc] initWithTitle:@"主菜单"];
    NSMenuItem * windowItem = [[NSMenuItem alloc] initWithTitle:@"Window Item" action:Nil keyEquivalent:@""];
    [mainMenu addItem:windowItem];
    
    NSMenu* subMenu = [[NSMenu alloc] initWithTitle:@"子菜单"];
    
    [subMenu addItem:[[NSMenuItem alloc] initWithTitle:@"About" action:@selector(onAbout) keyEquivalent:@""]];
    [subMenu addItem:[[NSMenuItem alloc] initWithTitle:@"Quit" action:@selector(onQuitApplication) keyEquivalent:@""]];
    
    [mainMenu setSubmenu:subMenu forItem:windowItem];
    
    [NSApplication sharedApplication].mainMenu = mainMenu;
}
-(void)onQuitApplication
{
    [[NSApplication sharedApplication] terminate:self];
    
}

-(void)onAbout
{
    
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}
@end
