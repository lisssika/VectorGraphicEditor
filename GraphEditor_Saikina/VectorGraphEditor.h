#pragma once
#include <string>
#include <sstream>
#include "Reader.h"
#include "VectorFigure.h"
#include "GraphCommand.h"
#include "Scene.h"

void pars_command_line(std::stringstream& command_line, std::string& command, std::string& figure_name);

class VectorGraphEditor {
public:
	VectorGraphEditor(
		std::string const& scene_inp_file_name_,
		std::string const& scene_out_file_name_,
		std::string const& commands_file_name_
	);
	void execute();

	~VectorGraphEditor();

private:
	std::string scene_inp_file_name, scene_out_file_name, commands_file_name;
	Scene scene;
	std::vector<IGraphCommand*> history;

	void addAndExecuteCommand(IGraphCommand* cmd);
	void undo();
};