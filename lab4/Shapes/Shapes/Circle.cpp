#include "Circle.h"

CCircle::CCircle(CPoint const& centerPoint, double const& radius, string const& outlineColor, string const& fillColor)
	: m_center(centerPoint)
	, m_radius(radius)
{
	SetOutlineColor(outlineColor);
	SetFillColor(fillColor);
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

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}
