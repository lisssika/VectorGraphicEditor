#pragma once
#include <map>
#include <string>
#include "VectorFigure.h"
class Scene final {
public:
	void make_scene_from_file(std::string const& scene_file_name);
	IVectorFigure* get_figure_by_name(std::string const& figure_name);
	friend std::ofstream& operator<< (std::ofstream& out, Scene const& scene);
	void print_scene_in_file(std::string const& file_out_name) const;
	~Scene();
private:
	std::map<std::string, IVectorFigure*> scene_;
};