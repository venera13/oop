#pragma once
#include "Point.h"

#include "math.h"
#include <string>

using namespace std;

struct Point
{
	double x;
	double y;
};

class IShape
{
public:
	IShape() = default;
	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual string ToString() const = 0;

	virtual void SetOutlineColor(string const& color) = 0;
	virtual string GetOutlineColor() const = 0;
};
