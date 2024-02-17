#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include "demoScene.h"
#include "ECS/ECS.hpp"
#include "ECS/ComponentManager.hpp"
#include "ECS/EntityManager.hpp"
#include <iostream>

demoScene::demoScene(){
    Window::getInstance().setColor(0.0f, 0.0f, 1.0f, 1.0f);
    std::string filePaths[2] = {"assets\\shader\\vshader.glsl",
                            "assets\\shader\\fshader.glsl"};
    defaultShader = shader(filePaths);
    isChange = false;
}

void demoScene::gui(float s){
    DND::setup();
    DND::build();
}

void demoScene::update(float s){

    defaultShader.use();
    // upload camera matrix
    defaultShader.uploadUniform("uProjection", camera.getProjection());
    defaultShader.uploadUniform("uView", camera.getModelView());

    // bind vao
    glBindVertexArray(vao);
    // enable vertex attr
    glEnableVertexAttribArray(0);

    // Rect obj = ComponentManager::findComponentData<Rect>(gameObjs);
    // for(int i = 0; i < 4; i++){
    //     obj.verticies[3*i] += 1;
    // }
    // ComponentManager::setComponentData<Rect>(gameObjs, obj);
    // glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // glBufferSubData(GL_ARRAY_BUFFER, 0, 48, obj.verticies);

    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // unbind
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
    defaultShader.detach();


    if(!isChange && ImGui::IsMouseClicked(ImGuiMouseButton_Left)){
        isChange = true;
    }
    if(isChange && transitionTime > 0){
        transitionTime -= s;
        ImVec4 grad = ImVec4(s*5.0f, s*5.0f, s*5.0f, 0.0f);
        ImVec4 currentColor = Window::getInstance().getColor();
        Window::getInstance().setColor(
            currentColor.x - grad.x,
            currentColor.y - grad.y, 
            currentColor.z - grad.z, 
            currentColor.w - grad.w
        );
    }else if(isChange){
        Window::changeScene(0);
    }
}

void demoScene::init(){
    defaultShader.init();
    ComponentManager::init();
    EntityManager::init();
    Rect vertexArray;

    Entity rec1 = EntityManager::getUniqueID();
    ComponentManager::registerEntity(rec1);
    ComponentManager::registerComponent<Rect>(rec1);
    ComponentManager::setComponentData<Rect>(rec1, vertexArray);
    Rect obj = ComponentManager::findComponentData<Rect>(rec1);

    gameObjs = rec1;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(obj.verticies), obj.verticies, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementOrder), elementOrder, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, (3)*sizeof(float), 0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);

}