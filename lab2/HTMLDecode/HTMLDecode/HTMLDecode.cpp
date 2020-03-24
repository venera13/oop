#include "HTMLDecode.h"

#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

string HtmlDecode(string const& html)
{
	for_each(html.begin(), html.end(), [](char ch) {
		cout << ch << "\n";
	});
	return "html";
}
