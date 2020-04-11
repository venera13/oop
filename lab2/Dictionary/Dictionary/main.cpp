#include "Dictionary.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary dictionary;
	dictionary.fileName = *GetDictionaryFileName(argc, argv);
	if (dictionary.fileName.empty())
	{
		return 1;
	}
	dictionary.map = GetDictionaryMap(dictionary.fileName);
	DialogWithUser(cin, cout, dictionary);
	return 0;
}
