//
//  UIScrollView+Refresh.h
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RefreshBaseView.h"

@class RefreshHeaderView;
@class RefreshFooterView;

@interface UIScrollView (Refresh)

- (RefreshHeaderView *)addHeaderWithRefreshHandler:(RefreshedHandler)refreshHandler;


- (RefreshFooterView *)addFooterWithRefreshHandler:(RefreshedHandler)refreshHandler;

@end
