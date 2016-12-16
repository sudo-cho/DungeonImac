#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

enum typeObjectCollectable {potion = 0, weapon = 1, gold = 2};

class ObjectCollectable {
public:
	ObjectCollectable();
	ObjectCollectable(int,int,std::string);
	~ObjectCollectable();
	std::string type;
	int typeObj;
	int amount;
	std::string name;
};