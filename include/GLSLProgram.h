#pragma once
#define GLEW_STATIC

#include <string_view>
#include <GL/glew.h>
#include <cstdint>

class GLSLProgram
{
public:
    GLSLProgram(){};
    ~GLSLProgram() = default;

    void compileShaders(const std::string_view vertexShaderFilePath, const std::string_view fragmentShaderFilePath);
    void linkShaders();
    void addAttribute(std::string_view attr);
    void use();
    void unuse();

    GLuint getUniformLocation(std::string_view uniformName);

private:
    GLuint _programID{0};
    GLuint _vertexShaderID{0};
    GLuint _fragmentShaderID{0};
    std::uint8_t _numAttributes{0};

    void compileShader(std::string_view filePath, GLuint shaderID);
};
