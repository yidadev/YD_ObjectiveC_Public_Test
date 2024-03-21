//
//  NSString+TYHex.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TYHex)

- (NSString *)ty_hexString;
- (NSString *)ty_hexToUTF8String;

- (NSData *)ty_hexToData;
- (uint32_t)ty_hexToIntValue;

@end

NS_ASSUME_NONNULL_END
