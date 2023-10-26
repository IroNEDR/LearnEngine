#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

struct GLTexture
{
    GLuint id;
    int width;
    int height;
};