//Sam Baker
//07/01/2022
//Module for reading and extracting data from files

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define MAX_BUFFER 50            //Maxed buffer len


class PointFile {
	private:
		std::fstream file;
		std::string path;

	public:
		//Constructor and Destructor
		PointFile(std::string path_i);
		~PointFile();
		

		//Get data from file
		void file_exists();
		int line_length();
};