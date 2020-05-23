#include "Rectangle.h"

using namespace std;

CRectangle::CRectangle(CPoint const& leftTopPoint, double const& width, double const& height, std::string const& outlineColor, std::string const& fillColor)
	: m_leftTopPoint(leftTopPoint)
	, m_width(width)
	, m_height(height)
{
	SetOutlineColor(stoul(outlineColor, 0, 16));
	SetFillColor(stoul(fillColor, 0, 16));
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

string CRectangle::ToString() const
{
	stringstream info;
	CPoint rightBottomPoint = GetRightBottomPoint();
	info << "Name: rectangle;\n"
		 << "Left top point: " << m_leftTopPoint.x() << ", " << m_leftTopPoint.y() << ";\n"
		 << "Right bottom point: " << rightBottomPoint.x() << ", " << rightBottomPoint.y() << ";\n"
		 << "Width: " << GetWidth() << ";\n"
		 << "Height: " << GetHeight() << ";\n"
		 << "Area: " << GetArea() << ";\n"
		 << "Perimeter: " << GetPerimeter() << ";\n"
		 << "Outline color: " << GetOutlineColor() << ";\n"
		 << "Fill color: " << GetFillColor() << ";" << endl;
	return info.str();
}

void CRectangle::Draw(ICanvas& canvas) const
{
	CPoint rightBottomPoint = GetRightBottomPoint();
	std::vector<CPoint> points = {
		{ m_leftTopPoint.x(), m_leftTopPoint.y() },
		{ m_leftTopPoint.x() + m_width, m_leftTopPoint.y() },
		{ rightBottomPoint.x(), rightBottomPoint.y() },
		{ m_leftTopPoint.x(), m_leftTopPoint.y() + m_height }
	};
	canvas.DrawFillPoligon(points, GetOutlineColor(), GetFillColor());
}

CPoint CRectangle::GetLeftTopPoint() const
{
	return m_leftTopPoint;
}

CPoint CRectangle::GetRightBottomPoint() const
{
	return CPoint(m_leftTopPoint.x() + m_width, m_leftTopPoint.y() + m_height);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
