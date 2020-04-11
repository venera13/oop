#pragma once
#include <Windows.h>

#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <map>
#include <optional>

using namespace std;

struct Dictionary
{
	string fileName;
	multimap<string, string> map;
};
