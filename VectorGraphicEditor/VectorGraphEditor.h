#pragma once
#include <string>
#include <sstream>
#include "Reader.h"
#include "VectorFigure.h"
#include "GraphCommand.h"
#include "Scene.h"

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

	~VectorGraphEditor();

private:
	std::string scene_inp_file_name_, scene_out_file_name_, commands_file_name_;
	Scene scene_;
	std::vector<IGraphCommand*> history_;

	void add_and_execute_command(IGraphCommand* cmd);
	void undo();
};
