#pragma once

#include <vector>
#include <string_view>

class IOManager
{
public:
    static bool readFileToBuffer(std::string_view filePath, std::vector<unsigned char> &buffer);
};