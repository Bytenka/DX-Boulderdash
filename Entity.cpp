#include <string>
#include <iostream>
#include "Entity.h"
#include "main.h"

Entity::Entity(std::string textureRelativePath)
	: GameObject(textureRelativePath), m_orientation(FacingUp)
{
	LOG_METHOD_CALL;
}

Entity::~Entity()
{
	LOG_METHOD_CALL;
}
