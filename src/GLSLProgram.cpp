
#include <fstream>
#include <string>
#include <string_view>
#include <vector>
#include "GLSLProgram.h"
#include "Errors.h"

void GLSLProgram::compileShaders(const std::string_view vertexShaderFilePath, const std::string_view fragmentShaderFilePath)
{
    this->_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    if (this->_vertexShaderID == 0)
    {
        Errors::fatalError("Vertex shader could not to be created");
        return;
    }

    this->_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    if (this->_fragmentShaderID == 0)
    {
        Errors::fatalError("Fragment shader could not be created");
        return;
    }

    compileShader(vertexShaderFilePath, this->_vertexShaderID);
    compileShader(fragmentShaderFilePath, this->_fragmentShaderID);
}

void GLSLProgram::linkShaders()
{

    glAttachShader(this->_programID, this->_vertexShaderID);
    glAttachShader(this->_programID, this->_fragmentShaderID);

    glLinkProgram(this->_programID);

    GLint isLinked{0};

    glGetProgramiv(this->_programID, GL_LINK_STATUS, (int *)&isLinked);

    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(this->_programID, GL_INFO_LOG_LENGTH, &maxLength);

        char *errorLog = nullptr;
        glGetProgramInfoLog(this->_programID, maxLength, &maxLength, errorLog);

        glDeleteProgram(this->_programID);

        glDeleteShader(this->_vertexShaderID);
        glDeleteShader(this->_fragmentShaderID);

        std::printf("%s\n", errorLog);
        Errors::fatalError("Failed to link shaders");
        return;
    }

    glDetachShader(this->_programID, this->_vertexShaderID);
    glDetachShader(this->_programID, this->_fragmentShaderID);

    glDeleteShader(this->_vertexShaderID);
    glDeleteShader(this->_fragmentShaderID);
}

void GLSLProgram::addAttribute(std::string_view attr)
{
    glBindAttribLocation(this->_programID, this->_numAttributes++, attr.data());
}

void GLSLProgram::use()
{
    glUseProgram(this->_programID);
    for (int i = 0; i < this->_numAttributes; i++)
    {
        // is is the position of the attribute in the shader code
        glEnableVertexAttribArray(i);
    }
}

void GLSLProgram::unuse()
{
    glUseProgram(0);
    for (int i = 0; i < this->_numAttributes; i++)
    {
        // is is the position of the attribute in the shader code
        glDisableVertexAttribArray(i);
    }
}

void GLSLProgram::compileShader(std::string_view filePath, GLuint shaderID)
{

    this->_programID = glCreateProgram();
    std::ifstream vertexFile(filePath.data());
    if (vertexFile.fail())
    {
        perror(filePath.data());
        Errors::fatalError("Failed to open " + std::string(filePath));
    }
    std::string fileContents{""};
    std::string line;

    while (std::getline(vertexFile, line))
    {
        fileContents += line + "\n";
    }
    vertexFile.close();

    const char *contentsPtr = fileContents.c_str();
    glShaderSource(shaderID, 1, &contentsPtr, nullptr);
    glCompileShader(shaderID);

    GLint success{0};
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE)
    {
        GLint maxLength{0};
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<char> errorLog(maxLength);
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, &errorLog[0]);

        glDeleteShader(shaderID);
        std::printf("%s\n", &errorLog[0]);
        Errors::fatalError("Shader at " + std::string(filePath) + " failed to compile");
        return;
    }
}

GLuint GLSLProgram::getUniformLocation(std::string_view uniformName)
{

    GLint location = glGetUniformLocation(this->_programID, uniformName.data());
    if (location == GL_INVALID_INDEX)
    {
        Errors::fatalError("Uniform " + std::string(uniformName) + " not found in shader!");
    }
    return location;
}