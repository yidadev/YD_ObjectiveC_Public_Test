//
//  TYAESImpl.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/17.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TYAESKeySize) {
    TYAESKey128Bits,    // 128位
    TYAESKey256Bits     // 256位
};

typedef NS_ENUM(NSInteger, TYAESMode) {
    TYAESModeP7ECB,     // ECB模式 kCCOptionPKCS7Padding | kCCOptionECBMode
    TYAESModeP7CBC      // CBC模式 kCCOptionPKCS7Padding
};


@interface TYAESConfig : NSObject

/**
 秘钥大小, 默认TYAESKey128Bits
 */
@property (nonatomic, assign) TYAESKeySize keySize;

/**
 加密模式，默认TYAESModeP7ECB
 */
@property (nonatomic, assign) TYAESMode mode;

/**
 TYAESModeP7CBC加密时使用的向量, 默认为空
 */
@property (nonatomic, strong) NSData *CBCIV;

+ (instancetype)default128Config;

+ (instancetype)default256Config;

@end


@interface TYAESImpl : NSObject

/**
 AES加密数据
 
 @param data 需要加密的内容
 @param keyData 秘钥
 @param config 加密配置, 默认可以使用+ [TYAESConfig defaultConfig]
 @return 加密后的内容
 */
+ (NSData *)encryptData:(NSData *)data keyData:(NSData *)keyData config:(TYAESConfig *)config;

/**
 AES解密数据
 
 @param data 需要加密的内容
 @param keyData 秘钥
 @param config 解密配置, 默认可以使用+ [TYAESConfig defaultConfig]
 @return 解密后的内容
 */
+ (NSData *)decryptData:(NSData *)data keyData:(NSData *)keyData config:(TYAESConfig *)config;


# pragma mark - deprecated
// 128:ECB  256:CBC
+ (NSData *)encryptData:(NSData *)data keyData:(NSData *)keyData keySize:(TYAESKeySize)keySize DEPRECATED_MSG_ATTRIBUTE("use encryptData:keyData:config: instead.");

// 128:ECB  256:CBC
+ (NSData *)decryptData:(NSData *)data keyData:(NSData *)keyData keySize:(TYAESKeySize)keySize DEPRECATED_MSG_ATTRIBUTE("use decryptData:keyData:config: instead.");

@end
