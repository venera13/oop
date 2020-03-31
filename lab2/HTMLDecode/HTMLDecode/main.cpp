#include "HTMLDecode.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: HTMLDecode.exe <html string>\n";
		return 1;
	}
	string htmlString = argv[1];
	string resultHtml;
	resultHtml = HtmlDecode(htmlString);
	cout << resultHtml;
}
