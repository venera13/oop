#include <iostream>
#include <fstream>
#include <string>
#include <optional>

typedef double Matrix3x3[3][3];

using namespace std;

template<typename T, std::size_t N>
constexpr std::size_t SizeOfArray(T(&)[N])
{
	return N;
}

struct Args
{
	std::string inputFileName;
};

std::optional<Args> ParseArg(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: Invert.exe <input file name>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	return args;
}

void InitUnixMatrix(Matrix3x3 matrix, int matrixSize)
{
	for(int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			if(i == j)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
}

bool GetInputMatrix(const std::string& inputFileName, Matrix3x3 matrix)
{
	cout << inputFileName << "\n";
	std::ifstream input;
	input.open(inputFileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << inputFileName << "' for reading\n";
		return false;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			input >> matrix[i][j];
		}
	}
	
	return true;
}

void PrintoutMatrix(Matrix3x3 matrix, int matrixSize)
{
	cout.precision(3);
	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void InvertMatrix3x3(Matrix3x3 matrix, Matrix3x3 invertMatrix, int matrixSize)
{
	InitUnixMatrix(invertMatrix, matrixSize);

	int unixString = 0;
	double unixStringKoef = 0;
	double stringKoef = 0;

	for (int arrayColumns = 0; arrayColumns < matrixSize; ++arrayColumns)
	{
		for (int arrayString = 0; arrayString < matrixSize; ++arrayString)
		{
			unixStringKoef = matrix[arrayColumns][arrayColumns];
			if (unixStringKoef && !unixString)
			{
				for (int singleRowColumn = 0; singleRowColumn < matrixSize; ++singleRowColumn)
				{
					matrix[arrayColumns][singleRowColumn] = matrix[arrayColumns][singleRowColumn] / unixStringKoef;
					invertMatrix[arrayColumns][singleRowColumn] = invertMatrix[arrayColumns][singleRowColumn] / unixStringKoef;
				}

				unixString = arrayColumns;
			}
	
			if (arrayString != arrayColumns)
			{
				stringKoef = matrix[arrayString][arrayColumns];
				
				for (int singleRowColumn = 0; singleRowColumn < matrixSize; ++singleRowColumn)
				{
                    matrix[arrayString][singleRowColumn] = matrix[arrayString][singleRowColumn] - matrix[unixString][singleRowColumn] * stringKoef;
					invertMatrix[arrayString][singleRowColumn] = invertMatrix[arrayString][singleRowColumn] - invertMatrix[unixString][singleRowColumn] * stringKoef;
				}
				
			}
			stringKoef = 0;
		}
		unixStringKoef = 0;
		unixString = 0;
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseArg(argc, argv);
	if (!args)
	{
		std::cout << "Invalid arguments count\n";
		std::cout << "Usage: Invert.exe <input file name>\n";
		return 1;
	}
	Matrix3x3 matrix = {};
	
	if (!GetInputMatrix(args->inputFileName, matrix)) 
	{
		return 1;
	};

	Matrix3x3 invertMatrix = {};
	int arraySize = SizeOfArray(matrix);

	InvertMatrix3x3(matrix, invertMatrix, arraySize);
	PrintoutMatrix(invertMatrix, arraySize);
	return 0;
}
