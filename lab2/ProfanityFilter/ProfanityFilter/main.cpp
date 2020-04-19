#include "stdafx.h"
#include "ProfanityFilter.h"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto args = ParseArg(argc, argv);
	if (!args)
	{
		return 1;
	}
	auto invalidWordsList = GetInvalidWordsList(args->filterFileName);
	if (!invalidWordsList)
	{
		return 1;
	}
	GetFilterMessage(cin, cout, *invalidWordsList);
}

