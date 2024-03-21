//
//  NSLocale+TYLanguage.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * TY_SystemLanguage(void);
FOUNDATION_EXTERN NSString * TY_SystemLanguageCode(void) __deprecated_msg("Use TY_SystemLanguage() instead");
FOUNDATION_EXTERN BOOL TY_IsChineseLanguage(void);

@interface NSLocale (TYLanguage)

/**
 This method will get current app language and not system language,
 if user switch language in the app, this method can get the changed
 language. Try not to use [[NSBundle mainBundle] preferredLocalizations]
 or [NSLocale preferredLanguages].
 */
+ (NSString *)ty_systemLanguage;

/**
 Deprecated method, this method is same as ty_systemLanguage.
 */
+ (NSString *)ty_systemLanguageCode __deprecated_msg("Use ty_systemLanguage instead");

+ (BOOL)ty_isChineseLanguate;

@end

NS_ASSUME_NONNULL_END
