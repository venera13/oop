#pragma once
#include "Shape.h"
#include <boost/algorithm/string.hpp>

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(istream& commands);
	string GetInfoShapeWithMaxArea() const;
	string GetInfoShapeWithMinPerimeter() const;

private:
	vector<unique_ptr<IShape>> m_shapes;
};
