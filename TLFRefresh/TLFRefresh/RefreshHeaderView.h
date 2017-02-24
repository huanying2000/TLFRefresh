//
//  RefreshHeaderView.h
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "RefreshBaseView.h"

@interface RefreshHeaderView : RefreshBaseView<TLFHeaderCircleViewDelegate>

+ (instancetype)headerWithRefreshHandler:(RefreshedHandler )refreshHandler;

@end
