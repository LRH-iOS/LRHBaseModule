//
//  UILabel+Extension.m
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "UILabel+Extension.h"

@implementation UILabel (Extension)

+ (CGSize)getSizeFromNSString:(NSString *)str maxSize:(CGSize)maxSize withFont:(UIFont *)font
{
    NSDictionary *attribute = @{NSFontAttributeName:font};
    
    CGSize size = [str boundingRectWithSize:maxSize options: NSStringDrawingTruncatesLastVisibleLine | NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading attributes:attribute context:nil].size;
    return size;
}

+ (CGRect)formatLabel:(UILabel *)lbl maxSize:(CGSize)maxSize;
{
    CGSize expectedLabelSize = [self getSizeFromNSString:lbl.text maxSize:maxSize withFont:lbl.font];
    
    [lbl setNumberOfLines:0];
    CGRect newFrame = lbl.frame;
    newFrame.size.height = expectedLabelSize.height;
    newFrame.size.width = maxSize.width;
    lbl.frame = newFrame;
    return newFrame;
}

+ (CGRect)formatLimitFourRowLabel:(UILabel *)lbl maxSize:(CGSize)maxSize;
{
    NSString *onerowStr = @"null";
    
    CGSize oneRowLabelSize = [self getSizeFromNSString:onerowStr maxSize:maxSize withFont:lbl.font];
    CGSize expectedLabelSize = [self getSizeFromNSString:lbl.text maxSize:maxSize withFont:lbl.font];
    
    [lbl setNumberOfLines:4];
    CGRect newFrame = lbl.frame;
    newFrame.size.height = oneRowLabelSize.height * 4 < expectedLabelSize.height ? oneRowLabelSize.height * 4 : expectedLabelSize.height;
    newFrame.size.width = maxSize.width;
    lbl.frame = newFrame;
    return newFrame;
}

+ (NSMutableAttributedString *)setLabelRowSpace:(CGFloat)space str:(NSString *)str
{
    NSMutableAttributedString *attributedString = [[NSMutableAttributedString alloc] initWithString:str];
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    [paragraphStyle setLineSpacing:space];//设置行间距
    [attributedString addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:NSMakeRange(0, str.length)];
    return attributedString;
}


@end
