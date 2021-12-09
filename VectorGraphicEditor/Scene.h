#pragma once
#include <map>
#include <string>
#include <memory>
#include <fstream>
#include "VectorFigure.h"
class Scene final {
public:
	void make_scene_from_file(std::string const& scene_file_name);
	std::shared_ptr<IVectorFigure> get_figure_by_name(std::string const& figure_name);
	void print_scene_in_file(std::ofstream& file) const;
private:
	std::map<std::string, std::shared_ptr<IVectorFigure>> scene_;
};