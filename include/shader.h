#include <iostream>
#include <vector>
#include <string>
#include "File.h"
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#ifndef RENDER
#define RENDER
class shader
{
private:
    std::string vertexSource;
    std::string fragmentSource;
    GLint program;
    bool beingUsed;
public:
    /*
        pass in an array of file path in which the first is for vertex shader 
        and the second is for fragment shader
    */
    shader(std::string filePath[2]);
    shader();
    void init();
    void detach();
    void use();
    void uploadUniform(const char* varName, glm::mat4 matrix);
    void uploadTexture(const char* varName, GLuint slot);
};
#endif