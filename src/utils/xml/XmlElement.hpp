#ifndef XMLELEMENT_H
#define XMLELEMENT_H

#include <string>
#include <vector>
#include <ostream>

#include "../strings/StringUtils.hpp"

class XmlElement {
    
private:
    std::string name;
    std::vector<std::string> params;

    std::vector<XmlElement> parents;
    std::vector<XmlElement> children;

public:
    XmlElement(std::string name, std::vector<std::string> params);
    std::string getName();
    std::vector<std::string> getParams();
    std::string getParam(int index);
    void addParam(std::string p);
    void removeParam(int index);
    std::string getParam(std::string node);
    bool hasParam(std::string name);

    void addParent(XmlElement e);
    void removeParent(XmlElement e);
    std::vector<XmlElement> getParents();
    void addChild(XmlElement e);
    void removeChild(XmlElement e);
    std::vector<XmlElement> getChildren();

    std::string toString();
};

bool &operator==(std::ostream &s, XmlElement const& xmlElement);

#endif