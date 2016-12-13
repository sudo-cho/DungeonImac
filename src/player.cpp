#include "player.hpp"

Player::Player(glm::vec2 pos, int dir, int health, int gold, int potion, int weapon) : MapObject (pos,dir,"player")
{
	this->health = health;
	this->gold = gold;
	this->potion = potion;
	this->weapon = weapon;
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
