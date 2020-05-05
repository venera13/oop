#include "ConsoleCommand.h"

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
