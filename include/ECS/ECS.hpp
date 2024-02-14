#pragma once
#include <stdint.h>
#include <bitset>
#include <vector>
#include "glm/vec2.hpp"


const int MAX_ENTITY = 2;
using Entity = int16_t;
const int MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

struct Translation{
    int position;
    int angle;
}; typedef struct Translation Translation;

struct speed{
    int speed;
    int accelaration;
}; typedef struct speed Speed;

struct Rectangle{
    float verticies[12]={
        0.0f, 0.0f, 0.0f,       
        0.0f, 100.0f, 0.0f,     
        100.0f, 100.0f, 0.0f,   
        100.0f, 0.0f, 0.0f     
    };
}; typedef struct Rectangle Rect;