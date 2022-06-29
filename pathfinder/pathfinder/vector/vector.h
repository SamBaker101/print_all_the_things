#pragma once

class Vector {
	private:
		float start_y;
		float start_x;
		float end_y;
		float end_x;

	public:
		Vector() {
			start_x = -1;
			start_y = -1;
			end_y = -1;
			end_x = -1;
		}

		Vector(float start_a, float start_b, float end_a, float end_b) {
			start_x = start_a;
			start_y = start_b;
			end_y = end_a;
			end_x = end_b;
		}

		float get_length() {
			return sqrt((end_x - start_x) * (end_x - start_x) + (end_y - start_y) * (end_y - start_y));
		}
};