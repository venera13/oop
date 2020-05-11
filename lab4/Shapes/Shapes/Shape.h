#pragma once
#include "IShape.h"

class CShape : virtual public IShape
{
public:
	void SetOutlineColor(string const& color) override;
	string GetOutlineColor() const override;

private:
	string m_outlineColor = "000000";
};