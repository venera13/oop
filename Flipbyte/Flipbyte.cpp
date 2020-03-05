#include <iostream>
#include <optional>
#include <string>
#include <sstream>

const int numberOfBits = 8;

struct Arg
{
    double number;
};

std::optional<Arg> ParseArg(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: Filebyte.exe <number is decimal numeric system>\n";
        return std::nullopt;
    }

    std::stringstream ss;
    ss << argv[1];

    Arg arg;
    if (!(ss >> arg.number))
    {
        std::cout << "This is not a number!\n";
        return std::nullopt;
    }
    return arg;
}

bool IsIntegerValue(double number)
{
    if (number - (int)number == 0)
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

int main(int argc, char* argv[])
{
    auto arg = ParseArg(argc, argv);
    if (IsDecimalNumeralSystem(arg->number) && arg)
    {
        int numberToBinary[numberOfBits] = {};
        int intNumber = (int)arg->number;

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