#include "Player.h"

Player::Player()
    : m_position(sf::Vector2f()), m_orientation(DOWN), canMove(true)
{
    if (!m_texture.loadFromFile(ressourcesPath + "player.png"))
    {
        std::cout << "Unable to load player's graphics\n";
    }

    m_sprite.setTexture(m_texture);

    std::cout << "Entity Player Created\n";
}

Player::~Player()
{
    std::cout << "Entity Player Destroyed\n";
}

void Player::draw()
{
	gameCanvas->draw(m_sprite);
}

void Player::move(PlayerMove direction)
{
    if (canMove)
    {
        switch (direction)
        {
        case UP:
            std::cout << "move UP\n";
            break;

        case DOWN:
            std::cout << "move DOWN\n";
            break;

        case LEFT:
            std::cout << "move LEFT\n";
            break;

        case RIGHT:
            std::cout << "move RIGHT\n";
            break;
        }
        canMove = false;
    }
}