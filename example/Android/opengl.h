/*
 * @Author: moqiong player_theworld@protonmail.com
 * @Date: 2022-09-27 23:18:50
 * @LastEditors: moqiong player_theworld@protonmail.com
 * @LastEditTime: 2022-09-27 23:59:07
 * @FilePath: /stb_image-example/example/Android/opengl.h
 * @Description: 
 * 
 * Copyright (c) 2022 by moqiong player_theworld@protonmail.com, All Rights Reserved. 
 */
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GLES2/gl2.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
struct {
    bool exist;
    GLuint UID;
    int width;
    int height;
} images[100] {};

void LoadTextureFromFileMemory(string Path, GLuint &out_id, int &out_width, int &out_height);
bool Is_File_Exist(char* file_path);
void initImageTexture();