#include "IOManager.h"
#include <fstream>
#include <cstdint>

bool IOManager::readFileToBuffer(std::string_view filePath, std::vector<unsigned char> &buffer)
{
    std::ifstream file(filePath.data(), std::ios::binary);
    if (file.fail())
    {
        perror(filePath.data());
        return false;
    }

    // seek to the end to get the filesize
    file.seekg(0, std::ios::end);

    std::uint32_t fileSize = static_cast<std::uint32_t>(file.tellg());

    // jump back to the beginning of the file to start reading
    file.seekg(0, std::ios::beg);

    // reduce the file size by the size of the file header
    fileSize -= static_cast<std::uint32_t>(file.tellg());

    buffer.resize(fileSize);

    file.read((char *)&(buffer[0]), fileSize);
    file.close();
    return true;
}