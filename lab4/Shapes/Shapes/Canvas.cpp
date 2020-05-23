#include "Canvas.h"
#include "stdafx.h"

using namespace std;

sf::Color GetValidateColor(std::string color) 
{
	if (color.length() != 6)
	{
		cout << "Incorrect color";
		return sf::Color(0, 0, 0);
	}
	else
	{
		uint32_t newColor = stoi(color);
		uint32_t red = ((newColor / 256) / 256) % 256;
		uint32_t green = (newColor / 256) % 256;
		uint32_t blue = newColor % 256;
		return sf::Color(red, green, blue);
	}
}

CCanvas::CCanvas(sf::RenderWindow& window)
	: m_window(window)
{
}

void CCanvas::DrawLine(CPoint const& startPoint, CPoint const& endPoint, std::string const& lineColor) const
{
	sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f((float)startPoint.x(), (float)startPoint.y())),
		sf::Vertex(sf::Vector2f((float)endPoint.x(), (float)endPoint.y()))
	};
	line->color = GetValidateColor(lineColor);
	m_window.draw(line, 2, sf::Lines);
}

void CCanvas::DrawFillPoligon(std::vector<CPoint> const& points, std::string const& outlineColor, std::string const& fillColor) const
{
	sf::ConvexShape shape;
	shape.setPointCount(points.size());
	for (size_t i = 0; i < points.size(); i++)
	{
		shape.setPoint(i, sf::Vector2f((float)points[i].x(), (float)points[i].y()));
	}
	shape.setFillColor(GetValidateColor(fillColor));
	shape.setOutlineThickness(3);
	shape.setOutlineColor(GetValidateColor(outlineColor));
	m_window.draw(shape);
}

void CCanvas::DrawCircle(CPoint const& center, double const& radius, std::string const& outlineColor, std::string const& fillColor) const
{
	sf::CircleShape circle(radius);
	circle.setFillColor(GetValidateColor(fillColor));
	circle.setOutlineThickness(3);
	circle.setOutlineColor(GetValidateColor(outlineColor));
	circle.move((float)center.x(), (float)center.y());
	m_window.draw(circle);
}

