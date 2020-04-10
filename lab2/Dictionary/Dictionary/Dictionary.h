#pragma once
#include "stdafx.h"

using namespace std;

multimap<string, string> GetDictionaryMap();

void AddNewWord(multimap<string, string> const& dictionaryMap, string const& word, string const& tranlate);

void SaveNewWords(string const& dictioanaryFileName, multimap<string, string> const& newWordsMap);

string GetTranslate(multimap<string, string> const& dictionaryMap, string const& worldd);

void DialogWithUser(multimap<string, string> const& dictionaryMap);