#include "Camera.h"
#ifndef SCENE
#define SCENE
class Scene
{
protected:
    Camera camera;
public:
    float transitionTime = 1; // In second

    Scene(){camera = Camera(glm::vec2(0.0f, 0.0f));};
    Scene(Camera cam){camera = cam;};
    virtual void update(float s){};
    virtual void init(){};
};
#endif