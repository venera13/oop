#pragma once
#include "ICanvas.h"
#include "Point.h"
#include <SFML/Graphics.hpp>

class CCanvas final : public ICanvas
{
public:
	CCanvas(sf::RenderWindow& window);
	void DrawLine(CPoint const& startPoint, CPoint const& endPoint, uint32_t const& lineColor) const override;
	void DrawFillPoligon(std::vector<CPoint> const& points, uint32_t const& outlineColor, uint32_t const& fillColor) const override;
	void DrawCircle(CPoint const& center, double const& radius, uint32_t const& outlineColor, uint32_t const& fillColor) const override;

private:
	sf::RenderWindow& m_window;
};
