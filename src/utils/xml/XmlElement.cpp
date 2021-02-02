#include "XmlElement.hpp"

XmlElement::XmlElement(std::string name, std::vector<std::string> params) {
    this->name = name;
    this->params = params;
}

std::string XmlElement::getName() {
    return this->name;
}
std::vector<std::string> XmlElement::getParams() {
    return this->params;
}
std::string XmlElement::getParam(int index) {
    return (this->params).at(index);
}
void XmlElement::addParam(std::string p) {
    (this->params).push_back(p);
}
void XmlElement::removeParam(int index) {
    (this->params).erase((this->params).begin() + index);
}
std::string XmlElement::getParam(std::string node) {
    for(std::string param : this->params) {
        param = param.replace(param.begin(),param.end(),"\"", "");
        std::vector<std::string> splitStr = split(param,'\'');
        try {
            if(!splitStr.at(0).compare(node)) return splitStr.at(1);
        } catch(int e) {}
    }
    throw 1; //Nothing found
}
bool XmlElement::hasParam(std::string name) {
    try {
        this->getParam(name);
    } catch(int e) { return false; }
    return true;
}

void XmlElement::addParent(XmlElement e) {
    this->parents.push_back(e);
}
void XmlElement::removeParent(XmlElement e) {
    for(int i=0;i<parents.size();i++) {
        if(parents.at(i) == e) {
            (this->parents).erase((this->parents).begin() + i);
            break;
        }
    }
}
std::vector<XmlElement> XmlElement::getParents() {
    return this->parents;
}
void XmlElement::addChild(XmlElement e) {
    this->children.push_back(e);
}
void XmlElement::removeChild(XmlElement e) {
    for(int i=0;i<children.size();i++) {
        if(children.at(i) == e) {
            (this->children).erase((this->children).begin() + i);
            break;
        }
    }
}
std::vector<XmlElement> XmlElement::getChildren() {
    return this->children;
}
std::string XmlElement::toString() {
    std::string s1 = "Name="+this->getName()+", Parameters=";
    std::string params = "[ ";
    for(std::string p:this->getParams()) params += p + ", ";
    params += "]";
    return s1+params;
}


bool& operator==(XmlElement const &s, XmlElement const& xmlElement) {
    return s==xmlElement;
}
