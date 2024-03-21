//
//  NSObject+TYDeepCopy.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TYDeepCopy)

/**
 use NSKeyedArchiver and NSKeyedUnarchiver to do deep copy
 you can override this method to do deep copy by yourself
 */
- (id)ty_deepCopy;

- (id)ty_deepCopyWithArchiver:(Class)archiver unarchiver:(Class)unarchiver;

@end

NS_ASSUME_NONNULL_END
