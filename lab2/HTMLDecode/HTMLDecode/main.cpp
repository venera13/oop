#include "HTMLDecode.h"
#include <iostream>

using namespace std;

int main()
{
	string htmlString;
	while (getline(cin, htmlString))
	{
		cout << HtmlDecode(htmlString) << endl;
	}
	return 0;
}
