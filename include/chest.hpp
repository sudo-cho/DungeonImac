#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <string>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include "mapobject.hpp"
#include "objectcollectable.hpp"


class Chest : public MapObject {
public:
	Chest(glm::vec2, int, GLuint*, ObjectCollectable);
	~Chest();
	glm::vec2 position;
	int direction;
	GLuint texture;
	ObjectCollectable content;
};