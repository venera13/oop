#pragma once
#include <Windows.h>

#include <fstream>
#include <iostream>
#include <map>
#include <optional>
#include <string>
#include <string_view>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

struct Dictionary
{
	string fileName;
	multimap<string, string> map;
};
