#include "Reader.h"
#include <string>
#include <sstream>
#include <stdexcept>
#include <fstream>
#include "VectorFigure.h"
#include <vector>


FileReader::FileReader(std::string const& file_name) {
	my_file.open(file_name);
	if (!my_file.is_open()) {
		throw std::runtime_error("file opening error");
	}
}
FileReader:: ~FileReader() {
	my_file.close();
}

bool FileReader::read_next_line(std::stringstream& line) {
	std::string str;
	if (std::getline(my_file, str)) {
		line.str(str);
		return true;
	}
	return false;
}

bool read_figure_type_and_id(std::string const& str, std::string& figure_type, std::string& figure_id) {
	auto iter_left_bracket = str.find('[');
	if (iter_left_bracket != std::string::npos) {
		figure_type = str.substr(0, iter_left_bracket);
		auto iter_right_bracket = str.find(']', iter_left_bracket);
		if (iter_right_bracket != std::string::npos) {
			figure_id = str.substr(iter_left_bracket + 1, iter_right_bracket - iter_left_bracket - 1);
			return true;
		}
	}
	return false;
}

std::vector<double> read_n_numbers(std::stringstream& str, size_t n) {
	std::vector<double> numbers;
	for (size_t i = 0; i < n; i++) {
		double x;
		str >> x;
		if (str.fail())
		{
			throw std::runtime_error("Not enough numbers");
		}
		else {
			numbers.push_back(x);
		}
	}

	return numbers;
}
