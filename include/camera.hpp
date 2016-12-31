#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <glimac/common.hpp>
#include "level.hpp"

enum directionCamera { NORD = 0, EST = 1, SUD = 2, OUEST = 3};

class Camera {
public: 
	Camera();
	Camera(glm::vec2, int);
	~Camera();
	void cameraMove(Level);
	
	glm::vec2 position;
	int direction;
};