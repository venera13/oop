#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>

using namespace std;

class CRectangle final : public CSolidShape
{
public:
	CRectangle(CPoint const& leftTopPoint, double const& width, double const& height, string const& outlineColor, string const& fillColor);
	~CRectangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;

	CPoint GetLeftTopPoint() const;
	CPoint GetRightBottomPoint() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTopPoint = CPoint(0, 0);
	double m_width = 0;
	double m_height = 0;
};
