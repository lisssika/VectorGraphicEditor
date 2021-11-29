#include "Scene.h"
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include "Reader.h"
#include "VectorFigure.h"
#include <sstream>

Scene::~Scene() {
	for (auto& figure : scene_) {
		delete figure.second;
	}
}
void Scene::make_scene_from_file(std::string const& scene_file_name) {
	FileReader scene_file(scene_file_name);
	std::stringstream figure_line;
	const std::string rect_str("rect");
	const std::string line_str ("line");
	const std::string ellipse_str ("ellipse");

	while (scene_file.read_next_line(figure_line)) {
		std::string str;
		figure_line >> str;
		std::string figure_type;
		std::string figure_id;
		if (!read_figure_type_and_id(str, figure_type, figure_id)) {
			throw("Invalid data format in the scene file");
		}
		std::string figure_name = figure_type + "[" + figure_id + "]";
		if (figure_type == rect_str) {
			std::vector<double> args = read_n_numbers(figure_line, 4);
			scene_.insert(std::pair<std::string, IVectorFigure*>(figure_name, new Rect{ figure_name, {args[0], args[1]}, {args[2], args[3]} }));

		}
		else if (figure_type == line_str) {
			std::vector<double> args = read_n_numbers(figure_line, 4);
			scene_.insert(std::pair<std::string, IVectorFigure*>(figure_name, new Line{ figure_name, {args[0], args[1]}, {args[2], args[3]} }));
		}
		else if (figure_type == ellipse_str) {
			std::vector<double> args = read_n_numbers(figure_line, 6);
			scene_.insert(std::pair<std::string, IVectorFigure*>(figure_name, new Ellipse{ figure_name, {args[0], args[1]}, {args[2], args[3]}, {args[4], args[5]} }));
		}
		else
		{
			figure_line.str("");
			figure_line.clear();
			throw std::runtime_error("the unknown figure type");
		}
		figure_line.str("");
		figure_line.clear();
	}
}

IVectorFigure* Scene::get_figure_by_name(std::string const& figure_name) {
	auto vector_figure_it = scene_.find(figure_name);
	if (vector_figure_it != scene_.end()) {
		return vector_figure_it->second;
	}
	else return nullptr;
}

std::ofstream& operator<< (std::ofstream& out, Scene const& scene) {
	for (auto& figure : scene.scene_) {
		if (typeid(*figure.second).name() == typeid(Ellipse).name()) {
			out << *dynamic_cast<Ellipse*>(figure.second);
		}
		else
			if (typeid(*figure.second).name() == typeid(Line).name()) {
				out << *dynamic_cast<Line*>(figure.second);
			}
			else
				if (typeid(*figure.second).name() == typeid(Rect).name()) {
					out << *dynamic_cast<Rect*>(figure.second);
				}
	}
	return out;
}
void Scene::print_scene_in_file(std::string const& file_out_name) const
{
	std::ofstream file_output;
	file_output.open(file_out_name);
	file_output << *this;
}
