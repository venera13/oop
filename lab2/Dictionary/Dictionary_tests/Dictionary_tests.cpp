#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../Dictionary/Dictionary.h"
#include <Windows.h>

using namespace std;

void CompareMaps(multimap<string, string> const& firstMap, multimap<string, string> const& secondMap)
{
	for (auto it1 = firstMap.cbegin(), it2 = secondMap.cbegin(); it1 != firstMap.cend(); ++it1, ++it2)
	{
		CHECK(it1->first == it2->first);
		CHECK(it1->second == it2->second);
	}
		
}

SCENARIO("Check input streams")
{
	WHEN("correct input stream")
	{
		int numberArguments = 2;
		char args[][255] = { "C:\\projects\\study\\oop\\lab2\\Dictionary\\x64\\Debug\\Dictionary.exe", "Dictionary.txt" };
		char* str[2];
		str[0] = &args[0][0];
		str[1] = &args[1][0];

		THEN("correct file name")
		{
			string dictionaryFileName = *GetDictionaryFileName(numberArguments, str);
			CHECK(dictionaryFileName == "Dictionary.txt");
		}
	}

	WHEN("input file name is empty")
	{
		int numberArguments = 2;
		char args[][255] = { "C:\\projects\\study\\oop\\lab2\\Dictionary\\x64\\Debug\\Dictionary.exe", "" };
		char* str[2];
		str[0] = &args[0][0];
		str[1] = &args[1][0];

		THEN("output file name is also empty")
		{
			string dictionaryFileName = *GetDictionaryFileName(numberArguments, str);
			CHECK(dictionaryFileName == "");
		}
	}
}

SCENARIO("Check map getting")
{
	WHEN("correct dictionary file")
	{
		string dictionaryFileName = "DictionaryForTest.txt";
		multimap<string, string> testMap = { { "cat", "Кошка" }, { "cat", "Кот" }, { "Hi", "Привет" } };

		THEN("correct dictionary map")
		{
			multimap<string, string> dictionaryMap = GetDictionaryMap(dictionaryFileName);
			CompareMaps(dictionaryMap, testMap);
		}
	}
	WHEN("dictionary file is empty")
	{
		string dictionaryFileName = "EmptyDictionaryForTest.txt";

		multimap<string, string> testMap;

		THEN("dictionary map is also empty")
		{
			multimap<string, string> dictionaryMap = GetDictionaryMap(dictionaryFileName);
			CompareMaps(dictionaryMap, testMap);
		}
	}
	WHEN("uncorrect dictionary file")
	{
		string dictionaryFileName = "UncorrectDictionaryForTest.txt";
		multimap<string, string> testMap = { { "cat", "Кот" }, { "Hi", "Привет" } };

		THEN("dictionary map is equal to nullopt")
		{
			multimap<string, string> dictionaryMap = GetDictionaryMap(dictionaryFileName);
			CompareMaps(dictionaryMap, testMap);
		}
	}
}

SCENARIO("Check dictionary program")
{
	WHEN("correct input stream")
	{
		istringstream input("cat\nSun\nСолнце\n...\nY\n");
		ostringstream output;
		string dictionaryFileName = "DictionaryForDialogTest.txt";

		THEN("correct dialog")
		{
			Dictionary dictionary;
			dictionary.fileName = dictionaryFileName;
			dictionary.map = { { "cat", "Кот" }, { "Hi", "Привет" } };
			DialogWithUser(input, output, dictionary);
			CHECK(output.str() == "Кот\n");
		}
	}
}
