#include <iostream>
#include <string>
#include <fstream>
#include "Level.h"
#include "Dirt.h"
#include "main.h"

Level::Level()
	: m_map(nullptr)
{
	// Loading the level
	std::ifstream levelFile;
	levelFile.open(ressourcesPath + "level1.dat");
	if (levelFile.is_open())
	{
		std::string lineData;
		std::vector<GameObject**> tempMap;		// Will be tranformed at the end of the constructor with createMapArray()

		while (std::getline(levelFile, lineData))
		{
			if (lineData != "")
			{
				if (lineData.at(0) != '#' && lineData.at(0) != '\n')
				{

					std::size_t cut = lineData.find("=");	// Identify attributes definition lines
					if (cut != std::string::npos)			// Is an attribute definition line
					{
						std::string instruction = lineData.substr(0, cut);
						std::string* value = new std::string(lineData.substr(cut + 1));

						if (instruction.compare("name") == 0) // Do
							m_name = value->data();

					}
					else									// Line is a level layout description
					{
						GameObject** raw = new GameObject*[lineData.size()];
						for (unsigned int i = 0; i < lineData.size(); i++)
						{
							switch (lineData.at(i))
							{
							case 'D':
								raw[i] = new Dirt();
								break;
							default:
								break;
							}
						}
						tempMap.push_back(raw);
						m_width = lineData.size();

						//delete[] test;
						std::cout << "\"" << lineData << "\" processed" << std::endl;
					}
				}
			}
		}
		createMapArray(tempMap);
		levelFile.close();
	}
	else std::cerr << "Unable to open file\n";
	// Loading the level
}

Level::~Level()
{
	//for (int i = 0; i < m_entities.size(); i++)
	//	delete[]
	for (unsigned int i = 0; i < m_height; i++)
	{
		delete[] m_map[i];
	}
	delete m_name;
}

const char* const Level::getName() const
{
	return m_name;
}

void Level::draw()
{
	for (unsigned int raw = 0; raw < m_height; raw++)
		for (unsigned int col = 0; col < m_width; col++)
		{
			//std::cout << m_map
			//GameObject* p = m_map[raw];
			(*(m_map[raw][col])).draw(Canvas::CanvasType::GAME);
		}
}

void Level::createMapArray(std::vector<GameObject**>& previous)
{
	m_height = previous.size();
	m_map = new GameObject**[m_height];
	
	for (unsigned int i = 0; i < m_height; i++)
	{
		m_map[i] = previous.at(i);
	}

	//std::copy(previous.begin(), previous.end(), m_map);
}