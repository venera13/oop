#include <iostream>
#include <string>

bool IsIntegerValue(double number)
{
    if (number)
    {
        return number - (int)number == 0;
    }
    else
    {
        return false;
    }
    return true;
}

std::string ToBinary(int number)
{
    std::string result;
    int bin = 0;
    while (number)
    {
        bin = bin * 10 + (number & 1);// ? 1 : 0;
        number >>= 1;
    }
    return result;
}

bool IsDecimalNumeralSystem(double &number)
{
    if (IsIntegerValue(number))
    {
        number = (int)number;
    }
    if (number < 0 || number > 255)
    {
        return false;
    }
    return true;
}

int main()
{
    double number;
    std::cout << "Enter a integer number: ";
    if (std::cin.get())
    {
        return 1;
    }
    std::cin >> number;
  
    if (IsDecimalNumeralSystem(number))
    {
       std::cout << "This number is in the decimal numeral system.\n";
       ToBinary(number);
    }
    else
    {
        std::cout << "This number is NOT in the decimal numeral system.\n";
    }
    return 0;
}

//перевод в двоичную систему
//отзеркаливание полученного числа
//перевод в десятичную систему