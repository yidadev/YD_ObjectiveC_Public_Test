//
//  NSString+TYEncrypt.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/16.
//

#import <Foundation/Foundation.h>
#import "TYDigestImpl.h"
#import "TYRSAImpl.h"
#import "TYAESImpl.h"

@interface NSString (TYDigestAlgorithm)

- (NSString *)ty_md5String;

- (NSString *)ty_sha1String;

- (NSData *)ty_hmacWithKey:(NSString *)key type:(TYHmacType)type;
@end



// AES 加密，只支持返回 Hex String
@interface NSString (TYAESEncrypt)

// AES128加解密，key的长度必须小于等于16，否则会加密失败
- (NSString *)ty_AES128EncryptWithKey:(NSString *)key;
- (NSString *)ty_AES128DecryptWithKey:(NSString *)key;

// AES256加解密，key的长度必须小于等于32，否则会加密失败
- (NSString *)ty_AES256EncryptWithKey:(NSString *)key;
- (NSString *)ty_AES256DecryptWithKey:(NSString *)key;
@end



@interface NSString (TYRSAEncrypt)

#pragma mark - 加密

/**
 RSA公钥加密，返回base64编码的加密密文
 
 @param publicKey 公钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @*param config 加密配置，默认: + [TYRSAConfig defaultConfig]
 @return Base64编码的加密密文
 */
- (NSString *)ty_base64RSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSString *)ty_base64RSAEncryptWithPublicKey:(NSString *)publicKey config:(TYRSAConfig *)config;

/**
 RSA公钥加密，返回16进制的加密密文
 
 @param publicKey publicKey 公钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @*param config config 加密配置，默认: + [TYRSAConfig defaultConfig]
 @return 16进制的加密密文
 */
- (NSString *)ty_hexRSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSString *)ty_hexRSAEncryptWithPublicKey:(NSString *)publicKey config:(TYRSAConfig *)config;


#pragma mark - 解密

/**
 RSA私钥解密16进制密文，返回解密内容
 
 @param privateKey 私钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @return 解密内容
 */
- (NSString *)ty_RSADecryptHexWithPrivateKey:(NSString *)privateKey;
- (NSString *)ty_RSADecryptHexWithPrivateKey:(NSString *)privateKey config:(TYRSAConfig *)config;

/**
 RSA私钥解密base64密文，返回解密内容
 
 @param privateKey 私钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @return 解密内容
 */
- (NSString *)ty_RSADecryptBase64WithPrivateKey:(NSString *)privateKey;
- (NSString *)ty_RSADecryptBase64WithPrivateKey:(NSString *)privateKey config:(TYRSAConfig *)config;

@end
