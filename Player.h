#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
  Player();
  ~Player();
  void update();
  void move(Direction direction);
  void resetMovingCooldown();

private:
  sf::Clock m_movingCooldown;
  sf::Time m_movingCooldownValue;
  int m_diamondsCollected;
  bool m_oneMoveAllowed;
  bool attemptMove(sf::Vector2i);
};