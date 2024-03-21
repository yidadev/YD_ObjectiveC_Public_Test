//
//  TYLanguageLoader.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/12/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYLanguageLoaderDelegate <NSObject>

@optional

/// 在获取多语言前的回调方法，如果该回调返回了非nil值，则localizedString方法会返回这个值。
/// 可以用这个方法运行时修改工程多语言，如果走了before就不会再走下面的after方法了
/// @param languageKey 多语言key
- (nullable NSString *)beforeLocalizedWithKey:(NSString *)languageKey;

/// 在获取多语言后的回调方法，如果该回调返回了非nil值，则localizedString方法会返回这个值。
/// 可以用这个方法运行时修改工程多语言，如果对翻译的内容不满意可以做替换等等
/// @param languageKey 多语言key
/// @param isFound 是否找到了多语言翻译
/// @param isCurrent 当isFound为True时，这个字段才有效。是否在main bundle(不是默认的语言bundle)中取到的多语言翻译。
/// @param localizedString 多语言翻译的内容，如果isFound为NO，则localizedString==languageKey
- (nullable NSString *)afterLocalizedWithKey:(NSString *)languageKey
                                     isFound:(BOOL)isFound
                                   isCurrent:(BOOL)isCurrent
                             localizedString:(NSString *)localizedString;
@end


@interface TYLanguageLoader : NSObject

@property (nonatomic, weak) id<TYLanguageLoaderDelegate> delegate;

/// 当前多语言在使用的bundle和兜底语言，需要修改可以使用
/// registerLocalizedBundle:defaultLanguage:方法注册
@property (nonatomic, strong, readonly) NSBundle *localizedBundle;
@property (nonatomic, copy, readonly) NSString *defaultLanguage;

+ (instancetype)sharedInstance;

// 如果在特定语言bundle下，退回到上一层rootBundle中
+ (NSBundle *)languageRootBundle:(NSBundle *)bundle;


/// 注册一个bundle和兜底语言，多语言会从设置的bundle里取，默认[NSBundle mainBundle]和@"en";
/// @param bundle 自定义取多语言的bundle
/// @param defaultLanguage 默认语种，如果其他语种取不到时会用默认语种进行补全，比如@"en".
///                        如果该参数为nil，则默认用@"en"
- (void)registerLocalizedBundle:(NSBundle *)bundle defaultLanguage:(NSString *)defaultLanguage;


/// 在register bundle中是否能找到keys对应的多语言
/// @param languageKey 多语言key
- (BOOL)isExistLocalized:(NSString *)languageKey;


/// 获取key值对应的多语言
/// @param languageKey 多语言key
- (NSString *)localizedString:(NSString *)languageKey;
@end

NS_ASSUME_NONNULL_END
