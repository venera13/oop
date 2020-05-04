#include "ConsoleCommand.h"

int main()
{
	CConsoleCommand consoleCommand;
	string command;
	while (getline(cin, command))
	{
		consoleCommand.DoCommand(command);
	}
}