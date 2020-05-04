#include "ConsoleCommand.h"
#include "LineSegment.h"
#include "Point.h"

void CConsoleCommand::DoCommand(string const& commandLine)
{
	vector<string> command;
	boost::split(command, commandLine, is_any_of(" "), token_compress_on);

	if (command[0] == "LineSegment" && command.size() == 6)
	{
		CLineSegment lineSegment(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5]);
		cout << lineSegment.ToString();
	}
}
