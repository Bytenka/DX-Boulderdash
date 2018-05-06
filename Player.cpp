#include <iostream>
#include <string>
#include "Canvas.h"
#include "Player.h"
#include "main.h"

Player::Player(sf::Vector2f position)
    : Entity("player.png")
{
	LOG_METHOD_CALL;
    std::cout << "Entity Player Created\n";
}

Player::~Player()
{
	LOG_METHOD_CALL;
    std::cout << "Entity Player Destroyed\n";
}

void Player::draw(Canvas::CanvasType onWhat)
{
    update();
	GameObject::draw(onWhat);
}

void Player::resetMovingCooldown()
{
    m_movingCooldown = 0;
}

void Player::update()
{
    if (m_movingCooldown > 0)
        m_movingCooldown--;
    m_sprite.setPosition(m_position);
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
        m_movingCooldown += 15;
    }
}