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

bool hasInvalidRepeatitions(string input)
{
    std::vector<char> unallowedDouble({'V', 'L', 'D'});

    if (input.empty())
        return false;
    if (input.size() == 1)
        return false;
    int count = 1;
    if (input.size() > 1)
    {
        for (auto i = input.begin(); i != input.end() - 1; i++)
        {
            if (*i == *(i + 1))
            {
                ++count;
                if (count == 2 && std::find(unallowedDouble.begin(), unallowedDouble.end(), *i) != unallowedDouble.end())
                    return true;
                if (count > 3)
                    return true;
            }
            else
            {
                count = 1;
            }
        }
    }

    return false;
}

int romano(std::string input)
{
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
    if (input.size() == 1)
        return convertOne(input[0]);

    if (hasInvalidRepeatitions(input))
        return -1;

    int total = 0;
    for (auto i = input.begin(); i != input.end(); ++i)
    {
        auto current = convertOne(*i);
        // prevent accessing outside the vector
        if (i + 1 != input.end())
        {
            auto next = convertOne(*(i + 1));
            if (next > current)
            {
                if (current == 10 && next > 100)
                {
                    return -1;
                }
                if (current == 5 || current == 50 || current == 500)
                {
                    return -1;
                }
                total += next - current;
                i++;
                continue;
            }
        }
        total += current;
    }

    return total;
}
