#pragma once
#include "main.h"
#include "Entity.h"
#include <iostream>
#include <string>

class Player : public Entity
{
public:
  Player(sf::Vector2f position);
  ~Player();
  void move(Direction direction);
  void update();
  void draw();
  void resetMovingCooldown();

private:
  int m_movingCooldown = 0;
};