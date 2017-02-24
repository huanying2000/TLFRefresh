//
//  RefreshBaseView.h
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TLFFooterCircleView.h"
#import "TLFHeaderCircleView.h"

typedef NS_ENUM(NSInteger,ReFreshState){
    RefreshStateNormal = 1,//正常状态
    RefreshStatePulling = 2,//控件正在被拉动
    RefreshStateLoading = 3,//正在加载中
    ReFreshStateNoMoreData = 4 //上拉提示没有更多的数据
};

typedef NS_ENUM(NSInteger,RefreshViewType) {
    RefreshBaseViewTypeHeader = -1,
    RefreshBaseViewTypeFooter = 1
};

//刷新偏移量的高度
static const CGFloat LoadingOffsetHeight = 60;
//文本颜色
#define FCXREFRESHTEXTCOLOR [UIColor colorWithRed:255.0/255.0 green:255.0/255.0 blue:255.0/255.0 alpha:1.0]

@class RefreshBaseView;
typedef void(^RefreshedHandler)(RefreshBaseView *refreshView);

@interface RefreshBaseView : UIView {
    //时间
    UILabel *_timeLabel;
    
    UILabel *_statusLabel;
    UIImageView *_arrowImage;
    TLFHeaderCircleView *_headerCircle;
    TLFFooterCircleView *_footerCircle;
    UIEdgeInsets _originalEdgeInset;
}

@property (nonatomic,strong) UIScrollView *scrollView;//需要添加刷新的滚动视图

@property (nonatomic,copy) RefreshedHandler refreshHander;//相应的当前事件状态

@property (nonatomic,unsafe_unretained) ReFreshState refreshState;//刷新状态


//正常状态下的提示文本
@property(nonatomic,copy) NSString *normalStateText;

//下拉状态下的提示文本
@property (nonatomic,copy) NSString *pullingStateText;

//加载状态下的提示文本
@property (nonatomic,copy) NSString *loadingStateText;

//没有更多数据的时候的提示文本
@property (nonatomic,copy) NSString *noMoreDataStateText;

//设置各种状态的文本
- (void)setStateText;

//添加刷新页面
- (void)addRefreshContentView;

//开始刷新
- (void)startRefresh;

//结束刷新
- (void)endRefresh;

//当scrollView的contentOffSet发生改变的时候调用
- (void)scrollViewContentOffsetDidChange;

//当scrollView的contentSize发生改变的时候调用
- (void)scrollViewContentSizeDidChange;












@end
