#version 460 core

in vec4 fColor;
in vec2 fTextureCoord;

out vec4 color;

uniform sampler2D TEX_SAMPLER;

void main(){
    color = texture(TEX_SAMPLER, fTextureCoord);
    // color = fColor;
}