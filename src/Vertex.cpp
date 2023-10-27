#include "Vertex.h"

void Vertex::setPosition(float x, float y)
{
    this->position.x = x;
    this->position.y = y;
}

void Vertex::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->color.r = r;
    this->color.g = g;
    this->color.b = b;
    this->color.a = a;
}

void Vertex::setUV(float u, float v)
{
    this->uv.u = u;
    this->uv.v = v;
}
