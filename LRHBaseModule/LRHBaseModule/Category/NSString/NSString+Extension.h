//
//  NSString+Extension.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Extension)

- (NSString *)sha256;

- (NSData *)lc_MD5Data;

- (NSData *)lc_SHA256Data;

// 十六进制转换成NSString
- (NSString *)lc_convertHexStrToString;

//将NSString转换成十六进制的字符串则可使用如下方式:
- (NSString *)lc_convertStringToHexString;

- (NSString *)lc_AESEncryptStringForkey:(NSString *)key;

- (NSString *)lc_AESDecryptStringForkey:(NSString *)key;

//计算字符串高度
+ (CGSize)sizeWithString:(NSString *)string font:(CGFloat)font maxWidth:(CGFloat)maxWidth;

//计算字符串宽度
+ (CGSize)sizeWithString:(NSString *)string font:(CGFloat)font maxHeight:(CGFloat)maxHeight;

/**
 *  改变NSAttributedString
 */
+ (NSAttributedString *)changeTextTypeWithStr:(NSString *)str changeStr:(NSString *)changeStr normalSize:(CGFloat)normalSize changeSize:(CGFloat)changeSize normalColor:(UIColor *)normalColor changeColor:(UIColor *)changeColor isBoldChange:(BOOL)isBold;

@end

NS_ASSUME_NONNULL_END
