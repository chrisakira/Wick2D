#include "vector_math.h"

force_vector vector_sum(force_vector vector_1, force_vector vector_2) {
	return vector_1;
}

force_vector vector_sub(force_vector vector_1, force_vector vector_2) {
	return vector_1;
}

force_vector vector_multi(force_vector vector_1, force_vector vector_2) {
	return vector_1;
}

quaternion_rotation angle_to_quaternion_2D(float angle) {
    return {cos(angle / 2), 0, 0, sin(angle / 2)};
}

force_vector calculate_resulting_force(force_vector f1, force_vector f2) {
    struct force_vector result;

    // Compute the components of each force
    position_xyz f1_components = {
        f1.vector.x * f1.intensity,
        f1.vector.y * f1.intensity,
        f1.vector.z * f1.intensity
    };

    position_xyz f2_components = {
        f2.vector.x * f2.intensity,
        f2.vector.y * f2.intensity,
        f2.vector.z * f2.intensity
    };

    // Add the components
    result.vector.x = f1_components.x + f2_components.x;
    result.vector.y = f1_components.y + f2_components.y;
    result.vector.z = f1_components.z + f2_components.z;

    // Calculate the magnitude of the resulting force
    result.intensity = sqrt(result.vector.x * result.vector.x +
                            result.vector.y * result.vector.y +
                            result.vector.z * result.vector.z);

    // Normalize the resulting direction vector
    double magnitude = sqrt(result.vector.x * result.vector.x +
                            result.vector.y * result.vector.y +
                            result.vector.z * result.vector.z);

    if (magnitude > 0) {
        result.vector.x /= magnitude;
        result.vector.y /= magnitude;
        result.vector.z /= magnitude;
    }
    return result;
}

position_xyz normalize(position_xyz vec) {
    double magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    if (magnitude == 0) return { 0, 0, 0 };
    return { vec.x / magnitude, vec.y / magnitude, vec.z / magnitude };
}