#pragma once
#include "Vector2D.h"
#include <string>


class IVectorFigure {
public:
	IVectorFigure(std::string name_);
	virtual void translate(Vector2D dxdy) = 0;
	virtual void scale(double sx, double sy) = 0;
	virtual void rotate(double deg) = 0;
	std::string get_name() const;
protected:
	std::string name;
};

class Rect final : public IVectorFigure {
public:
	Rect(std::string name_, Vector2D const& a_, Vector2D const& b_);
	virtual void translate(Vector2D dxdy);
	virtual void scale(double sx, double sy);
	virtual void rotate(double deg);
	friend std::ofstream& operator<<(std::ofstream& out, Rect const& rect);
private:
	Vector2D a;
	Vector2D b;
};

class Line final : public IVectorFigure {
public:
	Line(std::string name_, Vector2D const& a_, Vector2D const& b_);
	virtual void translate(Vector2D dxdy_);
	virtual void scale(double sx, double sy);
	virtual void rotate(double deg);
	friend std::ofstream& operator<<(std::ofstream& out, Line const& line);
private:
	Vector2D a;
	Vector2D b;
};

class Ellipse final : public IVectorFigure {
public:
	Ellipse(std::string name_, Vector2D const& center_, Vector2D const& a_, Vector2D const& b_);

	virtual void translate(Vector2D dxdy_);
	virtual void scale(double sx, double sy);
	virtual void rotate(double deg);
	friend std::ofstream& operator<<(std::ofstream& out, Ellipse const& ellipse);
	
private:
	Vector2D center;
	Vector2D a;
	Vector2D b;
};
