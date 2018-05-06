#pragma once
#include "GameObject.h"

class Entity : public GameObject
{
public:
	enum Orientation
	{
		FacingUp = 0,
		FacingDown,
		FacingLeft,
		FacingRight
	};

	enum Direction
	{
		Up = 0,
		Down,
		Left,
		Right
	};

public:
	Entity(std::string textureRelativePath);
	virtual ~Entity();
	virtual void move(Direction direction) = 0;
	virtual void update() = 0;

protected:
	Orientation  m_orientation;
	sf::Vector2f m_position;
};