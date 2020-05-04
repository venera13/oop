#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(string const& commandLine);
};
