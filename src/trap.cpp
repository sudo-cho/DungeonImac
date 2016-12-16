#include "trap.hpp"

using namespace std;

enum Direction { N = 0, E = 1, S = 2, O = 3};

Trap::Trap(glm::vec2 pos, int dir, GLuint * tex, int dam) : MapObject (pos,dir,"trap"){
	position = pos;
	direction = dir;
	if (tex != NULL) texture = *tex;
	damage = dam;
}

Trap::~Trap(){

}