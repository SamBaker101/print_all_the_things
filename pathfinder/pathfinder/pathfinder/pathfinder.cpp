/*
Sam Baker
06/27/2022
Pathfinder application for use with 3D printer salvage project - to be used with 2D drawing prototype
When complete application will take in image file showing path to be cutout and return a set of vectors 
to guide the print head around the path
*/


#include "pathfinder.h"

int main() {
	std::cout << "Hello World \n";

	Vector myVector(1.2, 2.6, 3.1, 4.5);

	std::cout << myVector.get_length();
	
	return getchar();;
}