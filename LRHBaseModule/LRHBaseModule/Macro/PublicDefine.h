//
//  PublicDefine.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#ifndef PublicDefine_h
#define PublicDefine_h

#parm mark - 基础信息配置
// 屏幕宽度
#define kScreenWidth    MIN([[UIScreen mainScreen]bounds].size.width, [[UIScreen mainScreen]bounds].size.height)
// 屏幕高度
#define kScreenHeight   MAX([[UIScreen mainScreen]bounds].size.width, [[UIScreen mainScreen]bounds].size.height)

//6为标准适配的,如果需要其他标准可以修改
#define kScale_W(w)     (kScreenWidth/375) * (w)
#define kScale_H(h)     (kScreenHeight/667) * (h)

// 状态栏高度
#define kStatusBarHeight  ([UIApplication sharedApplication].statusBarFrame.size.height)

// 导航栏高度
#define kNavigationBarHeight  44.f

// 导航栏加状态栏高度
#define kNavStatusHeight  (kNavigationBarHeight + kStatusBarHeight)

// Tabbar高度
#define kTabBarHeight     (kISiPhoneX ? (49.f+34.f) : 49.f)

// 安全区域间隔
#define kSafeAreInsets(view) ({UIEdgeInsets insets; if(@available(iOS 11.f, *)) {insets = view.safeAreaInsets;} else {insets = UIEdgeInsetsZero;} insets;})

// 底部安全距离
#define kBottomSafeMargin   (kISiPhoneX ? 34.f : 0.f)
// 顶部安全距离
#define kTopSafeMargin      (kISiPhoneX ? 24.f : 0.f)
// 横屏左右的安全距离
#define kLandscapeSafeMargin (kISiPhoneX ? 44.f : 0.f)
// 横屏左右的视频安全距离
#define kLandscapeVideoSafeMargin (kISiPhoneX ? 64.f : 0.f)


#parm mark - 手机型号
#define kISiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define kScreenMaxLength (MAX(kScreenWidth, kScreenHeight))
#define kScreenMinLength (MIN(kScreenWidth, kScreenHeight))
#define kISiPhone5  (kISiPhone && kScreenMaxLength == 568.0)
#define kISiPhone6  (kISiPhone && kScreenMaxLength == 667.0)
#define kISiPhone6P (kISiPhone && kScreenMaxLength == 736.0)
#define kISiPhoneX  (kISiPhone && kScreenMaxLength == 812.0)
#define kISiPhoneXr (kISiPhone && kScreenMaxLength == 896.0)
#define kISiPhoneXX (kISiPhone && kScreenMaxLength > 811.0)
#define kIOS8+  ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)
#define kIOS10+ ([[[UIDevice currentDevice] systemVersion] floatValue] >= 10.0)
#define kIOS11+ ([[[UIDevice currentDevice] systemVersion] floatValue] >= 11.0)

#parm mark - 字体样式
//字体适配
#define kScaleFont(fontSize) [UIFont systemFontOfSize: fontSize*kScreenWidth/375]
#define kBoldFont(x)    [UIFont boldSystemFontOfSize:x]
#define kFont(x)        [UIFont systemFontOfSize:x]
#define kNameFont(x)    [UIFont fontWithName:@"Heiti SC" size:x]

#parm mark - 颜色设置
//RGB格式
#define kRGB(r, g, b)       [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
//RGBA格式
#define kRGBA(r, g, b, a)   [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a]
//随机颜色
#define kRandomColor        [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

#parm mark - 系统对象
//APP对象 （单例对象）
#define kApplication    [UIApplication sharedApplication]
// 主窗口
#define kMainWindow     ([UIApplication sharedApplication].delegate).window
//NSUserDefaults实例化
#define kUserDefaults   [NSUserDefaults standardUserDefaults]
//通知中心 （单例对象）
#define kNotificationCenter [NSNotificationCenter defaultCenter]
//发送通知
#define KPostNotification(name,obj,info) [[NSNotificationCenter defaultCenter]postNotificationName:name object:obj userInfo:info]
//APP版本号
#define kVersion [[[NSBundle mainBundle] infoDictionary] valueForKey:@"CFBundleShortVersionString"]
//系统版本号
#define kSystemVersion [[UIDevice currentDevice] systemVersion]

//加载图片
#define kGetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
//弱引用
#define kWeakSelf(type)  __weak typeof(type) weak##type = type
//强引用
#define kStrongSelf(type)  __strong typeof(type) type = weak##type
//安全调用Block
#define kSafeBlock(blockName,...) ({!blockName ? nil : blockName(__VA_ARGS__);})
//加载xib
#define kLoadNib(nibName) [UINib nibWithNibName:nibName bundle:[NSBundle mainBundle]]
//字符串拼接
#define kStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]
//属性快速声明（建议使用代码块）
#define kPropertyString(name)       @property(nonatomic,copy) NSString *name;
#define kPropertyStrong(type,name)  @property(nonatomic,strong) type *name;
#define kPropertyAssign(name)       @property(nonatomic,assign) NSInteger name;
// View 圆角和加边框
#define kViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]
// View 圆角
#define kViewRadius(View, Radius)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]
//永久存储对象
#define kSetUserDefaults(object, key)                                                                                                 \
({                                                                                                                                             \
NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults];                                                                         \
[defaults setObject:object forKey:key];                                                                                                    \
[defaults synchronize];                                                                                                                    \
})
//获取对象
#define kGetUserDefaults(key) [[NSUserDefaults standardUserDefaults] objectForKey:key]
//删除某一个对象
#define kRemoveUserDefaults(key)                                         \
({                                                                          \
NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];       \
[defaults removeObjectForKey:_key];                                     \
[defaults synchronize];                                                 \
})
//清除 NSUserDefaults 保存的所有数据
#define kRemoveAllUserDefaults  [[NSUserDefaults standardUserDefaults] removePersistentDomainForName:[[NSBundle mainBundle] bundleIdentifier]]

#parm mark - 获取时间
//获得当前的年份
#define  kCurrentYear   [[NSCalendar currentCalendar] component:NSCalendarUnitYear fromDate:[NSDate date]]
//获得当前的月份
#define  kCurrentMonth  [[NSCalendar currentCalendar] component:NSCalendarUnitMonth fromDate:[NSDate date]]
//获得当前的日期
#define  kCurrentDay    [[NSCalendar currentCalendar] component:NSCalendarUnitDay fromDate:[NSDate date]]
//获得当前的小时
#define  kCurrentHour   [[NSCalendar currentCalendar] component:NSCalendarUnitHour fromDate:[NSDate date]]
//获得当前的分
#define  kCurrentMin    [[NSCalendar currentCalendar] component:NSCalendarUnitMinute fromDate:[NSDate date]]
//获得当前的秒
#define  kCurrentSec    [[NSCalendar currentCalendar] component:NSCalendarUnitSecond fromDate:[NSDate date]]

#parm mark - 沙盒路径
//获取沙盒 temp
#define kPathTemp NSTemporaryDirectory()
//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
//Library/Caches 文件路径
#define kFilePath ([[NSFileManager defaultManager] URLForDirectory:NSCachesDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:YES error:nil])


#parm mark - 线程
//GCD - 在Main线程上运行
#define kMainThread(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);
//GCD - 开启异步线程
#define kGlobalThread(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);

#parm mark - 判空
//字符串是否为空
#define kISNullString(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
//数组是否为空
#define kISNullArray(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0 ||[array isEqual:[NSNull null]])
//字典是否为空
#define kISNullDict(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0 || [dic isEqual:[NSNull null]])
//是否是空对象
#define kISNullObject(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))
//判断对象是否为空,为空则返回默认值
#define kGetNullDefaultObj(_value,_default) ([_value isKindOfClass:[NSNull class]] || !_value || _value == nil || [_value isEqualToString:@"(null)"] || [_value isEqualToString:@"<null>"] || [_value isEqualToString:@""] || [_value length] == 0)?_default:_value

#parm mark - 自定义Log
#ifdef DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) nil
#endif


#endif /* PublicDefine_h */
