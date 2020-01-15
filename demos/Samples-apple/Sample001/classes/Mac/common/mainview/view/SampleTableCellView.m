//
//  SampleTableCellView.m
//  Samples Mac
//
//  Created by dudu on 2019/12/11.
//

#import "SampleTableCellView.h"
@interface SampleTableCellView()
{
    NSTextField* _customTextFiled;
}

@end

@implementation SampleTableCellView

-(instancetype)init
{
    if(self = [super init]){
        [self setup];
    }
    
    return self;
}

-(instancetype)initWithFrame:(NSRect)frameRect
{
    if(self = [super initWithFrame:frameRect]){
        [self setup];
    }
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];
    
    // Drawing code here.
    
    
}

-(void)setObjectValue:(id)objectValue
{
    [super setObjectValue:objectValue];
    
    NSObject* obj = objectValue;
    if ([obj isKindOfClass:[NSObject class]]) {
        
        [self.textField setStringValue:[obj description]];
    }
}

-(void)setup
{
    _customTextFiled = [[NSTextField alloc] init];
    self.textField = _customTextFiled;
}

@end
