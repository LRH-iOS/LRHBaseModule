//
//  BaseTableViewController.m
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "BaseTableViewController.h"

@interface BaseTableViewController ()

@end

@implementation BaseTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.page = 1;
}

- (void)createMJRefresh
{
    [self createHeaderRefresh];
    [self createFooterRefresh];
}

- (void)createHeaderRefresh
{
    //self.tableView.mj_header = self.header;
    //[self.tableView.mj_header beginRefreshing];
}

- (void)createFooterRefresh
{
    //self.tableView.mj_footer = self.footer;
    //没数据时自动隐藏
    //self.tableView.mj_footer.automaticallyHidden = YES;
}

- (void)requestRreshData
{
    self.page = 1;
    
    [self requestMJListData];
    
    //[self.tableView.mj_header endRefreshing];
}

- (void)requestMoreData
{
    self.page++;
    
    [self requestMJListData];
    
    //[self.tableView.mj_footer endRefreshing];
}

- (void)requestMJListData
{
    //具体请求放到相应的子类请求
}

#pragma mark - 创建UITableView
- (UITableView *)tableView
{
    if (!_tableView) {
        
        UITableViewStyle style = _isUITableViewStylePlain ? UITableViewStylePlain : UITableViewStyleGrouped;
        _tableView = [[UITableView alloc]initWithFrame:CGRectZero style:style];
        //        _tableView.estimatedRowHeight = 0;
        //        _tableView.estimatedSectionHeaderHeight = 0;
        //        _tableView.estimatedSectionFooterHeight = 0;
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.showsVerticalScrollIndicator = NO;
//        _tableView.backgroundColor = kBgColor;
//        _tableView.separatorColor = kSegLineColor; //分割线颜色
//        _tableView.emptyDataSetSource = self;
//        _tableView.emptyDataSetDelegate = self;
        
        [self.view addSubview:_tableView];
        
        //[self setupEmptyDataView];
        
        //隐藏多余Cell
        self.tableView.tableFooterView = [[UIView alloc]initWithFrame:CGRectZero];
        
    }
    return _tableView;
}

#pragma mark - UITableViewDelegate、UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 1;//self.dataArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 0.001;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return 0.001;
}
- (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    return nil;
}
- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section{
    return nil;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identify = @"UITableViewCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identify];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    return cell;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
