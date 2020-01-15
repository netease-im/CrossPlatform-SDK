//
//  SampleModel.m
//  Samples Mac
//
//  Created by dudu on 2019/12/11.
//

#import "SampleModel.h"
#import "YYModel.h"

@interface SampleModel ()<NSCopying>

@end

@implementation SampleModel
-(NSString *)description
{
    return self.title;
}

-(id)copyWithZone:(NSZone *)zone
{
    SampleModel* model = [[SampleModel allocWithZone:zone] init];
    model.title = self.title;
    model.tag = self.tag;
    model.viewController = self.viewController;
    return model;
}
@end
