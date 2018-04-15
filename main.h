#pragma once
#include <SFML/Graphics.hpp>

extern sf::RenderTexture* menuCanvas;
extern sf::RenderTexture* gameCanvas;
extern std::string ressourcesPath;
extern const int g_tileSize;

enum Direction
{
    Up = 0,
    Right,
    Down,
    Left
};