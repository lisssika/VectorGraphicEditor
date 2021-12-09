#include "Scene.h"
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include "Reader.h"
#include "VectorFigure.h"
#include <sstream>
#include <memory>

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
			throw std::runtime_error("Invalid data format in the scene file");
		}
		std::string figure_name = figure_type + "[" + figure_id + "]";
		if (figure_type == rect_str) {
			std::vector<double> args = read_n_numbers(figure_line, 4);
			scene_.insert(std::pair<std::string, std::shared_ptr<IVectorFigure>>(figure_name, new Rect{ figure_name, {args[0], args[1]}, {args[2], args[3]} }));

		}
		else if (figure_type == line_str) {
			std::vector<double> args = read_n_numbers(figure_line, 4);
			scene_.insert(std::pair<std::string, std::shared_ptr<IVectorFigure>>(figure_name, new Line{ figure_name, {args[0], args[1]}, {args[2], args[3]} }));
		}
		else if (figure_type == ellipse_str) {
			std::vector<double> args = read_n_numbers(figure_line, 6);
			scene_.insert(std::pair<std::string, std::shared_ptr<IVectorFigure>>(figure_name, new Ellipse{ figure_name, {args[0], args[1]}, {args[2], args[3]}, {args[4], args[5]} }));
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

std::shared_ptr<IVectorFigure> Scene::get_figure_by_name(std::string const& figure_name) {
	const auto vector_figure_it = scene_.find(figure_name);
	if (vector_figure_it != scene_.end()) {
		return vector_figure_it->second;
	}
	else return nullptr;
}

void Scene::print_scene_in_file(std::ofstream& file) const
{
	for(auto& figure:scene_)
	{
		file << figure.second->to_string();
	}
}

