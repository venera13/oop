#include "stdafx.h"
#include "VectorProcessor.h"

using namespace std;

int main(int argc, char* argv[])
{
	auto numbers = GetNumbersVector(cin);
	VectorProcessor(numbers);
	sort(numbers.begin(), numbers.end());
	PrintVector(numbers);
	return 0;
}
