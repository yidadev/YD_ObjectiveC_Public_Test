//
//  NSObject+TYDefiniteness.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/27.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TYDefiniteness)

/**
 convert id or NSObject to int
 retrun 0 if fail
 */
- (NSInteger)ty_int;
/**
 convert id or NSObject to unsigned int
 retrun 0 if fail
 */
- (NSUInteger)ty_uInt;
/**
 convert id or NSObject to float
 retrun 0.0 if fail
 */
- (CGFloat)ty_float;
/**
 convert id or NSObject to double
 retrun 0.0 if fail
 */
- (double)ty_double;
/**
 convert id or NSObject to bool
 retrun NO if fail
 */
- (BOOL)ty_bool;
/**
 convert id or NSObject to string
 retrun nil if fail
 */
- (NSString *)ty_string;
/**
 convert id or NSObject to array
 retrun nil if fail
 */
- (NSArray *)ty_array;
/**
 convert id or NSObject to dictionary
 retrun nil if fail
 */
- (NSDictionary *)ty_dictionary;


- (BOOL)ty_isDictionaryAndNotEmpty;
- (BOOL)ty_isStringAndNotEmpty;
- (BOOL)ty_isArrayAndNotEmpty;

@end

NS_ASSUME_NONNULL_END
