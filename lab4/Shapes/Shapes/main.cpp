#include "ConsoleCommand.h"

int main()
{
	CConsoleCommand consoleCommand;
	try
	{
		consoleCommand.DoCommand(cin);
	}
	catch (invalid_argument const& e)
	{
		cout << e.what() << endl;
	}
	return false;
}
