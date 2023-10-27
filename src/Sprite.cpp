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
    vertexData[0].setPosition(x + width, y + height);
    vertexData[0].setUV(1.0f, 1.0f);

    vertexData[1].setPosition(x, y + height);
    vertexData[1].setUV(0.0f, 1.0f);

    vertexData[2].setPosition(x, y);
    vertexData[2].setUV(0.0f, 0.0f);
    // x and y coordinates of the 3 vertices of the second triangle+

    vertexData[3].setPosition(x, y);
    vertexData[3].setUV(0.0f, 0.0f);

    vertexData[4].setPosition(x + width, y);
    vertexData[4].setUV(1.0f, 0.0f);

    vertexData[5].setPosition(x + width, y + height);
    vertexData[5].setUV(1.0f, 1.0f);

    for (int i = 0; i < 6; i++)
    {
        vertexData[i].setColor(255, 0, 255, 255);
    }
    vertexData[1].setColor(0, 0, 255, 255);
    vertexData[4].setColor(0, 255, 0, 255);
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

    // UV Attribute Pointer
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, uv));
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}