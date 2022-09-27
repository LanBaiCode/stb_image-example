/*
 * @Author: moqiong player_theworld@protonmail.com
 * @Date: 2022-09-27 23:18:59
 * @LastEditors: moqiong player_theworld@protonmail.com
 * @LastEditTime: 2022-09-28 00:10:15
 * @FilePath: /stb_image-example/example/Android/opengl.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by moqiong player_theworld@protonmail.com, All Rights Reserved. 
 */

void LoadTextureFromFileMemory(string Path, GLuint &texture, int &out_width, int &out_height){
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int image_width = 0;
    int image_height = 0;
    void *file_data;
    unsigned char *file_data_size = stbi_load(Path.c_str(), &image_width, &image_height, NULL, 4);
    if (file_data_size){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, file_data_size);
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        printf("加载纹理失败!文件名: %s\n", Path.c_str());
    }
    out_width = image_width;
    out_height = image_height;
    stbi_image_free(file_data_size);
}

bool Is_File_Exist(char* file_path) {
    if (FILE* file = fopen(file_path, "r")) {
        fclose(file);
        return true;
    }else {
        return false;
    }
}

void initImageTexture(){
    //这里你可以自定义文件的路径,比如动态获取so的执行路径
    string imagePath = "/sdcard/";
    imagePath += "1.png";
    if (Is_File_Exist((char*)imagePath.c_str())){
        images[0].exist = true;
        LoadTextureFromFileMemory(imagePath, images[0].UID, images[0].width, images[0].height);
    }else{
        images[0].exist = false;
    }
    
}