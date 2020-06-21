#pragma once
#include <iostream>
#include <sstream>
#include <numeric>

class CRational
{
public:
	CRational(int numerator = 0, int denominator = 1);

	int GetNumerator() const;
	int GetDenominator() const;
	double ToDouble() const;
	std::pair<int, CRational> ToCompoundFraction() const;

	CRational const operator+() const;
	CRational const operator-() const;

	CRational& operator+=(const CRational& rational);
	CRational& operator-=(const CRational& rational);
	CRational& operator*=(const CRational& rational);
	CRational& operator/=(const CRational& rational);

private:
	int m_numerator;
	int m_denominator;
	void NormalizeRational();
};

CRational const operator+(const CRational& firstRational, const CRational& secondRational);
CRational const operator-(const CRational& firstRational, const CRational& secondRational);
CRational const operator*(const CRational& firstRational, const CRational& secondRational);
CRational const operator/(const CRational& firstRational, const CRational& secondRational);
bool operator==(const CRational& firstRational, const CRational& secondRational);
bool operator!=(const CRational& firstRational, const CRational& secondRational);
bool operator<(const CRational& firstRational, const CRational& secondRational);
bool operator<=(const CRational& firstRational, const CRational& secondRational);
bool operator>(const CRational& firstRational, const CRational& secondRational);
bool operator>=(const CRational& firstRational, const CRational& secondRational);
std::ostream& operator<<(std::ostream& ostream, const CRational& rational);