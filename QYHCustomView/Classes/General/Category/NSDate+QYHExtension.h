//
//  NSDate+QYHExtension.h
//  QYHProgressHUD
//
//  Created by saj-king on 2020/4/13.
//  Copyright © 2020 SAJ. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (QYHExtension)

///时间戳
@property (nonatomic,copy,readonly) NSString *timestamp;
///时间成分
@property (nonatomic,strong,readonly) NSDateComponents *components;
///是否是今年
@property (nonatomic,assign,readonly) BOOL isThisYear;
///是否是本月
@property (nonatomic,assign,readonly) BOOL isThisMonth;
///是否是今天
@property (nonatomic,assign,readonly) BOOL isToday;
///是否是昨天
@property (nonatomic,assign,readonly) BOOL isYesToday;

-(BOOL)isToweek;

/**
 *  Get方法
 */
- (NSInteger)year;
- (NSInteger)month;
- (NSInteger)day;
- (NSInteger)hour;
- (NSInteger)minute;
- (NSInteger)second;
- (NSString *)weekday;

/**
 *  获取NSDate时间
 */
+ (NSDate *)dateWithYear:(NSInteger)year
                   month:(NSInteger)month
                     day:(NSInteger)day
                    hour:(NSInteger)hour
                  minute:(NSInteger)minute
                  second:(NSInteger)second;
/**
 *  获取年月日(NSString)
 */
+ (NSString *)stringYearMonthDay;

/**
 *  获取时分秒(NSString)
 */
+ (NSString *)stringTime;

/**
 *  计算两个NSDate时间的差距
 *
 *  @param startDate 开始时间
 *  @param endDate   结束时间
 *
 *  @return 剩余时间结构体(包含:年,月,日,时,分,秒)
 */
+ (NSDateComponents*)daysOffsetBetweenStartDate:(NSDate *)startDate endDate:(NSDate *)endDate with:(NSCalendarUnit)unitFlags;

//获取设定当前时间时和分的NSDate
+ (NSDate *)dateWithHour:(int)hour
                  minute:(int)minute;

//获取当前时间年月日时分秒
+ (NSString *)stringYearMonthDayHourMinute;

//获取当前年月日时分秒毫秒
+ (NSString *)stringYearMonthDayHourMinuteNanosecond;

/**
 *  (上午)(am)小时分钟的时间字符串
 */
- (NSString *)timeHourMinute; //时间(24小时)
- (NSString *)timeHourMinuteWithPrefix; //添加上下午前缀(12小时)
- (NSString *)timeHourMinuteWithSuffix;  //添加am pm 前缀(12小时)
- (NSString *)timeHourMinuteWithPrefix:(BOOL)enablePrefix suffix:(BOOL)enableSuffix;

/**
 *   时间戳字符串
 */
- (NSString *)stringTime;   // 时:分
- (NSString *)stringMonthDay;   // 月.日
- (NSString *)stringYearMonthDay;   // 年-月-日
- (NSString *)stringYearMonthDayHourMinuteSecond;   // 年-月-日 时:分:秒
+ (NSString *)stringLoacalDate;     // 当地时间 年-月-日 时:分:秒

/**
 *  日期格式
 */
+ (NSString *)dateFormatString; //yyyy-MM-dd
+ (NSString *)timeFormatString;//HH:mm:ss
+ (NSString *)timestampFormatString;//yyyy-MM-dd HH:mm:ss
+ (NSString *)timestampFormatStringSubSeconds;//yyyy-MM-dd HH:mm

/**
 *  日期增减
 */
- (NSDate *) dateByAddingDays: (NSInteger) dDays;
- (NSDate *) dateBySubtractingDays: (NSInteger) dDays;

/**
 *  相对时间
 */
+ (NSDate *) dateTomorrow;
+ (NSDate *) dateYesterday;
+ (NSDate *) dateWithDaysFromNow: (NSInteger) days;
+ (NSDate *) dateWithDaysBeforeNow: (NSInteger) days;
+ (NSDate *) dateWithHoursFromNow: (NSInteger) dHours;
+ (NSDate *) dateWithHoursBeforeNow: (NSInteger) dHours;
+ (NSDate *) dateWithMinutesFromNow: (NSInteger) dMinutes;
+ (NSDate *) dateWithMinutesBeforeNow: (NSInteger) dMinutes;
+ (NSDate *) dateStandardFormatTimeZeroWithDate: (NSDate *) aDate;  //标准格式的零点日期
- (NSInteger) daysBetweenCurrentDateAndDate;                     //负数为过去，正数为未来

#pragma mark - Date compare
- (BOOL)isEqualToDateIgnoringTime: (NSDate *) aDate;
- (NSString *)stringYearMonthDayCompareToday;                 //返回“今天”，“明天”，“昨天”，或年月日

#pragma mark - Date and string convert
//格式字符串 转成 时间(默认格式)
+ (NSDate *)dateFromString:(NSString *)string;
//格式字符串 转成 时间(指定格式)
+ (NSDate *)dateFromString:(NSString *)string withFormat:(NSString *)format;
//时间(默认格式) 转成 格式字符串
+ (NSString *)string;
//时间(没有ss) 转成 格式字符串
+ (NSString *)stringCutSeconds;
//毫秒YYMMddHHmmssSSS
+ (NSString *)stringCutMilliseconds;
#pragma mark - ==================== 补充 ==========================
//获取当前时间的longlong字符串
+ (NSString *)getLongLongStrWithNow;

//秒字符串 转成 时间
+ (NSDate *)getDateWithLongLongStr:(NSString *)longLongStr;

//时间 转成 秒字符串
- (NSString *)getLongLongStrWith;

//秒字符串 转 时间字符串
- (NSString *)getDateStrWithLongLongStrr:(NSString *)longLongStr;

//时间字符串 转 秒字符串
- (NSString *)getLongLongStrWithDateStr:(NSString *)dateStr;

//时区转换
- (NSDate *)getNowDateFromatAnDate;

//对比时间差
+ (NSString *)getTotalTimeWithStartTime:(NSString *)startTime endTime:(NSString *)endTime;

//通过剩余秒数返回剩余天时分
+ (NSString *)byMillisecondToDayHour:(NSString *)millisecondTime;

//获取当前时间（年-月-日）
+ (NSDate *)currentTimeNSDate;

//获取当前时间（年-月-日）
+ (NSString *)currentTimeYMD;

//获取当前的时间时分秒
+ (NSString*)getCurrentTimeHMS;

//获取一周前（年-月-日）
+ (NSString *)oneWeekTimeYMD;

//30天前年月日
+ (NSString *)thirtyWeekTimeYMD;

+ (NSString *)oneDayLater:(NSString *)time;

//比较两个时间大小
+ (int)compareOneDay:(NSDate *)oneDay withAnotherDay:(NSDate *)anotherDay;

//获取当前时间的月的第一天
+ (NSString *)getFirstOfThisMonth;

//将xx:xx:xx 转化成秒
+ (int )changeTimeToMiao:(NSString *)time;

@end

NS_ASSUME_NONNULL_END
