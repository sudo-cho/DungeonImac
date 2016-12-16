#include <objectcollectable.hpp>

using namespace std;

ObjectCollectable::ObjectCollectable(){
}

ObjectCollectable::ObjectCollectable(int typeO, int a, std::string n){
	if(typeO == potion) type = "potion";
	else if(typeO == weapon) type = "weapon";
	else if(typeO == gold) type = "gold";
	typeObj = typeO;
	amount = a;
	name = n;
}

ObjectCollectable::~ObjectCollectable(){
}