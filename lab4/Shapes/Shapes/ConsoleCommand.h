#pragma once
#include "Shape.h"
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;
using namespace boost;

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(istream& commands);
	string GetInfoShapeWithMaxArea();
	string GetInfoShapeWithMinPerimeter();

private:
	vector<unique_ptr<IShape>> m_shapes;
};
