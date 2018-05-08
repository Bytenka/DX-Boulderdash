#pragma once
#include <SFML\Graphics.hpp>
#include "Canvas.h"
#include "main.h"
class GameObject
{
public:
	GameObject(std::string = "invalid_texture.png");
	virtual ~GameObject();
	
	void setTexture(sf::Texture);
	sf::Texture getTexture() const;
	void reloadSprite();
	sf::Sprite  getSprite() const;
	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition() const;

	virtual void update();
	virtual void draw(Canvas::CanvasType);

protected:
	sf::Vector2f m_position;
	sf::Texture  m_texture;
	sf::Sprite   m_sprite;
};

