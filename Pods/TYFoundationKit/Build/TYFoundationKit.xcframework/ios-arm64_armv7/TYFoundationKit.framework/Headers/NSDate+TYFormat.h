//
//  NSDate+TYFormat.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN BOOL TY_Is24HourClock(void);

@interface NSDate (TYFormat)

@property (nonatomic, readonly) NSDateComponents *ty_dateComponments __deprecated_msg("Use ty_dateComponents instead");
@property (nonatomic, readonly) NSDateComponents *ty_dateComponents;
@property (nonatomic, readonly) NSInteger ty_year;
@property (nonatomic, readonly) NSInteger ty_month;
@property (nonatomic, readonly) NSInteger ty_day;
@property (nonatomic, readonly) NSInteger ty_weekday;
@property (nonatomic, readonly) NSInteger ty_hour;
@property (nonatomic, readonly) NSInteger ty_minute;
@property (nonatomic, readonly) NSInteger ty_second;

/**
 format current date
 if dateFormat == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
- (NSString *)ty_stringWithFormat:(NSString * _Nullable)dateFormat;
- (NSString *)ty_stringWithFormat:(NSString * _Nullable)dateFormat timeZone:(NSTimeZone * _Nullable)timeZone;
/**
 format current date
 if formatter == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
- (NSString *)ty_stringWithFormatter:(NSDateFormatter * _Nullable)formatter;


/**
 create date with format string
 if dateFormat == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
+ (instancetype)ty_dateFromString:(NSString *)dateStr withFormat:(NSString * _Nullable)dateFormat;
+ (instancetype)ty_dateFromString:(NSString *)dateStr withFormat:(NSString * _Nullable)dateFormat timeZone:(NSTimeZone * _Nullable)timeZone;
/**
 create date with format string
 if dateFormat == nil, use "yyyy-MM-dd HH:mm:ss" instead
 */
+ (instancetype)ty_dateFromString:(NSString *)dateStr withFormatter:(NSDateFormatter * _Nullable)formatter;


/**
 return YES if self.ty_year self.ty_month self.ty_day equal to [NSDate date]
 */
- (BOOL)ty_isToday;

/**
 if unit == 0, return self.timeIntervalSince1970 == date.timeIntervalSince1970
 */
- (BOOL)ty_isEqualToDate:(NSDate *)date withOptions:(NSCalendarUnit)unit;



+ (BOOL)ty_is24HourClock;

@end

NS_ASSUME_NONNULL_END
