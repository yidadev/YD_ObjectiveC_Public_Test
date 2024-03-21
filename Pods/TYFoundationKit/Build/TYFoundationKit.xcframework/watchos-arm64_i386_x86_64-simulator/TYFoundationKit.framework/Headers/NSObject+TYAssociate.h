//
//  NSObject+TYAssociate.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TYAssociate)

- (void)ty_setAssociate:(_Nullable id)value withKey:(const void *)key;
- (void)ty_setAssociate:(_Nullable id)value withStringKey:(NSString *)keyStr;

- (void)ty_setWeakAssociate:(_Nullable id)value withKey:(const void *)key;
- (void)ty_setWeakAssociate:(_Nullable id)value withStringKey:(NSString *)keyStr;

- (_Nullable id)ty_getAssociateWithKey:(const void *)key;
- (_Nullable id)ty_getAssociateWithStringKey:(NSString *)keyStr;

- (void)ty_removeAllAssociate;

@end

NS_ASSUME_NONNULL_END
