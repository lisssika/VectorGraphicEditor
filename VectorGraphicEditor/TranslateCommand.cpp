#include "TranslateCommand.h"
#include "VectorFigure.h"
#include"Vector2D.h"

TranslateCommand::TranslateCommand(std::shared_ptr<IVectorFigure>& figure, Vector2D dxdy_) :figure_(figure), dxdy_(dxdy_) {}
void TranslateCommand::redo() const {
	figure_->translate(dxdy_);
}
void TranslateCommand::undo() const {
	figure_->translate({ -dxdy_.get_x(), -dxdy_.get_y() });
}

