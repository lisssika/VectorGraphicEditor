#pragma once
#include "VectorFigure.h"
#include"Vector2D.h"
#include <memory>
class IGraphCommand {
public:

	virtual void redo() const = 0;
	virtual void undo() const = 0;
	virtual ~IGraphCommand() = default;
};

class TranslateCommand final : public IGraphCommand {
public:
	TranslateCommand(std::shared_ptr<IVectorFigure>& figure_, Vector2D dxdy_);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	std::shared_ptr<IVectorFigure> figure_;
	Vector2D dxdy_;
};

class ScaleCommand final : public IGraphCommand {
public:
	ScaleCommand(std::shared_ptr<IVectorFigure>& figure_, double sx, double sy);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	std::shared_ptr<IVectorFigure> figure_;
	double sx_, sy_;
};

class RotateCommand final : public IGraphCommand {
public:
	RotateCommand(std::shared_ptr<IVectorFigure>& figure_, double deg_);
	virtual void redo() const override;
	virtual void undo() const override;
private:
	std::shared_ptr<IVectorFigure> figure_;
	double deg_;
};
