#include "HTMLDecode.h"

#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

struct Entities
{
	string quotationMark = "&quot;";
	string singleQuote = "&apos;";
	string lessThanSign = "&lt;";
	string greaterThanSign = "&gt;";
	string ampersand = "&amp;";
};

string HtmlDecode(string const& html)
{
	for_each(html.begin(), html.end(), [](char ch) {
		cout << ch << "\n";
	});
	return "html";
}
