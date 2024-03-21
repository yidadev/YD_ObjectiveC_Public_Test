//
//  NSURL+TYPrefs.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURL (TYPrefs)

+ (NSURL *)ty_appPrefsWifi;
+ (NSURL *)ty_appPrefsBLE;
+ (NSURL *)ty_appPrefsLocation;

+ (NSURL *)ty_appPrefsApplicationSetting NS_AVAILABLE_IOS(8.0);

@end

NS_ASSUME_NONNULL_END
