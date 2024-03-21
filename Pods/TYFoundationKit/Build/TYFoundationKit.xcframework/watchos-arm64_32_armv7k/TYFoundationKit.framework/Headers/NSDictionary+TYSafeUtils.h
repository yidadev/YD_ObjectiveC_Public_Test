//
//  NSDictionary+TYSafeUtils.h
//  TYSmartSceneModule
//
//  Created by mile on 2020/8/17.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (TYSafeUtils)

- (id)ty_safeObjectForKey:(id)key;
- (id)ty_safeObjectForKey:(id)key class:(Class)aClass;

- (bool)ty_boolForKey:(id)key;
- (CGFloat)ty_floatForKey:(id)key;
- (NSInteger)ty_integerForKey:(id)key;
- (int)ty_intForKey:(id)key;
- (long)ty_longForKey:(id)key;
- (NSNumber *)ty_numberForKey:(id)key;
- (NSString *)ty_stringForKey:(id)key;
- (NSDictionary *)ty_dictionaryForKey:(id)key;
- (NSArray *)ty_arrayForKey:(id)key;
- (NSMutableDictionary *)ty_mutableDictionaryForKey:(id)key;
- (NSMutableArray *)ty_mutableArrayForKey:(id)key;

@end

NS_ASSUME_NONNULL_END
