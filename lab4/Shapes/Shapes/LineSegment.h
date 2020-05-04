#pragma once
#include <iostream>
#include <sstream>
#include "Shape.h"
#include "Point.h"

using namespace std;

class CLineSegment final : public CShape
{
public:
	CLineSegment(CPoint const& startPoint, CPoint const& endPoint, string const& color);
	~CLineSegment() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint = CPoint(0, 0);
	CPoint m_endPoint = CPoint(0, 0);
};
