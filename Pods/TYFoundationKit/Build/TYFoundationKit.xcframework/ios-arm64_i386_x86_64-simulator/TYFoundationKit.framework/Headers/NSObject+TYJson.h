//
//  NSObject+TYJson.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TYJson)

+ (id)ty_objectFromJson:(NSString *)json;

- (NSString *)ty_jsonString;

@end

NS_ASSUME_NONNULL_END
