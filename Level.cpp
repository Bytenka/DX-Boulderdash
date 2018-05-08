#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Level.h"
#include "Player.h"
#include "Diamond.h"
#include "Dirt.h"
#include "main.h"

extern Player* player;
extern Canvas* canvas;

Level::Level(std::string levelFileLocation)
{
	std::vector<GameObject**> levelLines;
	std::ifstream levelFile;
	levelFile.open(ressourcesPath + levelFileLocation);

	if (levelFile.is_open())
	{
		std::string lineData;
		while (std::getline(levelFile, lineData))
		{
			if (lineData != "")
				if (lineData.at(0) != '#' && lineData.at(0) != '\n')
					processLineData(lineData, levelLines);
		}
		generateLevelFromVector(levelLines);
	}
	else
		std::cerr << "Unable to open level file\n";

	m_logicClock.restart();
}

Level::~Level()
{
	for (unsigned int row = 0; row < m_height; row++)
		delete[] m_map[row];
}

void Level::processLineData(std::string data, std::vector<GameObject**>& destVector)
{
	// Process if the line is a variable definition line
	std::size_t cut = data.find("=");
	if (cut != std::string::npos) // It's a ^^^^^^
		assignVarValue(data.substr(0, cut), data.substr(cut + 1));
	else
	{
		destVector.push_back(generateLevelRow(data)); // Create a new row in the game based on the instructions
		m_width = data.size(); // Push it to the vector storing the lines
	}
}

void Level::assignVarValue(std::string varID, std::string varValue)
{
	if (varID.compare("name") == 0)
		m_name = varValue;
	// Need to implement other things @TODO
}

GameObject** Level::generateLevelRow(std::string rowData)
{
	GameObject** oneRow = new GameObject*[rowData.size()];
	for (unsigned int i = 0; i < rowData.size(); i++)
	{
		switch (rowData.at(i))
		{
		case 'P':
			player = new Player();
			oneRow[i] = player;
			break;
		case 'D':
			oneRow[i] = new Dirt();
			break;
		case 'G':
			oneRow[i] = new Diamond(Diamond::DiamondType::Green);
			break;
		case 'B':
			oneRow[i] = new Diamond(Diamond::DiamondType::Blue);
			break;
			//case 'R':
			//break;
		default:
			std::cerr << rowData.at(i) << " is not a valid character for level definition\n";
			break;
		}
	}
	return oneRow;
}

void Level::generateLevelFromVector(std::vector<GameObject**>& data)
{
	m_map = new GameObject**[data.size()];
	m_height = data.size();

	for (unsigned int row = 0; row < data.size(); row++)
		m_map[row] = data.at(row);
}

void Level::updateObject(int row, int col)
{
	GameObject* thisOne = m_map[row][col];
	thisOne->setPosition(sf::Vector2f((float)col * g_tileSize, (float)row * g_tileSize));
}

void Level::draw()
{
	bool shouldUpdate = false;
	if (m_logicClock.getElapsedTime() > sf::milliseconds(200))
	{
		shouldUpdate = true;
		m_logicClock.restart();
	}
	sf::RectangleShape outline(sf::Vector2f(m_width * g_tileSize, m_height * g_tileSize));
	outline.setFillColor(sf::Color::Transparent);
	outline.setOutlineThickness(1);
	outline.setOutlineColor(sf::Color::Black);
	canvas->draw(outline, Canvas::CanvasType::GAME);

	for (unsigned int row = 0; row < m_height; row++)
		for (unsigned int col = 0; col < m_width; col++)
		{
			GameObject* currentObject = m_map[row][col];

			if (typeid(*currentObject) == typeid(Player))
				updateObject(row, col);

			else if (shouldUpdate)
				updateObject(row, col);
			currentObject->draw(Canvas::CanvasType::GAME);
		}
}

std::string Level::getName() const
{
	return m_name;
}

void Level::moveObject(sf::Vector2u from, sf::Vector2u to, GameObject* objAtPreviousLoc)
{
	if (from.x >= m_width || from.y >= m_height)
	{
		std::cerr << "Invalid starting location in " << __FUNCTION__ << std::endl;
		return;
	}

	if (to.x >= m_width || to.y >= m_height)
	{
		std::cerr << "Invalid starting location in " << __FUNCTION__ << std::endl;
		return;
	}

	if (objAtPreviousLoc == nullptr)
	{
		std::cerr << "NULLPTR provided in " << __FUNCTION__ << std::endl;
		return;
	}

	GameObject* toDelete = m_map[to.y][to.x];
	m_map[to.y][to.x] = m_map[from.y][from.x];
	m_map[from.y][from.x] = objAtPreviousLoc;
	delete toDelete;
}

GameObject* Level::getObjectAt(sf::Vector2u loc)
{
	if (loc.x >= m_width || loc.y >= m_height)
		return nullptr;
	return m_map[loc.y][loc.x];
}

sf::Vector2f Level::getSize() const
{
	return sf::Vector2f(m_width, m_height);
}