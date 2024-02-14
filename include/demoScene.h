#pragma once
#include "Scene.h"
#include "window.h"

class demoScene: public Scene
{
private:
    bool isChange;
    GLuint vbo, vao, ebo;
    int elementOrder[6] = {
        0, 1, 2,
        0, 2, 3
    };
public:
    demoScene();
    void update(float s) override;
    void gui(float s) override;
    void init() override;
};