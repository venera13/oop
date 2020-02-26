#include <iostream>
#include <optional>
#include <string>

bool IsIntegerValue(double number)
{
    if (number && (number - (int)number == 0))
    {
        return true;
    }
    return false;
}

bool IsDecimalNumeralSystem(double &number)
{
    if (IsIntegerValue(number))
    {
        number = (int)number;
        if (number >= 0 && number <= 255)
        {
            return true;
        }
    }
    return false;
}

using namespace std;
int main()
{
    double number;
    std::cout << "Enter a integer number: ";
    std::cin >> number;
    if (!number)
    {
        std::cout << "This number is NOT INTEGER!\n";
        return 1;
    }
    int numberToBinary[8] = {};
  
    if (IsDecimalNumeralSystem(number))
    {
        int intNumber = (int)number;
        for (int i = 0; i < 8; i++)
        {
            numberToBinary[i] = (intNumber >> i) & 1;
        }
        int result = 0;
        int coef = 1;
        for (int i = 7; i >= 0; i--)
        {
            int numberSum = numberToBinary[i] * coef;
            result += numberSum;
            coef *= 2;
        }
        std::cout << result << "\n";
    }
    else
    {
        std::cout << "This number is NOT in the decimal numeral system.\n";
    }
    return 0;
}

//отзеркаливание полученного числа
//перевод в десятичную систему