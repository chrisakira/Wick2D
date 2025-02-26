#pragma once

#include "extra_functions.h"

#include <cstdint>
#include <cstring>
#include <vector>

typedef struct {
	double x;
	double y;
	double z;
}position_xyz;

typedef struct {
	double a;
	double b;
	double c;
	double d;
}quaternion_rotation;

struct force_vector {
    position_xyz vector; // Direction of the force as a vector
    double intensity;    // Magnitude of the force
    bool active;
    uint64_t expirantion_timer;
    force_vector(position_xyz vector = {}, double intensity=0, bool active=false, uint64_t expirantion_timer=10) :vector(vector), intensity(intensity), active(active), expirantion_timer(expirantion_timer + get_unix_time_ms()) {}
    bool operator==(const force_vector& other) const {
        return (intensity == other.intensity) && (vector.x == other.vector.x) && (vector.y == other.vector.y) && (vector.z == other.vector.z);
    }
};

struct movement_vector {
    std::vector<force_vector*> applied_forces;  // Force being applied on the object
    force_vector resultant_force;               // Holder for the resultant force so that i don't need to recalculate every time
    bool recalculate_force;                     // Enables the recalculation of the resultant force
    position_xyz movement_vector;               // Unit vector of the current movement 
    double mass;                                // Mass of the entity     
    double acceleration;                        // Current acceleration  
    double speed;                               // Current speed 
    double speed_max;                           // Current max allowed speed 
    double speed_min;                           // Current minimun allowed speed
    double terrain_modifier;                    // Terrain modifier, changes how the resultant force is applied to the acceleration
    
    ~movement_vector() {
        for (auto force : applied_forces) {
            delete force; // Free memory
        }
        applied_forces.clear(); // Clear the vector
    }

    // Add force to list
    force_vector* add_force(const position_xyz& vector, double intensity, bool active, uint64_t expiration_timer);
    
    // Remove force from list
    bool remove_force(force_vector* vector);
};


typedef struct {
	double yaw;
	double roll;
	double pitch;
}euler_angles;

typedef struct {
	double width;
	double length;
	double height;
}square_dimensions;

typedef struct {
    uint64_t ID;
    char text[256];
} status_effects;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} happiness_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} sadness_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} fear_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} anger_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} surprise_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} disgust_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} contempt_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} love_emotion;

typedef struct {
    uint32_t max;
    uint32_t min;
    uint32_t current;
} shame_emotion;

typedef struct {
    happiness_emotion happiness;
    sadness_emotion sadness;
    fear_emotion fear;
    anger_emotion anger;
    surprise_emotion surprise;
    disgust_emotion disgust;
    contempt_emotion contempt;
    love_emotion love;
    shame_emotion shame;
} emotions_struct;

typedef struct {
    int64_t false_health;

    int64_t health_actual;
    int64_t health_max;
    float health_modifier;

    int64_t mana_actual;
    int64_t mana_max;
    float mana_modifier;

    int64_t stamina_actual;
    int64_t stamina_max;
    float stamina_modifier;

    emotions_struct emotions;

    std::vector<status_effects> status_list;
} status;

enum Entity_IDs {
    Unnamed_Entity_ID,
    Main_Entity_ID,

};