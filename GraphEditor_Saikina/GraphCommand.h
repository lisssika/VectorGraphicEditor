#pragma once
#include "VectorFigure.h"
#include"Vector2D.h"
class IGraphCommand {
public:

	virtual void redo() = 0;
	virtual void undo() = 0;
};

class TranslateCommand final : public IGraphCommand {
public:
	TranslateCommand(IVectorFigure* const figure_, Vector2D dxdy_);
	virtual void redo();
	virtual void undo();
private:
	IVectorFigure* figure;
	Vector2D dxdy;
};

class ScaleCommand final : public IGraphCommand {
public:
	ScaleCommand(IVectorFigure* const figure_, double sx_, double sy_);
	virtual void redo();
	virtual void undo();
private:
	IVectorFigure* figure;
	double sx, sy;
};

class RotateCommand final : public IGraphCommand {
public:
	RotateCommand(IVectorFigure* const figure_, double deg_);
	virtual void redo();
	virtual void undo();
private:
	IVectorFigure* figure;
	double deg;
};
