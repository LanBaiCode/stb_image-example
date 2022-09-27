/*
 * @Author: moqiong player_theworld@protonmail.com
 * @Date: 2022-09-27 22:36:21
 * @LastEditors: moqiong player_theworld@protonmail.com
 * @LastEditTime: 2022-09-27 23:57:24
 * @FilePath: /stb_image-example/example/Windows/dx11.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by moqiong player_theworld@protonmail.com, All Rights Reserved. 
 */


bool LoadTextureFromFileMemory(ID3D11Device* g_pd3dDevice, const char *filename, ID3D11ShaderResourceView*& out_srv, int& out_width, int& out_height) {
   int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    //或者使用stbi_load_from_memory
    //unsigned char* image_data = stbi_load_from_memory(data, size, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;


    D3D11_TEXTURE2D_DESC desc;
    ZeroMemory(&desc, sizeof(desc));
    desc.Width = image_width;
    desc.Height = image_height;
    desc.MipLevels = 1;
    desc.ArraySize = 1;
    desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc.SampleDesc.Count = 1;
    desc.Usage = D3D11_USAGE_DEFAULT;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;

    ID3D11Texture2D* pTexture = NULL;
    D3D11_SUBRESOURCE_DATA subResource;
    subResource.pSysMem = image_data;
    subResource.SysMemPitch = desc.Width * 4;
    subResource.SysMemSlicePitch = 0;
    g_pd3dDevice->CreateTexture2D(&desc, &subResource, &pTexture);

    D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc;
    ZeroMemory(&srvDesc, sizeof(srvDesc));
    srvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srvDesc.Texture2D.MipLevels = desc.MipLevels;
    srvDesc.Texture2D.MostDetailedMip = 0;
    g_pd3dDevice->CreateShaderResourceView(pTexture, &srvDesc, &out_srv);
    pTexture->Release();

    out_width = image_width;
    out_height = image_height;
    stbi_image_free(image_data);

    return true;
}

string getCurrentDirectoryEx() {
	char buff[100];
	return _getcwd(buff, 100);
}

bool Is_File_Exist(const std::string& file_path) {
	if (FILE* file = fopen(file_path.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}
void initImageTexture(ID3D11Device* g_pd3dDevice){
    //这里获取当前的运行目录
    string path = getCurrentDirectoryEx();
    path += "1.png";
    //这里可以先判断下是否存在文件
    if (Is_File_Exist(path)){
        memset(images, 0, sizeof(images));
        images[0].exist = true;
        LoadTextureFromFileMemory(g_pd3dDevice, path.c_str(), images[0].UID, images[0].width, images[0].height);
    }else{
        images[0].exist = false;
    }
    
}