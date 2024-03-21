//
//  TYRSAImpl.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/17.
//

#import <Foundation/Foundation.h>
#import <Security/Security.h>

@class TYRSAConfig;

@interface TYRSAConfig : NSObject
/**
 RSA加密填充的类型, 默认kSecPaddingPKCS1
 
 kSecPaddingPKCS1 填充模式，最常用的模式, 会增加随机数，就算key相同每次加密出的密文不同。
 输入: 加密内容必须比RSA钥模长(modulus)短至少11个字节, 也就是RSA_size(rsa) – 11如果输入的明文过长，必须切割，然后填充
 对应java: RSA/ECB/PKCS1Padding
 
 
 kSecPaddingOAEP 会增加随机数，就算key相同每次加密出的密文不同。
 输入：RSA_size(rsa) – 41
 对应java: RSA/NONE/OAEPWithSHA1AndMGF1Padding
 
 kSecPaddingNone　　不填充, key相同每次加密出的内容必定相同。
 输入：可以和RSA钥模长一样长，如果输入的明文过长，必须切割，　然后填充
 对应java: RSA
 */
@property (nonatomic, assign) SecPadding paddingType;

/**
 分块加密时，每个块与公钥大小的差额(字节)
 
 PKCS1_PADDING: 11   OAEP_PADDING: 41   OAEP_PADDING: 0
 */
@property (nonatomic, assign, readonly) int blockInterval;

/**
 public/private key中是否包含头部和尾部, 默认NO
 公钥:
        -----BEGIN PUBLIC KEY-----
        -----END PUBLIC KEY-----
 
 私钥:
        -----BEGIN RSA PRIVATE KEY-----
        -----END RSA PRIVATE KEY-----
 */
@property (nonatomic, assign) BOOL keyWithHeader;

+ (instancetype)defaultConfig;

@end


typedef NS_ENUM(NSInteger, TYRSAKeySize) {
    TYRSAKey512Bits  = 512,     // 512位
    TYRSAKey1024Bits = 1024,    // 1024位
    TYRSAKey2048Bits = 2048     // 2048位
};

// 本类只用于加密/解密Data类型的数据，入参和返回值转换由上层类(NSString+TYSecurity\NSData+TYSecurity)实现
@interface TYRSAImpl : NSObject

/**
 RSA加密

 @param data 需要加密的数据
 @param publicKey 公钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @param config 加密配置，默认可以用+ [TYRSAConfig defaultConfig]
 @return 加密后的数据
 */
+ (NSData *)encryptData:(NSData *)data publicKey:(NSString *)publicKey config:(TYRSAConfig *)config;

/**
 RSA解密

 @param data 需要解密的数据
 @param privateKey 私钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @param config 解密配置，默认可以用+ [TYRSAConfig defaultConfig]
 @return 解密后的数据
 */
+ (NSData *)decryptData:(NSData *)data privateKey:(NSString *)privateKey config:(TYRSAConfig *)config;

/**
 生成公钥和私钥

 @param keySize 密钥位数
 @param pair 公钥私钥回调block
 */
+ (void)generateKeyPairWithSize:(TYRSAKeySize)keySize keyPair:(void(^)(SecKeyRef publicKeyRef, SecKeyRef privateKeyRef))pair;

@end
