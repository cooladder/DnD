#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <stb/stb_image.h>
#define STB_IMAGE_IMPLEMENTATION
#ifndef MYTEXTURE
#define MYTEXTURE
class Texture
{
private:
    const char* filePath;
    GLuint textureID;
public:
    Texture(){};
    Texture(const char* file_path);
    void bind();
    void unbind();
};
#endif