#pragma once
#include <vector>
#include "Entity.h"

class Level
{
public:
	Level();
	~Level();
	const char* const getName() const;
	void draw();

private:
	void createMapArray(std::vector<GameObject**>&);

private:
	const char* m_name;
	std::size_t m_width;
	std::size_t m_height;
	GameObject*** m_map; // A (m_height by m_width) matrix
    //std::vector<GameObject*> m_map;
	std::vector<Entity> m_entities;
};

