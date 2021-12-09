#pragma once
#include "GraphCommand.h"
#include "VectorFigure.h"
#include"Vector2D.h"
#include <memory>

class ScaleCommand final : public IGraphCommand {
public:
	ScaleCommand(std::shared_ptr<IVectorFigure>& figure_, double sx, double sy);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	std::shared_ptr<IVectorFigure> figure_;
	double sx_, sy_;
};