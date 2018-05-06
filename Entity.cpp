#include <string>
#include <iostream>
#include "Entity.h"
#include "main.h"

Entity::Entity(std::string textureRelativePath)
	: GameObject(textureRelativePath), m_position(sf::Vector2f(0.0f, 0.0f)), m_orientation(FacingUp)
{
	LOG_METHOD_CALL;
}

Entity::~Entity()
{
	LOG_METHOD_CALL;
}
