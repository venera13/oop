#pragma once
#include "Shape.h"
#include <boost/algorithm/string.hpp>
#include <SFML/Graphics.hpp>

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(std::istream& commands);
	std::vector<std::unique_ptr<IShape>>::const_iterator GetShapeWithMaxArea() const;
	std::vector<std::unique_ptr<IShape>>::const_iterator GetShapeWithMinPerimeter() const;
	std::string GetShapeInfo(std::vector<std::unique_ptr<IShape>>::const_iterator shape) const;
	void DrawShapes() const;

private:
	std::vector<std::unique_ptr<IShape>> m_shapes;
};
