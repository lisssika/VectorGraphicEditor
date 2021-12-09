#pragma once
#include "GraphCommand.h"
#include "VectorFigure.h"
#include"Vector2D.h"
#include <memory>

class RotateCommand final : public IGraphCommand {
public:
	RotateCommand(std::shared_ptr<IVectorFigure>& figure_, double deg_);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	std::shared_ptr<IVectorFigure> figure_;
	double deg_;
};
