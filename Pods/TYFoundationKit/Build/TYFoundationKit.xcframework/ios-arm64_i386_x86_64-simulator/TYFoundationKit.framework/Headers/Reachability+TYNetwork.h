//
//  Reachability+TYNetwork.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/15.
//

#if TARGET_OS_IOS

#import <Reachability/Reachability.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    TYNetworkStatusUnknown = 0,
    TYNetworkStatusUnreachable,
    TYNetworkStatusWWAN2G,
    TYNetworkStatusWWAN3G,
    TYNetworkStatusWWAN4G,
    TYNetworkStatusWiFi = 100,
} TYNetworkStatus;

typedef void(^TYNetworkStatusChangedHandler)(TYNetworkStatus status);


FOUNDATION_EXTERN TYNetworkStatus TY_NetworkStatus(void);
FOUNDATION_EXTERN BOOL TY_NetworkReachable(void);
FOUNDATION_EXTERN BOOL TY_NetworkWiFiReachable(void);
/**
 return NO if connect with WiFi
 */
FOUNDATION_EXTERN BOOL TY_NetworkWWANReachable(void);
/**
 handler will be associated to obj
 */
FOUNDATION_EXTERN void TY_NetworkStatusChanged(NSObject *obj, TYNetworkStatusChangedHandler handler);


@interface Reachability (TYNetwork)

- (TYNetworkStatus)ty_networkStatus;

- (void)ty_addNetworkStatusObserver:(NSObject *)obj withHandler:(TYNetworkStatusChangedHandler)handler;

@end

NS_ASSUME_NONNULL_END

#endif
