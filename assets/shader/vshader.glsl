#version 460 core

layout(location=0) in vec3 aPos;

uniform mat4  uProjection;
uniform mat4 uView;

out vec4 fColor;

void main(){
    fColor = vec4(1.0, 0.0, 0.0, 1.0);
    gl_Position = uProjection * uView * vec4(aPos, 1.0);
}