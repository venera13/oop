#include "stdafx.h"
#include "HTMLDecode.h"

using namespace std;

const char ENTITY_NAME_START_SYMBOL = '&';
const char ENTITY_NAME_END_SYMBOL = ';';

char GetSymbolByEntityName(string_view const& entityName)
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

size_t StringDecodingProcess(string const& decodingString, string& resultString, size_t startPosition)
{
	size_t endPosition = decodingString.find_first_of(ENTITY_NAME_END_SYMBOL, startPosition);
	string_view entityName = string_view(decodingString).substr(startPosition, endPosition - startPosition + 1);
	char symbol = GetSymbolByEntityName(entityName);
	if (symbol)
	{
		resultString += symbol;
		startPosition = endPosition;
	}
	else
	{
		resultString += decodingString[startPosition];
	}
	return startPosition;
}

string HtmlDecode(string const& html)
{
	char ch;
	string resultHtml;

	for (size_t i = 0; i < html.length(); i++)
	{
		ch = html[i];

		if (ch == ENTITY_NAME_START_SYMBOL)
		{
			i = StringDecodingProcess(html, resultHtml, i);
		}
		else
		{
			resultHtml += ch;
		}
	}
	return resultHtml;
}
