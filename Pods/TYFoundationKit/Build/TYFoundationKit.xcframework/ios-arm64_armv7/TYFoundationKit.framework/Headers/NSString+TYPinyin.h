//
//  NSString+TYPinyin.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TYPinyin)

/**
 the Chinese Pinyin of current string
 Support Japanese and Korean
 */
- (NSString *)ty_pinyin;

- (NSString *)ty_pinyinWithDiacritics;

/**
 the first letter of Pinyin
 */
- (NSString *)ty_initialsOfPinyin;

@end

NS_ASSUME_NONNULL_END
