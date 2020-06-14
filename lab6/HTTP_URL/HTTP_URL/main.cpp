#include <iostream>
#include <string>
#include "CHttpUrl.h"
#include "CUrlParsingError.h"

int main()
{
	std::string input;
	while (getline(std::cin, input))
	{
		try
		{
			CHttpUrl::CHttpUrl(input);
		}
		catch (const CUrlParsingError& error)
		{
			std::cout << error.what() << std::endl;
		}
	}
}
