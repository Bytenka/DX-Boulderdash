#pragma once
#include "GameObject.h"

class Level
{
public:
	Level(std::string levelFileLocation);
	~Level();

	void updateObject(int row, int col);
	void draw();
	std::string getName() const;
	void moveObject(sf::Vector2u from, sf::Vector2u to, GameObject* objAtPreviousLoc);
	GameObject* getObjectAt(sf::Vector2u);
	sf::Vector2f getSize() const;

private:
	void processLineData(std::string data, std::vector<GameObject**>& destVector);
	void assignVarValue(std::string varID, std::string varValue);
	GameObject** generateLevelRow(std::string rowData);
	void generateLevelFromVector(std::vector<GameObject**>& data);

private:
	std::string m_name;
	std::size_t m_width;
	std::size_t m_height;

	GameObject*** m_map;
	sf::Clock m_logicClock;
};