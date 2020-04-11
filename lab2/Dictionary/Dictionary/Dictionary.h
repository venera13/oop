#pragma once
#include "stdafx.h"

multimap<string, string> GetDictionaryMap(Dictionary const& dictionary);

string GetDictionaryFileName(int argc, char* argv[]);

void AddNewWord(multimap<string, string> const& dictionaryMap, string const& word, string const& tranlate);

void SaveNewWords(string const& dictioanaryFileName, multimap<string, string> const& newWordsMap);

string GetTranslate(multimap<string, string> const& dictionaryMap, string const& worldd);

void DialogWithUser(Dictionary const& dictionary);