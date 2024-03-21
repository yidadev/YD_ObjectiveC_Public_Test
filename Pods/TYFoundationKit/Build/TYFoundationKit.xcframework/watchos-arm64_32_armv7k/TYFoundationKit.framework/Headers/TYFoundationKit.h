//
//  TYFoundationKit.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2018/12/24.
//

#ifdef __OBJC__
    #import <Foundation/Foundation.h>
#else
    #ifndef FOUNDATION_EXTERN
        #if defined(__cplusplus)
            #define FOUNDATION_EXTERN extern "C"
        #else
            #define FOUNDATION_EXTERN extern
        #endif
    #endif
#endif

#ifndef TYFoundationKit_h
#define TYFoundationKit_h

#import "NSObject+TYFoundation.h"
#import "TYFoundationKitMacro.h"
#import "TYAssert.h"

#import "CLLocationCoordinate+TYCategory.h"
#import "NSNotificationCenter+TYCategory.h"
#import "NSFileManager+TYCategory.h"
#import "NSDictionary+TYCategory.h"
#import "NSTimeZone+TYCategory.h"
#import "NSBundle+TYCategory.h"
#import "NSLocale+TYCategory.h"
#import "NSString+TYCategory.h"
#import "NSLocale+TYCountry.h"
#import "NSArray+TYCategory.h"
#import "NSData+TYCategory.h"
#import "NSDate+TYCategory.h"
#import "NSURL+TYCategory.h"
#import "NSObject+TYRateLimiting.h"
#import "TYDispatchQueue.h"
#import "TYVersionString.h"
#import "TYWeakProxy.h"

#pragma mark - Encrypt
#import "TYDigestImpl.h"
#import "TYAESImpl.h"
#import "TYRSAImpl.h"
#import "TYStringXORImpl.h"

#pragma mark - Localized
#import "TYLanguageLoader.h"
#import "NSString+TYLocalized.h"

#import "TYTemperatureConversion.h"

#if TARGET_OS_IOS

#import "Reachability+TYNetwork.h"

#import "TYAuthorizationManager.h"
#import "TYLocalizedCollation.h"

#endif

#endif /* TYFoundationKit_h */
