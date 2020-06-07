#include "Solve.h"

int Sign(const double number)
{
	if (number > 0)
	{
		return 1;
	}
	else if (number < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

EquationRoots3 GetRoots(double a, double b, double c)
{
	EquationRoots3 roots;
	double q = (pow(a, 2) - 3 * b) / 9;
	double r = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;
	double s = pow(q, 3) - pow(r, 2);
	if (s < 0)
	{
		if (q > 0)
		{
			const auto phi = acosh(abs(r) / sqrt(pow(q, 3))) / 3;
			roots.numRoots = 1;
			roots.roots[0] = -2 * Sign(r) * sqrt(q) * cosh(phi) - (a / 3);
		}
		else if (q < 0)
		{
			auto phi = (asinh(abs(r) / sqrt(pow(abs(q), 3)))) / 3;
			roots.numRoots = 1;
			roots.roots[0] = -2 * Sign(r) * sqrt(abs(q)) * cosh(phi) - a / 3;
		}
		else
		{
			roots.numRoots = 1;
			roots.roots[0] = -cbrt(c - pow(a, 3) / 27) - a / 3;
		}
	}
	else if (s > 0)
	{
		auto phi = (acos(r / sqrt(pow(q, 3)))) / 3;
		roots.numRoots = 3;
		roots.roots[0] = -2 * sqrt(q) * cos(phi) - a / 3;
		roots.roots[1] = -2 * sqrt(q) * cos(phi + (2 * M_PI) / 3) - a / 3;
		roots.roots[2] = -2 * sqrt(q) * cos(phi - (2 * M_PI) / 3) - a / 3;
	}
	else
	{
		roots.numRoots = 2;
		roots.roots[0] = -2 * cbrt(r) - a / 3;
		roots.roots[1] = cbrt(r) - a / 3;
	}
	return roots;
}

EquationRoots3 Solve3(double a, double b, double c, double d)
{
	if (a == 0)
	{
		throw std::invalid_argument("The coefficient at x^3 cannot be zero");
	}
	auto roots = GetRoots(b / a, c / a, d / a);
	return roots;
}
