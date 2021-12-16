#pragma once
#include <string>
#include <stdexcept>
#include <fstream>
#include "VectorFigure.h"
#include <vector>

class FileReader final{
public:
	FileReader(std::string const& file_name);
	bool read_next_line(std::stringstream& line);
private:
	std::ifstream my_file;
	std::string str;
};

std::vector<double> read_n_numbers(std::stringstream& str, size_t n);
bool read_figure_type_and_id(std::string const& str, std::string& figure_type, std::string& figure_id);