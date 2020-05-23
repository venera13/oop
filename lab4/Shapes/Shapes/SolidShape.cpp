#include "SolidShape.h"

using namespace std;

void CSolidShape::SetFillColor(string const& color)
{
	m_fillColor = color;
}

string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::SetOutlineColor(string const& color)
{
	CShape::SetOutlineColor(color);
}

string CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}
