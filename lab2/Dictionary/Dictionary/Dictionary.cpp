#include "stdafx.h"
#include "Dictionary.h"

const string DICTIONARY_FILE_PATH = "Dictionary.txt";
const string INPUT_END_TEXT = "...";

multimap<string, string> GetDictionaryMap()
{
	multimap<string, string> resultMap;
	ifstream dictionaryFile;
	dictionaryFile.open(DICTIONARY_FILE_PATH);
	if (dictionaryFile.is_open())
	{
		while (!dictionaryFile.eof())
		{
			string word, translate;
			dictionaryFile >> word;
			dictionaryFile >> translate;
			resultMap.insert(pair<string, string>(word, translate));
		}
	}
	else
	{
		cout << "Error" << "\n";
	}

	return resultMap;
}

string GetTranslationWorld(string_view const& world)
{
	return string();
}

void DialogWithUser(multimap<string, string> const& dictionaryMap)
{
	string inputString;
	while (getline(cin, inputString))
	{
		if (inputString == INPUT_END_TEXT)
		{
			cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << "\n";
			break;
		}
		else
		{
			auto translate = dictionaryMap.find(inputString);
			cout << "cin " << translate->second << "\n";
		}
	
	}
}
