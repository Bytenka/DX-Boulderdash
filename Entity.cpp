#include <string>
#include <iostream>
#include "main.h"
#include "Entity.h"

Entity::Entity(std::string textureRelativePath)
: m_position(sf::Vector2f()), m_orientation(FacingUp)
{
    if (!m_texture.loadFromFile(ressourcesPath + textureRelativePath))
        std::cerr << "Unable to load entity's texture\n";
    
    m_sprite.setTexture(m_texture);

}

Entity::~Entity()
{
}