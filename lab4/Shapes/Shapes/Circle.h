#pragma once
#define _USE_MATH_DEFINES

#include "Point.h"
#include "SolidShape.h"

class CCircle final : public CSolidShape
{
public:
	CCircle(CPoint const& centerPoint, double const& radius, std::string const& outlineColor, std::string const& fillColor);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(ICanvas& canvas) const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center = CPoint(0, 0);
	double m_radius = 0;
};
