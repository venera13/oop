﻿#include <iostream>
#include <optional>
#include <sstream>
#include <string>

struct Arg
{
	uint8_t byte;
};

std::optional<Arg> ParseArg(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: Filebyte.exe <number is decimal numeric system>\n";
		return std::nullopt;
	}
	int inputByte;
	try
	{
		inputByte = std::stoi(argv[1]);
	}
	catch (const std::logic_error&)
	{
		std::cout << "This is not a number!\n";
		return std::nullopt;
	}
	if (inputByte < std::numeric_limits<uint8_t>::min() || inputByte > std::numeric_limits<uint8_t>::max())
	{
		return std::nullopt;
	}
	Arg arg;
	arg.byte = inputByte;
	return arg;
}

void FlipType(uint8_t& byte)
{
	byte = (byte & 0x55) << 1 | (byte >> 1) & 0x55;
	byte = (byte & 0x33) << 2 | (byte >> 2) & 0x33;
	byte = (byte & 0x0F) << 4 | (byte >> 4) & 0x0F;
}

int main(int argc, char* argv[])
{
	auto arg = ParseArg(argc, argv);
	if (!arg)
	{
		return 1;
	}
	FlipType(arg->byte);
	std::cout << static_cast<int>(arg->byte) << "\n";
	return 0;
}
