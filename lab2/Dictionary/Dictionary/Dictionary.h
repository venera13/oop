#pragma once
#include "stdafx.h"

using namespace std;

multimap<string, string> GetDictionaryMap();

string GetTranslationWorld(string_view const& world);

void DialogWithUser(multimap<string, string> const& dictionaryMap);