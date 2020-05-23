#pragma once
#include "Point.h"
#include "ICanvasDrawable.h"
#include <string>

class IShape : virtual public ICanvasDrawable
{
public:
	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;

	virtual void SetOutlineColor(std::string const& color) = 0;
	virtual std::string GetOutlineColor() const = 0;
};
