#pragma once

struct Position
{
    float x;
    float y;
};

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct Vertex
{
    // the vertex struct should always have a multiple of 4 bytes for performance reasons
    Position position;
    Color color;
};