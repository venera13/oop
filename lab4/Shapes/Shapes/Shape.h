#pragma once
#include "IShape.h"

class CShape : virtual public IShape
{
public:
	CShape() = default;
	~CShape() = default;

	void SetOutlineColor(string const& color);
	string GetOutlineColor() const;

private:
	string m_outlineColor = "000000";
};