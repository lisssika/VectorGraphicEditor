#pragma once
#include <string>

#include "Scene.h"
#include "Commander.h"

void pars_command_line(std::stringstream& command_line, std::string& command, std::string& figure_name);

class VectorGraphEditor final
{
public:
	VectorGraphEditor(
		const std::string& scene_inp_file_name,
		const std::string& scene_out_file_name,
		const std::string& commands_file_name
	);
	void execute();

private:
	std::string scene_inp_file_name_, scene_out_file_name_, commands_file_name_;
	void fill_scene_from_file(std::string const& scene_file_name);
	Scene scene_;
	Commander commander_;
};
