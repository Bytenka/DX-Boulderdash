#pragma once
#include "main.h"
#include <iostream>

class Player
{
  public:
    enum PlayerMove
    {
        UP = 0,
        RIGHT,
        DOWN,
        LEFT
    };

  public:
    bool canMove;
    
  public:
    Player();
    ~Player();
    void move(PlayerMove direction);
    void draw();

  private:
    sf::Vector2f m_position;
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    PlayerMove m_orientation;
};