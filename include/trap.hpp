#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "mapobject.hpp"


class Trap : public MapObject {
public:
	Trap(glm::vec2, int, GLuint*,int);
	~Trap();
	glm::vec2 position;
	int direction;
	GLuint texture;
	int damage;
};