#pragma once
#include <map>
#include <string>
#include "VectorFigure.h"
class Scene {
public:
	void make_scene_from_file(std::string scene_file_name);
	IVectorFigure* get_figure_by_name(std::string figure_name);
	friend std::ofstream& operator<< (std::ofstream& out, Scene const& scene);
	void print_scene_in_file(std::string file_out_name);
	~Scene();
private:
	std::map<std::string, IVectorFigure*> scene;
};