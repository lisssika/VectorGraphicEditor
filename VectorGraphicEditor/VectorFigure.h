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
