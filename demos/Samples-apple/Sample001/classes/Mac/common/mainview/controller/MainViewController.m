//
//  MainViewController.m
//  Samples Mac
//
//  Created by dudu on 2019/12/10.
//

#import "MainViewController.h"
#import "BaseSampleViewController.h"
#import "NIMLoginViewController.h"
#import "SampleModel.h"
#import "SampleTableCellView.h"
#import "YYModel.h"
#import "NSString+ext.h"

#define MAS_SHORTHAND
#import "Masonry.h"


#define SampleCellViewCellId @"SampleTableCellView"

@interface MainViewController ()<NSTableViewDelegate,NSTableViewDataSource>
@property (nonatomic,strong)NSTableView* tableView;
@property (nonatomic,strong)NSScrollView* scrollView ;
@property (nonatomic,strong)NSMutableArray* data;
@end

@implementation MainViewController

-(instancetype)initWithNibName:(NSNibName)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    if (self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil]) {
        [self loadView];
        [self setup];

        [self setupSubViews];
        [self layoutSubviews];
    }
    
    return self;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    // Do view setup here.
//    [self setup];
//    [self setupSubViews];
    
}

-(void)dealloc
{
    
}

-(void)setup
{
    NSArray* array = @[
        @{@"title":@"sample1",@"tag":@(1),@"viewController":@"Sample01ViewController"},
        @{@"title":@"sample2",@"tag":@(2),@"viewController":@"Sample02ViewController"},
     ] ;
    
    _data =  [[NSMutableArray alloc] init];
    for (NSDictionary* dict in array) {
        SampleModel* model = [SampleModel yy_modelWithDictionary:dict];
        if(model != nil){
            //[_data addObject:dict];
            [_data addObject:model];

            //[_data addObject:model.title];
        }
    }
}

-(void)setupSubViews
{
    _scrollView = [[NSScrollView alloc] init];
    _scrollView.hasVerticalScroller = YES;
    _scrollView.autohidesScrollers = YES;
    [self.view addSubview: _scrollView];
    
    _tableView = [[NSTableView alloc] initWithFrame:self.view.bounds];
    _tableView.delegate = self;
    _tableView.dataSource = self;
    _tableView.allowsTypeSelect = YES;
    _tableView.selectionHighlightStyle = NSTableViewSelectionHighlightStyleRegular;
    _tableView.allowsEmptySelection = YES;
    _tableView.allowsColumnSelection = YES;
    _tableView.autoresizesSubviews = YES;
    _tableView.floatsGroupRows = YES;
    _tableView.gridStyleMask = NSTableViewGridNone;
    _tableView.gridColor = [NSColor magentaColor];
    _tableView.usesAlternatingRowBackgroundColors = YES;
    
    
    _tableView.headerView = nil;
    _tableView.allowsColumnResizing = YES;
    
        
    NSTableColumn* columm = [[NSTableColumn alloc] initWithIdentifier:SampleCellViewCellId];
    columm.editable = NO;
    [_tableView addTableColumn:columm];
    
    //[self.view addSubview:_scrollView];
    _scrollView.contentView.documentView = _tableView;
    
    [_tableView reloadData];
}

-(void)layoutSubviews
{
    [_scrollView makeConstraints:^(MASConstraintMaker *make) {
        make.centerX.mas_equalTo(self.view.centerX);
        make.centerY.mas_equalTo(self.view.centerY);
        make.size.mas_equalTo(self.view);
    }];
}

-(void)loadView
{
    [self setView:[[NSView alloc] init]];
}

- (void)viewWillLayout
{
    [super viewWillLayout];
    
//    [self.presentedViewControllers enumerateObjectsUsingBlock:^(__kindof NSViewController * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//        obj.view.frame = self.view.frame;
//        [obj.view layout];
//    }];
}
#pragma mark -

-(NSArray*)dataSource
{
    return _data;
}

#pragma mark notification
- (void)tableViewSelectionDidChange:(NSNotification *)notification
{
    NSTableView* tableView = [notification object];
    if (tableView != nil) {
        NSIndexSet* indexers = [tableView selectedRowIndexes];
        if (indexers != nil) {
            [indexers enumerateIndexesUsingBlock:^(NSUInteger idx, BOOL * _Nonnull stop) {
                NSLog(@"currentSelected: %lu",idx);
                
                SampleModel* model = [self.data objectAtIndex:idx];
                if (![NSString isEmptyOrNull:model.viewController]) {
                    Class clz = NSClassFromString(model.viewController);
                    BaseSampleViewController* controller = [[clz alloc] initWithFrame:self.view.bounds];
                    //LoginViewController *controller = [[LoginViewController alloc] init];
                    controller.view.frame = self.view.bounds;
                    controller.title = model.title;

                    [controller setBackClick:^(NSViewController * _Nonnull vc) {
                        [self dismissViewController:vc];
                    }];
                    
                    [self presentViewControllerAsSheet:controller];
                    [self preferredContentSizeDidChangeForViewController:controller];
                    
                    [tableView deselectRow:idx];
//
                }
            }];
        }
    }
}

#pragma mark NSTableViewDelegate
//- (NSView *)tableView:(NSTableView *)tableView viewForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row
//{
//    if (tableColumn == nil) {
//        return nil;
//    }
//    SampleModel* model = [[self dataSource] objectAtIndex:row];
//    SampleTableCellView* view = [tableView makeViewWithIdentifier:tableColumn.identifier owner:self];
//    if (view == nil) {
//        view = [[SampleTableCellView alloc] initWithFrame:NSMakeRect(0, 0, 60, 40)];
//       // view.layer.backgroundColor = [NSColor redColor].CGColor;
//        view.identifier = SampleCellViewCellId;
//        //[view.textField setStringValue:model.title];
//        view.objectValue = model;
//        view.hidden = NO;
//        [view makeConstraints:^(MASConstraintMaker *make) {
//
//        }];
//
//    }
//
//    return view;
//}

//- (NSTableRowView *)tableView:(NSTableView *)tableView rowViewForRow:(NSInteger)row
//{
//    NSTableRowView* rowView =  [[NSTableRowView alloc] init];
//    rowView.selectionHighlightStyle = NSTableViewSelectionHighlightStyleNone;
//
//    return rowView;
//}
#pragma mark NSTableViewDataSource
- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView
{
    return [[self dataSource] count];
}

- (nullable id)tableView:(NSTableView *)tableView objectValueForTableColumn:(nullable NSTableColumn *)tableColumn row:(NSInteger)row
{
    return [[self dataSource] objectAtIndex:row];
}
- (BOOL)tableView:(NSTableView *)tableView shouldEditTableColumn:(nullable NSTableColumn *)tableColumn row:(NSInteger)row
{
    return NO;
}

-(CGFloat)tableView:(NSTableView *)tableView heightOfRow:(NSInteger)row
{
//    NSTableRowView* view = [tableView rowViewAtRow:row makeIfNecessary:NO];
//    if (view.height > 0) {
//
//    }
    return 60.f;
}

@end
