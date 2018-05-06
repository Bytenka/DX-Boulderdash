#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Player.h"
#include "Canvas.h"
#include "Level.h"
#include "Dirt.h"

// LINUX AND WINDOWS BUILD
//#define PATH_TO_RESSOURCES "/home/hugo/Documents/Dev/DX-Boulderdash/Source_files/Ressources/"
#define PATH_TO_RESSOURCES "D:/#Windows Stuff/Documents/Dev/DX-Boulderdash/DX-Boulderdash/Ressources/"

/*
enum CanvasToDisplay
{
	MENU,
	LEVEL
};*/

//CanvasToDisplay currentCanvas;
int g_tileSize = 32;
Canvas* canvas;
Player* player;

std::string ressourcesPath = PATH_TO_RESSOURCES;

int main()
{
	/*int** test = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		test[i] = new int;
		*test[i] = i;
	}

	std::cout << *test[3] << std::endl;*/

	canvas = new Canvas();
	player = new Player(sf::Vector2f(0, 0));
	Level* lvl1 = new Level();
	std::cout << lvl1->getName() << std::endl;

	// Initializing window
	sf::RenderWindow mainWindow(sf::VideoMode(640, 480), "DX-Boulderdash");
	mainWindow.setFramerateLimit(60);
	mainWindow.setKeyRepeatEnabled(false);

	//currentCanvas = LEVEL; // @DEBUG

	while (mainWindow.isOpen())
	{
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mainWindow.close();
				break;

			case sf::Event::KeyPressed:
				canvas->sendKeyPress(event.key.code);
				break;

			case sf::Event::KeyReleased:
				canvas->sendKeyRelease(event.key.code);
				break;
			}
		}

		/*sf::RenderTexture *canvasToDisplay = nullptr;
		switch (currentCanvas)
		{
		case MENU:
			canvasToDisplay = menuCanvas;
			break;
		case LEVEL:
			canvasToDisplay = gameCanvas;
			break;
		default:
			break;
		}*/

		{ // Rendering and logic

			canvas->clear(Canvas::CanvasType::GAME, sf::Color::Blue);
			/*if (currentCanvas == MENU)
			{
			}
			else
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					player.move(Direction::Up);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					player.move(Direction::Down);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					player.move(Direction::Left);
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					player.move(Direction::Right);
				player.draw();
			}
			canvasToDisplay->display();*/

		} // Rendering and logic

		// Finally drawing everything to the screen
		lvl1->draw();
		player->draw(Canvas::CanvasType::GAME);
		mainWindow.clear();
		mainWindow.draw(canvas->getFrame());
		mainWindow.display();
	}
	delete canvas;
	delete player;
	return 0;
}