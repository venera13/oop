#pragma once
#include "Point.h"
#include "stdint.h"
#include <vector>
#include <string>

class ICanvas
{
public:
	virtual ~ICanvas() = default;

	virtual void DrawLine(CPoint const& startPoint, CPoint const& endPoint, uint32_t const& lineColor) const = 0;
	virtual void DrawFillPoligon(std::vector<CPoint> const& points, uint32_t const& outlineColor, uint32_t const& fillColor) const = 0;
	virtual void DrawCircle(CPoint const& center, double const& radius, uint32_t const& outlineColor, uint32_t const& fillColor) const = 0;
};
