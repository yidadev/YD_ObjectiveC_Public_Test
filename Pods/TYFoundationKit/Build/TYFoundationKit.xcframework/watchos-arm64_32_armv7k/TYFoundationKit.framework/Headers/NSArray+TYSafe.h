//
//  NSArray+TYSafe.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2018/12/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSArray<ObjectType> (TYSafe)

- (ObjectType)ty_safeObjectAtIndex:(NSUInteger)index;

@end

@interface NSMutableArray (TYSafe)

- (void)ty_safeAddObject:(id)anObject;
- (void)ty_safeInsertObject:(id)anObject atIndex:(NSUInteger)index;

@end

NS_ASSUME_NONNULL_END
