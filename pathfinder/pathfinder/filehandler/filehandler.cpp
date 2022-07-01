//Sam Baker
//07/01/2022
//Module for reading and extracting data from files

#include "filehandler.hpp"


//Constructor and Destructor
PointFile::PointFile(std::string path_i) {
	path = path_i;
	file.open(path);
	if (file.fail())
		std::cout << "Error Opening File \n";
}


PointFile::~PointFile() {
	file.close();
}


void PointFile::file_exists() {
	if (file.fail())
		std::cout << "This File Doesn't Exist \n";
	else if (!(file.fail()))
		std::cout << "File Exists \n";
}

int PointFile::line_length() {
	int line_count = 0;
	std::string string_buffer;
	
	std::ifstream ifs(path);

	//This isn't working yet
	while (!ifs.eof()) {
	std::getline(ifs, string_buffer);
		++line_count;
	}
	
	return line_count;
}


void PointFile::print_file() {
	std::string string_buffer;
	std::ifstream ifs(path);

	//This isn't working yet
	while (!ifs.eof()) {
		std::getline(ifs, string_buffer);
		std::cout << string_buffer << "\n";
	}
}