//
//  UIButton+Extension.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (Extension)

/**
 * 设置带有图片在上文字在下的按钮
 */
- (void)setUIButtonImageUpWithTitleDownUI;

/**
 *  图片在右、文字在左
 */
- (void)setUIButtonImageRightWithTitleLeftUI;

@end

NS_ASSUME_NONNULL_END
