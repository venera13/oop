#include "stdafx.h"
#include "ConsoleCommand.h"

using namespace std;

int main()
{
	CConsoleCommand consoleCommand;
	consoleCommand.DoCommand(cin);
	cout << "Shape with max area:\n";
	cout << consoleCommand.GetInfoShapeWithMaxArea();
	cout << "Shape with min perimeter:\n";
	cout << consoleCommand.GetInfoShapeWithMinPerimeter();

	return false;
}
