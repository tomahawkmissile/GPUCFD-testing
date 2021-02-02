#include "XmlProcessor.hpp"

XmlProcessor::XmlProcessor(std::string path) {
    this->path = path;
}

std::vector<std::string> XmlProcessor::readLines() {
    std::ifstream file;
    file.open(this->path,std::ios::in);
    std::vector<std::string> lines;
    std::string line;
    if(!file.is_open()) {
        throw -1;
    } else {
        while(getline(file,line)) 
        lines.push_back(line);
        file.close();
    }
    return lines;
}
std::string convertVectorToString(std::vector<std::string> input) {
    std::string s;
    for(std::vector<std::string>::const_iterator i = input.begin() ; i != input.end() ; ++i) s+=*i;
    return s;
}
std::vector<std::string> smartSpaceSplit(std::string line) {
    bool inQuotes=false;
    std::vector<std::string> arr;
    int last=0;
    if(line.at(line.length()-1)=='/') line=line.substr(0,line.length()-1);
    for(int i=0;i<line.length();i++) {
        char c = line.at(i);
        switch(c) {
            case '"':
                inQuotes=!inQuotes;
                break;
            case ' ':
                if(!inQuotes && i>0) {
                    arr.push_back(line.substr(last,i));
                    last=i+1;
                    break;
                }
            default:
                if(i==line.length()-2) {
                    arr.push_back(line.substr(last,i+2));
                    return arr;
                }
                break;
        }
    }
    return arr;
}
XmlElement XmlProcessor::generateElementFromLine(std::string line) {
    std::vector<std::string> stuff = this->smartSpaceSplit(line);
    std::string name = stuff.at(0);
    std::vector<std::string>::const_iterator first = stuff.begin()+1;
    std::vector<std::string>::const_iterator last = stuff.end();
    std::vector<std::string> stuff(first,last);
    XmlElement* e = new XmlElement(name,stuff);
    return *e;
}
std::vector<std::string> XmlProcessor::run() {
    std::string file = this->convertVectorToString(this->readLines());
    std::vector<XmlElement> elements;
    std::vector<std::string> 
}