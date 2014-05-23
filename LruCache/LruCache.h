//
//  LruCache.h
//
//  Created by robin on 5/20/14.
//  Copyright (c) 2014 Robin Zhang. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LruCache : NSObject

// subclass need to implement sizeOf: method. create: and entryRemoved methods are optional.
- (NSInteger)sizeOf:(NSString *)key value:(id)value;
- (id)create:(NSString *)key;
- (void)entryRemoved:(BOOL)evicted key:(NSString *)key oldValue:(id)oldValue newValue:(id)newValue;

- (id)initWithMaxSize:(NSInteger)maxSize;
- (void)resize:(NSInteger)maxSize;
- (id)get:(NSString *)key;
- (id)put:(NSString *)key value:(id)value;
- (void)trimToSize:(NSInteger)maxSize;
- (id)remove:(NSString *)key;
- (void)evictAll;

@property (readonly) NSInteger size;
@property (readonly) NSInteger maxSize;
@property (readonly) NSInteger hitCount;
@property (readonly) NSInteger missCount;
@property (readonly) NSInteger createCount;
@property (readonly) NSInteger putCount;
@property (readonly) NSInteger evictionCount;

@end
