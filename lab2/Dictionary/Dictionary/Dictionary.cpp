#include "stdafx.h"
#include "Dictionary.h"

const string INPUT_END_TEXT = "...";

multimap<string, string> GetDictionaryMap(string const& dictionaryFileName)
{
	multimap<string, string> resultMap;
	string fileString;
	ifstream dictionaryFile(dictionaryFileName);
	while (getline(dictionaryFile, fileString))
	{
		vector<string> words;
		boost::split(words, fileString, is_any_of(" "), token_compress_on);
		int countEmptyElem = static_cast<int>(count_if(words.cbegin(), words.cend(), [](string word) { return word.empty(); }));
		if (words.size() != 2 || countEmptyElem != 0)
		{
			cout << "Ќекорректный файл словар€.";
			exit(1);
		}
		resultMap.insert(pair<string, string>(words[0], words[1]));
	}

	dictionaryFile.close();

	return resultMap;
}

string GetDictionaryFileName(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: Dictionary.exe <dictionary file name>\n";
		exit(1);
	}

	return argv[1];
}

void AddNewWord(multimap<string, string>& dictionaryMap, string const& word, string const& tranlate)
{
	dictionaryMap.insert(pair<string, string>(word, tranlate));
}

void SaveNewWords(string const& dictioanaryFileName, multimap<string, string> const& newWordsMap)
{
	ofstream output;
	output.open(dictioanaryFileName, ios::app);
	if (!output.is_open())
	{
		cout << "‘айл " << dictioanaryFileName << " не удалось открыть дл€ записи.\n";
		exit(1);
	}

	for (auto& item : newWordsMap)
	{
		output << "\n"
			   << item.first << " " << item.second;
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
			if (newWords.empty())
			{
				break;
			}
			cout << "¬ словарь были внесены изменени€. ¬ведите Y или y дл€ сохранени€ перед выходом."
				 << "\n";
			saveNewWords = true;
		}
		else
		{
			string translate = GetTranslate(dictionary.map, inputString);
			if (translate.length() == 0)
			{
				cout << "Ќеизвестное слово У" << inputString << "Ф. ¬ведите перевод или пустую строку дл€ отказа.\n";
				newWord = inputString;
			}
			else
			{
				cout << translate << "\n";
			}
		}
	}
}
