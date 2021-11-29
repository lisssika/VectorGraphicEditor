#include "VectorFigure.h"
#include "Vector2D.h"
#include <string>
#include <fstream>

IVectorFigure::IVectorFigure(std::string name) : name_(name) {}

std::string IVectorFigure::get_name() const
{
	return name_;
}

Rect::Rect(std::string name, Vector2D const& a, Vector2D const& b) : IVectorFigure(name), a_(a), b_(b) {}

void Rect::translate(Vector2D const& dxdy) {
	a_ = a_ + dxdy;
	b_ = b_ + dxdy;
}

void Rect::scale(double sx, double sy) {
	if (sx * sy != 0) {
		Vector2D centr = (a_ + b_) * 0.5;
		Vector2D centr_to_a = a_ - centr;
		Vector2D centr_to_b = b_ - centr;
		centr_to_a.x *= sx;
		centr_to_a.y *= sy;
		centr_to_b.x *= sx;
		centr_to_b.y *= sy;
		a_ = centr + centr_to_a;
		b_ = centr + centr_to_b;
	}
	else
	{
		throw std::runtime_error("Scale coefficient is 0");
	}
}

void Rect::rotate(double deg) {
	Vector2D center_coord{ a_.x + (b_.x - a_.x) / 2,  a_.y + (b_.y - a_.y) / 2 };
	Vector2D vector_cntr_a = center_coord - a_;
	Vector2D vector_cntr_b = center_coord - b_;
	vector_cntr_a.rot(deg);
	vector_cntr_b.rot(deg);
	a_ = center_coord + vector_cntr_a;
	b_ = center_coord + vector_cntr_b;
}


std::ofstream& operator<<(std::ofstream& out, Rect const& rect) {
	out << rect.get_name() << ' ' << (dynamic_cast<Rect const&> (rect).a_) << ' ' << dynamic_cast<Rect const&> (rect).b_ << '\n';
	return out;
}

Line::Line(std::string name_, Vector2D const& a_, Vector2D const& b_) :IVectorFigure(name_), a_(a_), b_(b_) {}

void Line::translate(Vector2D const& dxdy_) {
	a_ = a_ + dxdy_;
	b_ = b_ + dxdy_;
}
void Line::scale(double sx, double sy) {
	if (sx * sy != 0) {
		Vector2D centr = (a_ + b_) * 0.5;
		Vector2D centr_to_a = a_ - centr;
		Vector2D centr_to_b = b_ - centr;
		centr_to_a.x *= sx;
		centr_to_a.y *= sy;
		centr_to_b.x *= sx;
		centr_to_b.y *= sy;
		a_ = centr + centr_to_a;
		b_ = centr + centr_to_b;
	}
	else
	{
		throw std::runtime_error("Scale coefficient is 0");
	}
}
void Line::rotate(double deg) {
	Vector2D center_coord{ a_.x + (b_.x - a_.x) / 2,  a_.y + (b_.y - a_.y) / 2 };
	Vector2D vector_cntr_a = center_coord - a_;
	Vector2D vector_cntr_b = center_coord - b_;
	vector_cntr_a.rot(deg);
	vector_cntr_b.rot(deg);
	a_ = center_coord + vector_cntr_a;
	b_ = center_coord + vector_cntr_b;
}

std::ofstream& operator<<(std::ofstream& out, Line const& line) {
	out << line.get_name() << ' ' << (dynamic_cast<Line const&> (line).a_) << ' ' << dynamic_cast<Line const&> (line).b_ << '\n';
	return out;
}

Ellipse::Ellipse(std::string name_, Vector2D const& center_, Vector2D const& a_, Vector2D const& b_) :IVectorFigure(name_), center_(center_), a_(a_), b_(b_) {}

void Ellipse::translate(Vector2D const& dxdy) {
		a_ = a_ + dxdy;
		b_ = b_ + dxdy;
		center_ = center_ + dxdy;
	}
 void Ellipse::scale(double sx, double sy) {
		if (sx * sy != 0) {
			a_ = center_+Vector2D{ (a_ - center_).x * sx, (a_ - center_).y * sy };
			b_ = center_+ Vector2D{ (b_ - center_).x * sx, (b_ - center_).y * sy };
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

	std::ofstream& operator<<(std::ofstream& out, Ellipse const& ellipse) {
		out << ellipse.name_ << ' ' << dynamic_cast<Ellipse const&> (ellipse).center_ << ' ' << dynamic_cast<Ellipse const&> (ellipse).a_ << ' ' << dynamic_cast<Ellipse const&> (ellipse).b_ << '\n';
		return out;
	}
