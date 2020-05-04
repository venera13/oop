#pragma once
#include "ISolidShape.h"
#include "Shape.h"

class CSolidShape : public ISolidShape
	, public CShape
{
public:
	CSolidShape() = default;
	virtual ~CSolidShape() = default;

	void SetFillColor(string const& color) override;
	string GetFillColor() const;

	void SetOutlineColor(string const& color) override;
	string GetOutlineColor() const;

private:
	string m_fillColor = "000000";
};
