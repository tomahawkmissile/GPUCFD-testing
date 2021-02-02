#ifndef XMLPROCESSOR_H
#define XMLPROCESSOR_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "XmlElement.hpp"

class XmlProcessor {

private:
    std::string path;

public:
    XmlProcessor(std::string path);
    std::vector<std::string> readLines();
    std::string convertVectorToString(std::vector<std::string> input);
    std::vector<std::string> smartSpaceSplit(std::string line);
    XmlElement generateElementFromLine(std::string line);
    std::vector<std::string> run();
};

#endif