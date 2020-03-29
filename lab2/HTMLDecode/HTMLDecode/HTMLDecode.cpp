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
	string newHtml, entityName;

	for (size_t i = 0; i < html.length(); i++)
	{
		ch = html[i];
		if (ch == '&')
		{
			startPosition = i;
			entityName += ch;
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
					newHtml += symbol;
				}
				else
				{
					newHtml += entityName;
				}

				entityName = "";
			}
		}
		else
		{
			newHtml += ch;
		}
	}
	return newHtml;
}
