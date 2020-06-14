#pragma once

#include <iostream>
#include <string>

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string error);
};