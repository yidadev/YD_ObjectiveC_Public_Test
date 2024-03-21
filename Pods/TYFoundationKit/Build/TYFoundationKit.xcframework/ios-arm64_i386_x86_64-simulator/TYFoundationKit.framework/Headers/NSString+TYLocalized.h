//
//  NSString+TYLocalized.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TYLocalized)
@property (nonatomic, readonly) NSString *ty_localized;

/// Use localizedString from MainBundle if found, otherwise search from the Placehold Bundle
+ (NSString *)ty_localized:(NSString *)key placeholdBundle:(NSBundle *)bundle;

@end

NS_ASSUME_NONNULL_END
