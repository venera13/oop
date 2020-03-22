#include "stdafx.h"
#include "VectorProcessor.h"

#include <functional>
#include <iterator>
#include <numeric>

using namespace std;

vector<double> GetNumbersVector(istream& input)
{
	return {
		istream_iterator<double>(input), (istream_iterator<double>())
	};
}

void VectorProcessor(vector<double>& numbers)
{
	if (numbers.empty())
	{
		return;
	}
	double multiplier = *max_element(numbers.begin(), numbers.end());
	double divider = *min_element(numbers.begin(), numbers.end());
	transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double number) {
		return number * multiplier / divider;
	});
}

void PrintVector(const vector<double>& numbers, ostream& output)
{
	copy(numbers.begin(), numbers.end(), ostream_iterator<double>(output, " "));
}
