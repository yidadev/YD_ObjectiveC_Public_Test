//
//  NSURL+TYComponents.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (TYComponents)

@property (nonatomic, strong, readonly) NSString *ty_scheme;
@property (nonatomic, strong, readonly) NSString *ty_host;
@property (nonatomic, strong, readonly) NSString *ty_path;
@property (nonatomic, strong, readonly) NSString *ty_query;

@property (nonatomic, strong, readonly) NSArray *ty_pathArray;
@property (nonatomic, strong, readonly) NSDictionary *ty_queryDictionary;

/**
 if value isn't NSString, it will be ignore
 */
- (NSURL *)ty_URLByAppendingQuery:(NSDictionary<NSString *, NSString *> *)query;
- (id)ty_valueForQueryKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
