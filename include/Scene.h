#include "Camera.h"
#include "shader.h"
#include "ECS/ECS.hpp"
#ifndef SCENE
#define SCENE
class Scene
{
protected:
    Camera camera;
    shader defaultShader;
    Entity gameObjs;
public:
    float transitionTime = 1; // In second

    Scene(){camera = Camera(glm::vec2(0.0f, 0.0f));};
    Scene(Camera cam){camera = cam;};
    virtual void update(float s){};
    virtual void gui(float s){};
    virtual void init(){};
};
#endif