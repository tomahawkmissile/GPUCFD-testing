#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <arrayfire.h>
#include <cxxopts.hpp>

#include "version.h"

#include "testcfd.hpp"

using namespace af;

void parse(int argc, const char* argv[]);

int main(int argc, const char* argv[]) {
    std::cout << "Version " << GPUCFD_VERSION_MAJOR << "." << GPUCFD_VERSION_MINOR << std::endl;

    parse(argc, argv);
}

void printArrayFireInformation() {
    int deviceCount = getDeviceCount();

    std::cout << "Arrayfire information:" << std::endl;
    std::cout << std::endl;

    for(int i=0;i<deviceCount;i++) {
        setDevice(i);
        info();
    }

    std::cout << std::endl;
    std::cout << "done." << std::endl;
}

void parse(int argc, const char* argv[]) {
    try {
        cxxopts::Options options("GPUCFD", "ArrayFire based program");
        options.add_options()
        ("d,device","choose device",cxxopts::value<std::string>())
        ("g,debug", "enable debug messages",cxxopts::value<bool>() -> default_value("false"));

        auto result = options.parse(argc, argv);

        try {
            bool debugEnabled = result["debug"].as<bool>();
            if(debugEnabled) printArrayFireInformation();
        } catch (const cxxopts::OptionException& e) {}

    } catch (const cxxopts::OptionException& e) {
        std::cout << "error parsing options: " << e.what() << std::endl;
        exit(1);
    }
}
