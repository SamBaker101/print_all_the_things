/*
Sam Baker
06/27/2022
Pathfinder application for use with 3D printer salvage project - to be used with 2D drawing prototype
When complete application will take in image file showing path to be cutout and return a set of vectors 
to guide the print head around the path
*/


#include "pathfinder.hpp"



//At this time this is primarily just a test function for modules
int main() {
	using std::cout;

	cout << "Hello World \n";
	vector_test_1();
	file_test_1();
	
	return getchar();;
}