/*
 * @Author: moqiong player_theworld@protonmail.com
 * @Date: 2022-09-27 22:37:20
 * @LastEditors: moqiong player_theworld@protonmail.com
 * @LastEditTime: 2022-09-27 23:59:19
 * @FilePath: /stb_image-example/example/Windows/dx11.h
 * @Description: 
 * 
 * Copyright (c) 2022 by moqiong player_theworld@protonmail.com, All Rights Reserved. 
 */
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"
#include <d3d11.h>
#include <D3dx9tex.h>
#include <D3DX11.h>
#include <stdio.h>
#include <string>
#pragma comment(lib,"D3DX11.lib")
#pragma comment(lib,"D3D11.lib")

using namespace std;
struct {
    bool exist;
    ID3D11ShaderResourceView* UID;
    int width;
    int height;
} images[100]{};
bool LoadTextureFromFileMemory(ID3D11Device* g_pd3dDevice, const char *filename, ID3D11ShaderResourceView*& out_srv, int& out_width, int& out_height);
bool Is_File_Exist(const std::string& file_path);
void initImageTexture(ID3D11Device* g_pd3dDevice);