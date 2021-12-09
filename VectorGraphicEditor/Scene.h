#pragma once
#include <map>
#include <string>
#include <memory>
#include <fstream>
#include "VectorFigure.h"
class Scene final {
public:
	void add_figure(const std::string& name, std::shared_ptr<IVectorFigure> figure);
	std::shared_ptr<IVectorFigure> get_figure_by_name(std::string const& figure_name);
	std::string to_string() const;
private:
	std::map<std::string, std::shared_ptr<IVectorFigure>> scene_;
};