#include "ScaleCommand.h"
#include "VectorFigure.h"
#include"Vector2D.h"
#include "DoubleIsEqual.h"

ScaleCommand::ScaleCommand(std::shared_ptr<IVectorFigure>& figure, double sx, double sy) :figure_(figure), sx_(sx), sy_(sy) {}
void ScaleCommand::redo() const {
	figure_->scale(sx_, sy_);
}
void ScaleCommand::undo()const {
	if (double_is_equal(sx_, 0) || (double_is_equal(sy_, 0)))
	{
		throw std::runtime_error("Divided by zero. Scale can't be 0");
	}
	figure_->scale(1 / sx_, 1 / sy_);
}

