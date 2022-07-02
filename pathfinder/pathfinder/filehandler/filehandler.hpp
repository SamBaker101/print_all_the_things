//Sam Baker
//07/01/2022
//Module for reading and extracting data from files

#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../vector/vector.hpp"


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

		//Print function
		void print_file();

		//Create Point Array
		void create_array(int num_points, Vector *points);
};

		