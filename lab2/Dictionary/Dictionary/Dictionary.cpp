#include "stdafx.h"
#include "Dictionary.h"

const string INPUT_END_TEXT = "...";

void deleteSpaces(string& string)
{
	size_t index;
	size_t strBegin = string.find_first_not_of(' ');
	size_t strEnd = string.find_last_not_of(' ');
	while (((index = string.find(' ')) != std::string::npos) && (index < strBegin))
	{
		string.erase(index, 1);
	}
	while ((index = string.find(' ', strEnd)) != std::string::npos)
	{
		string.erase(index, 1);
	}
}

multimap<string, string> GetDictionaryMap(string const& dictionaryFileName)
{
	multimap<string, string> resultMap;
	string fileString;
	ifstream dictionaryFile(dictionaryFileName);
	regex translatableWordRegex("^[A-Za-z]+$");
	regex translateRegex("^[ј-яа-€Є®]+$");
	while (getline(dictionaryFile, fileString))
	{
		vector<string> words;
		boost::split(words, fileString, is_any_of(" "), token_compress_on);
		string translatablePhrase, translatePhrase;
		for (int i = 0; i < words.size(); i++)
		{
			string word = words[i];
			if (word.empty())
			{
				break;
			}
			else if (regex_match(word, translatableWordRegex))
			{
				translatablePhrase += word;
				translatablePhrase += ' ';
			}
			else if (regex_match(word, translateRegex))
			{
				translatePhrase += word;
				translatePhrase += ' ';
			}
			else
			{
				break;
			}
		}
		deleteSpaces(translatablePhrase);
		deleteSpaces(translatePhrase);
		if (translatablePhrase.empty() || translatePhrase.empty())
		{
			continue;
		}
		resultMap.insert(pair<string, string>(translatablePhrase, translatePhrase));
	}

	dictionaryFile.close();

	return resultMap;
}

optional<string> GetDictionaryFileName(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: Dictionary.exe <dictionary file name>\n";
		return nullopt;
	}

	return argv[1];
}

void AddNewWord(multimap<string, string>& dictionaryMap, string const& word, string const& tranlate)
{
	dictionaryMap.insert(pair<string, string>(word, tranlate));
}

bool SaveNewWords(string const& dictioanaryFileName, multimap<string, string> const& newWordsMap)
{
	bool error = false;
	ofstream output;
	output.open(dictioanaryFileName, ios::app);
	if (!output.is_open())
	{
		cout << "‘айл " << dictioanaryFileName << " не удалось открыть дл€ записи.\n";
		error = true;
	}

	for (auto& item : newWordsMap)
	{
		output << "\n"
			   << item.first << " " << item.second;
	}
	return error;
}

string StringToLowerCase(string const& inputString)
{
	string stringToLowerCase = inputString;
	transform(stringToLowerCase.begin(), stringToLowerCase.end(), stringToLowerCase.begin(), ::tolower);
	return stringToLowerCase;
}

string GetTranslate(multimap<string, string> const& dictionaryMap, string const& world)
{
	auto translate = dictionaryMap.equal_range(StringToLowerCase(world));
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

void DialogWithUser(istream& input, ostream& output, Dictionary const& dictionary)
{
	string inputString, newWord;
	bool saveNewWords = false;
	multimap<string, string> newWords;
	while (getline(input, inputString))
	{
		if (newWord.length() != 0)
		{
			if (inputString.length() != 0)
			{
				AddNewWord(newWords, StringToLowerCase(newWord), inputString);
				cout << "—лово У" << newWord << "Ф сохранено в словаре как У" << inputString << "Ф.\n";
			}
			newWord.clear();
		}
		else if (saveNewWords)
		{
			if (inputString == "Y" || inputString == "y")
			{
				if (SaveNewWords(dictionary.fileName, newWords))
				{
					cout << "»зменени€ сохранены. ƒо свидани€.\n";
				}
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
				translate = GetTranslate(newWords, inputString);
			}
			if (translate.length() == 0)
			{
				cout << "Ќеизвестное слово У" << inputString << "Ф. ¬ведите перевод или пустую строку дл€ отказа.\n";
				newWord = inputString;
			}
			else
			{
				output << translate << "\n";
			}
		}
	}
}
