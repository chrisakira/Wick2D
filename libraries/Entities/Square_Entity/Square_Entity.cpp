#include "Square_Entity.h"




bool Square_Entity::colliding(Square_Entity* entity_2) {
	return  (this->get_x() < entity_2->get_x() + entity_2->get_length() && this->get_x() + this->get_length() > entity_2->get_x()) &&
		(this->get_y() < entity_2->get_y() + entity_2->get_height() && this->get_y() + this->get_height() > entity_2->get_y()) &&
		(this->get_z() < entity_2->get_z() + entity_2->get_width() && this->get_z() + this->get_width() > entity_2->get_z());
}

bool Square_Entity::touching(Square_Entity* entity_2) { 
	return  (this->get_x() <= (entity_2->get_x() + entity_2->get_length()) && (this->get_x() + this->get_length()) >= entity_2->get_x()) &&
			(this->get_y() <= (entity_2->get_y() + entity_2->get_height()) && (this->get_y() + this->get_height()) >= entity_2->get_y()) &&
			(this->get_z() <= (entity_2->get_z() + entity_2->get_width())  && (this->get_z() + this->get_width())  >= entity_2->get_z());
}