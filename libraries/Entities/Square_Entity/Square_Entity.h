#pragma once 
#include "structs.h"
#include "Base_Entity.h"

class Square_Entity : public Base_Entity {
public:

	Square_Entity(	uint64_t ID = Entity_IDs::Unnamed_Entity_ID, 
					const char name[256] = "Unnamed Square") : 
						Base_Entity(ID, name), 
						square_size({}) {}

	Square_Entity(	uint64_t ID, 
					const char name[256],
					square_dimensions square_size, 
					position_xyz entity_position, 
					quaternion_rotation entity_quaternion): 
						Base_Entity(ID, name, entity_position, entity_quaternion), 
						square_size(square_size) {}


	~Square_Entity() {}

	// Getters
	double get_width()  const { return this->square_size.width; }
	double get_height() const { return this->square_size.height; }
	double get_length() const { return this->square_size.length; }

	int32_t get_width_int()  const { return (int32_t)this->square_size.width; }
	int32_t get_height_int() const { return (int32_t)this->square_size.height; }
	int32_t get_length_int() const { return (int32_t)this->square_size.length; }

	// Setters
	void set_width(double width)   { this->square_size.width  = width;  }
	void set_height(double height) { this->square_size.height = height; }
	void set_length(double length) { this->square_size.length = length; }

	bool colliding(Square_Entity* entity_2);
	bool touching(Square_Entity* entity_2);

private:
	square_dimensions square_size = {};

};