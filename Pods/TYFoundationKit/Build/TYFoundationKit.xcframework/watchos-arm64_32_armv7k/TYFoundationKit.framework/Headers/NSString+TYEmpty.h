//
//  NSString+TYEmpty.h
//  AFNetworking
//
//  Created by 津渡 on 2020/6/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TYEmpty)

- (BOOL)isValid;
- (NSString *)ty_safeString;

@end

NS_ASSUME_NONNULL_END
