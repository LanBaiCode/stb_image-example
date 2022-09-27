/*
 * @Author: moqiong player_theworld@protonmail.com
 * @Date: 2022-09-27 23:35:42
 * @LastEditors: moqiong player_theworld@protonmail.com
 * @LastEditTime: 2022-09-27 23:59:13
 * @FilePath: /stb_image-example/example/iOS/Metal.mm
 * @Description: 
 * 
 * Copyright (c) 2022 by moqiong player_theworld@protonmail.com, All Rights Reserved. 
 */
@implementation Metal
-(id<MTLTexture>)LoadTextureFromFileMemory:(id<MTLDevice>)device imageData:(void *)imageData DataSize:(size_t)fileDataSize width:(int&)width height:(int&)height{
    if (fileDataSize > 1) {
        unsigned char *pixels = stbi_load_from_memory((stbi_uc const *)imageData, (int)fileDataSize, &width, &height, NULL, 4);
        if (pixels != NULL) {
            MTLTextureDescriptor *textureDescriptor = [MTLTextureDescriptor texture2DDescriptorWithPixelFormat:MTLPixelFormatRGBA8Unorm
                                                                                                         width:(NSUInteger)width
                                                                                                        height:(NSUInteger)height
                                                                                                     mipmapped:NO];
            textureDescriptor.usage = MTLTextureUsageShaderRead;
            textureDescriptor.storageMode = MTLStorageModeShared;
            id<MTLTexture> texture = [device newTextureWithDescriptor:textureDescriptor];
            [texture replaceRegion:MTLRegionMake2D(0, 0, (NSUInteger)width, (NSUInteger)height) mipmapLevel:0 withBytes:pixels bytesPerRow:(NSUInteger)width * 4];
            
            stbi_image_free(pixels);
            return texture;
        }
    }
    return NULL;
}
- (void)initImageTexture:(id<MTLDevice>)device{
    //使用异步加载,别卡主线程
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        memset(images, 0, sizeof(images));
        // 读取沙盒路径图片
        NSString *path = [NSString stringWithFormat:@"%@/Library/Caches/%@.png", NSHomeDirectory(), @"pngName"];
        // 转NSData
         NSData *imageData = [NSData dataWithContentsOfFile:path];
        if (imageData != NULL){
            images[0].exist = true;
            images[0].UID = [self LoadTextureFromFileMemory:device imageData:(void *)[imageData bytes] DataSize:[imageData length] width:images[0].width height:images[0].height];
        }else{
            images[0].exist = false;
        }
    });
}

@end