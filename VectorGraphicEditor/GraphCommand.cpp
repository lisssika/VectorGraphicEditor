#include "GraphCommand.h"
#include "VectorFigure.h"
#include"Vector2D.h"
#include "DoubleIsEqual.h"

TranslateCommand::TranslateCommand(std::shared_ptr<IVectorFigure>& figure, Vector2D dxdy_) :figure_(figure), dxdy_(dxdy_) {}
void TranslateCommand::redo() const {
	figure_->translate(dxdy_);
}
void TranslateCommand::undo() const {
	figure_->translate({ -dxdy_.get_x(), -dxdy_.get_y() });
}

ScaleCommand::ScaleCommand(std::shared_ptr<IVectorFigure>& figure, double sx, double sy) :figure_(figure), sx_(sx), sy_(sy) {}
void ScaleCommand::redo() const {
	figure_->scale(sx_, sy_);
}
void ScaleCommand::undo()const {
	if(double_is_equal(sx_,0)||(double_is_equal(sy_, 0)))
	{
		throw std::runtime_error("Divided by zero. Scale can't be 0");
	}
	figure_->scale(1 / sx_, 1 / sy_);
}

RotateCommand::RotateCommand(std::shared_ptr<IVectorFigure>& figure, double deg_) :figure_(figure), deg_(deg_) {}
void RotateCommand::redo() const {
	figure_->rotate(deg_);
}
void RotateCommand::undo()const {
	figure_->rotate(-deg_);
}
