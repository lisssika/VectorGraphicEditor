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
	void fill_scene_from_file();
	void read_and_exec_commands();
	void print_scene_into_file() const;
	Scene scene_;
	Commander commander_;

	static std::string rect_str_;
	static std::string line_str_;
	static std::string ellipse_str_;
};
