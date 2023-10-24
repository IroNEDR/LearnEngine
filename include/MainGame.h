#pragma once
#define GLEW_STATIC
#include <SDL/SDL.h>
#include <cstdint>
#include <string>

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
    MainGame(std::uint16_t screenWidth, std::uint16_t screenHeight, GameState gameState) : _screenWidth(screenWidth), _screenHeight(screenHeight),
                                                                                           _gameState(GameState::PLAY){};
    ~MainGame() = default;

    void run();

private:
    void initSystems();
    void initShaders();
    void processInput();
    void gameLoop();
    void drawGame();

    SDL_Window *_window = nullptr;
    std::uint16_t _screenWidth;
    std::uint16_t _screenHeight;
    GameState _gameState;
    Sprite _sprite;

    GLSLProgram _colorProgram;
};
