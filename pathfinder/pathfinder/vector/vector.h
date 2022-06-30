#pragma once

#include <cmath>

class Vector {
	private:
		float start_y;
		float start_x;
		float end_y;
		float end_x;
		float len_y;
		float len_x;


	public:
		Vector() {
			start_x = -1;
			start_y = -1;
			end_y = -1;
			end_x = -1;
			len_y = -1;
			len_x = -1;
		}

		Vector(float start_a, float start_b, float end_a, float end_b) {
			start_x = start_a;
			start_y = start_b;
			end_y = end_a;
			end_x = end_b;
			len_y = end_y - start_y;
			len_x = end_x - start_x;
		}

		void set_start(float x, float y) {
			start_x = x;
			start_y = y;
		}

		void set_end(float x, float y) {
			end_x = x;
			end_y = y;
		}

		float get_length() {
			return sqrt(len_x * len_x + len_y * len_y);
		}


		float get_angle() {
			return tan(len_y / len_x);
		}


};