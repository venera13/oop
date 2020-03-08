#include <iostream>
#include <optional>
#include <string>
#include <sstream>

struct Arg
{
    uint8_t byte;
};

std::optional<Arg> ParseArg(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: Filebyte.exe <number is decimal numeric system>\n";
        return std::nullopt;
    }
    if (std::stoi(argv[1]) < std::numeric_limits<uint8_t>::min() || std::stoi(argv[1]) > std::numeric_limits<uint8_t>::max())
    {
        return std::nullopt;
    }
    Arg arg;
    arg.byte = std::stoi(argv[1]);
    if (!arg.byte)
    {
        std::cout << "This is not a number!\n";
        return std::nullopt;
    }
    return arg;
}

void FlipType(uint8_t& byte)
{
    byte = (byte & 0x55) << 1 | (byte >> 1) & 0x55;
    byte = (byte & 0x33) << 2 | (byte >> 2) & 0x33;
    byte = (byte & 0x0F) << 4 | (byte >> 4) & 0x0F;
}

int main(int argc, char* argv[])
{
    auto arg = ParseArg(argc, argv);
    if (!arg)
    {
        return 1;
    }
    FlipType(arg->byte);
    std::cout << static_cast<int>(arg->byte) << "\n";
    return 0;
}