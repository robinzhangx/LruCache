//
//  LruCache.h
//
//  Created by robin on 5/20/14.
//  Copyright (c) 2014 Robin Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LruCacheDelegate <NSObject>

- (NSInteger)sizeOf:(NSString *)key value:(id)value;

@optional
- (id)create:(NSString *)key;
- (void)entryRemoved:(BOOL)evicted key:(NSString *)key oldValue:(id)oldValue newValue:(id)newValue;

@end

@interface LruCache : NSObject

- (id)initWithMaxSize:(NSInteger)maxSize;
- (void)resize:(NSInteger)maxSize;
- (id)get:(NSString *)key;
- (id)put:(NSString *)key value:(id)value;
- (void)trimToSize:(NSInteger)maxSize;
- (id)remove:(NSString *)key;
- (void)evictAll;
- (NSMutableDictionary *)snapshot;

@property (readonly) NSInteger size;
@property (readonly) NSInteger maxSize;
@property (readonly) NSInteger hitCount;
@property (readonly) NSInteger missCount;
@property (readonly) NSInteger createCount;
@property (readonly) NSInteger putCount;
@property (readonly) NSInteger evictionCount;

@property (nonatomic, weak) id<LruCacheDelegate> delegate;

@end
