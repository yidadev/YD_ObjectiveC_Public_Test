//
//  NSObject+TYSwizzle.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN BOOL TY_OverrideImplementation(Class cls, SEL sel, id(^implBlock)(Class originCls, SEL originSel, IMP originImp));

@interface NSObject (TYSwizzle)

+ (BOOL)ty_swizzleInstanceMethod:(SEL)originalSel with:(SEL)swizzleSel;
+ (BOOL)ty_swizzleClassMethod:(SEL)originalSel with:(SEL)swizzleSel;

+ (BOOL)ty_swizzleAddMethod:(SEL)addSel fromClass:(Class)implCls method:(SEL)implSel;

@end

NS_ASSUME_NONNULL_END
