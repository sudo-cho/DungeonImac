#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "MapObject.hpp"
#include "TypeMonster.hpp"


class Monster : public MapObject {
public:
	Monster(glm::vec2,int,GLuint*,TypeMonster);
	~Monster();
	glm::vec2 move ();
	int changeDirection(int);
	void modifyHealth(int);
	int die();
	int attack();
	glm::vec2 getPos();
	int getDir();

private:
	TypeMonster * type;
	GLuint texture;
};
