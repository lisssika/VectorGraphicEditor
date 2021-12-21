#define _USE_MATH_DEFINES
#include <cmath>
#include "Vector2D.h"
#include <ostream>
#include <string>
#include "DoubleIsEqual.h"

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
	const double x_coordinate = std::round((x * cos(rad) - y * sin(rad)) * 1.e6) /1.e6;
	const double y_coordinate = std::round((x * sin(rad) + y * cos(rad)) * 1.e6 )/ 1.e6;
	x = x_coordinate;
	y = y_coordinate;
}

void Vector2D::scale(double sx, double sy)
{
	x *= sx;
	y *= sy;
}

std::string Vector2D::to_string() const
{
	return to_string(x) + " " + to_string(y);
}

double Vector2D::get_x() const
{
	return x;
}

double Vector2D::get_y() const
{
	return y;
}

bool Vector2D::operator==(Vector2D const& p) const
{
	return double_is_equal(x, p.x) && double_is_equal(y, p.y);
}

std::string Vector2D::to_string(double number) const
{
	std::string number_str = std::to_string(number);
	for (unsigned i = number_str.size(); i > 0; i--)
	{
		if (number_str[i] == '0')
		{
			number_str.pop_back();
		}
		if (number_str[i] == '.')
		{
			return number_str;
		}
	}
	return std::to_string(number);
}
