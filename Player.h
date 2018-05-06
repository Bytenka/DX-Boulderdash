#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
  Player(sf::Vector2f position);
  ~Player();
  void update();
  void move(Direction direction);
  void draw(Canvas::CanvasType);
  void resetMovingCooldown();

private:
  int m_movingCooldown = 0;
};