#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../VectorProcessor/VectorProcessor.h"

const auto inf = std::numeric_limits<double>::infinity();

void CompareVectors(const std::vector<double>& firstVector, const std::vector<double>& secondVector)
{
	CHECK(firstVector.size() == secondVector.size());
	REQUIRE(equal(firstVector.begin(), firstVector.end(), secondVector.begin(), [](auto x, auto y) {
		return x == y || (isnan(x) && isnan(y));
	}));
}

SCENARIO("Check input and output streams")
{
	WHEN("input stream is empty")
	{
		std::istringstream input("");
		std::ostringstream output;
		THEN("output stream is also empty")
		{
			auto numbers = GetNumbersVector(input);
			PrintVector(numbers, output);
			CHECK(output.str().empty());
			CHECK(input.eof());
		}
	}

	WHEN("correct input stream")
	{
		std::istringstream input("5 2 0 2.16 -2 3");
		std::ostringstream output;
		THEN("correct output stream")
		{
			auto numbers = GetNumbersVector(input);
			PrintVector(numbers, output);
			CHECK(output.str() == "5 2 0 2.16 -2 3 ");
			CHECK(input.eof());
		}
	}

	WHEN("uncorrect input stream")
	{
		std::istringstream input("  0 string");
		std::ostringstream output;
		THEN("output stream with number only")
		{
			auto numbers = GetNumbersVector(input);
			PrintVector(numbers, output);
			CHECK(output.str() == "0 ");
			CHECK(!input.eof());
		}
	}

	WHEN("uncorrect input stream")
	{
		std::istringstream input("  string 0");
		std::ostringstream output;
		THEN("empty output stream")
		{
			auto numbers = GetNumbersVector(input);
			PrintVector(numbers, output);
			CHECK(output.str() == "");
			CHECK(!input.eof());
		}
	}
}

SCENARIO("Vector Processor")
{
	WHEN("input vector is empty")
	{
		vector<double> numbers = {};
		vector<double> emptyVector = {};
		THEN("output vector also empty")
		{
			VectorProcessor(numbers);
			CHECK(numbers == emptyVector);
		}
	}

	WHEN("min number is null")
	{
		vector<double> numbers = { 3, 9, 0 };
		vector<double> vectorWithInfinity = { inf, inf, NAN };
		THEN("output vector with infinity")
		{
			VectorProcessor(numbers);
			CompareVectors(numbers, vectorWithInfinity);
		}
	}

	WHEN("correct input vector")
	{
		vector<double> numbers = { 5, -2, 3 };
		vector<double> correctVector = { -12.5, 5, -7.5 };
		THEN("output vector also correct")
		{
			VectorProcessor(numbers);
			CompareVectors(numbers, correctVector);
		}
	}
}