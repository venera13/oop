#include "LineSegment.h"

using namespace std;

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& color)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
	SetOutlineColor(stoul(color, 0, 16));
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

void CLineSegment::Draw(ICanvas& canvas) const
{
	canvas.DrawLine(m_startPoint, m_endPoint, GetOutlineColor());
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}
