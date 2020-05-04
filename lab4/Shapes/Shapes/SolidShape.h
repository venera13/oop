#pragma once
#include "ISolidShape.h"

class CSolidShape : virtual public ISolidShape
{
public:
	CSolidShape() = default;
	virtual ~CSolidShape() = default;

	void SetFillColor(string const& color);
	string GetFillColor() const;

private:
	string m_fillColor = "000000";
};
