#include <iomanip>
#include <iostream>
#include <fstream>
#include <optional>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;

enum class Mode { Crypt, Decrypt };

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

uint8_t MixBitsBack (uint8_t byte)
{
	uint8_t newByte = 0;
	newByte |= (byte & 0b11000000) >> 3;
	newByte |= (byte & 0b00100000) << 2;
	newByte |= (byte & 0b00011100) >> 2;
	newByte |= (byte & 0b00000011) << 5;
	return newByte;
}

optional<Mode> ValidateMode(string cryptType)
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

bool ValidateKey (string key)
{
	return all_of(key.begin(), key.end(), isdigit) && (stoi(key) >= 0 && stoi(key) <= 255);
}

optional<Args> ParseArg (int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: crypt.exe <crype type> <input file> <output file> <key>\n";
		return nullopt;
	}
	Args args;
	auto cryptMode = ValidateMode(argv[1]);
	if(!cryptMode)
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

char Crypt (char ch, uint8_t key)
{
	cout << ch << " - ";
	uint8_t byte = static_cast<uint8_t>(ch);
	byte ^= key;
	byte = MixBits(byte);
	cout << static_cast<char>(byte) << "\n";
	return static_cast<char>(byte);
}

char Decrypt (char ch, uint8_t key)
{
	cout << ch << " - ";
	uint8_t byte = static_cast<uint8_t>(ch);
	byte = MixBitsBack(byte);
	byte ^= key;
	cout << static_cast<char>(byte) << "\n";
	return static_cast<char>(byte);
}

bool Crypter(const Mode& cryptMode, const string& inputFileName, const string& outputFileName, const uint8_t& cryptKey)
{
	bool error = false; 

	ifstream input;
	input.open(inputFileName, ios::binary);
	if (!input.is_open())
	{
		cout << "Failed to open '" << inputFileName << "' for reading\n";
		error = true;
	}

	ofstream output;
	output.open(outputFileName, ios::binary);
	if (!output.is_open())
	{
		cout << "Failed to open '" << outputFileName << "' for writing\n";
		error = true;
	}

	if (cryptMode == Mode::Crypt)
	{
		transform (
			istream_iterator<uint8_t> (input), (istream_iterator<uint8_t> ()),
			ostream_iterator<uint8_t> (output),
			[key = cryptKey] (uint8_t ch) {
			return Crypt (ch, key);
		});
	}
	else
	{
		transform (
			istream_iterator<char> (input), (istream_iterator<char> ()),
			ostream_iterator<char> (output),
			[key = cryptKey](char ch) {
				return Decrypt (ch, key);
			});
	}

	/*void TransformStream (istream & input, ostream & output, function<char (char)> transform);

	if (cryptMode == Mode::Crypt)
	{
		TransformStream (input, output, [key = cryptKey] (char ch) {
			return Crypt (char, key);
		});
	}
	else
	{
		TransformStream (input, output, [key = cryptKey] (char ch) {
			return Decrypt (char, key);
		});
	}*/
	/*for (char ch; input.get(ch); )
	{
		if (cryptMode == Mode::Crypt)
		{
			output.put(Crypt(ch, cryptKey));
		}
		else if(cryptMode == Mode::Decrypt)
		{
			output.put(Decrypt(ch, cryptKey));
		}
	}*/
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

	if (!Crypter(args->mode, args->inputFileName, args->outputFileName, args->key))
	{
		return 1;
	}

	return 0;
}
