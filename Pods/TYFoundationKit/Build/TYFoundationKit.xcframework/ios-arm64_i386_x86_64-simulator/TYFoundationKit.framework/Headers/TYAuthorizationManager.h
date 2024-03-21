//
//  TYAuthorizationManager.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/16.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IOS

#import <CoreLocation/CoreLocation.h>
#import <CoreTelephony/CTCellularData.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN BOOL TY_AuthorizationLocationAvailable(void);
FOUNDATION_EXPORT BOOL TY_AuthorizaitonCellularDataAvailable(void);

@interface TYAuthorizationManager : NSObject

+ (CLAuthorizationStatus)locationAuthorizationStatus;
+ (CTCellularDataRestrictedState)cellularDataAuthorizationStatus;

@end

NS_ASSUME_NONNULL_END

#endif
