//
//  NSTimeZone+TYTimeDifference.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @return [NSTimeZone localTimeZone].name
 */
FOUNDATION_EXTERN NSString * TY_LocalTimeZoneName(void);
/**
 if timeZoneName is nil, use localTimeZone insted
 @return string like +08:00
 */
FOUNDATION_EXTERN NSString * TY_TimeDifferenceWithGMT(NSString * _Nullable timeZoneName);


@interface NSTimeZone (TYTimeDifference)

/**
 @return string like +08:00
 */
- (NSString *)ty_timeDifferenceWithGMT;

@end

NS_ASSUME_NONNULL_END
