#include <iostream>

typedef double Matrix3x3[3][3];

using namespace std;

void InvertMatrix3x3(Matrix3x3 matrix, int matrixSize)
{
	Matrix3x3 unitMatrix = {
		{1.0, 0, 0},
		{0, 1.0, 0},
		{0, 0, 1.0}
	};

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
					unitMatrix[arrayColumns][singleRowColumn] = unitMatrix[arrayColumns][singleRowColumn] / unixStringKoef;
				}

				unixString = arrayColumns;
			}
	
			if (arrayString != arrayColumns)
			{
				stringKoef = matrix[arrayString][arrayColumns];
				
				for (int singleRowColumn = 0; singleRowColumn < matrixSize; ++singleRowColumn)
				{
                    matrix[arrayString][singleRowColumn] = matrix[arrayString][singleRowColumn] - matrix[unixString][singleRowColumn] * stringKoef;
				    unitMatrix[arrayString][singleRowColumn] = unitMatrix[arrayString][singleRowColumn] - unitMatrix[unixString][singleRowColumn] * stringKoef;
				}
				
			}
			stringKoef = 0;
		}
		unixStringKoef = 0;
		unixString = 0;
	}


	for (int i = 0; i < matrixSize; ++i)
	{
		for (int j = 0; j < matrixSize; ++j)
		{
			cout << unitMatrix[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	Matrix3x3 matrix = {
		{1.0, 2.0, -1.0},
		{3.0, 0, 2.0},
	    {4.0, -2.0, 5.0}
	};

	InvertMatrix3x3(matrix, 3);
	return 1;
}
