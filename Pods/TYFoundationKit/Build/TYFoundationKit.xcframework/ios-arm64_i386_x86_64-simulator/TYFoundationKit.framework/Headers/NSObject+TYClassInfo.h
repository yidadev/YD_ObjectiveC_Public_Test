//
//  NSObject+TYClassInfo.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TYClassInfo)

+ (NSString *)ty_className;
- (NSString *)ty_className;

+ (BOOL)ty_isMetaClass;
+ (Class)ty_superClass;

@end

NS_ASSUME_NONNULL_END
