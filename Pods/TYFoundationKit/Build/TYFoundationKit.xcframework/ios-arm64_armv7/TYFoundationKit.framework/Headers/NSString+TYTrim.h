//
//  NSString+TYTrim.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TYTrim)

- (NSString *)ty_trimWithWhitespaceAndNewline;
- (NSString *)ty_trimWithCharacterSet:(NSCharacterSet *)set;

@end

NS_ASSUME_NONNULL_END
