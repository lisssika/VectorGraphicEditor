#pragma once
#include "Vector2D.h"
#include <cmath>
#include <fstream>
#include <ostream>
#define PI 3.14159265 

Vector2D::Vector2D(double x, double y) :x_coord(x), y_coord(y) {}
Vector2D::Vector2D() : x_coord{ 0 }, y_coord{ 0 }{}

Vector2D Vector2D::operator+(Vector2D p) {
	return{ x_coord + p.x_coord, y_coord + p.y_coord };
}
Vector2D Vector2D::operator-(Vector2D p) {
	return{ x_coord - p.x_coord, y_coord - p.y_coord };
}
Vector2D Vector2D::operator*(double a) {
	return { x_coord * a, y_coord * a };
}
void Vector2D::rot(double deg) {
	auto rad = deg * PI / 180;
	double x_coord_ = std::round(x_coord * cos(rad) - y_coord * sin(rad)) * 1.e6 /1.e6;
	double y_coord_ = std::round(x_coord * sin(rad) + y_coord * cos(rad) )* 1.e6 / 1.e6;
	x_coord = x_coord_;
	y_coord = y_coord_;
}

std::ostream& operator<<(std::ostream& out, Vector2D const& vector) {
	out << vector.x_coord << " " << vector.y_coord ;
	return out;
}
