#include <cstddef>

#include "Sprite.h"
#include "Vertex.h"

Sprite::Sprite()
{
    _vboID = 0;
    _x = 0;
    _y = 0;
    _width = 0;
    _height = 0;
}

Sprite::~Sprite()
{
    if (_vboID != 0)
    {
        glDeleteBuffers(1, &_vboID);
    }
}

void Sprite::init(float x, float y, float width, float height)
{
    _x = x;
    _y = y;
    _width = width;
    _height = height;

    if (_vboID == 0)
    {
        glGenBuffers(1, &_vboID);
    }

    Vertex vertexData[6]{};

    // x and y coordinates of the 3 vertices of the first triangle
    vertexData[0].position.x = x + width;
    vertexData[0].position.y = y + height;

    vertexData[1].position.x = x;
    vertexData[1].position.y = y + height;

    vertexData[2].position.x = x;
    vertexData[2].position.y = y;

    // x and y coordinates of the 3 vertices of the second triangle
    vertexData[3].position.x = x;
    vertexData[3].position.y = y;

    vertexData[4].position.x = x + width;
    vertexData[4].position.y = y;

    vertexData[5].position.x = x + width;
    vertexData[5].position.y = y + height;

    for (int i = 0; i < 6; i++)
    {
        vertexData[i].color.r = 255;
        vertexData[i].color.g = 0;
        vertexData[i].color.b = 255;
        vertexData[i].color.a = 255;
    }

    vertexData[1].color.r = 0;
    vertexData[1].color.g = 0;
    vertexData[1].color.b = 255;
    vertexData[1].color.a = 255;

    vertexData[4].color.r = 0;
    vertexData[4].color.g = 255;
    vertexData[4].color.b = 0;
    vertexData[4].color.a = 255;
    // Bind Buffer (Which buffer should be active)
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    // upload data to the GPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    // unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);

    // we just want one ( the first one => idx 0)
    glEnableVertexAttribArray(0);

    // This is the position attribute pointer of our vertex struct
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));

    // This is the color attribute pointer of our vertex struct
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void *)offsetof(Vertex, color));

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}