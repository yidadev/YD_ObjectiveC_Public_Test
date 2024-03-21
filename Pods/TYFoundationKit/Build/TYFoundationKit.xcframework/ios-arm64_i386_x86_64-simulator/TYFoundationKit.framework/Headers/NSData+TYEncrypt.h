//
//  NSData+TYEncrypt.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/4/16.
//

#import <Foundation/Foundation.h>
#import "TYRSAImpl.h"
#import "TYAESImpl.h"
#import "TYDigestImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSData (TYDigestAlgorithm)

- (NSString *)ty_md5String;

- (NSString *)ty_sha1String;
@end



// AES 加密，只支持返回 Hex String
@interface NSData (TYAESEncrypt)
- (NSData *)ty_AES128EncryptWithKey:(NSString *)key;
- (NSData *)ty_AES128DecryptWithKey:(NSString *)key;

- (NSData *)ty_AES256EncryptWithKey:(NSString *)key;
- (NSData *)ty_AES256DecryptWithKey:(NSString *)key;
@end



@interface NSData (TYRSAEncrypt)
/**
 RSA公钥加密，返回加密后的数据
 
 @param publicKey 公钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @*param config 加密配置，默认: + [TYRSAConfig defaultConfig]
 @return 加密后的数据
 */
- (NSData *)ty_RSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSData *)ty_RSAEncryptWithPublicKey:(NSString *)publicKey config:(TYRSAConfig *)config;

/**
 RSA私钥解密数据，返回解密的数据
 
 @param privateKey 私钥，支持带header和不带header的格式，可以用config.keyWithHeader定义。
 @return 解密内容
 */
- (NSData *)ty_RSADecryptWithPrivateKey:(NSString *)privateKey;
- (NSData *)ty_RSADecryptWithPrivateKey:(NSString *)privateKey config:(TYRSAConfig *)config;
@end
NS_ASSUME_NONNULL_END
