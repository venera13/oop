#include "Shape.h"

using namespace std;

void CShape::SetOutlineColor(string const& color)
{
	m_outlineColor = color;
}

string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}
