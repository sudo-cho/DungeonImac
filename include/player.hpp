#pragma once

#include "mapobject.hpp"

class Player : public MapObject{
private:
  int health;
  int gold;
  int potion;
  int weapon;
public:
  Player(glm::vec2 pos, int dir, int health, int gold, int potion, int weapon);

  /* getters */
  int getHealth();
  int getGold();
  int getPotion();
  int getWeapon();

  void decreaseHealth(int val);
  void damageTake(Player *player);
};
