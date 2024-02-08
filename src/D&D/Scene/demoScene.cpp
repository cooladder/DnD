#include "demoScene.h"
#include <iostream>

demoScene::demoScene(){
    Window::getInstance().setColor(0.0f, 0.0f, 1.0f, 1.0f);
    isChange = false;
}

void demoScene::update(float s){
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