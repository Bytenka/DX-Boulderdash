#pragma once
#include "Canvas.h"

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

	enum Direction
	{
		Up = 0,
		Right,
		Down,
		Left
	};

  public:
    Entity(std::string textureRelativePath);
    ~Entity();
    virtual void move(Direction direction) = 0;
    virtual void update() = 0;
    virtual void draw(Canvas::CanvasType)   = 0;

    sf::Vector2f m_position;
  protected:
    Orientation  m_orientation;
    sf::Texture  m_texture;
    sf::Sprite   m_sprite;
};