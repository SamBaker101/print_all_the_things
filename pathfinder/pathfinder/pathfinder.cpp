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
	
	Vector myVector(1, 2.6, 3.1, 4.5);
	Vector myVector2(3.1, 4.5);
	
	Vector myVector3 = myVector + myVector2;
	
	myVector3.print_vector();

	cout << myVector3.get_length();
	

	PointFile FileTest(POINTFILE_PATH);

	FileTest.file_exists();
	const int length = FileTest.line_length();
	cout << "Line Count: " << length << "\n";
	FileTest.print_file();

	cout << " Creating Array \n";
	Vector *point_array = new Vector[length];

	FileTest.create_array(length, point_array);

	for (int i = 0; i < length; i++) {
		point_array[i].print_vector();
	}

	delete point_array;
	return getchar();;
}