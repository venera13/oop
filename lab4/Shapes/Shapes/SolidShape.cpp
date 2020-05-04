#include "SolidShape.h"

void CSolidShape::SetFillColor(string const& color)
{
	m_fillColor = color;
}

string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}
