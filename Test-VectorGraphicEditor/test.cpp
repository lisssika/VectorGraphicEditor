#include "pch.h"
#include <string>
#include <memory>

#include "../VectorGraphicEditor/DoubleIsEqual.h"
#include "../VectorGraphicEditor/Vector2D.h"

#include "../VectorGraphicEditor/Ellipse.h"
#include "../VectorGraphicEditor/Line.h"
#include "../VectorGraphicEditor/Rect.h"

#include "../VectorGraphicEditor/Scene.h"

#include "../VectorGraphicEditor/RotateCommand.h"
#include "../VectorGraphicEditor/ScaleCommand.h"
#include "../VectorGraphicEditor/TranslateCommand.h"
#include "../VectorGraphicEditor/Commander.h"

//----------------------------------------------------------Vector2D
class VectorUyilities:public  ::testing::Test
{
public:
	Vector2D v;
	Vector2D u = {3.5, 4.5};
	Vector2D w = {10, -1.5};
};
class VectorTest: public VectorUyilities{};

TEST_F(VectorTest, constructor)
{
	EXPECT_EQ(v, Vector2D(0, 0));
	EXPECT_EQ(u, Vector2D(3.5, 4.5));
}
TEST_F(VectorTest, get)
{
	EXPECT_EQ(v.get_x(), 0);
	EXPECT_EQ(v.get_y(), 0);
	EXPECT_EQ(u.get_x(), 3.5);
	EXPECT_EQ(u.get_y(), 4.5);
}
TEST_F(VectorTest, scale)
{
	u.scale(3, 2);
	EXPECT_EQ(u, Vector2D(10.5, 9.));
}
TEST_F(VectorTest, rot)
{
	u.rot(180);
	EXPECT_EQ(u.to_string(), std::string("-3.5 -4.5"));
}
TEST_F(VectorTest, operator_mult)
{
	u = u * 2;
	EXPECT_EQ(u, Vector2D(7., 9.));

}
TEST_F(VectorTest, operator_plus)
{
	u = u + w;
	EXPECT_EQ(u, Vector2D( 13.5, 3. ));
}

TEST_F(VectorTest, operator_minus)
{
	u = u - w;
	EXPECT_EQ(u, Vector2D(-6.5, 6.));
}
//----------------------------------------------------------VectorFigures
class EllipseTest:public ::testing::Test
{
protected:
	Ellipse ellipse = Ellipse("f1", Vector2D{ 1., 1. }, Vector2D{ 3., 1. }, Vector2D{ 1., 21. });

};

TEST_F(EllipseTest, constructor) {
	EXPECT_EQ(ellipse.to_string(), std::string("f1 1. 1. 3. 1. 1. 21."));
}
TEST_F(EllipseTest, rotate) {
	ellipse.rotate(90);
	EXPECT_EQ(ellipse.to_string(), std::string("f1 1. 1. 1. 3. -19. 1."));
}

TEST_F(EllipseTest, translate) {
	ellipse.translate({10, -1});
	EXPECT_EQ(ellipse.to_string(), std::string("f1 11. 0. 13. 0. 11. 20."));
}

TEST_F(EllipseTest, scale) {
	ellipse.scale( 10, -1 );
	EXPECT_EQ(ellipse.to_string(), std::string("f1 1. 1. 21. 1. 1. -19."));
}



class LineTest :public ::testing::Test
{
protected:
	Line line = Line("f1", Vector2D{ 5., 9. }, Vector2D{ 5., 19. });
};

TEST_F(LineTest, constructor) {

	EXPECT_EQ(line.to_string(), std::string("f1 5. 9. 5. 19."));
}

TEST_F(LineTest, rotate) {
	line.rotate(90);
	EXPECT_EQ(line.to_string(), std::string("f1 0. 14. 10. 14."));
}

TEST_F(LineTest, translate) {
	line.translate({ 10, -1 });
	EXPECT_EQ(line.to_string(), std::string("f1 15. 8. 15. 18."));
}

TEST_F(LineTest, scale) {
	line.scale(10, -2);
	EXPECT_EQ(line.to_string(), std::string("f1 5. 24. 5. 4."));
}

class RectTest :public ::testing::Test
{
protected:
	Rect rect = Rect("f1", Vector2D{ 5., 9. }, Vector2D{ 5., 19. });
};

TEST_F(RectTest, constructor) {

	EXPECT_EQ(rect.to_string(), std::string("f1 5. 9. 5. 19."));
}

TEST_F(RectTest, rotate) {
	rect.rotate(90);
	EXPECT_EQ(rect.to_string(), std::string("f1 0. 14. 10. 14."));
}

TEST_F(RectTest, translate) {
	rect.translate({ 10, -1 });
	EXPECT_EQ(rect.to_string(), std::string("f1 15. 8. 15. 18."));
}

TEST_F(RectTest, scale) {
	rect.scale(10, -2);
	EXPECT_EQ(rect.to_string(), std::string("f1 5. 24. 5. 4."));
}
//----------------------------------------------------------Scene
class SceneUtilities :public  ::testing::Test
{
public:
	Scene scene;
	std::shared_ptr<IVectorFigure>rect;
	void SetUp() override
	{
		rect = std::make_shared<Rect>(
			Rect{
				"rect[r1]",
				{ 3, 4 },
				{ 5, 6 }
			}
		);
		scene.add_figure("rect[r1]", rect);
	}
};
class SceneTest:public SceneUtilities{};
TEST_F(SceneTest, add)
{
	EXPECT_EQ(rect.get(), scene.get_figure_by_name("rect[r1]").get());
}
TEST_F(SceneTest, to_string)
{
	EXPECT_EQ(scene.to_string(), std::string("rect[r1] 3. 4. 5. 6.\n"));
}
//----------------------------------------------------------Commands
class CommandTest :public ::testing::Test
{
protected:
	/*std::shared_ptr<IVectorFigure> ellipse = std::make_shared<Ellipse>(
		"f1", Vector2D{ 1., 1. }, Vector2D{ 3., 1. }, Vector2D{ 1., 21. });
	std::shared_ptr<IVectorFigure> line = std::make_shared < Line>(
		"f1", Vector2D{ 5., 9. }, Vector2D{ 5., 19. });
		*/
	std::shared_ptr<IVectorFigure> rect = std::make_shared <Rect>(
		"f1", Vector2D{ 5., 9. }, Vector2D{ 5., 19. });
	const std::shared_ptr<IVectorFigure> rect_orig = std::make_shared <Rect>(
		"f1", Vector2D{ 5., 9. }, Vector2D{ 5., 19. });
};
TEST_F(CommandTest, rotate)
{
	RotateCommand rot(rect, 90);
	rot.redo();
	Rect r("f1", { 0, 14 }, { 10, 14 });
	EXPECT_EQ(rect.get()->to_string(), r.to_string());
	rot.undo();
	EXPECT_EQ(rect.get()->to_string(), rect_orig.get()->to_string());
}
TEST_F(CommandTest, scale)
{
	ScaleCommand scale(rect, 10, -2);
	scale.redo();
	Rect r("f1", {5., 24.}, {5., 4.});
	scale.undo();
	EXPECT_EQ(rect.get()->to_string(), rect_orig.get()->to_string());
}
TEST_F(CommandTest, translate)
{
	TranslateCommand translate(rect, {10, -1});
	translate.redo();
	Rect r("f1", {15., 8.}, {15., 18.});
	translate.undo();
	EXPECT_EQ(rect.get()->to_string(), rect_orig.get()->to_string());
}

//----------------------------------------------------------Commander
TEST (Commander, add)
{
	Commander commander;
	std::shared_ptr<IVectorFigure> rect = std::make_shared<Rect>("r", Vector2D{ 1, 2 }, Vector2D{ 3, 4 });
	std::shared_ptr<IGraphCommand> translate = std::make_shared<TranslateCommand>(rect, Vector2D(2, 3));
	commander.add_and_execute_command(translate);
	Rect translated_rect("r", Vector2D{ 3, 5 }, Vector2D{ 5, 7 });
	EXPECT_EQ(rect.get()->to_string(), translated_rect.to_string());
}
TEST(Commander, undo)
{
	Commander commander;
	std::shared_ptr<IVectorFigure> rect = std::make_shared<Rect>("r", Vector2D{ 1, 2 }, Vector2D{ 3, 4 });
	std::shared_ptr<IGraphCommand> translate = std::make_shared<TranslateCommand>(rect, Vector2D(2, 3));
	commander.add_and_execute_command(translate);
	Rect translated_rect("r", Vector2D{ 3, 5 }, Vector2D{ 5, 7 });
	Rect original_rect("r", Vector2D{ 1, 2 }, Vector2D{ 3, 4 });

	EXPECT_EQ(rect.get()->to_string(), translated_rect.to_string());
	commander.undo();
	EXPECT_EQ(rect.get()->to_string(), original_rect.to_string());
}