#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifndef CAMERA
#define CAMERA
class Camera {
private:
    glm::vec2 pos;
    glm::mat4 projection, modelView;
public:
    Camera(glm::vec2 position);
    Camera(){};
    void adjustProjection();
    glm::vec2 getPos();
    glm::mat4 getProjection();
    glm::mat4 getModelView();
    void moveAlongVec2(glm::vec2 vector);
};
#endif