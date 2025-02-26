#include "structs.h"

force_vector* movement_vector::add_force(const position_xyz& vector, double intensity, bool active, uint64_t expiration_timer) {
    force_vector* tmp = new force_vector(vector, intensity, active, expiration_timer); 
    applied_forces.push_back(tmp);
    recalculate_force = true;
    return tmp;
}

bool movement_vector::remove_force(force_vector* vector) { 
    if (vector == NULL)
        return false;
    applied_forces.erase(std::remove(applied_forces.begin(), applied_forces.end(), vector),applied_forces.end());
    delete vector;
    
    return true;
}

