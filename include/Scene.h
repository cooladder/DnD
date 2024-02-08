#include "Camera.h"
#include "ECS/ECS.hpp"
#ifndef SCENE
#define SCENE
class Scene
{
protected:
    Camera camera;
    Entity gameObjs[MAX_ENTITY];
public:
    float transitionTime = 1; // In second

    Scene(){camera = Camera(glm::vec2(0.0f, 0.0f));};
    Scene(Camera cam){camera = cam;};
    virtual void update(float s){};
    virtual void init(){};
};
#endif