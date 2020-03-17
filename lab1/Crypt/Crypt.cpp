#include <iostream>
#include <fstream>
#include <optional>
#include <sstream>
#include <algorithm>

using namespace std;

struct Args
{
    string cryptType;
    string inputFileName;
    string outputFileName;
	string key;
};

optional<Args> ParseArg(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: crypt.exe <crype type> <input file> <output file> <key>\n";
		return nullopt;
	}
	Args args;
	args.cryptType = argv[1];
	args.inputFileName = argv[2];
	args.outputFileName = argv[3];
	args.key = argv[4];
	return args;
}

bool ValidateCrypeType(string cryptType)
{
	return cryptType == "crypt" || cryptType == "decrypt";
}

bool ValidateKey(string key)
{
	return all_of(key.begin(), key.end(), isdigit) && (stoi(key) >= 0 && stoi(key) <= 255);
}

uint8_t MixBits(uint8_t byte)
{
	uint8_t newByte = 0;
	newByte |= (byte & 0b10000000) >> 2;
	newByte |= (byte & 0b01100000) >> 5;
	newByte |= (byte & 0b00011000) << 3;
	newByte |= (byte & 0b00000111) << 2;
	return newByte;
}

uint8_t MixBitsBack(uint8_t byte)
{
	uint8_t newByte = 0;
	newByte |= (byte & 0b11000000) >> 3;
	newByte |= (byte & 0b00100000) << 2;
	newByte |= (byte & 0b00011100) >> 2;
	newByte |= (byte & 0b00000011) << 5;
	return newByte;
}

char Crypt(char ch, uint8_t key)
{
	uint8_t byte = static_cast<uint8_t>(ch);
	byte ^= key;
	byte = MixBits(byte);
	return static_cast<char>(byte);
}

char Decrypt(char ch, uint8_t key)
{
	uint8_t byte = static_cast<uint8_t>(ch);
	byte = MixBitsBack(byte);
	byte ^= key;
	return static_cast<char>(byte);
}

bool InitCrypt(optional<Args> args)
{
	bool error = false; 

	if (!ValidateCrypeType(args->cryptType))
	{
		cout << "Crypt type not valide\n";
		error = true;
	}
	if (!ValidateKey(args->key))
	{
		cout << "Key not valide\n";
		error = true;
	}

	std::ifstream input;
	input.open(args->inputFileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << args->inputFileName << "' for reading\n";
		error = true;
	}

	std::ofstream output;
	output.open(args->outputFileName);
	if (!output.is_open())
	{
		std::cout << "Failed to open '" << args->outputFileName << "' for writing\n";
		error = true;
	}

	for (char ch; input.get(ch); )
	{
		if (args->cryptType == "crypt")
		{
			output.put(Crypt(ch, stoi(args->key)));
		}
		else if(args->cryptType == "decrypt")
		{
			output.put(Decrypt(ch, stoi(args->key)));
		}
	}
	return !error;
}

int main(int argc, char* argv[])
{
    auto args = ParseArg(argc, argv);
	if (!args)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: crypt.exe <crype type> <input file> <output file> <key>\n";
		return 1;
	}

	if (!InitCrypt(args)) 
	{
		return 1;
	};

	return 0;
}