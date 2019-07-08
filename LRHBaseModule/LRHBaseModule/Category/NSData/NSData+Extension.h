//
//  NSData+Extension.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (Extension)


- (NSData *)lc_SHA256Data;

- (NSData *)reverseData;

- (NSString *)data2Str;

/// CCOperation
- (NSData *)AES256CBCOperation:(uint32_t)operation keyData:(NSData *)key ivData:(NSData *)iv;

//将NSString转换成十六进制的字符串则可使用如下方式:
- (NSString *)lc_convertToHexString;

@end

NS_ASSUME_NONNULL_END
