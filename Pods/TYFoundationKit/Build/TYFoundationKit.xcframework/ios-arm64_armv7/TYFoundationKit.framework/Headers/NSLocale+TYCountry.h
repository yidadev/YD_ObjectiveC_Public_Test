//
//  NSLocale+TYCountry.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#if TARGET_OS_IOS
FOUNDATION_EXPORT NSString * TY_ISOCountryCode(void);
#endif

@interface NSLocale (TYCountry)

#if TARGET_OS_IOS
+ (NSString *)ty_ISOCountryCode;
#endif

@end

NS_ASSUME_NONNULL_END
