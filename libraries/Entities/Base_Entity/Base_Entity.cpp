#include "Base_Entity.h"



void Base_Entity::force_check()
{ 
    for (auto force : entity_movement.applied_forces) {
        if (force->expirantion_timer <= get_unix_time_ms()) {
            entity_movement.recalculate_force = true;
            force->active = false; 
            entity_movement.remove_force(force);
        }
    } 
}

void Base_Entity::update_force()
{
    if (entity_movement.recalculate_force == true) {
        entity_movement.recalculate_force = false;

        // calculate the resulting force
        entity_movement.resultant_force = {};
        for (auto force : entity_movement.applied_forces) {
            if (force == NULL)
                continue;

            if (force->active == true)
                entity_movement.resultant_force = calculate_resulting_force(entity_movement.resultant_force, *force);
            else
                entity_movement.remove_force(force);
        }
    }
}

void Base_Entity::update_movement()
{
     
    entity_movement.mass = 1;
    entity_movement.speed_max = 3;
    entity_movement.speed_min = 0;
    // Calculate the acceleration from the force applied
    entity_movement.acceleration = entity_movement.resultant_force.intensity / entity_movement.mass;

    // Calculate the new speed, ensuring it stays within the bounds
    entity_movement.speed += entity_movement.acceleration;
    if (entity_movement.speed > entity_movement.speed_max) entity_movement.speed = entity_movement.speed_max;
    if (entity_movement.speed < entity_movement.speed_min) entity_movement.speed = entity_movement.speed_min;

    // Update the movement direction by normalizing the applied force vector
    entity_movement.movement_vector = normalize(entity_movement.resultant_force.vector);

    // Scale the movement vector by the current speed
    entity_movement.movement_vector.x *= entity_movement.speed;
    entity_movement.movement_vector.y *= entity_movement.speed;
    entity_movement.movement_vector.z *= entity_movement.speed;

    this->entity_position.x += entity_movement.movement_vector.x;
    this->entity_position.y += entity_movement.movement_vector.y;
    this->entity_position.z += entity_movement.movement_vector.z;
}

void Base_Entity::update()
{
    this->force_check();
    this->update_force();
    this->update_movement();
}

const uint64_t Base_Entity::get_id() const {
    return this->ID;
}

void Base_Entity::set_id(uint64_t ID) {
    this->ID = ID;
}


const char* Base_Entity::get_name() const {
    return this->entity_name;
}


void Base_Entity::set_name(const char name[256]) {
    strncpy(this->entity_name, name, strlen(name) - 1);
    this->entity_name[sizeof(this->entity_name) - 1] = '\0';
}