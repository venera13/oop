#include "Dictionary.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Dictionary dictionary;
	dictionary.fileName = GetDictionaryFileName(argc, argv);
	dictionary.map = GetDictionaryMap(dictionary);
	DialogWithUser(dictionary);
	return 0;
}
