#include "chest.hpp"

using namespace std;

enum Direction { N = 0, E = 1, S = 2, O = 3};

Chest::Chest(glm::vec2 pos, int dir, GLuint * tex, ObjectCollectable cont) : MapObject (pos,dir,"chest"){
	position = pos;
	direction = dir;
	if (tex != NULL) texture = *tex;
	content = cont;
}

Chest::~Chest(){
}