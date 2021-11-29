#pragma once
#include <string>
#include <memory>
#include <utility>
#include <sstream>
#include "Reader.h"
#include "VectorFigure.h"
#include "GraphCommand.h"
#include "Scene.h"
#include "VectorGraphEditor.h"

void pars_command_line(std::stringstream& command_line, std::string& command, std::string& figure_name) {
	command_line >> command;
	command_line >> figure_name;
}

VectorGraphEditor::VectorGraphEditor(
	std::string const& scene_inp_file_name_,
	std::string const& scene_out_file_name_,
	std::string const& commands_file_name_
) :scene_inp_file_name(scene_inp_file_name_), scene_out_file_name(scene_out_file_name_), commands_file_name(commands_file_name_) {}

void VectorGraphEditor::execute() {
	scene.make_scene_from_file(scene_inp_file_name);
	std::stringstream command_line;
	FileReader command_reader(commands_file_name);
	while (command_reader.read_next_line(command_line))
	{
		std::string command, figure_name;
		pars_command_line(command_line, command, figure_name);
		if (command == "undo") {
			undo();
		}
		else {
			IVectorFigure* vector_figure = scene.get_figure_by_name(figure_name);
			if (vector_figure == nullptr) {
				throw std::runtime_error("Figure with this name is not exist");
			}
			if (command == "translate") {
				std::vector<double> dxdy = read_n_numbers(command_line, 2);
				IGraphCommand* cmd = new TranslateCommand(vector_figure, { dxdy[0], dxdy[1] });
				addAndExecuteCommand(cmd);
			}
			else
				if (command == "scale") {
					std::vector<double> sxsy = read_n_numbers(command_line, 2);
					IGraphCommand* cmd = new ScaleCommand(vector_figure, sxsy[0], sxsy[1]);
					addAndExecuteCommand(cmd);
				}
				else
					if (command == "rotate") {
						std::vector<double> deg = read_n_numbers(command_line, 1);
						IGraphCommand* cmd = new RotateCommand(vector_figure, deg[0]);
						addAndExecuteCommand(cmd);
					}
					else {
						command_line.str("");
						command_line.clear();
						throw std::runtime_error("This command is not exist");
					}
		}
		command_line.str("");
		command_line.clear();
	}
	scene.print_scene_in_file(scene_out_file_name);
}

VectorGraphEditor::~VectorGraphEditor() {
	for (auto& command : history) {
		delete command;
	}
}

void VectorGraphEditor::addAndExecuteCommand(IGraphCommand* cmd) {
	history.push_back(cmd);
	cmd->redo();
}
void VectorGraphEditor::undo() {
	if (history.empty()) return;
	auto cmd = history.back();
	cmd->undo();
	delete cmd;
	history.pop_back();
}
