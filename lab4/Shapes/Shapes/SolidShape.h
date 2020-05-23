#pragma once
#include "ISolidShape.h"
#include "Shape.h"

class CSolidShape : public ISolidShape
	, public CShape
{
public:
	CSolidShape() = default;
	virtual ~CSolidShape() = default;

	void SetFillColor(std::string const& color) override;
	std::string GetFillColor() const;

	void SetOutlineColor(std::string const& color) override;
	std::string GetOutlineColor() const;

private:
	std::string m_fillColor = "000000";
};
