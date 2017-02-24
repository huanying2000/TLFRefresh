//
//  RefreshFooterView.h
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "RefreshBaseView.h"

@interface RefreshFooterView : RefreshBaseView<TLFFooterCircleViewDelegate>

/*
 是否自动加载更多 默认上拉超过scrollView的内容高度时 直接加载更多
 */

@property (nonatomic,unsafe_unretained)BOOL autoLoadMore;

+ (instancetype)footerWithRefreshHandler:(RefreshedHandler)refreshHanlder;

//显示没有更多的数据
- (void)showNoMoreData;
//重置没有更多的数据 （消除没有更多的数据动态）
- (void)resetNoMoreData;

@end
