#pragma once 
#include <mutex>
#include "structs.h"
#include "vector_math.h"
#include "extra_functions.h"


class Base_Entity {
public:
	Base_Entity(uint64_t ID = Entity_IDs::Unnamed_Entity_ID, const char name[256] = "Unnamed Entity") :ID(ID) {
		strncpy(this->entity_name, name, strlen(name) - 1);
		this->entity_name[sizeof(this->entity_name) - 1] = '\0';
	}

	Base_Entity(uint64_t ID, 
				const char name[256], 
				position_xyz entity_position, 
				quaternion_rotation entity_quaternion) :
				ID(ID), 
				entity_position(entity_position), 
				entity_quaternion(entity_quaternion) 
	{
		strncpy(this->entity_name, name, strlen(name) - 1);
		this->entity_name[sizeof(this->entity_name) - 1] = '\0';
	}

	~Base_Entity() {}

	const uint64_t get_id() const;
	void set_id(uint64_t ID);

	const char* get_name() const;
	void set_name(const char name[256]);


	// Getters
	double get_x() const { return this->entity_position.x; }
	double get_y() const { return this->entity_position.y; }
	double get_z() const { return this->entity_position.z; }

	int32_t get_x_int() const { return (int32_t)this->entity_position.x; }
	int32_t get_y_int() const { return (int32_t)this->entity_position.y; }
	int32_t get_z_int() const { return (int32_t)this->entity_position.z; }

	// Setters
	void set_x(double x) { this->entity_position.x = x; }
	void set_y(double y) { this->entity_position.y = y; }
	void set_z(double z) { this->entity_position.z = z; }
	void set_xyz(double x, double y, double z) { this->entity_position.x = x; this->entity_position.y = y; this->entity_position.z = z; }

	status* get_status_ptr() { return &this->entity_status; }
	status  get_status()     { return  this->entity_status; }

	void update();
	void update_movement();
	void update_force();
	void force_check();

	// Movement vector struct
	movement_vector entity_movement;
private:
    // Entity ID
	uint64_t ID = 0;
	

	// Entity name 
	char entity_name[256] = {};

	// Entity base status 
	status entity_status = {};

	// Entity position in space
	position_xyz entity_position = {};

	// Quaternion Orientation
	quaternion_rotation entity_quaternion = {};

};