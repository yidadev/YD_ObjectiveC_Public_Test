//
//  NSString+TYUrlEncode.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TYUrlEncode)

- (NSString *)ty_urlEncode;
- (NSString *)ty_urlDecode;

@end

NS_ASSUME_NONNULL_END
