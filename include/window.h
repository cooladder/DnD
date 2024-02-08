/*
This contains main header files
Last Changed: 2024/1/26
*/

#ifndef COMMON_UTIL 
#define COMMON_UTIL 
#include <string>
#include <iostream>
#endif
#ifndef IMGUI
#define IMGUI
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#endif
#ifndef GLAD_GLFW
#define GLAD_GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#endif
#ifndef GAME_USAGE
#define GAME_USAGE
#include "gamePlayScene.h"
#include "demoScene.h"
#include "Scene.h"
#endif
#ifndef WINDOW
#define WINDOW
class Window
{
private:
    int width, height;
    std::string title;
    GLFWwindow* window;
    static Scene *currentScene;
    ImVec4 clear_color = ImVec4(1.0f, 0.0f, 0.0f, 1.00f);

    Window(int winWidth, int winHeight, std::string winTitle);
    void gl_init();
    void gl_end();
    void imgui_init();
    void imgui_end();
    void loop();
public:
    static Window& getInstance();
    int run();
    static void changeScene(int sceneIndex);
    void setColor(ImVec4 color);
    void setColor(float r, float g, float b, float a);
    ImVec4 getColor();
};
#endif