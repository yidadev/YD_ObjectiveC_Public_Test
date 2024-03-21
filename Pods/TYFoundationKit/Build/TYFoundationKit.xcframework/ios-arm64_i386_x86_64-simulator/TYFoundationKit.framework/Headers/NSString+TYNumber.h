//
//  NSString+TYNumber.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/29.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TYNumber)

+ (instancetype)ty_stringFromInteger:(NSInteger)num;

+ (instancetype)ty_stringFromFloat:(CGFloat)num;

+ (instancetype)ty_stringFromFloat:(CGFloat)num withFractionDigits:(NSUInteger)digit roundingMode:(NSNumberFormatterRoundingMode)mode;

/**
 return boolean ? @"1" : @"0";
 */
+ (instancetype)ty_stringFromBool:(BOOL)boolean;

+ (BOOL)ty_isPureInt:(NSString*)string;

@end

NS_ASSUME_NONNULL_END
