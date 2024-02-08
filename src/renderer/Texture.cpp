#include "Texture.h"

Texture::Texture(const char* file_path){
    filePath = file_path;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // set texture parameter behavior
    // repeat texture in both directions
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // pixelate when shrinking or stretching
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // use stb_image to load image
    int width;
    int height;
    int channels;
    unsigned char* image = stbi_load(filePath, &width, &height, &channels, 0);

    if(image == nullptr)
        std::cout << "Something goes wrong in loading image\n" << std::endl;

    if(channels == 3){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*)image);
    }
    else if(channels == 4){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (void*)image);
    }
    else    
        std::cout << "Unknown number of channel\n";

    stbi_image_free(image);
    // unbind
    unbind();
}

void Texture::bind(){
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void Texture::unbind(){
    glBindTexture(GL_TEXTURE_2D, 0);
}