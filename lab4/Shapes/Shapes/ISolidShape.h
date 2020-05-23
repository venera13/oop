#pragma once

#include "IShape.h"

class ISolidShape : virtual public IShape
{
public:
	virtual void SetFillColor(std::string const& color) = 0;
	virtual std::string GetFillColor() const = 0;
};
