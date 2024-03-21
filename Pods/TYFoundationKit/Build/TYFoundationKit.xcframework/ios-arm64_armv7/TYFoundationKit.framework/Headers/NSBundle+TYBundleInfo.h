//
//  NSBundle+TYBundleInfo.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSDictionary * TY_MainBundleInfoDictionary(void);

FOUNDATION_EXTERN id TY_MainBundleInfoWithKey(NSString * key);

FOUNDATION_EXTERN NSString * TY_MainBundleId(void);         /**< [NSBundle mainBundle].ty_bundleId */
FOUNDATION_EXTERN NSString * TY_MainBundleName(void);       /**< [NSBundle mainBundle].ty_bundleName */
FOUNDATION_EXTERN NSString * TY_MainBundleVersion(void);    /**< [NSBundle mainBundle].ty_bundleVersion */

FOUNDATION_EXTERN NSString * TY_AppName(void);              /**< [NSBundle mainBundle].ty_bundleName */
FOUNDATION_EXTERN NSString * TY_AppVersion(void);           /**< [NSBundle mainBundle].ty_bundleVersion */

/**
 @return return YES if info.plist contains value for key "NSExtension"
 */
FOUNDATION_EXTERN BOOL TY_IsExtensionBundle(void);


@interface NSBundle (TYBundleInfo)

- (NSString *)ty_bundleId;

/**
 bundle short verion string
 */
- (NSString *)ty_bundleVersion;

/**
 if bundle localized display name is not nil, return it
 else if bundle display name is not nil, return it
 else return bundle name
 */
- (NSString *)ty_bundleName;

@end

NS_ASSUME_NONNULL_END
