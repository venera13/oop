#pragma once

#include "IShape.h"

class ISolidShape : virtual public IShape
{
public:
	ISolidShape() = default;
	virtual ~ISolidShape() = default;

	virtual void SetFillColor(string const& color) = 0;
	virtual string GetFillColor() const = 0;
};
