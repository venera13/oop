#include <iostream>
#include <fstream>
#include <string>
#include <optional>

using namespace std;

typedef double matrix3x3[3][3];
struct Args
{
	string inputFileName;
};

template<typename T, size_t N>
constexpr size_t SizeOfArray(T(&)[N])
{
	return N;
}

optional<Args> ParseArg(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: Invert.exe <input file name>\n";
		return nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	return args;
}

double GetDeterminant(const matrix3x3 & matrix)
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] +
		matrix[0][2] * matrix[1][0] * matrix[2][1] +
		matrix[0][1] * matrix[1][2] * matrix[2][0] -
		matrix[0][2] * matrix[1][1] * matrix[2][0] -
		matrix[0][0] * matrix[1][2] * matrix[2][1] -
		matrix[0][1] * matrix[1][0] * matrix[2][2];
}

void InitUnixMatrix(matrix3x3 matrix, int matrixSize)
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

bool GetInputMatrix(const std::string& inputFileName, matrix3x3 matrix, int matrixSize)
{
	std::ifstream input;
	input.open(inputFileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << inputFileName << "' for reading\n";
		return false;
	}

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (!(input >> matrix[i][j]))
			{
				return false;
			};
		}
	}

	if (input.bad())
	{
		std::cout << "Failed to read data to input file\n";
		return false;
	}
	
	return true;
}

void PrintoutMatrix(matrix3x3 matrix, int matrixSize)
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

void InvertMatrix3x3(matrix3x3 matrix, matrix3x3 invertMatrix, int matrixSize)
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
	matrix3x3 matrix;
	int arraySize = SizeOfArray(matrix);
	if (!GetInputMatrix(args->inputFileName, matrix, arraySize))
	{
		return 1;
	};

	if (GetDeterminant(matrix) == 0)
	{
		return 1;
	}
	matrix3x3 invertMatrix;

	InvertMatrix3x3(matrix, invertMatrix, arraySize);
	PrintoutMatrix(invertMatrix, arraySize);
	return 0;
}
