#include "Rectangle.h"

CRectangle::CRectangle(CPoint const& leftTopPoint, double const& width, double const& height, string const& outlineColor, string const& fillColor)
	: m_leftTopPoint(leftTopPoint)
	, m_width(width)
	, m_height(height)
{
	if (width < 0 || height < 0)
	{
		throw invalid_argument("Rectable width and height cannot be negative");
	}
	SetOutlineColor(outlineColor);
	SetFillColor(fillColor);
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

CPoint CRectangle::GetLeftTopPoint() const
{
	return m_leftTopPoint;
}

CPoint CRectangle::GetRightBottomPoint() const
{
	return CPoint(m_leftTopPoint.x() + m_width, m_leftTopPoint.y() - m_height);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}
