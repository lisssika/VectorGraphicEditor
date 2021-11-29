#pragma once
#include <ostream>

struct Vector2D {
	Vector2D(double x, double y);
	Vector2D();
	double x;
	double y;
	Vector2D operator+(Vector2D const& p) const;
	Vector2D operator-(Vector2D const& p) const;
	Vector2D operator*(double a) const;
	void rot(double deg) ;
	friend std::ostream& operator<<(std::ostream& out, Vector2D const& vector);
};