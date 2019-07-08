//
//  RegExpValidate.m
//  LRHBaseModule
//
//  Created by LRH on 2019/7/8.
//  Copyright © 2019 LRH. All rights reserved.
//

#import "RegExpValidate.h"

@implementation RegExpValidate

//邮箱
+ (BOOL)validateEmail:(NSString *)email
{
    NSString *emailRegex = @"[A-Z0-9a-z._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,4}";
    NSPredicate *emailTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", emailRegex];
    return [emailTest evaluateWithObject:email];
}

//手机号码验证
+ (BOOL)validateMobile:(NSString *)mobile
{
    //手机号以13， 15，18开头，八个 \d 数字字符
    NSString *phoneRegex = @"^((13[0-9])|(15[^4,\\D])|(18[0,0-9]))\\d{8}$";
    NSPredicate *phoneTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",phoneRegex];
    return [phoneTest evaluateWithObject:mobile];
}

#pragma mark -  手机号码的有效性判断
+ (BOOL)isMobileNumber:(NSString *)mobileNum
{
    /**
     * 手机号码
     * 移动：134[0-8],135,136,137,138,139,147,150,151,152,157,158,159,182,187,188
     * 联通：130,131,132,155,156,185,186
     * 电信：133,1349,153,180,181,189,177
     */
    NSString * MOBILE = @"^1(3[0-9]|47|5[0-35-9]|8[025-9])\\d{8}$";
    /**
     10         * 中国移动：China Mobile
     11         * 134[0-8],135,136,137,138,139,150,151,157,158,159,182,187,188
     12         */
    NSString * CM = @"^1(34[0-8]|(3[5-9]|5[017-9]|8[278])\\d)\\d{7}$";
    /**
     15         * 中国联通：China Unicom
     16         * 130,131,132,152,155,156,185,186
     17         */
    NSString * CU = @"^1(3[0-2]|5[256]|8[56])\\d{8}$";
    /**
     20         * 中国电信：China Telecom
     21         * 133,1349,153,180,181,189
     22         */
    NSString * CT = @"^1((33|53|8[019]|77)[0-9]|349)\\d{7}$";
    /**
     25         * 大陆地区固话及小灵通
     26         * 区号：010,020,021,022,023,024,025,027,028,029
     27         * 号码：七位或八位
     28         */
    // NSString * PHS = @"^0(10|2[0-5789]|\\d{3})\\d{7,8}$";
    
    NSPredicate *regextestmobile = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", MOBILE];
    NSPredicate *regextestcm = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CM];
    NSPredicate *regextestcu = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CU];
    NSPredicate *regextestct = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", CT];
    
    if (([regextestmobile evaluateWithObject:mobileNum])
        || ([regextestcm evaluateWithObject:mobileNum])
        || ([regextestct evaluateWithObject:mobileNum])
        || ([regextestcu evaluateWithObject:mobileNum]))
    {
        return YES;
    } else {
        return NO;
    }
}


//车牌号验证
+ (BOOL)validateCarNo:(NSString *)carNo
{
    NSString *carRegex = @"^[\u4e00-\u9fa5]{1}[a-zA-Z]{1}[a-zA-Z_0-9]{4}[a-zA-Z_0-9_\u4e00-\u9fa5]$";
    NSPredicate *carTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",carRegex];
    NSLog(@"carTest is %@",carTest);
    return [carTest evaluateWithObject:carNo];
}

//车型
+ (BOOL)validateCarType:(NSString *)CarType
{
    NSString *CarTypeRegex = @"^[\u4E00-\u9FFF]+$";
    NSPredicate *carTest = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",CarTypeRegex];
    return [carTest evaluateWithObject:CarType];
}

//用户名
+ (BOOL)validateUserName:(NSString *)name
{
    NSString *userNameRegex = @"^[A-Za-z0-9]{6,20}+$";
    NSPredicate *userNamePredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",userNameRegex];
    BOOL B = [userNamePredicate evaluateWithObject:name];
    return B;
}

//密码
+ (BOOL)validatePassword:(NSString *)passWord
{
    NSString *passWordRegex = @"^[a-zA-Z0-9]{6,20}+$";
    NSPredicate *passWordPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",passWordRegex];
    return [passWordPredicate evaluateWithObject:passWord];
}

//昵称
+ (BOOL)validateNickname:(NSString *)nickname
{
    NSString *nicknameRegex = @"^[\u4e00-\u9fa5]{4,8}$";
    NSPredicate *passWordPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",nicknameRegex];
    return [passWordPredicate evaluateWithObject:nickname];
}

//身份证号
+ (BOOL)validateIdentityCard: (NSString *)identityCard
{
    BOOL flag;
    if (identityCard.length <= 0) {
        flag = NO;
        return flag;
    }
    NSString *regex2 = @"^(\\d{14}|\\d{17})(\\d|[xX])$";
    NSPredicate *identityCardPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES %@",regex2];
    return [identityCardPredicate evaluateWithObject:identityCard];
}

// 金钱
+ (BOOL)validateMoney:(NSString *)money {
    NSString *reg1 = @"^[0-9]+\\.[0-9]{0,1}$";
    NSPredicate *pre1 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", reg1];
    
    NSString *reg2 = @"^\\d+$";
    NSPredicate *pre2 = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", reg2];
    if ([pre1 evaluateWithObject:money] || [pre2 evaluateWithObject:money]) {
        return YES;
    }
    
    return NO;
}

#pragma mark - 正则表达式判断连续字符相同的3个数
+ (BOOL)sameCharacter:(NSString *)pwd
{
    BOOL flag;
    if (pwd.length <= 0) {
        flag = NO;
        return flag;
    }
    NSString *regex = @"(.)*(.)\\2{2}(.)*";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:pwd];
}

#pragma mark - 正则表达式判断只能数字
+ (BOOL)onlyNumber:(NSString *)str
{
    BOOL flag;
    if (str.length <= 0) {
        flag = NO;
        return flag;
    }
    NSString *regex = @"^[0-9]*$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:str];
}

#pragma mark - 正则表达式判断只能数字、字母
+ (BOOL)NumAndLetter:(NSString *)str
{
    BOOL flag;
    if (str.length <= 0) {
        flag = NO;
        return flag;
    }
    NSString *regex = @"^[0-9a-zA-Z]+$";//@"[a-zA-Z\0-9]+";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:str];
}


#pragma mark - 正则表达式判断只能数字、字母、中文
+ (BOOL)NumAndChineseAndLetter:(NSString *)str
{
    BOOL flag;
    if (str.length <= 0) {
        flag = NO;
        return flag;
    }
    NSString *regex = @"[a-zA-Z\u4e00-\u9fa5\0-9]+";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:str];
}

#pragma mark - 正则表达式判断只能数字、字母、中文、下划线
+ (BOOL)NumAndChineseAndLetterAndUnderline:(NSString *)str
{
    BOOL flag;
    if (str.length <= 0) {
        flag = NO;
        return flag;
    }
    NSString *regex = @"^[\u4e00-\u9fa5_a-zA-Z0-9]+$";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:str];
}

#pragma mark - 只能输入中文
+ (BOOL)validateChinese:(NSString *)str
{
    BOOL flag;
    if (str.length <= 0) {
        flag = NO;
        return flag;
    }
    NSString *regex = @"[\u4e00-\u9fa5]+";
    NSPredicate *pred = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regex];
    return [pred evaluateWithObject:str];
}


#pragma mark - 字符字节数统计（中文数字英文混合时求出多少字符）
+ (NSUInteger)unicodeLengthOfString:(NSString *)text {
    NSUInteger asciiLength = 0;
    
    for (NSUInteger i = 0; i < text.length; i++) {
        
        unichar uc = [text characterAtIndex: i];
        
        asciiLength += isascii(uc) ? 1 : 2;
    }
    
    //    NSUInteger unicodeLength = asciiLength / 2;
    //
    //    if(asciiLength % 2) {
    //        unicodeLength++;
    //    }
    
    return asciiLength;
}

#pragma mark - 统计字符字节数
+ (int)getLenghtDiffDoubletFor:(NSString *)str
{
    int len = 0;
    for (int i = 0; i < [str length]; i++) {
        int son = [str characterAtIndex:i];
        if (son > 0x4e00 && son < 0x9fff) {
            len+=2;
        }else{
            len+=1;
        }
    }
    return len;
}

#pragma mark - 统计字符长度
+ (int)indexDiffDoubletFor:(NSString *)str atLenght:(int)atLenght
{
    int len = 0,idx = 0;
    for (int i = 0; i < [str length]; i++) {
        int son = [str characterAtIndex:i];
        if (son > 0x4e00 && son < 0x9fff) {
            len+=2;
        }else{
            len+=1;
        }
        
        if(len >= atLenght)
            break;
        idx++;
    }
    return idx;
}

#pragma mark - 从字符串中提取数字
+ (int)toGetNumberFromString:(NSString *)str
{
    NSMutableString *numberString = [[NSMutableString alloc] init];
    NSString *tempStr;
    NSScanner *scanner = [NSScanner scannerWithString:str];
    NSCharacterSet *numbers = [NSCharacterSet characterSetWithCharactersInString:@"0123456789"];
    
    while (![scanner isAtEnd]) {
        // Throw away characters before the first number.
        [scanner scanUpToCharactersFromSet:numbers intoString:NULL];
        
        // Collect numbers.
        [scanner scanCharactersFromSet:numbers intoString:&tempStr];
        [numberString appendString:tempStr];
        tempStr = @"";
    }
    int number = [numberString intValue];
    return number;
}

//验证密码格式是否正确
+(BOOL)rightPassWord:(NSString *)string withMin:(int)min Max:(int)max
{
    if (string.length >= min && string.length <= max) {
        return YES;
    } else {
        return NO;
    }
}

+ (BOOL)isNullString:(NSString *)string {
    if (string == nil || string == NULL) {
        return YES;
    }
    if ([string isKindOfClass:[NSNull class]]) {
        return YES;
    }
    if ([[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] length]==0) {
        return YES;
    }
    return NO;
}

#pragma mark - 判断数据是否为空
+ (BOOL)judgeDictionaryIsNull:(NSDictionary *)dict
{
    if([dict isKindOfClass:[NSNull class]])
    {
        return YES;
    }  else if (dict == nil) {
        
        return YES;
    }else {
        return NO;
    }
}

+ (BOOL)verification:(NSString *)str withDigit:(int)digit title:(NSString *)title
{
    if ([self isNullString:str]) {
        
        //[SVProgressHUD showErrorWithStatus:[NSString stringWithFormat:@"%@不能为空",title]];
        return NO;
        
    } else if (str.length != digit) {
        
        //[SVProgressHUD showErrorWithStatus:[NSString stringWithFormat:@"%@输入有误",title]];
        return NO;
        
    } else {
        
        return YES;
    }
}

+ (BOOL)verificationPWD:(NSString *)str withMin:(int)min Max:(int)max title:(NSString *)title
{
    if ([self isNullString:str]) {
        
        //[SVProgressHUD showErrorWithStatus:[NSString stringWithFormat:@"%@不能为空",title]];
        return NO;
        
    } else if (![self rightPassWord:str withMin:min Max:max]) {
        
        //[SVProgressHUD showErrorWithStatus:[NSString stringWithFormat:@"%@输入有误",title]];
        return NO;
        
    } else {
        
        return YES;
    }
}

+ (int)getNumberToString:(NSString *)str
{
    NSScanner *scanner = [NSScanner scannerWithString:str];
    [scanner scanUpToCharactersFromSet:[NSCharacterSet decimalDigitCharacterSet] intoString:nil];
    int number;
    [scanner scanInt:&number];
    return number;
}


@end
