#include <iostream>
#include <string>

typedef double Matrix3x3[3][3];

using namespace std;

template<typename T, std::size_t N>
constexpr std::size_t SizeOfArray(T(&)[N])
{
	return N;
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

void PrintoutMatrix(Matrix3x3 matrix, int matrixSize)
{
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

int main()
{
	Matrix3x3 matrix = {
		{1.0, 2.0, -1.0},
		{3.0, 0, 2.0},
		{4.0, -2.0, 5.0}
	};
	Matrix3x3 invertMatrix = {};
	int arraySize = SizeOfArray(matrix);
	cout << "size " << arraySize << "\n";

	InvertMatrix3x3(matrix, invertMatrix, 3);
	PrintoutMatrix(matrix, 3);
	return 1;
}
