#include <iostream>
#include "Canvas.h"
#include "Player.h"
#include "main.h"

extern Player* player;

Canvas::Canvas()
	: m_currentCanvas(GAME), m_isDirKeyPressed(false), m_isUpPressed(false), m_isDownPressed(false), m_isLeftPressed(false), m_isRightPressed(false)
{
	// Initializing drawing buffers
	if (!m_menu.create(640, 480))
		std::cerr << "Unable to create texture for the menu\n";
	if (!m_game.create(640, 480))
		std::cerr << "Unable to create texture for the game\n";

	std::cout << "Canvas successfully created" << std::endl;
}


Canvas::~Canvas()
{
	std::cout << "Canvas deleted" << std::endl;
}

void Canvas::clear(CanvasType c, sf::Color color)
{
	switch (c)
	{
	case Canvas::GAME:
		m_game.clear(color);
		break;
	case Canvas::MENU:
		m_menu.clear(color);
		break;
	default:
		std::cerr << "Undefined canvas in function " << __FUNCTION__ << std::endl;
		break;
	}
}

void Canvas::sendKeyPress(sf::Keyboard::Key key)
{
	if (!m_isDirKeyPressed) // Switch on direction keys only is none is pressed
	{
		m_isDirKeyPressed = true;
		switch (key)
		{
		case sf::Keyboard::Key::Up:
			//std::cout << "Up is pressed\n";
			m_isUpPressed = true;
			player->resetMovingCooldown();
			break;

		case sf::Keyboard::Key::Down:
			m_isDownPressed = true;
			player->resetMovingCooldown();
			break;

		case sf::Keyboard::Key::Left:
			m_isLeftPressed = true;
			player->resetMovingCooldown();
			break;

		case sf::Keyboard::Key::Right:
			m_isRightPressed = true;
			player->resetMovingCooldown();
			break;
		default:
			break;
		}
	}

	switch (key) // Evaluate other keys
	{
	default:
		break;
	}
}

void Canvas::sendKeyRelease(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Key::Up:
		std::cout << "Up is pressed\n";
		m_isUpPressed = false;
		break;

	case sf::Keyboard::Key::Down:
		m_isDownPressed = false;
		break;

	case sf::Keyboard::Key::Left:
		m_isLeftPressed = false;
		break;

	case sf::Keyboard::Key::Right:
		m_isRightPressed = false;
		break;

	case sf::Keyboard::Key::Escape:

		if (m_currentCanvas == GAME)
		{
			setCurrentCanvas(MENU);
			std::cout << "Changed to menu \n";
		}
		else if (m_currentCanvas == MENU)
		{
			setCurrentCanvas(GAME);
			std::cout << "Changed to game\n";
		}

		break;

	default:
		break;
	}

	if (!(m_isUpPressed || m_isDownPressed || m_isLeftPressed || m_isRightPressed))
		m_isDirKeyPressed = false;
}

void Canvas::setCurrentCanvas(CanvasType c)
{
	m_currentCanvas = c;
}

void Canvas::draw(sf::Drawable& sprite, CanvasType c)
{
	switch (c)
	{
	case GAME:
		m_game.draw(sprite);
		break;

	case MENU:
		m_menu.draw(sprite);
		break;
	default:
		std::cerr << "Undefined canvas in function " << __FUNCTION__ << std::endl;
		break;
	}
}
void Canvas::update(CanvasType thisOne)
{
	switch (thisOne)
	{
	case GAME:
	{
		if (m_isUpPressed)
			player->move(Entity::Direction::Up);
		if (m_isDownPressed)
			player->move(Entity::Direction::Down);
		if (m_isLeftPressed)
			player->move(Entity::Direction::Left);
		if (m_isRightPressed)
			player->move(Entity::Direction::Right);
	}
	break;

	case MENU:
	{

	}
	break;
	default:
		std::cerr << "Undefined canvas in function " << __FUNCTION__ << std::endl;
		break;
	}
}

sf::Sprite Canvas::getFrame()
{
	update(m_currentCanvas);
	m_game.display(); // These are necessary to set the state of each canvas,
	m_menu.display(); // so applying every transform etc

	sf::Sprite spr;
	switch (m_currentCanvas)
	{
	case GAME:
		spr = sf::Sprite(m_game.getTexture());
		break;
	case MENU:
		spr = sf::Sprite(m_menu.getTexture());
		break;
	default:
		std::cerr << "Undefined canvas in function " << __FUNCTION__ << std::endl;
		break;
	}
	return spr;
}
