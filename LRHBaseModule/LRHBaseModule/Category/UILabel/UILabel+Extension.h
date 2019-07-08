//
//  UILabel+Extension.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UILabel (Extension)

/**
 计算出多行文字转行适配Size
 */
+ (CGSize)getSizeFromNSString:(NSString *)str maxSize:(CGSize)maxSize withFont:(UIFont *)font;

//格式化Labal
+ (CGRect)formatLabel:(UILabel *)lbl maxSize:(CGSize)maxSize;

/**
 计算label最多四行的size
 */
+ (CGRect)formatLimitFourRowLabel:(UILabel *)lbl maxSize:(CGSize)maxSize;

/**
 *  设置label多行时行间距
 **/
+ (NSMutableAttributedString *)setLabelRowSpace:(CGFloat)space str:(NSString *)str;

@end

NS_ASSUME_NONNULL_END
