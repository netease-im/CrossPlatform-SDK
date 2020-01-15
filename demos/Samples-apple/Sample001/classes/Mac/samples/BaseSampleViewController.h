//
//  BaseSampleViewController.h
//  Samples Mac
//
//  Created by dudu on 2019/12/13.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^BackClick)(NSViewController* vc);

@interface BaseSampleViewController : NSViewController

@property(nonatomic,strong) BackClick backClick;

-(void)setup;

-(void)setupSubViews;

-(void)layoutSubViews;
@end

NS_ASSUME_NONNULL_END
