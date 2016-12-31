#include "camera.hpp"

Camera::Camera(){
}

Camera::~Camera(){
}

Camera::Camera(glm::vec2 pos, int dir){
	position = pos;
	direction = dir;
}

void Camera::cameraMove(Level level){
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	
	if (state[SDL_SCANCODE_UP]){
		if (direction == NORD){
			if (level.getCaseFromPos(glm::vec2(position.x, position.y -1)).type == 1) position.y -= 1;
		}
		else if (direction == EST) {
			if (level.getCaseFromPos(glm::vec2(position.x +1, position.y)).type == 1) position.x += 1;
		}
		else if (direction == SUD) {
			if (level.getCaseFromPos(glm::vec2(position.x, position.y +1)).type == 1) position.y += 1;
		}
		else if (direction == OUEST) {
			if (level.getCaseFromPos(glm::vec2(position.x -1, position.y)).type == 1) position.x -= 1;
		}
		SDL_Delay(200);
	}
	else if (state[SDL_SCANCODE_DOWN]){
		if (direction == NORD){
			if (level.getCaseFromPos(glm::vec2(position.x, position.y +1)).type == 1) position.y += 1;
		}
		else if (direction == EST) {
			if (level.getCaseFromPos(glm::vec2(position.x -1, position.y)).type == 1) position.x -= 1;
		}
		else if (direction == SUD) {
			if (level.getCaseFromPos(glm::vec2(position.x, position.y -1)).type == 1) position.y -= 1;
		}
		else if (direction == OUEST) {
			if (level.getCaseFromPos(glm::vec2(position.x +1, position.y)).type == 1) position.x += 1;
		}
		SDL_Delay(200);
	}
	else if (state[SDL_SCANCODE_LEFT]){
		if (direction == NORD){
			if (level.getCaseFromPos(glm::vec2(position.x -1, position.y)).type == 1) position.x -= 1;
		}
		else if (direction == EST) {
			if (level.getCaseFromPos(glm::vec2(position.x, position.y -1)).type == 1) position.y -= 1;
		}
		else if (direction == SUD) {
			if (level.getCaseFromPos(glm::vec2(position.x +1, position.y)).type == 1) position.x += 1;
		}
		else if (direction == OUEST) {
			if (level.getCaseFromPos(glm::vec2(position.x, position.y +1)).type == 1) position.y += 1;
		}
		SDL_Delay(200);
	}
	else if (state[SDL_SCANCODE_RIGHT]){
		if (direction == NORD){
			if (level.getCaseFromPos(glm::vec2(position.x +1, position.y)).type == 1) position.x += 1;
		}
		else if (direction == EST) {
			if (level.getCaseFromPos(glm::vec2(position.x, position.y +1)).type == 1) position.y += 1;
		}
		else if (direction == SUD) {
			if (level.getCaseFromPos(glm::vec2(position.x -1, position.y)).type == 1) position.x -= 1;
		}
		else if (direction == OUEST) {
			if (level.getCaseFromPos(glm::vec2(position.x, position.y -1)).type == 1) position.y -= 1;
		}
		SDL_Delay(200);
	}
	// CLAVIER TOUCHE A
	else if (state[SDL_SCANCODE_Q]){
		if (direction == 0) direction = 3;
		else direction--;
		SDL_Delay(200);
	}
	// CLAVIER TOUCHE E
	else if (state[SDL_SCANCODE_E]){
		if (direction == 3) direction = 0;
		else direction++;
		SDL_Delay(200);
	}
}