//
//  NSObject+TYObserver.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 swizzle addObserver:forKeyPath:options:context: method
 and automatic remove observer when observer dealloc
 */
@interface NSObject (TYObserverAutoRemove)

@end


@interface NSObject (TYObserver)

/**
 add observer with block
 */
// - (void)ty_addObserverBlockForKeyPath:(NSString *)keyPath block:(void (^)(__weak id obj, id oldVal, id newVal))block;

@end

NS_ASSUME_NONNULL_END
