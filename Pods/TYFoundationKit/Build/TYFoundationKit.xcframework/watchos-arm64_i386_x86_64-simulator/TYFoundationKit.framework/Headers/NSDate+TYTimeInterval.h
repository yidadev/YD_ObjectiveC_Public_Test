//
//  NSDate+TYTimeInterval.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 current time interval since 1970 in second
 */
FOUNDATION_EXTERN NSTimeInterval TY_TimestampSEC(void);
/**
 current time interval since 1970 in millisecond
 */
FOUNDATION_EXTERN NSTimeInterval TY_TimestampMSEC(void);

/**
 current time interval since specific date
 if sinceDate is nil, return time interval since 1970
 if millisecond is YES, return time interval in millisecond
 */
FOUNDATION_EXTERN NSTimeInterval TY_TimestampSince(NSDate * _Nullable sinceDate, BOOL millisecond);



@interface NSDate (TYTimeInterval)

/**
 time interval since specific date, in second
 if sinceDate is nil, return time interval since 1970
 */
- (NSTimeInterval)ty_timeIntervalSEC:(NSDate * _Nullable)sinceDate;
/**
 time interval since specific date, in millisecond
 if sinceDate is nil, return time interval since 1970
 */
- (NSTimeInterval)ty_timeIntervalMSEC:(NSDate * _Nullable)sinceDate;


@end

NS_ASSUME_NONNULL_END
