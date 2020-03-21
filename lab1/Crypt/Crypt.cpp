#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>

using namespace std;

enum class Mode
{
	Crypt,
	Decrypt
};

struct Args
{
	string inputFileName;
	string outputFileName;
	uint8_t key;
	Mode mode;
};

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

optional<Mode> GetValidatedMode(string cryptType)
{
	if (cryptType == "crypt")
	{
		return Mode::Crypt;
	}
	else if (cryptType == "decrypt")
	{
		return Mode::Decrypt;
	}
	else
	{
		return nullopt;
	}
}

bool ValidateKey(string key)
{
	return all_of(key.begin(), key.end(), isdigit) && (stoi(key) >= 0 && stoi(key) <= 255);
}

optional<Args> ParseArg(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: crypt.exe <crype type> <input file> <output file> <key>\n";
		return nullopt;
	}
	Args args;
	auto cryptMode = GetValidatedMode(argv[1]);
	if (!cryptMode)
	{
		cout << "Crypt mode not valide\n";
		return nullopt;
	}
	args.mode = *cryptMode;

	if (!ValidateKey(argv[4]))
	{
		cout << "Key not valide\n";
		return nullopt;
	}

	args.key = stoi(argv[4]);

	args.inputFileName = argv[2];
	args.outputFileName = argv[3];

	return args;
}

char Encrypt(char ch, uint8_t key)
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

bool Crypter(Args args)
{
	bool error = false;
	ifstream input;
	input.open(args.inputFileName, ios::binary);
	input >> noskipws;
	if (!input.is_open())
	{
		cout << "Failed to open '" << args.inputFileName << "' for reading\n";
		error = true;
	}

	ofstream output;
	output.open(args.outputFileName, ios::binary);
	if (!output.is_open())
	{
		cout << "Failed to open '" << args.outputFileName << "' for writing\n";
		error = true;
	}

	if (args.mode == Mode::Crypt)
	{
		transform(
			istream_iterator<char>(input), istream_iterator<char>(),
			ostream_iterator<char>(output),
			[key = args.key](char ch) {
				return Encrypt(ch, key);
			});
	}
	else
	{
		transform(
			istream_iterator<char>(input), (istream_iterator<char>()),
			ostream_iterator<char>(output),
			[key = args.key](char ch) {
				return Decrypt(ch, key);
			});
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

	if (!Crypter(*args))
	{
		return 1;
	}

	return 0;
}
