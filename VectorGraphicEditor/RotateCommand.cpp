#include "RotateCommand.h"
#include "VectorFigure.h"

RotateCommand::RotateCommand(std::shared_ptr<IVectorFigure>& figure, double deg_) :figure_(figure), deg_(deg_) {}
void RotateCommand::redo() const {
	figure_->rotate(deg_);
}
void RotateCommand::undo()const {
	figure_->rotate(-deg_);
}
