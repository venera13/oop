#pragma once
#define _USE_MATH_DEFINES

#include "Point.h"
#include "SolidShape.h"

class CCircle final : public CSolidShape
{
public:
	CCircle(CPoint const& centerPoint, double const& radius, string const& outlineColor, string const& fillColor);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center = CPoint(0, 0);
	double m_radius = 0;
};
