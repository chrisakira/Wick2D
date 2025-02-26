#pragma once
#include <cstdint>
#include <cstring>
#include <cmath>
#include "structs.h"

force_vector vector_sum(force_vector vector_1, force_vector vector_2);

force_vector vector_sub(force_vector vector_1, force_vector vector_2);

force_vector vector_multi(force_vector vector_1, force_vector vector_2);

quaternion_rotation angle_to_quaternion_2D(float angle);

force_vector calculate_resulting_force(force_vector f1, force_vector f2);

position_xyz normalize(position_xyz vec);