#pragma once

#include <iostream>
#include <glm/glm/glm.hpp>
#include <string>


class TypeMonster {
public:
	TypeMonster(std::string,int,int,int);
	std::string type;
	int health;
	int gold;
	int force;
	
};