#pragma once
#include "IShape.h"

class CShape : virtual public IShape
{
public:
	void SetOutlineColor(std::string const& color) override;
	std::string GetOutlineColor() const override;

private:
	std::string m_outlineColor = "000000";
};