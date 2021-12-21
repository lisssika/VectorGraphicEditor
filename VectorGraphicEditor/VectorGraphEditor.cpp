#include <string>
#include <memory>
#include <fstream>
#include <sstream>

#include "Reader.h"

#include "Scene.h"
#include "VectorGraphEditor.h"

#include "VectorFigure.h"
#include "Ellipse.h"
#include "Line.h"
#include "Rect.h"

#include "GraphCommand.h"
#include "RotateCommand.h"
#include "ScaleCommand.h"
#include "TranslateCommand.h"

std::string VectorGraphEditor::rect_str_{ "rect" };
std::string VectorGraphEditor::line_str_{ "line" };
std::string VectorGraphEditor::ellipse_str_{ "ellipse" };

void pars_command_line(std::stringstream& command_line, std::string& command, std::string& figure_name) {
	command_line >> command;
	command_line >> figure_name;
}

VectorGraphEditor::VectorGraphEditor(
	std::string const& scene_inp_file_name,
	std::string const& scene_out_file_name,
	std::string const& commands_file_name
) :scene_inp_file_name_(scene_inp_file_name), scene_out_file_name_(scene_out_file_name), commands_file_name_(commands_file_name) {}

void VectorGraphEditor::execute()
{
	fill_scene_from_file();
	read_and_exec_commands();
	print_scene_into_file();
}

void VectorGraphEditor::fill_scene_from_file()
{
	FileReader scene_file(scene_inp_file_name_);
	std::stringstream figure_line;

	while (scene_file.read_next_line(figure_line)) {
		std::string str;
		figure_line >> str;
		std::string figure_type;
		std::string figure_id;
		if (!read_figure_type_and_id(str, figure_type, figure_id)) {
			throw std::runtime_error("Invalid data format in the scene file");
		}
		std::string figure_name = figure_type + "[" + figure_id + "]";
		if (figure_type == rect_str_) {
			std::vector<double> args = read_n_numbers(figure_line, 4);
			std::shared_ptr<IVectorFigure> rect(
				new Rect{
					figure_name,
					{args[0], args[1]},
					{args[2], args[3]}
				}
			);
			scene_.add_figure(figure_name, rect);
		}
		else if (figure_type == line_str_) {
			std::vector<double> args = read_n_numbers(figure_line, 4);
			std::shared_ptr<IVectorFigure> line(
				new Line{
					figure_name,
					{args[0], args[1]},
					{args[2], args[3]}
				}
			);
			scene_.add_figure(figure_name, line);
		}
		else if (figure_type == ellipse_str_) {
			std::vector<double> args = read_n_numbers(figure_line, 6);
			std::shared_ptr <IVectorFigure > ellipse(
				new Ellipse{
					figure_name,
					{args[0], args[1]},
					{args[2], args[3]},
					{args[4], args[5]},
				}
			);
			scene_.add_figure(figure_name, ellipse);
		}
		else
		{
			figure_line.str("");
			figure_line.clear();
			throw std::runtime_error("the unknown figure type");
		}
		figure_line.str("");
		figure_line.clear();
	}
}

void VectorGraphEditor::read_and_exec_commands()
{
	std::stringstream command_line;
	FileReader command_reader(commands_file_name_);
	while (command_reader.read_next_line(command_line))
	{
		std::string command, figure_name;
		pars_command_line(command_line, command, figure_name);
		if (command == "undo") {
			commander_.undo();
		}
		else {
			std::shared_ptr<IVectorFigure> vector_figure = scene_.get_figure_by_name(figure_name);
			if (!vector_figure) {
				throw std::runtime_error("Figure with this name is not exist");
			}
			if (command == "translate") {
				std::vector<double> dxdy = read_n_numbers(command_line, 2);
				Vector2D translate_vec{ dxdy[0], dxdy[1] };
				std::unique_ptr<IGraphCommand> cmd = 
					std::make_unique<TranslateCommand>(vector_figure, translate_vec);
				commander_.add_and_execute_command(std::move(cmd));
			}
			else
				if (command == "scale") {
					std::vector<double> sxsy = read_n_numbers(command_line, 2);
					std::unique_ptr<IGraphCommand> cmd = std::make_unique<ScaleCommand>(vector_figure, sxsy[0], sxsy[1]);
					commander_.add_and_execute_command(std::move(cmd));
				}
				else
					if (command == "rotate") {
						std::vector<double> deg = read_n_numbers(command_line, 1);
						std::unique_ptr<IGraphCommand> cmd = std::make_unique < RotateCommand>(vector_figure, deg[0]);
						commander_.add_and_execute_command(std::move(cmd));
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
}

void VectorGraphEditor::print_scene_into_file() const
{
	std::ofstream file(scene_out_file_name_);
	if(file)
	{
		file << scene_.to_string();
		file.close();
	}
	else
	{
		throw std::runtime_error("output file for scene is not open");
	}
}
