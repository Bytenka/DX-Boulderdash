#pragma once

#include "main.h"
#include <iostream>
#include <string>

class Entity
{
  public:
    enum Orientation
    {
        FacingUp = 0,
        FacingRight,
        FacingDown,
        FacingLeft
    };

  public:
    Entity(std::string textureRelativePath);
    ~Entity();
    virtual void move(Direction direction) = 0;
    virtual void update() = 0;
    virtual void draw()   = 0;

  protected:
    sf::Vector2f m_position;
    Orientation  m_orientation;
    sf::Texture  m_texture;
    sf::Sprite   m_sprite;
};