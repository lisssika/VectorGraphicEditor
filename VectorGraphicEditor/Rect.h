#pragma once
#include "VectorFigure.h"
#include "Vector2D.h"
#include <string>
class Rect final : public IVectorFigure {
public:
	Rect(std::string name, Vector2D const& a, Vector2D const& b);
	virtual void translate(Vector2D const& dxdy) override;
	virtual void scale(double sx, double sy)override;
	virtual void rotate(double deg) override;
	virtual std::string to_string() const override;
private:
	Vector2D a_;
	Vector2D b_;
};
