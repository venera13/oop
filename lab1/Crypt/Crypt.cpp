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
	return cryptType != "crypt" || cryptType != "decrypt";
}

bool ValidateKey(string key)
{
	cout << key << "\n";
	return all_of(key.begin(), key.end(), isdigit);
}

char Crypt(char ch, uint8_t key)
{
	uint8_t byte = static_cast<uint8_t>(ch);
	byte ^= key;
	return static_cast<char>(byte);
}

char Decrypt(char ch, uint8_t key)
{
	uint8_t byte = static_cast<uint8_t>(ch);
	byte ^= key;
	return static_cast<char>(byte);
}

void InitCrypt(optional<Args> args)
{
	bool error = false; 

	if (!ValidateCrypeType(args->cryptType))
	{
		cout << "Crypt type not valide\n";
		return;
	}
	if (!ValidateKey(args->key))
	{
		cout << "Key not valide\n";
		return;
	}

	std::ifstream input;
	input.open(args->inputFileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << args->inputFileName << "' for reading\n";
		return;
	}

	std::ofstream output;
	output.open(args->outputFileName);
	if (!output.is_open())
	{
		std::cout << "Failed to open '" << args->outputFileName << "' for writing\n";
		return;
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
			//output.put(Decrypt(ch, stoi(args->key)));
		}
	}
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

	InitCrypt(args);

	return 0;
}