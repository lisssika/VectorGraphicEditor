#include "VectorGraphEditor.h"
#include <iostream>
int main() {
	{
		VectorGraphEditor editor("scene_all_figures.txt", "result_scene_rotate.txt", "command_rotate.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what();
		}
	}
	{
		VectorGraphEditor editor("scene_all_figures.txt", "result_scene_scale.txt", "command_scale.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what();
		}
	}
	{
		VectorGraphEditor editor("scene_all_figures.txt", "result_scene_translate.txt", "command_translate.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what();
		}
	}
	{
		VectorGraphEditor editor("scene_all_figures.txt", "result_scene_undo.txt", "command_undo.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what();
		}
	}

	//exception
	{
		VectorGraphEditor editor("scene_exc_figure_type.txt", "result_scene_undo.txt", "command_undo.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what()<<'\n';
		}
	}
	{
		VectorGraphEditor editor("scene_exc_number_arg_ellipse.txt", "result_scene.txt", "command_undo.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what() << '\n';
		}
	}
	{
		VectorGraphEditor editor("scene_exc_number_arg_line.txt", "result_scene.txt", "command_undo.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what() << '\n';
		}
	}
	{
		VectorGraphEditor editor("scene_exc_number_arg_rect.txt", "result_scene.txt", "command_undo.txt");
		try {
			editor.execute();
		}
		catch (std::runtime_error error) {
			std::cout << error.what() << '\n';
		}
	}

	return 0;
}