#include "LineSegment.h"

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, string const& color)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
	SetOutlineColor(color);
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return hypot(m_endPoint.x() - m_startPoint.x(), m_endPoint.y() - m_startPoint.y());
}

string CLineSegment::ToString() const
{
	stringstream info;
	info << "Name: line segment;\n"
		 << "Start point: " << m_startPoint.x() << ", " << m_startPoint.y() << ";\n"
		 << "End point: " << m_endPoint.x() << ", " << m_endPoint.y() << ";\n"
		 << "Area: " << GetArea() << ";\n"
		 << "Perimeter: " << GetPerimeter() << ";\n"
		 << "Outline color: " << GetOutlineColor() << ";" << endl;
	return info.str();
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
