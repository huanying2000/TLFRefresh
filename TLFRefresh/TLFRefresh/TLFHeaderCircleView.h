//
//  TLFHeaderCircleView.h
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TLFHeaderCircleViewDelegate <NSObject>

- (void)startAnimation;

@end

@interface TLFHeaderCircleView : UIView{
    float radius;//圆的半径
    CGPoint center;//圆的中心
    float lineLength;//线的长度
}

@property (nonatomic,assign) float pro;

@property (nonatomic,assign) BOOL isAnimation;

@property (nonatomic,weak) id<TLFHeaderCircleViewDelegate>delegate;

- (void)didScrollWithProgress:(float)progress;


@end
