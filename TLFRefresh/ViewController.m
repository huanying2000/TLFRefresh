//
//  ViewController.m
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "ViewController.h"
#import "TLFRefresh.h"

@interface ViewController ()<UITableViewDelegate,UITableViewDataSource>
{
    UITableView *table;
    RefreshHeaderView *headerView;
    RefreshFooterView *footerView;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationController.navigationBar.translucent = NO;
    
    table = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height - 64) style:UITableViewStylePlain];
    table.delegate = self;
    table.dataSource = self;
    table.tableFooterView = [UIView new];
    
    [table registerClass:[UITableViewCell class] forCellReuseIdentifier:@"CELL"];
    [self.view addSubview:table];
    __weak __typeof (self)weakself = self;
    
    headerView = [table addHeaderWithRefreshHandler:^(RefreshBaseView *refreshView) {
        
        [weakself performSelector:@selector(handleRefresh) withObject:nil afterDelay:2.0];
    }];
    
    
    footerView = [table addFooterWithRefreshHandler:^(RefreshBaseView *refreshView) {
        [weakself performSelector:@selector(handleRefresh) withObject:nil afterDelay:2.0];
    }];
}

- (void)handleRefresh
{
    NSLog(@"哈哈哈哈哈");
    [headerView endRefresh];
    [footerView endRefresh];
}



- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 20;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"CELL"];
    cell.textLabel.text = [NSString stringWithFormat:@"%ld--%ld",(long)indexPath.section,(long)indexPath.row];
    return cell;
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    
}

@end
