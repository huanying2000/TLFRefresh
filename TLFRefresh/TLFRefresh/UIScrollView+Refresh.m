//
//  UIScrollView+Refresh.m
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "UIScrollView+Refresh.h"
#import "RefreshHeaderView.h"
#import "RefreshFooterView.h"

@implementation UIScrollView (Refresh)


- (RefreshHeaderView *)addHeaderWithRefreshHandler:(RefreshedHandler)refreshHandler {
    RefreshHeaderView *header = [RefreshHeaderView headerWithRefreshHandler:refreshHandler];
    header.scrollView = self;
    return header;
}


- (RefreshFooterView *)addFooterWithRefreshHandler:(RefreshedHandler)refreshHandler{
    RefreshFooterView *footer = [RefreshFooterView footerWithRefreshHandler:refreshHandler];
    footer.scrollView = self;
    return footer;
}

@end
