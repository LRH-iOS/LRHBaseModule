//
//  BaseCollectionViewController.m
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "BaseCollectionViewController.h"


@interface BaseCollectionViewController ()

@end

@implementation BaseCollectionViewController

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
//    self.collectionView.mj_header = self.header;
//    [self.collectionView.mj_header beginRefreshing];
}

- (void)createFooterRefresh
{
//    self.collectionView.mj_footer = self.footer;
//    self.collectionView.mj_footer.automaticallyHidden = YES;
}

- (void)requestRreshData
{
    self.page = 1;
    
    [self requestMJListData];
    
    //[self.collectionView.mj_header endRefreshing];
}

- (void)requestMoreData
{
    self.page++;
    
    [self requestMJListData];
    
    //[self.collectionView.mj_footer endRefreshing];
}

- (void)requestMJListData
{
    //具体请求放到相应的子类请求
}


- (UICollectionView *)collectionView
{
    if (!_collectionView) {
        
        _collectionView = [[UICollectionView alloc] initWithFrame:CGRectZero collectionViewLayout:[[UICollectionViewFlowLayout alloc] init]];
        _collectionView.showsVerticalScrollIndicator = NO;
        _collectionView.backgroundColor = UIColor.whiteColor;
        _collectionView.delegate = self;
        _collectionView.dataSource = self;
//        _collectionView.emptyDataSetSource = self;
//        _collectionView.emptyDataSetDelegate = self;
        [self.view addSubview:_collectionView];
        
        [_collectionView registerClass:[UICollectionViewCell class] forCellWithReuseIdentifier:@"UICollectionViewCell"];
        
        //[self setupEmptyDataView];
        
    }
    return _collectionView;
}

#pragma mark - UICollectionViewDataSource
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return 1;//self.dataArray.count;
}

- (UICollectionViewCell *)collectionView: (UICollectionView *)collectionView cellForItemAtIndexPath: (NSIndexPath *)indexPath {
    //重用cell
    static NSString *identify = @"UICollectionViewCell";
    UICollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:identify forIndexPath:indexPath];
    return cell;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
