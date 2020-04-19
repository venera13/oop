#include "ProfanityFilter.h"

optional<Args> ParseArg(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: ProfanityFilter.exe <filter file name>\n";
		return nullopt;
	}
	Args args;
	args.filterFileName = argv[1];
	return args;
}

string StringToLowerCase(string const& inputString)
{
	string stringToLowerCase = inputString;
	transform(stringToLowerCase.begin(), stringToLowerCase.end(), stringToLowerCase.begin(), ::tolower);
	return stringToLowerCase;
}

optional<set<string>> GetInvalidWordsList(const string& inputFileName)
{
	ifstream input;
	input.open(inputFileName);
	if (!input.is_open())
	{
		cout << "Failed to open '" << inputFileName << "' for reading\n";
		return nullopt;
	}
	string word;
	set<string> invalidWordsList;
	while (input.good())
	{
		input >> word;
		invalidWordsList.insert(StringToLowerCase(word));
	}

	return invalidWordsList;
}

void GetFilterMessage(istream& input, ostream& output, const set<string>& invalidWordsList)
{
	char ch;
	string word;
	while (input.get(ch))
	{
		if (isalpha((unsigned char)ch))
		{
			word += ch;
		}
		else if (word.length() == 0)
		{
			output << ch;
		}
		else if (CheckWordICensorial(word, invalidWordsList))
		{
			output << word << ch;
			word.clear();
		}
		else
		{
			output << ch;
			word.clear();
		}
	}
}

bool CheckWordICensorial(const string& word, const set<string>& invalidWordsList)
{
	return invalidWordsList.find(StringToLowerCase(word)) == invalidWordsList.end();
}
