#pragma once
#include "VectorFigure.h"
#include"Vector2D.h"
class IGraphCommand {
public:

	virtual void redo() const = 0;
	virtual void undo() const = 0;
	virtual ~IGraphCommand() = default;
};

class TranslateCommand final : public IGraphCommand {
public:
	TranslateCommand(IVectorFigure* const figure_, Vector2D dxdy_);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	IVectorFigure* figure_;
	Vector2D dxdy_;
};

class ScaleCommand final : public IGraphCommand {
public:
	ScaleCommand(IVectorFigure* const figure, double sx, double sy);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	IVectorFigure* figure_;
	double sx_, sy_;
};

class RotateCommand final : public IGraphCommand {
public:
	RotateCommand(IVectorFigure* const figure_, double deg_);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	IVectorFigure* figure_;
	double deg_;
};
