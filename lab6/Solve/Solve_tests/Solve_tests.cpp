#define CATCH_CONFIG_MAIN
#include "../../../catch/catch.hpp"

#include "../Solve/Solve.h"

static double epsilon = 1e-5;

bool IsEqual(double x, double y)
{
	return abs(x - y) < epsilon;
}

TEST_CASE("exception invalid argument")
{
	try
	{
		CHECK_THROWS_AS(Solve3(0, 0, 0, 0), std::invalid_argument);
	}
	catch (std::exception const& e)
	{
		CHECK(e.what() == std::string("The coefficient at x^3 cannot be zero"));
	}
}
TEST_CASE("correct arguments, when s < 0, q > 0")
{
	double root1 = 1.8063007167;
	EquationRoots3 roots = Solve3(1, 2, -3, -7);
	CHECK(roots.numRoots == 1);
	CHECK(IsEqual(roots.roots[0], root1));
}
TEST_CASE("correct arguments, when s < 0, q < 0")
{
	EquationRoots3 roots = Solve3(1, 2, 3, -7);
	CHECK(roots.numRoots == 1);
	CHECK(IsEqual(roots.roots[0], 1.6413587055));
}
TEST_CASE("correct arguments, when s < 0, q = 0")
{
	EquationRoots3 roots = Solve3(1, 2, 3, 7);
	CHECK(roots.numRoots == 1);
	CHECK(IsEqual(roots.roots[0], -2.7573294994));
}
TEST_CASE("correct arguments, when s > 0")
{
	EquationRoots3 roots = Solve3(1, 10, 3, -10);
	CHECK(roots.numRoots == 3);
	CHECK(IsEqual(roots.roots[0], -9.577763086));
	CHECK(IsEqual(roots.roots[1], 0.8322683989));
	CHECK(IsEqual(roots.roots[2], -1.2545053129));
}
TEST_CASE("correct arguments, when s = 0")
{
	EquationRoots3 roots = Solve3(1, 0, 0, 0);
	CHECK(roots.numRoots == 2);
	CHECK(IsEqual(roots.roots[0], 0));
}