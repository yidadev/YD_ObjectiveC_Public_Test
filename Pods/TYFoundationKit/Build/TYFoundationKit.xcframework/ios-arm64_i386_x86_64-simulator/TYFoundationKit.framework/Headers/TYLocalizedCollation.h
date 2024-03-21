//
//  TYLocalizedCollation.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE_IOS(3_0) @interface TYLocalizedCollation : NSObject

@property (nonatomic, strong, readonly) NSArray<NSString *> * collationTitles;
@property (nonatomic, strong, readonly) NSDictionary<NSString *, NSArray<id> *> * collationResult;

/**
 object in data must implement collation selector
 if object is kind of NSString, collation selector can be nil
 collation selector must return an NSString which will be used to sort
 collation selector may be called multiple times, so it should be fast
 */
- (instancetype)initWithData:(NSArray<id> *)data collationSelector:(nullable SEL)sel;

@end

NS_ASSUME_NONNULL_END
