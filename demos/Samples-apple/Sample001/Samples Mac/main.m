//
//  main.m
//  Samples Mac
//
//  Created by dudu on 2019/12/9.
//

#import <Cocoa/Cocoa.h>

int main(int argc, const char * argv[]) {

    id delegate = [[NSClassFromString(@"AppDelegate") alloc] init];
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.        
        [NSApplication sharedApplication].delegate = delegate;
    }
    return NSApplicationMain(argc, argv);
}
