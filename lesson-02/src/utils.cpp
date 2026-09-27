#include "utils.hpp"

std::string toupper(const std::string& str)
{
    std::string res{str};
    for (char& ch : res)
    {
        ch = std::toupper(ch);
    }
    return res;
}
