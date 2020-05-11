#pragma once
#include "Shape.h"
#include <boost/algorithm/string.hpp>

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(istream& commands);
	vector<unique_ptr<IShape>>::const_iterator GetShapeWithMaxArea() const;
	vector<unique_ptr<IShape>>::const_iterator GetShapeWithMinPerimeter() const;
	string GetShapeInfo(vector<unique_ptr<IShape>>::const_iterator shape) const;

private:
	vector<unique_ptr<IShape>> m_shapes;
};
