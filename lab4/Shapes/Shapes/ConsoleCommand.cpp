#include "ConsoleCommand.h"
#include "LineSegment.h"
#include "Point.h"
#include "Shape.h"
#include "SolidShape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

void CConsoleCommand::DoCommand(string const& commandLine)
{
	vector<string> command;
	boost::split(command, commandLine, is_any_of(" "), token_compress_on);

	if (command[0] == "LineSegment" && command.size() == 6)
	{
		CLineSegment lineSegment(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5]);
		cout << lineSegment.ToString();
	}
	else if (command[0] == "Triangle" && command.size() == 9)
	{
		CTriangle triangle(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8]);
		cout << triangle.ToString();
	}
	else if (command[0] == "Rectangle" && command.size() == 7)
	{
		CRectangle rectangle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6]);
		cout << rectangle.ToString();
	}
	else if (command[0] == "Circle" && command.size() == 6)
	{
		CCircle circle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5]);
		cout << circle.ToString();
	}
}
