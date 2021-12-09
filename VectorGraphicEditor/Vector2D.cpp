#define _USE_MATH_DEFINES
#include <cmath>
#include "Vector2D.h"
#include <ostream>
#include <string>

Vector2D::Vector2D(double x, double y) :x(x), y(y) {}
Vector2D::Vector2D() : x{ 0 }, y{ 0 }{}

Vector2D Vector2D::operator+(Vector2D const& p) const {
	return{ x + p.x, y + p.y };
}
Vector2D Vector2D::operator-(Vector2D const& p) const {
	return{ x - p.x, y - p.y };
}
Vector2D Vector2D::operator*(double a) const {
	return { x * a, y * a };
}
void Vector2D::rot(double deg) {
	const auto rad = deg * M_PI / 180;
	const double x_coordinate = std::round(x * cos(rad) - y * sin(rad)) * 1.e6 /1.e6;
	const double y_coordinate = std::round(x * sin(rad) + y * cos(rad) )* 1.e6 / 1.e6;
	x = x_coordinate;
	y = y_coordinate;
}

std::string Vector2D::to_string() const
{
	return std::to_string(x) + " " + std::to_string(y);
}

double Vector2D::get_x() const
{
	return x;
}

double Vector2D::get_y() const
{
	return y;
}
