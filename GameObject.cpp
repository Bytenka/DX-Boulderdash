#include <iostream>
#include "GameObject.h"
#include "Canvas.h"

extern Canvas* canvas;

GameObject::GameObject(std::string textureRelativePath)
	: m_position(sf::Vector2f(0.0f, 0.0f))
{
	LOG_METHOD_CALL;
	if (!m_texture.loadFromFile(ressourcesPath + textureRelativePath))
		std::cerr << "Unable to load game object's texture\n";

	m_sprite.setTexture(m_texture);
}

GameObject::~GameObject()
{
	LOG_METHOD_CALL;
}

void GameObject::setTexture(sf::Texture t)
{
	m_texture = t;
}

sf::Texture GameObject::getTexture() const
{
	return m_texture;
}

void GameObject::reloadSprite()
{
	m_sprite.setTexture(m_texture);
}

sf::Sprite GameObject::getSprite() const
{
	return m_sprite;
}

void GameObject::setPosition(sf::Vector2f p)
{
	m_position = p;
}

sf::Vector2f GameObject::getPosition() const
{
	return m_position;
}

void GameObject::update()
{
	m_sprite.setPosition(m_position);
}

void GameObject::draw(Canvas::CanvasType onWhat)
{
	update();
	canvas->draw(m_sprite, onWhat);
}
