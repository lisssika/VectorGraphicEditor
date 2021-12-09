#include "Scene.h"
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include "VectorFigure.h"
#include <memory>

void Scene::add_figure(const std::string& name, const std::shared_ptr<IVectorFigure>& figure)
{
	scene_.insert(std::make_pair(name, figure));
}

std::shared_ptr<IVectorFigure> Scene::get_figure_by_name(std::string const& figure_name) {
	const auto vector_figure_it = scene_.find(figure_name);
	if (vector_figure_it != scene_.end()) {
		return vector_figure_it->second;
	}
	else return nullptr;
}

std::string Scene::to_string() const
{
	std::string str_scene;
	for (auto& figure : scene_)
	{
		str_scene+= figure.second->to_string();
	}
	return str_scene;
}

