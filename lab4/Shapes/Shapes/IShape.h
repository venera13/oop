#pragma once
#include "Point.h"
#include <string>

class IShape
{
public:
	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;

	virtual void SetOutlineColor(string const& color) = 0;
	virtual string GetOutlineColor() const = 0;
};
