#pragma once
#define GLEW_STATIC
#include <SDL/SDL.h>
#include <cstdint>
#include <string>

#include "GLTExture.h"
#include "GLSLProgram.h"
#include "Sprite.h"

enum class GameState
{
    PLAY,
    EXIT
};

class MainGame
{
public:
    MainGame(std::uint16_t screenWidth, std::uint16_t screenHeight,
             GameState gameState)
        : _screenWidth(screenWidth), _screenHeight(screenHeight),
          _gameState(gameState), _time(0){};
    ~MainGame() = default;

    void run();

private:
    void initSystems();
    void initShaders();
    void processInput();
    void gameLoop();
    void drawGame();

    float _time;
    SDL_Window *_window = nullptr;
    std::uint16_t _screenWidth;
    std::uint16_t _screenHeight;
    GameState _gameState;
    Sprite _sprite;
    GLTexture _playerTexture;

    GLSLProgram _colorProgram;
};
