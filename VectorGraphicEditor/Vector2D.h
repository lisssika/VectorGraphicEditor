#pragma once
#include <ostream>
#include <string>

struct Vector2D {
	Vector2D(double x, double y);
	Vector2D();
	Vector2D operator+(Vector2D const& p) const;
	Vector2D operator-(Vector2D const& p) const;
	Vector2D operator*(double a) const;
	void rot(double deg) ;
	std::string to_string() const;
	double get_x() const;
	double get_y() const;
private:
	double x;
	double y;
};