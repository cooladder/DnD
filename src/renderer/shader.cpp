#include "shader.h"

shader::shader(std::string filePath[2]){
    vertexSource = File(filePath[0].c_str()).getContext();
    fragmentSource = File(filePath[1].c_str()).getContext();
    beingUsed = false;
}

shader::shader(){}

void shader::init(){
    // debug
    GLint success;
    // create shader and import shader source
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* c_str;
    glShaderSource(vertexShader, 1, &(c_str = vertexSource.c_str()), NULL);
    glShaderSource(fragmentShader, 1,&(c_str = fragmentSource.c_str()), NULL);

    // compile shader and log
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE){
        GLint maxLen;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLen);
        std::vector<GLchar> errorLog(maxLen);
        glGetShaderInfoLog(vertexShader, maxLen, &maxLen, &errorLog[0]);
        std::cout << "Failed to compile vertex shader\nerror info: ";
        for(char ch: errorLog)
            std::cout << ch;
    }

    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE){
        GLint maxLen;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLen);
        std::vector<GLchar> errorLog(maxLen);
        glGetShaderInfoLog(fragmentShader, maxLen, &maxLen, &errorLog[0]);
        std::cout << "Failed to compile fragment shader\nerror info: ";
        for(char ch: errorLog)
            std::cout << ch;
    }

    // create program obj and linking
    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(success == GL_FALSE){
        GLint maxLen;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLen);
        std::vector<GLchar> errorLog(maxLen);
        glGetProgramInfoLog(program, maxLen, &maxLen, &errorLog[0]);
        std::cout << "Failed to compile fragment shader\nerror info: ";
        for(char ch: errorLog)
            std::cout << ch;
    }
}

void shader::uploadUniform(const char* varName, glm::mat4 matrix){

    GLint varLocation = glGetUniformLocation(program, varName);
    use();
    glUniformMatrix4fv(varLocation, 1, GL_FALSE, &matrix[0][0]);
}

void shader::uploadTexture(const char* varName, GLuint slot){

    GLint varLocation = glGetUniformLocation(program, varName);
    use();
    glUniform1i(varLocation, slot);
    // std::cout << glGetError() << std::endl;
}

void shader::use(){
    if(!beingUsed){
        // draw rectangle
        glUseProgram(program);
        beingUsed = true;
    }
}

void shader::detach(){
    glUseProgram(0);
    beingUsed = false;
}
