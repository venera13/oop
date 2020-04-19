#pragma once
#include "stdafx.h"

optional<Args> ParseArg(int argc, char* argv[]);

string StringToLowerCase(string const& inputString);

optional<set<string>> GetInvalidWordsList(const string& inputFileName);

void GetFilterMessage(istream& input, ostream& output, const set<string>& invalidWordsList);

bool CheckWordICensorial(const string& word, const set<string>& invalidWordsList);