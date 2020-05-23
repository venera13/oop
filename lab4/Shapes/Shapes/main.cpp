#include "stdafx.h"
#include "ConsoleCommand.h"

using namespace std;

int main()
{
	CConsoleCommand consoleCommand;
	consoleCommand.DoCommand(cin);
	auto shapeWithMaxArea = consoleCommand.GetShapeWithMaxArea();
	auto shapeWithMinPerimeter = consoleCommand.GetShapeWithMinPerimeter();
	cout << "Shape with max area:\n";
	cout << consoleCommand.GetShapeInfo(shapeWithMaxArea);
	cout << "Shape with min perimeter:\n";
	cout << consoleCommand.GetShapeInfo(shapeWithMinPerimeter);
	consoleCommand.DrawShapes();

	return false;
}
