#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "monster.hpp"
#include "case.hpp"

enum typeMapObject {chest = 1, monster = 2, trap = 3, lever = 4};

class Level {
public:
	Level(std::string);
	~Level();
	void printLevelTest();
	void readImageFile(std::string);
	void createObjectFromLine(int,std::string);
	int width;
	int height;
	int nbChests;
	int nbMonsters;
	Case begin;
	Case end;
	std::vector<Case> map;
	std::vector<Monster> monsters;
	//Chest[] chests;
	//Trap[] traps;
};