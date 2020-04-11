#include "stdafx.h"
#include "Dictionary.h"

const string INPUT_END_TEXT = "...";

multimap<string, string> GetDictionaryMap(Dictionary const& dictionary)
{
	multimap<string, string> resultMap;
	ifstream dictionaryFile;
	dictionaryFile.open(dictionary.fileName);
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

	return resultMap;
}

string GetDictionaryFileName(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: Dictionary.exe <dictionary file name>\n";
		return "";
	}

	return argv[1];
}

void AddNewWord(multimap<string, string>& dictionaryMap, string const& word, string const& tranlate) 
{
	dictionaryMap.insert(pair<string, string>(word, tranlate));
}

void SaveNewWords(string const& dictioanaryFileName, multimap<string, string> const& newWordsMap)
{
	std::ofstream output;
	output.open(dictioanaryFileName, ios::app);
	if (!output.is_open())
	{
		std::cout << "Failed to open '" << dictioanaryFileName << "' for writing\n";
	}

	for (auto& item : newWordsMap)
	{
		output << "\n" << item.first << " " << item.second;
	}
}

string GetTranslate(multimap<string, string> const& dictionaryMap, string const& world)
{
	auto translate = dictionaryMap.equal_range(world);
	string translateString;
	if (translate.first != translate.second)
	{
		for (auto words = translate.first; words != translate.second; ++words)
		{
			if (words != translate.first)
			{
				translateString += ", ";
			}
			translateString += words->second;
		}
	}
	return translateString;
}

void DialogWithUser(Dictionary const& dictionary)
{
	string inputString, newWord;
	bool saveNewWords = false;
	multimap<string, string> newWords;
	while (getline(cin, inputString))
	{
		if (newWord.length() != 0)
		{
			if (inputString.length() != 0)
			{
				AddNewWord(newWords, newWord, inputString);
				cout << "—лово У" << newWord << "Ф сохранено в словаре как У" << inputString << "Ф.\n";
			}
			newWord.clear();
		}
		else if (saveNewWords)
		{
			if (inputString == "Y" || inputString == "y")
			{
				SaveNewWords(dictionary.fileName, newWords);
				cout << "»зменени€ сохранены. ƒо свидани€.\n";
			}
			break;
		}
		else if (inputString == INPUT_END_TEXT)
		{
			if (!newWords.empty())
			{
				cout << "¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом." << "\n";
				saveNewWords = true;
			}
			else
			{
				break;
			}
		}
		else
		{
			string translate = GetTranslate(dictionary.map, inputString);
			if (translate.length() == 0)
			{
				cout << "Ќеизвестное слово У" << inputString  << "Ф. ¬ведите перевод или пустую строку дл€ отказа.\n";
				newWord = inputString;
			}
			else
			{
				cout << translate << "\n";
			}
		}
	}
}
