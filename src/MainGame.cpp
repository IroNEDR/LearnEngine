#include <iostream>

#include "Errors.h"
#include "MainGame.h"
#include "ImageLoader.h"

void MainGame::run()
{
    initSystems();
    _sprite.init(-1.0f, -1.0f, 2.0f, 2.0f);
    this->_playerTexture = ImageLoader::loadPNG("resources/textures/jimmyJump_pack/PNG/CharacterRight_Standing.png");
    gameLoop();
}

void MainGame::initSystems()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    this->_window = SDL_CreateWindow("Main",
                                     SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                     _screenWidth, _screenHeight,
                                     SDL_WINDOW_OPENGL);
    if (this->_window == nullptr)
    {
        Errors::fatalError("SDL Window could not be created!");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (glContext == nullptr)
    {
        Errors::fatalError("SDL_GL context could not be created");
    }
    GLenum error = glewInit();
    if (error != GLEW_OK)
    {
        Errors::fatalError("Could not initialize glew");
    }

    // we want two windows to avoid flickering. one window for showing, one for drawing
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // RGB,Alpha
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    this->initShaders();
}

void MainGame::initShaders()
{
    this->_colorProgram.compileShaders("resources/shaders/colorShading.vert", "resources/shaders/colorShading.frag");
    this->_colorProgram.addAttribute("vertexPosition");
    this->_colorProgram.addAttribute("vertexColor");
    this->_colorProgram.addAttribute("vertexUV");
    this->_colorProgram.linkShaders();
}

void MainGame::gameLoop()
{
    while ((*this)._gameState != GameState::EXIT)
    {
        processInput();
        _time += 0.01f;
        drawGame();
    }
}

void MainGame::drawGame()
{

    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    this->_colorProgram.use();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->_playerTexture.id);
    GLint textureLocation = this->_colorProgram.getUniformLocation("textureSampler");
    glUniform1i(textureLocation, 0);
    this->_sprite.draw();

    GLuint timeLocation = this->_colorProgram.getUniformLocation("time");

    glUniform1f(timeLocation, this->_time);
    glBindTexture(GL_TEXTURE_2D, 0);
    this->_colorProgram.unuse();
    SDL_GL_SwapWindow(_window);
}

void MainGame::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            this->_gameState = GameState::EXIT;
            break;
        case SDL_MOUSEMOTION:
            std::cout << "x: " << event.motion.x << "y: " << event.motion.y << "\n";
            break;
        }
    }
}