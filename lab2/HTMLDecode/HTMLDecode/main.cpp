#include "HTMLDecode.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	string htmlString = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	HtmlDecode(htmlString);
}
