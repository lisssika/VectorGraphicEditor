#include "pch.h"
#include "../VectorGraphicEditor/VectorGraphEditor.h"
TEST(TestCaseName, TestName) {
  VectorGraphEditor editor("scene_all_figures.txt", "result_scene.txt", "command_rotate.txt");
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
/*TEST(ThrowExcept, figure_type) {
	EXPECT_THROW(VectorGraphEditor editor("scene_exc_figure_type.txt", "exc.txt", "command_rotate.txt"), std::runtime_error);
}
*/