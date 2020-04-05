#include "stdafx.h"
#include "HTMLDecode.h"

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
