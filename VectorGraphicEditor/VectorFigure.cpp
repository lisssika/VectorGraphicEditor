#include "VectorFigure.h"
#include "Vector2D.h"
#include <string>

IVectorFigure::IVectorFigure(std::string name_) : name(name_) {}

std::string IVectorFigure::get_name() const
{
	return name;
}

Rect::Rect(std::string name_, Vector2D const& a_, Vector2D const& b_) : IVectorFigure(name_), a(a_), b(b_) {}

void Rect::translate(Vector2D dxdy) {
	a = a + dxdy;
	b = b + dxdy;
}

void Rect::scale(double sx, double sy) {
	if (sx * sy != 0) {
		Vector2D centr = (a + b) * 0.5;
		Vector2D centr_to_a = a - centr;
		Vector2D centr_to_b = b - centr;
		centr_to_a.x_coord *= sx;
		centr_to_a.y_coord *= sy;
		centr_to_b.x_coord *= sx;
		centr_to_b.y_coord *= sy;
		a = centr + centr_to_a;
		b = centr + centr_to_b;
	}
	else
	{
		throw std::runtime_error("Scale coefficient is 0");
	}
}

void Rect::rotate(double deg) {
	Vector2D center_coord{ a.x_coord + (b.x_coord - a.x_coord) / 2,  a.y_coord + (b.y_coord - a.y_coord) / 2 };
	Vector2D vector_cntr_a = center_coord - a;
	Vector2D vector_cntr_b = center_coord - b;
	vector_cntr_a.rot(deg);
	vector_cntr_b.rot(deg);
	a = center_coord + vector_cntr_a;
	b = center_coord + vector_cntr_b;
}


std::ofstream& operator<<(std::ofstream& out, Rect const& rect) {
	out << rect.get_name() << ' ' << (dynamic_cast<Rect const&> (rect).a) << ' ' << dynamic_cast<Rect const&> (rect).b << '\n';
	return out;
}

Line::Line(std::string name_, Vector2D const& a_, Vector2D const& b_) :IVectorFigure(name_), a(a_), b(b_) {}

void Line::translate(Vector2D dxdy_) {
	a = a + dxdy_;
	b = b + dxdy_;
}
void Line::scale(double sx, double sy) {
	if (sx * sy != 0) {
		Vector2D centr = (a + b) * 0.5;
		Vector2D centr_to_a = a - centr;
		Vector2D centr_to_b = b - centr;
		centr_to_a.x_coord *= sx;
		centr_to_a.y_coord *= sy;
		centr_to_b.x_coord *= sx;
		centr_to_b.y_coord *= sy;
		a = centr + centr_to_a;
		b = centr + centr_to_b;
	}
	else
	{
		throw std::runtime_error("Scale coefficient is 0");
	}
}
void Line::rotate(double deg) {
	Vector2D center_coord{ a.x_coord + (b.x_coord - a.x_coord) / 2,  a.y_coord + (b.y_coord - a.y_coord) / 2 };
	Vector2D vector_cntr_a = center_coord - a;
	Vector2D vector_cntr_b = center_coord - b;
	vector_cntr_a.rot(deg);
	vector_cntr_b.rot(deg);
	a = center_coord + vector_cntr_a;
	b = center_coord + vector_cntr_b;
}

std::ofstream& operator<<(std::ofstream& out, Line const& line) {
	out << line.get_name() << ' ' << (dynamic_cast<Line const&> (line).a) << ' ' << dynamic_cast<Line const&> (line).b << '\n';
	return out;
}

Ellipse::Ellipse(std::string name_, Vector2D const& center_, Vector2D const& a_, Vector2D const& b_) :IVectorFigure(name_), center(center_), a(a_), b(b_) {}

void Ellipse::translate(Vector2D dxdy_) {
		a = a + dxdy_;
		b = b + dxdy_;
		center = center + dxdy_;
	}
 void Ellipse::scale(double sx, double sy) {
		if (sx * sy != 0) {
			a = center+Vector2D{ (a - center).x_coord * sx, (a - center).y_coord * sy };
			b = center+ Vector2D{ (b - center).x_coord * sx, (b - center).y_coord * sy };
		}
		else
		{
			throw std::runtime_error("Scale coefficient is 0");
		}
	}
void Ellipse::rotate(double deg) {
		Vector2D vector_cntr_a = a - center;
		Vector2D vector_cntr_b = b - center;
		vector_cntr_a.rot(deg);
		vector_cntr_b.rot(deg);
		a = center + vector_cntr_a;
		b = center + vector_cntr_b;
	}

	std::ofstream& operator<<(std::ofstream& out, Ellipse const& ellipse) {
		out << ellipse.name << ' ' << dynamic_cast<Ellipse const&> (ellipse).center << ' ' << dynamic_cast<Ellipse const&> (ellipse).a << ' ' << dynamic_cast<Ellipse const&> (ellipse).b << '\n';
		return out;
	}
