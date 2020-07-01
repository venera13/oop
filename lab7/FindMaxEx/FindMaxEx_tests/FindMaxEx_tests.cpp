#define CATCH_CONFIG_MAIN

#include "../../../catch/catch.hpp"

#include "../FindMaxEx/FindMaxEx.h"

struct Athlete
{
	std::string name;
	double height;
	double weight;
};

bool IsLessHeight(const Athlete& firstAthlete, const Athlete& secondAthlete)
{
	return (firstAthlete.height < secondAthlete.height);
}

bool IsLessWeight(const Athlete& firstAthlete, const Athlete& secondAthlete)
{
	return (firstAthlete.weight < secondAthlete.weight);
}

TEST_CASE("array is empty")
{
	std::vector<int> EmptyVector;
	int maxValue;
	CHECK_FALSE(FindMax(EmptyVector, maxValue, std::less<int>()));
}

TEST_CASE("correct int array")
{
	std::vector<int> vectorInt = { 5, 48, 2, 0, 0, 6 };
	int maxValue;
	CHECK(FindMax(vectorInt, maxValue, std::less<int>()));
}

std::vector<Athlete> athletes = {
	{ "Joey", 180.5, 70 },
	{ "Chandler", 179, 69.5 },
	{ "Ross", 175.8, 71.3 }
};

TEST_CASE("find the highest athlete")
{
	Athlete highestAthlete;
	FindMax(athletes, highestAthlete, IsLessHeight);
	CHECK(highestAthlete.name == "Joey");
}

TEST_CASE("find max weight athlete")
{
	Athlete maxWeightAthlete;
	FindMax(athletes, maxWeightAthlete, IsLessWeight);
	CHECK(maxWeightAthlete.name == "Ross");
}
