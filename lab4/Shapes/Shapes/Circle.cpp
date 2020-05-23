#include "Circle.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

CCircle::CCircle(CPoint const& centerPoint, double const& radius, std::string const& outlineColor, std::string const& fillColor)
	: m_center(centerPoint)
	, m_radius(radius)
{
	SetOutlineColor(stoul(outlineColor, 0, 16));
	SetFillColor(stoul(fillColor, 0, 16));
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

string CCircle::ToString() const
{
	stringstream info;
	info << "Name: circle;\n"
		 << "Center point: " << m_center.x() << ", " << m_center.y() << ";\n"
		 << "Radius: " << m_radius << ";\n"
		 << "Area: " << GetArea() << ";\n"
		 << "Perimeter: " << GetPerimeter() << ";\n"
		 << "Outline color: " << GetOutlineColor() << ";\n"
		 << "Fill color: " << GetFillColor() << ";" << endl;
	return info.str();
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.DrawCircle(m_center, m_radius, GetOutlineColor(), GetFillColor());
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
