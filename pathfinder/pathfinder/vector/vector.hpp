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

	Vector(Scalar_t start_x_i, Scalar_t start_y_i, Scalar_t end_x_i, Scalar_t end_y_i) {
		start_x = start_x_i;
		start_y = start_y_i;
		end_x = end_x_i;
		end_y = end_y_i;
		len_y = end_y - start_y;
		len_x = end_x - start_x;
	}

	const Scalar_t get_start_x() const;
	const Scalar_t get_start_y() const;
	const Scalar_t get_end_x() const;
	const Scalar_t get_end_y() const;
	const Scalar_t get_len_x() const;
	const Scalar_t get_len_y() const;


	void set_start(Scalar_t x, Scalar_t y);
	void set_end(Scalar_t x, Scalar_t y);
	void print_vector();
	Scalar_t get_length();
	Scalar_t get_angle();

};

//Operator Overloads for vector addition and subtraction
//Resulting vector will start at V1's starting point and add the len of v2 to its tip
Vector operator+(const Vector v1, const Vector v2);
Vector operator-(const Vector v1, const Vector v2);
