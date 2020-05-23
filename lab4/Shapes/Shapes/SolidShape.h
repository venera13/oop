#pragma once
#include "ISolidShape.h"
#include "Shape.h"

class CSolidShape : public ISolidShape
	, public CShape
{
public:
	CSolidShape() = default;
	virtual ~CSolidShape() = default;

	void SetFillColor(uint32_t const& color) override;
	uint32_t GetFillColor() const;

	void SetOutlineColor(uint32_t const& color) override;
	uint32_t GetOutlineColor() const;

private:
	uint32_t m_fillColor = 000000;
};
