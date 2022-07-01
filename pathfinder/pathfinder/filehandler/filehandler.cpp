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
	std::string string;
	
	//This isn't working yet
	while (std::getline(file, string)) {
		++line_count;
	}

	
	return line_count;
}