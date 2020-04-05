#pragma once
#include "stdafx.h"

using namespace std;

char GetSymbolByEntityName(string_view const& entityName);

size_t StringDecodingProcess(string const& decodingString, string& resultString, size_t startPosition);

string HtmlDecode(string const& html);