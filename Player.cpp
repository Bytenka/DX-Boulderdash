#include "Player.h"

Player::Player()
    : m_position(sf::Vector2f()), m_orientation(DOWN)
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

void Player::update()
{
    if (m_movingCooldown > 0)
        m_movingCooldown--;
        m_sprite.setPosition(m_position);
}

void Player::draw()
{
    update();
    gameCanvas->draw(m_sprite);
}

void Player::resetMovingCooldown()
{
    m_movingCooldown = 0;
}

void Player::move(PlayerMove direction)
{
    if (m_movingCooldown == 0)
    {
        sf::Vector2f dir;
        switch (direction)
        {
        case UP:
            dir = sf::Vector2f(0, -1);
            break;
        case DOWN:
            dir = sf::Vector2f(0, 1);
            break;
        case LEFT:
            dir = sf::Vector2f(-1, 0);
            break;
        case RIGHT:
            dir = sf::Vector2f(1, 0);
            break;
        }
        m_position += dir;
        m_movingCooldown += 15;
    }
}