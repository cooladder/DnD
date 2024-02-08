#include "Camera.h"

Camera::Camera(glm::vec2 position){
    pos = position;
    adjustProjection();
}

glm::vec2 Camera::getPos(){
    return pos;
}

void Camera::adjustProjection(){
    projection = glm::ortho(0.0f, 32.0f*40.0f, 0.0f, 32.0f*21.0f, 0.0f, 100.0f);
}

void Camera::moveAlongVec2(glm::vec2 vector){
    pos += vector;
}

glm::mat4 Camera::getModelView(){
    glm::vec3 camPos = glm::vec3(pos.x, pos.y, 20.0f);
    glm::vec3 camFacing = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 camTop = glm::vec3(0.0f, 1.0f, 0.0f);
    modelView = glm::lookAt(camPos, camPos+camFacing, camTop);
    return modelView;
}

glm::mat4 Camera::getProjection(){
    return projection;
}