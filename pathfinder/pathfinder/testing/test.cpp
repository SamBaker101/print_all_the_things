//Just tests

#include "test.hpp"

void vector_test_1() {
	Vector myVector(1, 2.6, 3.1, 4.5);
	Vector myVector2(3.1, 4.5);

	Vector myVector3 = myVector + myVector2;

	myVector3.print_vector();

	std::cout << myVector3.get_length();
}


void file_test_1() {
	PointFile FileTest(POINTFILE_PATH);

	FileTest.file_exists();
	const int length = FileTest.line_length();
	std::cout << "Line Count: " << length << "\n";
	FileTest.print_file();

	std::cout << " Creating Array \n";
	Vector* point_array = new Vector[length];

	FileTest.create_array(length, point_array);

	for (int i = 0; i < length; i++) {
		point_array[i].print_vector();
	}

	delete[] point_array;
}