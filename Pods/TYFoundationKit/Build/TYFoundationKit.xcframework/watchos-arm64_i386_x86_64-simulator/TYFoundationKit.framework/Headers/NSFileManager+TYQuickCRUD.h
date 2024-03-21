//
//  NSFileManager+TYQuickCRUD.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * TY_AppDirectory(void);
FOUNDATION_EXTERN NSString * TY_DocDirectory(void);
FOUNDATION_EXTERN NSString * TY_LibDirectory(void);
FOUNDATION_EXTERN NSString * TY_CacheDirectory(void);
FOUNDATION_EXTERN NSString * TY_TmpDirectory(void);


FOUNDATION_EXTERN NSString * TY_FilePath(NSString *inPath, NSString * _Nullable name);

FOUNDATION_EXTERN unsigned long long TY_FileSize(NSString *atPath, NSString * _Nullable name);

/**
 return YES if target exist, no matter it's directory or file
 */
FOUNDATION_EXTERN BOOL TY_FileExist(NSString *atPath, NSString * _Nullable name);

/**
 return YES if target exist, no matter it's directory or file
 isDir will be YES if target is directory
 */
FOUNDATION_EXTERN BOOL TY_FileExistAndType(NSString *atPath, NSString * _Nullable name, BOOL * _Nullable isDir);

/**
 return NO if there is a directory or file at the same path
 */
FOUNDATION_EXTERN BOOL TY_FileMake(NSString *atPath, NSString * _Nullable name, NSData * _Nullable contents);

/**
 return NO if there is a directory or file at the same path
 */
FOUNDATION_EXTERN BOOL TY_DirectoryMake(NSString *atPath, NSString * _Nullable name);

FOUNDATION_EXTERN BOOL TY_FileRemove(NSString *atPath, NSString * _Nullable name);

NS_ASSUME_NONNULL_END
