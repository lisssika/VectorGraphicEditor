#pragma once
#include "GraphCommand.h"
#include "VectorFigure.h"
#include"Vector2D.h"
#include <memory>
class TranslateCommand final : public IGraphCommand {
public:
	TranslateCommand(std::shared_ptr<IVectorFigure>& figure_, Vector2D dxdy_);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	std::shared_ptr<IVectorFigure> figure_;
	Vector2D dxdy_;
};

