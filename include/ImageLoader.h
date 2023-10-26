#pragma once
#include <string_view>

#include "GLTexture.h"

class ImageLoader
{
public:
    static GLTexture loadPNG(std::string_view filePath);
};