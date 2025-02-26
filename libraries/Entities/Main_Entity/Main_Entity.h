#pragma once 
#include "structs.h"
#include "Square_Entity.h"

class Main_Entity : public Square_Entity {
public:

	Main_Entity(const char name[256] = "Main Character") : Square_Entity(Entity_IDs::Main_Entity_ID, name, { 10, 10, 10 }, { 10, 10, 10 }, { 1, 0, 0, 0 }) {}

	Main_Entity(	const char name[256],
					square_dimensions square_size, 
					position_xyz entity_position, 
					quaternion_rotation entity_quaternion): 
					Square_Entity(Entity_IDs::Main_Entity_ID, name, square_size, entity_position, entity_quaternion) {}


	~Main_Entity() {}


private:
	bool alive;

	uint64_t death_count;
	
	uint64_t enimies_killed;

};