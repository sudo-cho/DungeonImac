#include "player.hpp"

Player::Player(int health, int gold, int potion, int weapon) :
  health(health),
  gold(gold),
  potion(potion),
  weapon(weapon)
{
  id++;
}

void Player::decreaseHealth(int val){
  this->health -= val;
}

void Player::damageTake(Player *player){
  decreaseHealth(player->getPotion());
}

int Player::getHealth(){
  return this->health;
}

int Player::getGold(){
  return this->gold;
}

int Player::getPotion(){
  return this->potion;
}

int Player::getWeapon(){
  return this->weapon;
  }
