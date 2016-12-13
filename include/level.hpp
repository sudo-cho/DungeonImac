#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <glm/glm.hpp>
#include <sstream>
#include <vector>

struct Case {
	glm::vec2 position;
	enum typeCase { empty = 0, path = 1, in = 2, out = 3};
};

struct PPMObject {
  std::string magicNum;
  int width, height, maxColVal;
  char * m_Ptr;
};

class Level {
public:
	Level(std::string);
	~Level();

private:
	Case begin;
	Case end;
	//Case[] map;
	//Monster[] monsters;
	//Chest[] chests;
	//Trap[] traps;
};