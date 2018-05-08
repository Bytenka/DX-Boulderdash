#include <iostream>
#include <typeinfo>
#include <string>
#include "Canvas.h"
#include "Dirt.h"
#include "Player.h"
#include "Void.h"
#include "Level.h"
#include "Diamond.h"
#include "main.h"

extern Level* loadedLevel;

Player::Player()
	: Entity("player.png"), m_movingCooldownValue(sf::milliseconds(200)), m_diamondsCollected(0), m_oneMoveAllowed(true)
{
	LOG_METHOD_CALL;
	m_movingCooldown.restart();
	std::cout << "Entity Player Created\n";
}

Player::~Player()
{
	LOG_METHOD_CALL;
	std::cout << "Entity Player Destroyed\n";
}

void Player::update()
{
	GameObject::update();
	//if (m_movingCooldown > 0)
		//m_movingCooldown--;
}

void Player::resetMovingCooldown()
{
	m_oneMoveAllowed = true;
}

void Player::move(Direction direction)
{
	//  if (m_movingCooldown == 0)
	//  {
	//      sf::Vector2f dir;
	//      switch (direction)
	//      {
	//      case Direction::Up:
	//          dir = sf::Vector2f(0, -1);
	//          break;
	//      case Direction::Down:
	//          dir = sf::Vector2f(0, 1);
	//          break;
	//      case Direction::Left:
	//          dir = sf::Vector2f(-1, 0);
	//          break;
	//      case Direction::Right:
	//          dir = sf::Vector2f(1, 0);
	//          break;
	//      }
	//      dir.x *= g_tileSize;
	//      dir.y *= g_tileSize;
	//      m_position += dir;
	//      m_movingCooldown += 10;
		  ////std::cout << m_position.x << " " << m_position.y << std::endl;
		  ////std::cout << m_sprite.getPosition().x << " " << m_sprite.getPosition().y << std::endl;
	//  }

	if (m_oneMoveAllowed || m_movingCooldown.getElapsedTime() > m_movingCooldownValue)
	{
		bool moveSucceeded;
		switch (direction)
		{
		case Up:
			moveSucceeded = attemptMove(sf::Vector2i(0, -1));
			break;
		case Down:
			moveSucceeded = attemptMove(sf::Vector2i(0, 1));
			break;
		case Left:
			moveSucceeded = attemptMove(sf::Vector2i(-1, 0));
			break;
		case Right:
			moveSucceeded = attemptMove(sf::Vector2i(1, 0));
			break;
		default:
			break;
		}

		if (!moveSucceeded)
			std::cerr << "Unable to move at this location\n";

		m_oneMoveAllowed = false;
		m_movingCooldown.restart();
	}
}

bool Player::attemptMove(sf::Vector2i desiredLoc)
{
	sf::Vector2u posOnGrid;
	posOnGrid.x = (int)(m_position.x / g_tileSize + desiredLoc.x);
	posOnGrid.y = (int)(m_position.y / g_tileSize + desiredLoc.y);

	GameObject* objectAt = loadedLevel->getObjectAt(posOnGrid);
	sf::Vector2u playerLocIndexes = sf::Vector2u(
		(unsigned)(m_position.x / g_tileSize),
		(unsigned)(m_position.y / g_tileSize)
	);
	if (objectAt != nullptr)
	{
		if (typeid(*objectAt) == typeid(Dirt) || typeid(*objectAt) == typeid(Void))
			loadedLevel->moveObject(playerLocIndexes, posOnGrid, new Void());
		else if (typeid(*objectAt) == typeid(Diamond))
		{
			loadedLevel->moveObject(playerLocIndexes, posOnGrid, new Void());
			m_diamondsCollected++;
		}
	}
	return true;
}

