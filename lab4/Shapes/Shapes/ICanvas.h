#pragma once
#include "Point.h"
#include "stdint.h"
#include <vector>
#include <string>

class ICanvas
{
public:
	virtual ~ICanvas() = default;

	virtual void DrawLine(CPoint const& startPoint, CPoint const& endPoint, std::string const& lineColor) const = 0;
	virtual void DrawFillPoligon(std::vector<CPoint> const& points, std::string const& outlineColor, std::string const& fillColor) const = 0;
	virtual void DrawCircle(CPoint const& center, double const& radius, std::string const& outlineColor, std::string const& fillColor) const = 0;
};
