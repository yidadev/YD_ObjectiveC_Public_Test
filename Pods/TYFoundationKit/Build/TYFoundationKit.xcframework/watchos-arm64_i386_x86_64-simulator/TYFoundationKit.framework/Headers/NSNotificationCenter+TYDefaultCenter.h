//
//  NSNotificationCenter+TYDefaultCenter.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/15.
//

#import <Foundation/Foundation.h>


/**
 post directly if current thread is main, async to main thread otherwise
 */
FOUNDATION_EXTERN void TY_PostNotification(NSString * _Nonnull name, NSDictionary * _Nullable userInfo);

NS_ASSUME_NONNULL_BEGIN

@interface NSNotificationCenter (TYDefaultCenter)

+ (void)ty_addObserver:(id)obj withName:(NSString *)name selector:(SEL)sel;

/**
 @param dictionary NSDictionary<NotificationName, NSStringFromSelector>
 */
+ (void)ty_addObserver:(id)obj withDictionary:(NSDictionary<NSString *, NSString *> *)dictionary;


/**
 post directly if current thread is main, async to main thread otherwise
 */
+ (void)ty_postNotificationAsyncOnMain:(NSString *)name;
+ (void)ty_postNotificationAsyncOnMain:(NSString *)name withUserInfo:(nullable NSDictionary *)userInfo;


@end

NS_ASSUME_NONNULL_END
