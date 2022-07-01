/*
Sam Baker
06/30/2022
Vector module intended to draw vectors between points along path
*/

#include "vector.hpp"


void Vector::set_start(Scalar_t x, Scalar_t y) {
	start_x = x;
	start_y = y;
}

void Vector::set_end(Scalar_t x, Scalar_t y) {
	end_x = x;
	end_y = y;
}

void Vector::print_vector() {
	std::cout << "Start: (" << start_x << ',' << start_y << ") \n";
	std::cout << "End  : (" << end_x << ',' << end_y << ") \n";
	std::cout << "Len  : (" << len_x << ',' << len_y << ") \n";
}

Scalar_t Vector::get_length() {
	return sqrt(len_x * len_x + len_y * len_y);
}


Scalar_t Vector::get_angle() {
	return tan(len_y / len_x);
}
