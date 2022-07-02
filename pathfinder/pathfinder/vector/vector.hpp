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
	//Overloaded constructors
	Vector();
	Vector(Scalar_t x, Scalar_t y);
	Vector(Scalar_t start_x_i, Scalar_t start_y_i, Scalar_t end_x_i, Scalar_t end_y_i);
	
	
	
	//Setter functions, len will be automatically modified when called
	void set_start(Scalar_t x, Scalar_t y);
	void set_end(Scalar_t x, Scalar_t y);

	void move_tail();
	void move_tail(Scalar_t x, Scalar_t y);

	//Simple getter functions
	const Scalar_t get_start_x() const;
	const Scalar_t get_start_y() const;
	const Scalar_t get_end_x() const;
	const Scalar_t get_end_y() const;
	const Scalar_t get_len_x() const;
	const Scalar_t get_len_y() const;
	
	//Getters requiring computations
	Scalar_t get_length();
	Scalar_t get_angle();

	//Prints Vector details (primarily for debugging
	void print_vector();
};

//Operator Overloads for vector addition and subtraction
//Resulting vector will start at V1's starting point and add the len of v2 to its tip
Vector operator+(const Vector v1, const Vector v2);
Vector operator-(const Vector v1, const Vector v2);
