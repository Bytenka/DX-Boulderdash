#include <SFML/Graphics.hpp>

#include "main.h"
#include "Player.h"

sf::RenderWindow *mainWindow;
std::string ressourcesPath = "/home/hugo/Documents/Dev/DX-Boulderdash/Ressources/";

int main()
{
    Player player = Player();
    mainWindow = new sf::RenderWindow(sf::VideoMode(640, 480), "DX-Boulderdash");

    while (mainWindow->isOpen())
    {
        sf::Event event;
        while (mainWindow->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                mainWindow->close();
                break;
                case sf::Event::KeyReleased:
                player.canMove = true;
            }
        }
        mainWindow->clear(sf::Color::White);

        sf::CircleShape c(40.0f);
        mainWindow->draw(c);

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
        
        player.draw();

        mainWindow->display();
    }
    delete mainWindow;
    return 0;
}