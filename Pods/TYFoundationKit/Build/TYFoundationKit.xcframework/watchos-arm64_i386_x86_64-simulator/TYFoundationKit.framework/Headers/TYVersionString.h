//
//  TYVersionString.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TYVersionString;

FOUNDATION_EXTERN TYVersionString * TYVersionStringMake(NSString *version);


@interface TYVersionString : NSString

- (instancetype)initWithString:(NSString *)aString;
+ (instancetype)versionWithString:(NSString *)aString;

/**
 if self is greater than version, will return NSOrderedDescending
 
 version with rc (e.g. 1.0.1-rc.1) or beta (e.g. 1.0.1-beta.1) is supported
 if compare 1.0.1 to 1.0.1-rc.1, will return NSOrderedDescending
 */
- (NSComparisonResult)compareToVersion:(__kindof NSString *)version;

@end

NS_ASSUME_NONNULL_END
