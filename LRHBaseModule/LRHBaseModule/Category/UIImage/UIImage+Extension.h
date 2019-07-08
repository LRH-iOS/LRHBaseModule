//
//  UIImage+Extension.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Extension)

/**
 缩放指定大小
 
 @param newSize 缩放后的尺寸
 @return UIImage
 */
- (UIImage *)resizeImageWithSize:(CGSize)newSize;

/**
 图片圆形裁剪
 
 @return UIImage
 */
- (UIImage *)ovalClip;

//图片宽度
@property(nonatomic, assign, readonly) CGFloat width;

//图片高度
@property(nonatomic, assign, readonly) CGFloat height;

/*!
 *  @author peng_kongan, 15-12-10 14:12:02
 *
 *  @brief  毛玻璃效果
 *
 *  @param blur 效果级别  最小为0 最大为1
 *
 *  @return 毛玻璃化后的图片
 */
- (UIImage *)lc_imageWithBlurLevel:(CGFloat)blur;

/*!
 *  @author peng_kongan, 16-01-15 09:01:30
 *
 *  @brief  将图片存到本地
 *
 *  @param aPath 本地路径
 *
 *  @return 操作结果
 */
- (BOOL)lc_writeToFileAtPath:(NSString*)aPath;

/*!
 *  @author peng_kongan, 15-12-12 13:12:00
 *
 *  @brief  获取屏幕截图
 *
 *  @return 屏幕截图
 */
+ (UIImage *)lc_imageWithScreenContents;



/*!
 *  @author peng_kongan, 15-12-12 13:12:11
 *
 *  @brief  根据颜色创建图片
 *
 *  @param color 颜色
 *
 *  @return UIImage
 */
+ (UIImage *)lc_createImageWithColor:(UIColor *)color;

/*!
 *  @author peng_kongan, 15-12-12 13:12:21
 *
 *  @brief  获取图片模块区域的图
 *
 *  @param rect 区域
 *
 *  @return 截取后的图片
 */
-(UIImage *)lc_imageAtRect:(CGRect)rect;

/*!
 *  @author peng_kongan, 15-12-12 13:12:08
 *
 *  @brief  //成比例的缩小图片
 *
 *  @param targetSize <#targetSize description#>
 *
 *  @return <#return value description#>
 */
- (UIImage *)lc_imageByScalingProportionallyToMinimumSize:(CGSize)targetSize;

/*!
 *  @author peng_kongan, 15-12-12 13:12:30
 *
 *  @brief  //成比例的缩放图片
 *
 *  @param targetSize <#targetSize description#>
 *
 *  @return <#return value description#>
 */
- (UIImage *)lc_imageByScalingProportionallyToSize:(CGSize)targetSize;

/*!
 *  @author peng_kongan, 15-12-12 13:12:15
 *
 *  @brief  拉伸图片到指定大小
 *
 *  @param targetSize <#targetSize description#>
 *
 *  @return <#return value description#>
 */
- (UIImage *)lc_imageByScalingToSize:(CGSize)targetSize;

/*!
 *  @author peng_kongan, 15-12-12 13:12:26
 *
 *  @brief  按弧度旋转
 *
 *  @param radians <#radians description#>
 *
 *  @return <#return value description#>
 */
- (UIImage *)lc_imageRotatedByRadians:(CGFloat)radians;

/*!
 *  @author peng_kongan, 15-12-12 13:12:35
 *
 *  @brief  按角度旋转
 *
 *  @param degrees <#degrees description#>
 *
 *  @return <#return value description#>
 */
- (UIImage *)lc_imageRotatedByDegrees:(CGFloat)degrees;  //按角都旋转

/*!
 *  @author peng_kongan, 15-12-12 13:12:50
 *
 *  @brief  根据宽度 按比例缩放图片
 *
 *  @param newWidth 心的宽度
 *
 *  @return <#return value description#>
 */
- (UIImage *)lc_keepScaleWithWidth:(float) newWidth;     //根据宽度 按比例缩放图片

/*!
 *  @author peng_kongan, 15-12-12 13:12:07
 *
 *  @brief  无损拉伸  适用于IOS5.0以上
 *
 *  @param top    上边距
 *  @param left   左边距
 *  @param bottom 下边距
 *  @param right  右边距
 *
 *  @return 拉伸后的图
 */
- (UIImage *)lc_scaleWithOutDamageInTop:(CGFloat)top     //无损拉伸  试用于ios5.0
                                   left:(CGFloat)left
                                 bottom:(CGFloat)bottom
                                  right:(CGFloat)right;

/**
 *  图片缩放
 *
 *  @param scaleSize 缩放比例
 *
 *  @return 缩放后图片
 */
- (UIImage *)lc_chnageToScale:(float)scaleSize;

/**
 *  中心区域裁剪成方形图片
 *
 *  @param size 目标尺寸，不自动进行放大，实际可能比size要小
 *
 *  @return 裁剪后的图片
 */
- (UIImage *)lc_centerClipBySize:(CGFloat)size;

/**
 *  中心区域裁剪成方形图片
 *
 *  @param size 目标尺寸，不自动进行放大，实际可能比size要小
 *
 *  @return 裁剪后的图片
 */
- (UIImage *)lc_centerScaleToSize:(CGSize)size;

/**
 *  裁剪中心区域固定比例的最大图片
 *
 *  @param rate 裁剪图片比例,比例大于1
 *
 *  @return 裁剪后的图片
 */
- (UIImage *)lc_cutWithWideRate:(CGFloat)rate;

/**
 拉伸图片到指定大小
 
 @param size 制定大小
 @return 新图片
 */
- (UIImage *)lc_imageScalingWithSize:(CGSize)size;

- (UIImage *)lc_imageWithColor:(UIColor *)color;

/**
 *  压缩图片到指定文件大小
 *
 *  @param size  目标大小（最大值）
 *
 *  @return 返回的图片文件
 */
- (NSData *)compressToMaxDataSizeKBytes:(CGFloat)size;

/**
 *  圆形图片
 */
- (UIImage *)circleImage;

/**
 *  设置图片圆角弧度
 */
- (UIImage *)imageWithCornerRadius:(CGFloat)radius;

/**
 *  图片抖动效果
 */
- (UIImage *)applyDarkEffect;

/**
 *  创建透明image
 */
+ (UIImage *)createTransparentImageRect:(CGRect)rect;

/**
 *    @brief 保存为文件
 *
 *  @param fileName path
 *  @param maxValue 超过多少KB就压缩
 *
 */
- (void)writeToFile:(NSString *)fileName compressedAtOver:(CGFloat)maxValue;

/**
 *  截取当前image对象rect区域内的图像
 */
+ (UIImage *)subImageinRect:(UIImage *)image rect:(CGRect)rect;

/**
 *  压缩图片至指定尺寸（会变形）
 */
+ (UIImage *)scaleImageNotKeepingRatio:(UIImage *)image targetSize:(CGSize)targetSize;

/**
 *  压缩图片至指定像素点
 */
+ (UIImage *)scaleImageAtPixel:(UIImage *)image pixel:(CGFloat)pixel;

/**
 *  在指定的size里面生成一张平铺的图片
 */
+ (UIImage *)tiledImage:(UIImage *)image targetSize:(CGSize)targetSize;

/**
 *  UIView转换为UIImage
 */
+ (UIImage *)imageWithView:(UIView *)view;

/**
 *  将两张图片合在一起生成一张图片
 */
+ (UIImage *)mergeImage:(UIImage *)image otherImage:(UIImage *)otherImage;

/**
 *  IOS缩放图片并截取中间部分显示
 */
+ (UIImage*)scaleImage:(UIImage *)image size:(CGSize )size;

/**
 *  图片不变形拉伸
 */
+ (UIImage *)scaleImageKeepingRatio:(UIImage *)image targetSize:(CGSize)targetSize;

/**
 *  颜色转换为背景图片(因为苹果官方没有高亮背景色的方法)
 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/**
 将base64编码转化为图片
 */
+ (UIImage *)baae64DataURL2Image:(NSString *)imgSrc;

/**
 *  截图
 */
+ (UIImage*)getSubImage:(UIImage *)image mCGRect:(CGRect)mCGRect centerBool:(BOOL)centerBool;

/**
 *  绘画Image
 */
+ (UIImage*) GetImageWithColor:(UIColor*)color andHeight:(CGFloat)height;


@end

NS_ASSUME_NONNULL_END
