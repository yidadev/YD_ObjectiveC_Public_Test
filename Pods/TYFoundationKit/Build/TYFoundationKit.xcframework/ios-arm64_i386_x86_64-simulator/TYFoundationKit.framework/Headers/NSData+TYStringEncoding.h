//
//  NSData+TYStringEncoding.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (TYStringEncoding)

- (NSString *)ty_UTF8String;
- (NSString *)ty_hexString;
- (NSString *)ty_base64String;

- (NSString *)ty_stringWithEncode:(NSStringEncoding)encode;

@end

NS_ASSUME_NONNULL_END
