//
//  TLFFooterCircleView.m
//  TLFRefresh
//
//  Created by mac on 16/9/14.
//  Copyright © 2016年 mac. All rights reserved.
//

#import "TLFFooterCircleView.h"

@implementation TLFFooterCircleView

- (instancetype) initWithFrame:(CGRect)frame {
    self = [super initWithFrame:frame];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        radius = 10;
        lineLength = 70;
        _isAnimation = NO;
    }
    return self;
}

- (void)drawRect:(CGRect)rect {
    [super drawRect:rect];
    CGPoint CG = CGPointMake(rect.size.width / 2, rect.size.height / 2);
    center = CG;
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSetShouldSubpixelQuantizeFonts(ctx, YES);
    CGContextSetAllowsAntialiasing(ctx, YES);
    
    CGContextBeginPath(ctx);
    CGContextSetStrokeColorWithColor(ctx, [UIColor whiteColor].CGColor);
    
    //画笔的宽度
    CGContextSetLineWidth(ctx, 1.0f);
    
    //绘线
    CGContextMoveToPoint(ctx, center.x, center.y + radius + lineLength * (1 - _pro));
    CGContextAddLineToPoint(ctx, center.x, center.y+radius);
    
    //绘圆
    CGContextAddArc(ctx, center.x, center.y, radius,  M_PI/2 ,5.0/3.0*M_PI*_pro + M_PI_2, 0);
    CGContextDrawPath(ctx, kCGPathStroke);
}

- (void)didScrollWithProgress:(float)progress {
    _pro = progress;
    if ((progress == 1) & !_isAnimation) {
        [self start];
        _isAnimation = YES;
    }
    [self setNeedsDisplay];
}
- (void)start {
    [_delegate startAnimation];
}


























@end
