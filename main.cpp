#include <SFML/Graphics.hpp>

#include "main.h"
#include "Player.h"

// LINUX AND WINDOWS BUILD
//#define PATH_TO_RESSOURCES "/home/hugo/Documents/Dev/DX-Boulderdash/Source_files/Ressources/"
#define PATH_TO_RESSOURCES "D:/#Windows Stuff/Documents/Dev/DX-Boulderdash/DX-Boulderdash/Ressources/"


enum CanvasToDisplay
{
	MENU,
	LEVEL
};

sf::RenderTexture* menuCanvas;
sf::RenderTexture* gameCanvas;
CanvasToDisplay currentCanvas;

std::string ressourcesPath = PATH_TO_RESSOURCES;


int main()
{
	Player player = Player();

	// Initializing drawing buffers
	sf::RenderTexture mt;
	if (!mt.create(640, 480))
		std::cerr << "Unable to create texture for the menu\n";
	menuCanvas = &mt;

	sf::RenderTexture gt;
	if (!gt.create(640, 480))
		std::cerr << "Unable to create texture for the game\n";
	gameCanvas = &gt;

	// Initializing window
	sf::RenderWindow mainWindow(sf::VideoMode(640, 480), "DX-Boulderdash");

	currentCanvas = LEVEL; // @DEBUG

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
			case sf::Event::KeyReleased:
				player.canMove = true;
			}
		}

		sf::RenderTexture* canvasToDisplay = nullptr;
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
		}

		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				player.move(Player::PlayerMove::UP);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				player.move(Player::PlayerMove::DOWN);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				player.move(Player::PlayerMove::LEFT);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				player.move(Player::PlayerMove::RIGHT);
			}
		}


		{ // Rendering and logic

			canvasToDisplay->clear(sf::Color::Red);
			if (currentCanvas == MENU)
			{
				player.draw();
			}
			else
			{

			}
			canvasToDisplay->display();

		} // Rendering and logic

		// Finally drawing everything to the screen
		sf::Sprite sprite(canvasToDisplay->getTexture());
		mainWindow.draw(sprite);
		mainWindow.display();

	}
	return 0;
}