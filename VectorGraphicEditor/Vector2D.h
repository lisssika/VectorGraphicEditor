#pragma once
#include <cmath>
#include <fstream>
#include <ostream>
#define PI 3.14159265 

struct Vector2D {
	Vector2D(double x, double y);
	Vector2D();
	double x_coord;
	double y_coord;
	Vector2D operator+(Vector2D p);
	Vector2D operator-(Vector2D p);
	Vector2D operator*(double a);
	void rot(double deg);
	friend std::ostream& operator<<(std::ostream& out, Vector2D const& vector);
};