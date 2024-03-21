//
//  TYDigestImpl.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/8.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TYDigestType) {
    TYDigestMD2Type,        // MD2算法
    TYDigestMD4Type,        // MD4算法
    TYDigestMD5Type,        // MD5算法
    TYDigestSHA1Type,       // SHA1算法
    TYDigestSHA224Type,     // SHA224算法
    TYDigestSHA256Type,     // SHA256算法
    TYDigestSHA384Type,     // SHA384算法
    TYDigestSHA512Type,     // SHA512算法
};

typedef NS_ENUM(NSInteger, TYHmacType) {
    TYHmacMD5Type,          // MD5算法
    TYHmacSHA1Type,         // SHA1算法
    TYHmacSHA224Type,       // SHA224算法
    TYHmacSHA256Type,       // SHA256算法
    TYHmacSHA384Type,       // SHA384算法
    TYHmacSHA512Type,       // SHA512算法
};

/*
 摘要算法实现
 */
@interface TYDigestImpl : NSObject

// MD算法和SHA算法
+ (NSData *)digestWithData:(NSData *)data type:(TYDigestType)digestType;

// HMAC算法
+ (NSData *)hmacWithData:(NSData *)data keyData:(NSData *)keyData type:(TYHmacType)hmacType;

@end
