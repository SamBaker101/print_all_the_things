/*
Sam Baker
06/30/2022
Vector module intended to draw vectors between points along path
*/

#include "vector.hpp"

const Scalar_t Vector::get_start_x() const  { return start_x; }
const Scalar_t Vector::get_start_y() const  { return start_y; }
const Scalar_t Vector::get_end_x()   const  { return end_x; }
const Scalar_t Vector::get_end_y()   const  { return end_y; }
const Scalar_t Vector::get_len_x()   const  { return len_x; }
const Scalar_t Vector::get_len_y()   const  { return len_y; }


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

Vector operator+(const Vector v1, const Vector v2) {
	return Vector(v1.get_start_x(), v1.get_start_y(),
				  v1.get_end_x() + v2.get_len_x(), 
				  v1.get_end_y() + v2.get_len_y());
}

Vector operator-(const Vector v1, const Vector v2) {
	return Vector(v1.get_start_x(), v1.get_start_y(), 
				  v1.get_end_x() - v2.get_len_x(), 
				  v1.get_end_y() - v2.get_len_y());
}