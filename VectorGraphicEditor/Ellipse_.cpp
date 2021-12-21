#include "Ellipse.h"
#include "VectorFigure.h"
#include "Vector2D.h"
#include <string>
#include <fstream>
#include <utility>
#include "DoubleIsEqual.h"

Ellipse::Ellipse(std::string name_, Vector2D const& center_, Vector2D const& a_, Vector2D const& b_) :IVectorFigure(
	std::move(name_)), center_(center_), a_(a_), b_(b_) {}

void Ellipse::translate(Vector2D const& dxdy) {
	a_ = a_ + dxdy;
	b_ = b_ + dxdy;
	center_ = center_ + dxdy;
}
void Ellipse::scale(double sx, double sy) {
	if ( !double_is_equal(sx*sy, 0)) {
		a_ = center_ + Vector2D{ (a_ - center_).get_x() * sx, (a_ - center_).get_y() * sy };
		b_ = center_ + Vector2D{ (b_ - center_).get_x() * sx, (b_ - center_).get_y() * sy };
	}
	else
	{
		throw std::runtime_error("Scale coefficient is 0");
	}
}
void Ellipse::rotate(double deg) {
	Vector2D vector_cntr_a = a_ - center_;
	Vector2D vector_cntr_b = b_ - center_;
	vector_cntr_a.rot(deg);
	vector_cntr_b.rot(deg);
	a_ = center_ + vector_cntr_a;
	b_ = center_ + vector_cntr_b;
}

std::string Ellipse::to_string() const
{
	return name_ + " " + center_.to_string() + " " + a_.to_string() + " " + b_.to_string();
}

bool Ellipse::operator==(Ellipse const& another)
{
	return (
		name_ == another.name_ &&
		center_ == another.center_ &&
		a_ == another.a_ &&
		b_ == another.b_
		);
}
