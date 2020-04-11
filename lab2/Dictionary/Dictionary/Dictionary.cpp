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
			continue;
		}
		resultMap.insert(pair<string, string>(words[0], words[1]));
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
		cout << "���� " << dictioanaryFileName << " �� ������� ������� ��� ������.\n";
		error = true;
	}

	for (auto& item : newWordsMap)
	{
		output << "\n"
			   << item.first << " " << item.second;
	}
	return error;
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
				AddNewWord(newWords, newWord, inputString);
				cout << "����� �" << newWord << "� ��������� � ������� ��� �" << inputString << "�.\n";
			}
			newWord.clear();
		}
		else if (saveNewWords)
		{
			if (inputString == "Y" || inputString == "y")
			{
				if (SaveNewWords(dictionary.fileName, newWords))
				{
					cout << "��������� ���������. �� ��������.\n";
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
			cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������."
				 << "\n";
			saveNewWords = true;
		}
		else
		{
			string translate = GetTranslate(dictionary.map, inputString);
			if (translate.length() == 0)
			{
				cout << "����������� ����� �" << inputString << "�. ������� ������� ��� ������ ������ ��� ������.\n";
				newWord = inputString;
			}
			else
			{
				output << translate << "\n";
			}
		}
	}
}
