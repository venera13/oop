#include "HTMLDecode.h"

#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

char GetSymbolByEntityName(string const& entityName)
{
	if (entityName == "&quot;")
	{
		return '"';
	}
	else if (entityName == "&apos;")
	{
		return '\'';
	}
	else if (entityName == "&lt;")
	{
		return '<';
	}
	else if (entityName == "&gt;")
	{
		return '>';
	}
	else if (entityName == "&amp;")
	{
		return '&';
	}
	return '\0';
}

string HtmlDecode(string const& html)
{
	int startPosition = 0;
	int endPosition = 0;
	char ch, symbol;
	string resultHtml, entityName;

	for (size_t i = 0; i < html.length(); i++)
	{
		ch = html[i];
		if (ch == '&')
		{
			if (!entityName.empty())
			{
				resultHtml += entityName;
			}
			startPosition = i;
			entityName = ch;
		}
		else if (!entityName.empty())
		{
			entityName += ch;

			if (ch == ';')
			{
				endPosition = i;
				symbol = GetSymbolByEntityName(html.substr(startPosition, endPosition - startPosition + 1));
				if (symbol)
				{
					resultHtml += symbol;
				}
				else
				{
					resultHtml += entityName;
				}

				entityName = "";
			}
		}
		else
		{
			resultHtml += ch;
		}
	}
	return resultHtml;
}
