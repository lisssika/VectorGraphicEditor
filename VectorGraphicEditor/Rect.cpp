#include "Rect.h"
#include "VectorFigure.h"
#include "Vector2D.h"
#include <string>
#include <fstream>
#include <utility>
#include "DoubleIsEqual.h"

std::string IVectorFigure::get_name() const
{
	return name_;
}

Rect::Rect(std::string name, Vector2D const& a, Vector2D const& b) : IVectorFigure(std::move(name)), a_(a), b_(b) {}

void Rect::translate(Vector2D const& dxdy) {
	a_ = a_ + dxdy;
	b_ = b_ + dxdy;
}

void Rect::scale(double sx, double sy) {
	if (!double_is_equal(sx * sy, 0)) {
		const Vector2D centr = (a_ + b_) * 0.5;
		Vector2D centr_to_a = a_ - centr;
		Vector2D centr_to_b = b_ - centr;
		centr_to_a.scale(sx, sy);
		centr_to_b.scale(sx, sy);
		a_ = centr + centr_to_a;
		b_ = centr + centr_to_b;
	}
	else
	{
		throw std::runtime_error("Scale coefficient is 0");
	}
}

void Rect::rotate(double deg) {
	const Vector2D center_coord{ a_.get_x() + (b_.get_x() - a_.get_x()) / 2,  a_.get_y() + (b_.get_y() - a_.get_y()) / 2 };
	Vector2D vector_cntr_a = center_coord - a_;
	Vector2D vector_cntr_b = center_coord - b_;
	vector_cntr_a.rot(deg);
	vector_cntr_b.rot(deg);
	a_ = center_coord + vector_cntr_a;
	b_ = center_coord + vector_cntr_b;
}

std::string Rect::to_string() const
{
	return name_ + " " + a_.to_string() + " " + b_.to_string();
}

bool Rect::operator==(Rect const& another) const
{
	return (
		name_ == another.name_ &&
		a_ == another.a_ &&
		b_ == another.b_
		);
}
