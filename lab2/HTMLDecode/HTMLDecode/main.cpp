#include "HTMLDecode.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string htmlString = "&gt;Cat &lt;says&t&gt; &qutot;Meow&quot;. M&amp;M&apos;";
	string newHtml;
	newHtml = HtmlDecode(htmlString);
	cout << newHtml << "\n";
}
