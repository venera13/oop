#include "Triangle.h"

using namespace std;

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, std::string const& outlineColor, std::string const& fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
	SetOutlineColor(stoul(outlineColor, 0, 16));
	SetFillColor(stoul(fillColor, 0, 16));
}

double CTriangle::GetArea() const
{
	double halfPerimeter = GetPerimeter() / 2;

	return sqrt(halfPerimeter * (halfPerimeter - hypot(m_vertex2.x() - m_vertex1.x(), m_vertex2.y() - m_vertex1.y()))
		* (halfPerimeter - hypot(m_vertex3.x() - m_vertex2.x(), m_vertex3.y() - m_vertex2.y()))
		* (halfPerimeter - hypot(m_vertex3.x() - m_vertex1.x(), m_vertex3.y() - m_vertex1.y())));
}

double CTriangle::GetPerimeter() const
{
	return hypot(m_vertex2.x() - m_vertex1.x(), m_vertex2.y() - m_vertex1.y())
		+ hypot(m_vertex3.x() - m_vertex2.x(), m_vertex3.y() - m_vertex2.y())
		+ hypot(m_vertex3.x() - m_vertex1.x(), m_vertex3.y() - m_vertex1.y());
}

string CTriangle::ToString() const
{
	stringstream info;
	info << "Name: triangle;\n"
		 << "Vertex 1: " << m_vertex1.x() << ", " << m_vertex1.y() << ";\n"
		 << "Vertex 2: " << m_vertex2.x() << ", " << m_vertex2.y() << ";\n"
		 << "Vertex 3: " << m_vertex3.x() << ", " << m_vertex3.y() << ";\n"
		 << "Area: " << GetArea() << ";\n"
		 << "Perimeter: " << GetPerimeter() << ";\n"
		 << "Outline color: " << GetOutlineColor() << ";\n"
		 << "Fill color: " << GetFillColor() << ";" << endl;
	return info.str();
}

void CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points = {
		{ m_vertex1.x(), m_vertex1.y() },
		{ m_vertex2.x(), m_vertex2.y() },
		{ m_vertex3.x(), m_vertex3.y() }
	};
	canvas.DrawFillPoligon(points, GetOutlineColor(), GetFillColor());
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}
