#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <glimac/common.hpp>

class Camera {
public: 
	Camera();
	Camera(glm::vec2);
	~Camera();
	
	glm::vec2 position;
	int direction;
};