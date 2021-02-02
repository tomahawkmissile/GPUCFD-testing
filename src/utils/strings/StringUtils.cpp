#include "StringUtils.hpp"

std::vector<std::string> StringUtils::split(const std::string &s, const char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while(getline(ss,item,delimiter)) {
        result.push_back(item);
    }
    return result;
}