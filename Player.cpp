#include "Player.h"

Player::Player(sf::Vector2f position)
    : Entity("player.png")
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

void Player::move(Direction direction)
{
    if (m_movingCooldown == 0)
    {
        sf::Vector2f dir;
        switch (direction)
        {
        case Direction::Up:
            dir = sf::Vector2f(0, -1);
            break;
        case Direction::Down:
            dir = sf::Vector2f(0, 1);
            break;
        case Direction::Left:
            dir = sf::Vector2f(-1, 0);
            break;
        case Direction::Right:
            dir = sf::Vector2f(1, 0);
            break;
        }
        dir.x *= g_tileSize;
        dir.y *= g_tileSize;
        m_position += dir;
        std::cout << m_position.x << " " << m_position.y << std::endl;
        m_movingCooldown += 15;
    }
}