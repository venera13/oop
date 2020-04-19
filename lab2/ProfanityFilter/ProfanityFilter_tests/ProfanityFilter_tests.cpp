#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../ProfanityFilter/ProfanityFilter.h"

void SetCompare(set<string> const& firstSet, set<string> const& secondSet)
{
	CHECK(firstSet.size() == secondSet.size());
	CHECK(equal(firstSet.begin(), firstSet.end(), secondSet.begin()));
}

SCENARIO("Check filter file")
{
	WHEN("filter file is empty")
	{
		string inputFileName = "empty.txt";
		istringstream invalidWords;
		set<string> invalidWordsListTestSet;
		string word;
		invalidWords >> word;
		invalidWordsListTestSet.insert(word);
		THEN("output stream is also empty")
		{
			auto invalidWordsList = *GetInvalidWordsList(inputFileName);
			SetCompare(invalidWordsList, invalidWordsListTestSet);
		}
	}
	WHEN("filter file is correct")
	{
		string inputFileName = "correctFilterFile.txt";
		istringstream invalidWords("joker дурак глупый");
		set<string> invalidWordsListTestSet;
		string word;
		while (invalidWords.good())
		{
			invalidWords >> word;
			invalidWordsListTestSet.insert(word);
		}
		THEN("output set is also correct")
		{
			auto invalidWordsList = *GetInvalidWordsList(inputFileName);
			SetCompare(invalidWordsList, invalidWordsListTestSet);
		}
	}
	WHEN("filter file is missing")
	{
		string inputFileName = "none.txt";
		THEN("output set is also correct")
		{
			auto invalidWordsList = GetInvalidWordsList(inputFileName);
			CHECK(invalidWordsList == nullopt);
		}
	}
}
SCENARIO("Check filter message")
{
	istringstream invalidWords("joker дурак villain");
	set<string> invalidWordsList;
	string word;
	while (invalidWords.good())
	{
		invalidWords >> word;
		invalidWordsList.insert(word);
	}

	WHEN("input message is correct")
	{
		istringstream input("I am a Joker.\nI am a villain.\n");
		ostringstream output;
		THEN("output message is also correct")
		{
			GetFilterMessage(input, output, invalidWordsList);
			CHECK(input.eof());
			CHECK(output.str() == "I am a .\nI am a .\n");
		}
	}
	WHEN("input message is empty")
	{
		istringstream input;
		ostringstream output;
		THEN("output message is also empty")
		{
			GetFilterMessage(input, output, invalidWordsList);
			CHECK(input.eof());
			CHECK(output.str() == "");
		}
	}

}