#include "romano.hpp"

using std::string;

int convertOne(char digit)
{
    switch (digit)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return -1;
    }
}

int romano(std::string input)
{
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    if (input.size() == 1)
    {
        return convertOne(input[0]);
    }
    return -1;
}