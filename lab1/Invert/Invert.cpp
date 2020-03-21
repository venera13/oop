#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

typedef array<array<double, 3>, 3> matrix3x3;

struct Args
{
	string inputFileName;
};

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

double GetDeterminant(const matrix3x3& matrix)
{
	return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][2] * matrix[1][0] * matrix[2][1] + matrix[0][1] * matrix[1][2] * matrix[2][0] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][0] * matrix[1][2] * matrix[2][1] - matrix[0][1] * matrix[1][0] * matrix[2][2];
}

matrix3x3 GetIdentityMatrix()
{
	matrix3x3 matrix;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}

optional<matrix3x3> ReadMatrixFromFile(const std::string& inputFileName)
{
	std::ifstream input;
	input.open(inputFileName);
	if (!input.is_open())
	{
		std::cout << "Failed to open '" << inputFileName << "' for reading\n";
		return nullopt;
	}

	matrix3x3 matrix = {
		{ { 0, 0, 0 },
			{ 0, 0, 0 },
			{ 0, 0, 0 } }
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!(input >> matrix[i][j]))
			{
				return nullopt;
			};
		}
	}

	if (input.bad())
	{
		std::cout << "Failed to read data from input file\n";
		return nullopt;
	}
	return matrix;
}

void PrintoutMatrix(matrix3x3& matrix)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << setprecision(3) << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

void DivideRowByCoefficient(matrix3x3& matrix, int matrixRow, double coefficient)
{
	for (int singleRowColumn = 0; singleRowColumn < 3; ++singleRowColumn)
	{
		matrix[matrixRow][singleRowColumn] = matrix[matrixRow][singleRowColumn] / coefficient;
	}
}

void SetToZeroColumnValue(matrix3x3& matrix, int matrixRow, int unitValueRow, double coefficient)
{
	for (int singleRowColumn = 0; singleRowColumn < 3; ++singleRowColumn)
	{
		matrix[matrixRow][singleRowColumn] = matrix[matrixRow][singleRowColumn] - matrix[unitValueRow][singleRowColumn] * coefficient;
	}
}

optional<matrix3x3> InvertMatrix3x3(matrix3x3& matrix)
{
	if (GetDeterminant(matrix) == 0)
	{
		cout << "Matrix hasn't inverse\n";
		return nullopt;
	}

	matrix3x3 invertMatrix = GetIdentityMatrix();

	int unitValueRow = 0;
	double unitValueItem = 0;
	double rowCoefficient = 0;

	for (int arrayColumn = 0; arrayColumn < 3; ++arrayColumn)
	{
		for (int arrayRow = 0; arrayRow < 3; ++arrayRow)
		{
			unitValueItem = matrix[arrayColumn][arrayColumn];
			if (unitValueItem && !unitValueRow)
			{
				DivideRowByCoefficient(matrix, arrayColumn, unitValueItem);
				DivideRowByCoefficient(invertMatrix, arrayColumn, unitValueItem);
			}
			unitValueRow = arrayColumn;

			if (arrayRow != arrayColumn)
			{
				rowCoefficient = matrix[arrayRow][arrayColumn];

				SetToZeroColumnValue(matrix, arrayRow, unitValueRow, rowCoefficient);
				SetToZeroColumnValue(invertMatrix, arrayRow, unitValueRow, rowCoefficient);
			}
			rowCoefficient = 0;
		}
		unitValueItem = 0;
		unitValueRow = 0;
	}
	return invertMatrix;
}

int main(int argc, char* argv[])
{
	auto args = ParseArg(argc, argv);
	if (!args)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: Invert.exe <input file name>\n";
		return 1;
	}

	auto matrix = ReadMatrixFromFile(args->inputFileName);
	if (!matrix)
	{
		return 1;
	}
	auto invertMatrix = InvertMatrix3x3(*matrix);
	if (!invertMatrix)
	{
		return 1;
	}
	PrintoutMatrix(*invertMatrix);
	return 0;
}
