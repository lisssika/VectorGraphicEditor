#pragma once
#include "VectorFigure.h"
#include "Vector2D.h"
#include <string>
class Ellipse final : public IVectorFigure {
public:
	Ellipse(std::string name_, Vector2D const& center_, Vector2D const& a_, Vector2D const& b_);

	virtual void translate(Vector2D const& dxdy) override;
	virtual void scale(double sx, double sy) override;
	virtual void rotate(double deg) override;
	virtual std::string to_string() const override;
	bool operator==(Ellipse const& another);
private:
	Vector2D center_;
	Vector2D a_;
	Vector2D b_;
};
