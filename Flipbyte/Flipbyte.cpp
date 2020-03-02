#include <iostream>
#include <optional>
#include <string>

const int numberOfBits = 8;

bool IsIntegerValue(double number)
{
    if ((number || number == 0) && (number - (int)number == 0))
    {
        return true;
    }
    return false;
}

bool IsDecimalNumeralSystem(double number)
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

void GetBinaryNumber(int number, int *arr)
{
    for (int i = 0; i < numberOfBits; i++)
    {
        arr[i] = (number >> i) & 1;
    }
}

int GetDecimalNumberNumber(int *arr)
{
    int result = 0;
    int coef = 1;
    for (int i = numberOfBits - 1; i >= 0; i--)
    {
        int numberSum = arr[i] * coef;
        result += numberSum;
        coef *= 2;
    }
    return result;
}

int main()
{
    double number;
    std::cout << "Enter a integer number: ";
    std::cin >> number;
    if (!number && number != 0)
    {
        std::cout << "This number is not an integer!\n";
        return 1;
    }
    
    if (IsDecimalNumeralSystem(number))
    {
        int numberToBinary[numberOfBits] = {};
        int intNumber = (int)number;

        GetBinaryNumber(intNumber, numberToBinary);
        int result = GetDecimalNumberNumber(numberToBinary);
        std::cout << result << "\n";
    }
    else
    {
        std::cout << "This number is not in the decimal numeral system.\n";
        return 1;
    }
    return 0;
}