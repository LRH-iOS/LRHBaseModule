//
//  NSArray+Extension.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray (Extension)

/**
 生成二维数组，避免添加空的数组
 
 @param arrays 数组
 @return 可变的二维数组
 */
+ (NSMutableArray*)lc_arrayWithObject:(NSArray*)arrays,...;

@end

NS_ASSUME_NONNULL_END
