/*
 * @Author: moqiong player_theworld@protonmail.com
 * @Date: 2022-09-27 23:35:36
 * @LastEditors: moqiong player_theworld@protonmail.com
 * @LastEditTime: 2022-09-27 23:59:11
 * @FilePath: /stb_image-example/example/iOS/Metal.h
 * @Description: 
 * 
 * Copyright (c) 2022 by moqiong player_theworld@protonmail.com, All Rights Reserved. 
 */
#define STB_IMAGE_IMPLEMENTATION
#import <UIKit/UIKit.h>
#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>

NS_ASSUME_NONNULL_BEGIN
struct {
    bool exist;
    id<MTLTexture> UID;
    int width;
    int height;
} images[100] {};

//可以使用OC写函数 或者 使用c++
@interface Metal : NSObject
- (id<MTLTexture>)LoadTextureFromFileMemory:(id<MTLDevice>)device imageData:(void *)imageData DataSize:(size_t)fileDataSize width:(int&)width height:(int&)height;
- (void)initImageTexture:(id<MTLDevice>)device;


@end

NS_ASSUME_NONNULL_END