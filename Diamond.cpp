#include "Diamond.h"
#include "Level.h"
#include "Void.h"

extern Level* loadedLevel;

Diamond::Diamond(DiamondType d)
	: GameObject(), m_type(d)
{
	sf::Texture* tempT = new sf::Texture();
	switch (m_type)
	{
	case Green:
		(*tempT).loadFromFile(ressourcesPath + "diamond_green.png");
		break;

	case Blue:
		(*tempT).loadFromFile(ressourcesPath + "diamond_blue.png");
		break;

	default:
		break;
	}

	setTexture(*tempT);
	reloadSprite();
}

Diamond::~Diamond()
{
}

void Diamond::update()
{
	GameObject::update();
	GameObject* objectBelow = loadedLevel->getObjectAt(sf::Vector2u(
		(unsigned)m_position.x / g_tileSize,
		(unsigned)m_position.y / g_tileSize + 1
	));

	if (objectBelow != nullptr)
	{
		if (typeid(*objectBelow) == typeid(Void))
			fall();
		else if (typeid(*objectBelow) == typeid(Diamond))
			fall();
	}
}

void Diamond::fall()
{
	sf::Vector2u objIndex(
		(unsigned)m_position.x / g_tileSize,
		(unsigned)m_position.y / g_tileSize
	);

	sf::Vector2u testBelowLoc = sf::Vector2u(sf::Vector2i(objIndex) + sf::Vector2i(0, 1));
	GameObject* testBelow = loadedLevel->getObjectAt(testBelowLoc);

	if (testBelow != nullptr && typeid(*testBelow) == typeid(Void))
	{
		loadedLevel->moveObject(objIndex, testBelowLoc, new Void());
		return;
	}

	sf::Vector2u testLeftLoc = sf::Vector2u(sf::Vector2i(objIndex) + sf::Vector2i(-1, 0));
	sf::Vector2u testLeftLoc2 = sf::Vector2u(sf::Vector2i(objIndex) + sf::Vector2i(-1, 1));
	GameObject* testLeft = loadedLevel->getObjectAt(testLeftLoc);
	GameObject* testLeft2 = loadedLevel->getObjectAt(testLeftLoc2);

	if (testLeft != nullptr && typeid(*testLeft) == typeid(Void)
		&& testLeft2 != nullptr && typeid(*testLeft2) == typeid(Void))
	{
		loadedLevel->moveObject(objIndex, testLeftLoc2, new Void());
		return;
	}

	sf::Vector2u testRightLoc = sf::Vector2u(sf::Vector2i(objIndex) + sf::Vector2i(1, 0));
	sf::Vector2u testRightLoc2 = sf::Vector2u(sf::Vector2i(objIndex) + sf::Vector2i(1, 1));
	GameObject* testRight = loadedLevel->getObjectAt(testRightLoc);
	GameObject* testRight2 = loadedLevel->getObjectAt(testRightLoc2);

	if (testRight != nullptr && typeid(*testRight) == typeid(Void)
		&& testRight2 != nullptr && typeid(*testRight2) == typeid(Void))
	{
		loadedLevel->moveObject(objIndex, testRightLoc2, new Void());
		return;
	}
}
