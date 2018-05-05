#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
  Player(sf::Vector2f position);
  ~Player();
  void move(Direction direction);
  void update();
  void draw(Canvas::CanvasType);
  void resetMovingCooldown();

private:
  int m_movingCooldown = 0;
};