LruCache
======
Objective-C implementation of Least Recently Used(LRU) cache.

Usage
======
Create subclass of ```LruCache```. For example: an ```ImageCache``` class to cache ```UIImage``` objects.
```
#import "LruCache.h"

@interface ImageCache : LruCache

@end
```
Override ```sizeOf:``` method to provide customized size of stored object.
```
@implementation ImageCache

- (NSInteger)sizeOf:(NSString *)key value:(id)value
{
    UIImage *img = (UIImage *)value;
    CGSize size = img.size;
    return (NSInteger)ceil(size.height * size.width * img.scale * 4);
}

@end
```
Instantiate ```ImageCache``` and use ```put:``` and ```get:``` method to store and retrieve objects.
```
ImageCache *imageCache = [[ImageCache alloc] initWithMaxSize:1024 * 1024 * 30]; // 30MB image cache.

NSString *key = @"img.png";
UIImage *img = [UIImage imageNamed:@"img.png"];
[imageCache put:key value:img];
```
```
UIImage *img = [imageCache get:key];
```

Install
======
Install using CocoaPods:
```
pod 'LruCache'
```

License
==============
```LruCache``` is available under the MIT license. See the LICENSE file for more info.

