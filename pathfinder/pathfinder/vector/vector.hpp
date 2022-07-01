/*
Sam Baker
06/30/2022
Vector module intended to draw vectors between points along path
*/


#pragma once

#include <cmath>
#include <iostream>

typedef double Scalar_t;

class Vector {
private:
	Scalar_t start_y;
	Scalar_t start_x;
	Scalar_t end_y;
	Scalar_t end_x;
	Scalar_t len_y;
	Scalar_t len_x;

public:
	Vector() {
		start_x = -1;
		start_y = -1;
		end_y = -1;
		end_x = -1;
		len_y = -1;
		len_x = -1;
	}

	Vector(Scalar_t start_a, Scalar_t start_b, Scalar_t end_a, Scalar_t end_b) {
		start_x = start_a;
		start_y = start_b;
		end_x = end_a;
		end_y = end_b;
		len_y = end_y - start_y;
		len_x = end_x - start_x;
	}

	void set_start(Scalar_t x, Scalar_t y);
	void set_end(Scalar_t x, Scalar_t y);
	void print_vector();
	Scalar_t get_length();
	Scalar_t get_angle();
};
