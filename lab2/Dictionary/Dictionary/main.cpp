#include "Dictionary.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	multimap<string, string> dictionaryMap = GetDictionaryMap();
	DialogWithUser(dictionaryMap);
	return 0;
}
