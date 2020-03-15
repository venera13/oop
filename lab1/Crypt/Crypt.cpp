#include <iostream>
#include <fstream>
#include <optional>
#include <sstream>

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

optional<string> GetValideCrypeType(string cryptType)
{
	if(cryptType != "crypt" || cryptType != "decrypt")
	{
		cout << "Crypt type not valide\n";
		return nullopt;
	}
	return cryptType;
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
	args->cryptType = *GetValideCrypeType(args->cryptType);
	cout << args->cryptType << "\n";
	return 0;
}