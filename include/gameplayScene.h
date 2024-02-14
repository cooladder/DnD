#include "Scene.h"
#include "window.h"
#include "DND.h"
#include "File.h"
#include "Texture.h"
#ifndef GAMEPLAY_SCENE
#define GAMEPLAY_SCENE

class gameplayScene: public Scene
{
private:
    bool isChange;
    GLuint vao, ebo, buffer;
    Texture texture;
    float vertexArray[36] = {
        // position             color                    texture coord
        0.0f, 0.0f, 0.0f,       1.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f,   // bottom left
        0.0f, 100.0f, 0.0f,     0.0f, 1.0f, 0.0f, 1.0f,  0.0f, 1.0f,   // bottom right
        100.0f, 100.0f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,  1.0f, 1.0f,   // top right
        100.0f, 0.0f, 0.0f,     0.0f, 0.0f, 0.0f, 1.0f,  1.0f, 0.0f    // top left
    };

    int elementOrder[6] = {
        0, 1, 2,
        0, 2, 3
    };
public:
    gameplayScene();
    void update(float s) override;
    void gui(float s) override;
    void init() override;
};
#endif