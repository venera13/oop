#include "Rational.h"

int GetGreatestCommonDivisor(int firstNumber, int secondNumber) 
{
	int result = 1;
	for (int i = firstNumber; i > 0; i--)
	{
		if (firstNumber % i == 0 && secondNumber % i == 0)
		{
			result = i;
			break;
		}
	}
	return result;
}

CRational::CRational(int numerator, int denominator)
{
	if (denominator == 0)
	{
		m_numerator = 0;
		m_denominator = 1;
	}
	else
	{
		m_numerator = numerator;
		m_denominator = denominator;
		NormalizeRational();
	}
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return (double)m_numerator / (double)m_denominator;
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int integer = m_numerator / m_denominator;
	int newNumerator = m_numerator - integer * m_denominator;

	return std::make_pair(integer, CRational(newNumerator, m_denominator));
}

CRational const CRational::operator+() const
{
	return CRational(m_numerator, m_denominator);
}

CRational const CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational& CRational::operator+=(const CRational& rational)
{
	m_numerator = m_numerator * rational.GetDenominator() + rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	NormalizeRational();
	return *this;
}

CRational& CRational::operator-=(const CRational& rational)
{
	m_numerator = m_numerator * rational.GetDenominator() - rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	NormalizeRational();
	return *this;
}

CRational& CRational::operator*=(const CRational& rational)
{
	m_numerator *= rational.GetNumerator();
	m_denominator *= rational.GetDenominator();
	NormalizeRational();
	return *this;
}

CRational& CRational::operator/=(const CRational& rational)
{
	if (rational.GetNumerator() == 0)
	{
		throw std::invalid_argument("Denominator is zero");
	}
	m_numerator *= rational.GetDenominator();
	m_denominator *= rational.GetNumerator();
	NormalizeRational();
	return *this;
}

void CRational::NormalizeRational()
{
	int gcd = GetGreatestCommonDivisor(m_numerator, m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
	if (m_denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
}

CRational const operator+(const CRational& firstRational, const CRational& secondRational)
{
	int newNumerator = firstRational.GetNumerator() * secondRational.GetDenominator() + secondRational.GetNumerator() * firstRational.GetDenominator();
	int newDenominator = firstRational.GetDenominator() * secondRational.GetDenominator();
	return CRational(newNumerator, newDenominator);
}

CRational const operator-(const CRational& firstRational, const CRational& secondRational)
{
	int newNumerator = firstRational.GetNumerator() * secondRational.GetDenominator() - secondRational.GetNumerator() * firstRational.GetDenominator();
	int newDenominator = firstRational.GetDenominator() * secondRational.GetDenominator();
	return CRational(newNumerator, newDenominator);
}

CRational const operator*(const CRational& firstRational, const CRational& secondRational)
{
	int newNumerator = firstRational.GetNumerator() * secondRational.GetNumerator();
	int newDenominator = secondRational.GetDenominator() * firstRational.GetDenominator();
	return CRational(newNumerator, newDenominator);
}

CRational const operator/(const CRational& firstRational, const CRational& secondRational)
{
	if (secondRational.GetNumerator() == 0)
	{
		throw std::invalid_argument("Denominator is zero");
	}
	int newNumerator = firstRational.GetNumerator() * secondRational.GetDenominator();
	int newDenominator = firstRational.GetDenominator() * secondRational.GetNumerator();
	return CRational(newNumerator, newDenominator);
}

bool operator==(const CRational& firstRational, const CRational& secondRational)
{
	return firstRational.GetNumerator() == secondRational.GetNumerator() && firstRational.GetDenominator() == secondRational.GetDenominator();
}

bool operator!=(const CRational& firstRational, const CRational& secondRational)
{
	return firstRational.GetNumerator() != secondRational.GetNumerator() || firstRational.GetDenominator() != secondRational.GetDenominator();
}

bool operator<(const CRational& firstRational, const CRational& secondRational)
{
	return firstRational.GetNumerator() * secondRational.GetDenominator() < firstRational.GetDenominator() * secondRational.GetNumerator();
}

bool operator<=(const CRational& firstRational, const CRational& secondRational)
{
	return firstRational.GetNumerator() * secondRational.GetDenominator() <= firstRational.GetDenominator() * secondRational.GetNumerator();
}

bool operator>(const CRational& firstRational, const CRational& secondRational)
{
	return firstRational.GetNumerator() * secondRational.GetDenominator() > firstRational.GetDenominator() * secondRational.GetNumerator();
}

bool operator>=(const CRational& firstRational, const CRational& secondRational)
{
	return firstRational.GetNumerator() * secondRational.GetDenominator() >= firstRational.GetDenominator() * secondRational.GetNumerator();
}

std::ostream& operator<<(std::ostream& ostream, const CRational& rational)
{
	ostream << rational.GetNumerator() << "/" << rational.GetDenominator();
	return ostream;
}
