#include "Shape.h"

void CShape::SetOutlineColor(string const& color)
{
	m_outlineColor = color;
}

string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}
