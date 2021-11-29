#include "pch.h"
#include "../VectorGraphicEditor/VectorGraphEditor.h"
#include <string>
#include <fstream>

TEST(Command, Rotate) {
	//Vector2D a;
	VectorGraphEditor editor("scene_all_figures.txt", "result_scene.txt", "command_rotate.txt");
	std::string str;
	std::ifstream file;
	file.open("result_scene.txt");
	std::getline(file, str);
	EXPECT_EQ(str, std::string("ellipse[e3] 0 0 0 4 7 0"));
	std::getline(file, str);
	EXPECT_EQ(str, std::string("line[7] 5 9 5 19"));
	std::getline(file, str);
	EXPECT_EQ(str, std::string("rect[34] -5 -3 5 3"));
}
/*TEST(ThrowExcept, figure_type) {
	EXPECT_THROW(VectorGraphEditor editor("scene_exc_figure_type.txt", "exc.txt", "command_rotate.txt"), std::runtime_error);
}
*/