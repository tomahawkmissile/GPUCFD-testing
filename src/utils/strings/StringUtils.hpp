#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>
#include <sstream>

class StringUtils {

public:
    std::vector<std::string> StringUtils::split(const std::string &s, const char delimiter);

};

#endif