#include "Canvas.h"
#include "stdafx.h"

using namespace std;

sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

CCanvas::CCanvas(sf::RenderWindow& window)
	: m_window(window)
{
}

void CCanvas::DrawLine(CPoint const& startPoint, CPoint const& endPoint, uint32_t const& lineColor) const
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f((float)startPoint.x(), (float)startPoint.y())),
		sf::Vertex(sf::Vector2f((float)endPoint.x(), (float)endPoint.y()))
	};
	line[0].color = GetValidateColor(lineColor);
	line[1].color = GetValidateColor(lineColor);
	m_window.draw(line, 2, sf::Lines);
}

void CCanvas::DrawFillPoligon(std::vector<CPoint> const& points, uint32_t const& outlineColor, uint32_t const& fillColor) const
{
	sf::ConvexShape shape;
	shape.setPointCount(points.size());
	for (size_t i = 0; i < points.size(); i++)
	{
		shape.setPoint(i, sf::Vector2f((float)points[i].x(), (float)points[i].y()));
	}
	shape.setFillColor(GetValidateColor(fillColor));
	shape.setOutlineThickness(1);
	shape.setOutlineColor(GetValidateColor(outlineColor));
	m_window.draw(shape);
}

void CCanvas::DrawCircle(CPoint const& center, double const& radius, uint32_t const& outlineColor, uint32_t const& fillColor) const
{
	sf::CircleShape circle((float)radius);
	circle.setFillColor(GetValidateColor(fillColor));
	circle.setOutlineThickness(1);
	circle.setOutlineColor(GetValidateColor(outlineColor));
	circle.move((float)(center.x() - radius), (float)(center.y() - radius));
	m_window.draw(circle);
}

