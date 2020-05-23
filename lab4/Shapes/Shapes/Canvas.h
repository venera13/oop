#pragma once
#include "ICanvas.h"
#include "Point.h"
#include <SFML/Graphics.hpp>

class CCanvas final : public ICanvas
{
public:
	CCanvas(sf::RenderWindow& window);
	void DrawLine(CPoint const& startPoint, CPoint const& endPoint, std::string const& lineColor) const override;
	void DrawFillPoligon(std::vector<CPoint> const& points, std::string const& outlineColor, std::string const& fillColor) const override;
	void DrawCircle(CPoint const& center, double const& radius, std::string const& outlineColor, std::string const& fillColor) const override;

private:
	sf::RenderWindow& m_window;
};
