#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>

using namespace std;

class CTriangle final : public CSolidShape
{
public:
	CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, string const& outlineColor, string const& fillColor);
	~CTriangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1 = CPoint(0, 0);
	CPoint m_vertex2 = CPoint(0, 0);
	CPoint m_vertex3 = CPoint(0, 0);
};
