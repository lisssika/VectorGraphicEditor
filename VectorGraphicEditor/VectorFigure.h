#pragma once
#include "Vector2D.h"
#include <string>


class IVectorFigure {
public:
	IVectorFigure(std::string name);
	virtual void translate(Vector2D const& dxdy) = 0;
	virtual void scale(double sx, double sy) = 0;
	virtual void rotate(double deg) = 0;
	std::string get_name() const;
	virtual std::string to_string() const = 0;
	virtual ~IVectorFigure() = default;
protected:
	std::string name_;
};

class Rect final : public IVectorFigure {
public:
	Rect(std::string name, Vector2D const& a, Vector2D const& b);
	virtual void translate(Vector2D const& dxdy) override;
	virtual void scale(double sx, double sy)override;
	virtual void rotate(double deg) override;
	virtual std::string to_string() const override;
private:
	Vector2D a_;
	Vector2D b_;
};

class Line final : public IVectorFigure {
public:
	Line(const std::string& name, Vector2D const& a, Vector2D const& b);
	virtual void translate(Vector2D const& dxdy_) override;
	virtual void scale(double sx, double sy) override;
	virtual void rotate(double deg) override;
	virtual std::string to_string() const override;
private:
	Vector2D a_;
	Vector2D b_;
};

class Ellipse final : public IVectorFigure {
public:
	Ellipse(std::string name_, Vector2D const& center_, Vector2D const& a_, Vector2D const& b_);

	virtual void translate(Vector2D const& dxdy) override;
	virtual void scale(double sx, double sy) override;
	virtual void rotate(double deg) override;
	virtual std::string to_string() const override;	
private:
	Vector2D center_;
	Vector2D a_;
	Vector2D b_;
};
