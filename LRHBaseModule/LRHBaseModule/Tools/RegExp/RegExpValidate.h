//
//  RegExpValidate.h
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  正则表达式验证类
 */
@interface RegExpValidate : NSObject

/** 邮箱 */
+ (BOOL)validateEmail:(NSString *)email;

/** 手机号码验证 */
+ (BOOL)validateMobile:(NSString *)mobile;

//验证手机号码的有效性
+ (BOOL)isMobileNumber:(NSString *)mobileNum;

/** 车牌号验证 */
+ (BOOL)validateCarNo:(NSString *)carNo;

/** 车型 */
+ (BOOL)validateCarType:(NSString *)CarType;

/** 用户名 */
+ (BOOL)validateUserName:(NSString *)name;

/** 密码 */
+ (BOOL)validatePassword:(NSString *)passWord;

/** 昵称 */
+ (BOOL)validateNickname:(NSString *)nickname;

/** 身份证号 */
+ (BOOL)validateIdentityCard: (NSString *)identityCard;

/** 判断金钱
 1.只能输入数字和小数点
 2.只能输入一个小数点
 3.小数点后后面只能输入两位数字 */
+ (BOOL)validateMoney: (NSString *)money;


/*
 ========自己后期加的=========
 */

//验证连续相同的3个字符
+ (BOOL)sameCharacter:(NSString *)pwd;

//只能数字
+ (BOOL)onlyNumber:(NSString *)str;

//正则表达式判断只能数字、字母
+ (BOOL)NumAndLetter:(NSString *)str;

//正则表达式判断只能数字字母中文
+ (BOOL)NumAndChineseAndLetter:(NSString *)str;

//正则表达式判断只能数字字母中文下划线
+ (BOOL)NumAndChineseAndLetterAndUnderline:(NSString *)str;

//只能输入中文
+ (BOOL)validateChinese:(NSString *)str;

//统计字符字节数
+ (NSUInteger)unicodeLengthOfString:(NSString *)text;

//也是统计字符字节数的（中英文数字混合都可以）
+ (int)getLenghtDiffDoubletFor:(NSString *)str;

//统计字符长度
+ (int)indexDiffDoubletFor:(NSString *)str atLenght:(int)atLenght;

//字符串中提取数字
+ (int)toGetNumberFromString:(NSString *)str;

/**
 *  验证密码格式是否正确
 *
 */
+ (BOOL)rightPassWord:(NSString *)string withMin:(int)min Max:(int)max;

/**
 * 字符串空值判断
 *
 */
+ (BOOL)isNullString:(NSString *)string;

/**
 判断字典是否为空
 */
+ (BOOL)judgeDictionaryIsNull:(NSDictionary *)dict;

/**
 * 字符串空值、位数判断以及提示
 *
 */
+ (BOOL)verification:(NSString *)str withDigit:(int)digit title:(NSString *)title;

/**
 * 验证密码格式
 *
 */
+ (BOOL)verificationPWD:(NSString *)str withMin:(int)min Max:(int)max title:(NSString *)title;

/**
 *  从字符串中获取数字
 */
+ (int)getNumberToString:(NSString *)str;


@end

NS_ASSUME_NONNULL_END
