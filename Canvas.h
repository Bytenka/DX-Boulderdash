#pragma once
#include <SFML/Graphics.hpp>

class Canvas
{
public:
	enum CanvasType
	{
		GAME,
		MENU
	};

	Canvas();
	sf::Sprite getFrame();
	void draw(sf::Drawable&, CanvasType);
	void clear(CanvasType, sf::Color = sf::Color::Black);
	void sendKeyPress(sf::Keyboard::Key);
	void sendKeyRelease(sf::Keyboard::Key);
	void setCurrentCanvas(CanvasType);
	void update(CanvasType);
	~Canvas();

private:
	sf::RenderTexture m_game;
	sf::RenderTexture m_menu;
	CanvasType m_currentCanvas;

	bool m_isUpPressed;
	bool m_isDownPressed;
	bool m_isLeftPressed;
	bool m_isRightPressed;
	bool m_isDirKeyPressed; // Used to make only one move at the time

	/* Unused code, but I keep it because it says sommething important

	const int m_loggedKeysCount;	
	//^^^ MUST BE ABOVE m_loggedKeys ^^^
	// This is because in the initialization list
	// (: foo(4), test('a') etc.), variables are initialized IN THE ORDER OF
	// DECLARATION, so in this case, m_loggedKeysCount must be initialized first
	// in order to allocate correctly.
	bool* m_loggedKeys;				// 0 = Up, 1 = Down, 2 = Left, 3 = Right

	*/
};