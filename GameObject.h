#pragma once
#include <SFML\Graphics.hpp>
#include "Canvas.h"
#include "main.h"
class GameObject
{
public:
	GameObject(std::string);
	virtual ~GameObject();
	
	void setTexture(sf::Texture);
	sf::Texture getTexture() const;
	void setSprite (sf::Sprite);
	sf::Sprite  getSprite() const;
	void setPosition(sf::Vector2i);
	sf::Vector2i getPosition() const;

	void draw(Canvas::CanvasType);

protected:
	sf::Vector2i m_position;
	sf::Texture  m_texture;
	sf::Sprite   m_sprite;
};

