//
//  NSDictionary+TYSafe.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSMutableDictionary (TYSafe)

- (void)ty_safeSetObject:(id)anObject forKey:(id<NSCopying>)aKey;

@end

NS_ASSUME_NONNULL_END
