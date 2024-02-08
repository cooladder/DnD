#ifndef DEMO_SCENE
#define DEMO_SCENE
#include "Scene.h"
#include "window.h"

class demoScene: public Scene
{
private:
    bool isChange;
public:
    demoScene();
    void update(float s) override;
};
#endif