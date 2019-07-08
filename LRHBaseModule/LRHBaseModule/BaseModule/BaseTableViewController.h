//
//  BaseTableViewController.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BaseViewController.h"

NS_ASSUME_NONNULL_BEGIN

@interface BaseTableViewController : BaseViewController <UITableViewDelegate,UITableViewDataSource>

@property (nonatomic, strong) UITableView *tableView;

@property (nonatomic, assign) NSInteger page;

@property (nonatomic, assign) BOOL isUITableViewStylePlain;

/**
 *  配置上下拉刷新／加载更多
 */
- (void)createMJRefresh;

/**
 *  下拉刷新
 */
- (void)createHeaderRefresh;

/**
 *  MJ加载更多
 */
- (void)createFooterRefresh;

@end

NS_ASSUME_NONNULL_END
