#pragma once
#include "stdafx.h"

multimap<string, string> GetDictionaryMap(string const& dictionaryFileName);

string StringToLowerCase(string const& inputString);

optional<string> GetDictionaryFileName(int argc, char* argv[]);

void AddNewWord(multimap<string, string> const& dictionaryMap, string const& word, string const& tranlate);

bool SaveNewWords(string const& dictioanaryFileName, multimap<string, string> const& newWordsMap);

string GetTranslate(multimap<string, string> const& dictionaryMap, string const& worldd);

void DialogWithUser(istream& input, ostream& output, Dictionary const& dictionary);
