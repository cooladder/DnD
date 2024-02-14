#include "gameplayScene.h"
#include <iostream>
#include <vector>

gameplayScene::gameplayScene(){
    Window::getInstance().setColor(0.0f, 1.0f, 0.0f, 1.0f);
    std::string filePaths[2] = {"C:\\Users\\Jim\\OneDrive\\Desktop\\DnD\\asset\\shader\\default_vertex_shader.glsl",
                            "C:\\Users\\Jim\\OneDrive\\Desktop\\DnD\\asset\\shader\\default_fragment_shader.glsl"};
    defaultShader = shader(filePaths);
    isChange = false;
}

void gameplayScene::gui(float s){
    DND::setup();
}

void gameplayScene::update(float s){

    defaultShader.use();
    // upload camera matrix
    defaultShader.uploadUniform("uProjection", camera.getProjection());
    defaultShader.uploadUniform("uView", camera.getModelView());
    // upload texture
    glActiveTexture(GL_TEXTURE0);
    texture.bind();
    defaultShader.uploadTexture("TEX_SAMPLER", 0);

    // bind vao
    glBindVertexArray(vao);
    // enable vertex attr
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    
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
        Window::changeScene(1);
    }
}

void gameplayScene::init(){
    //init
    defaultShader.init();
    texture = Texture("C:\\Users\\Jim\\OneDrive\\Desktop\\DnD\\asset\\iamge\\images.jpg");

    // generate vertex buffer object(VBO)
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexArray), vertexArray, GL_STATIC_DRAW);

    // generate vertex array object(VAO)
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // generate element buffer object(EBO)
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elementOrder), elementOrder, GL_STATIC_DRAW);

    // set vertex attribute
    int posSize = 3;
    int colorSize = 4;
    int textCoordSize = 2;
    int stride = posSize + colorSize + textCoordSize;
    glVertexAttribPointer(0, posSize, GL_FLOAT, GL_FALSE, (stride)*sizeof(float), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, colorSize, GL_FLOAT, GL_FALSE, (stride)*sizeof(float), (void*)(posSize*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, textCoordSize, GL_FLOAT, GL_FALSE, (stride)*sizeof(float), (void*)((posSize + colorSize)*sizeof(float)));
    glEnableVertexAttribArray(2);
}