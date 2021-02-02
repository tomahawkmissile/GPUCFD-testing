#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <arrayfire.h>
#include <cxxopts.hpp>

#include "version.h"

using namespace af;

void parse(int argc, const char* argv[]);

int main(int argc, const char* argv[]) {

    int deviceCount = getDeviceCount();

    std::cout << "Arrayfire Information:" << std::endl;
    std::cout << std::endl;

    for(int i=0;i<deviceCount;i++) {
        setDevice(i);
        info();
    }

    std::cout << std::endl;
    std::cout << "Done." << std::endl;

    parse(argc, argv);
}

void parse(int argc, const char* argv[]) {
    try {
        cxxopts::Options options(argv[0], " - example command line options");
        options.positional_help("[optional args]").show_positional_help();
        options.allow_unrecognised_options().add_options()
        ("solver","choose solver");
    } catch (const cxxopts::OptionException& e) {
        std::cout << "error parsing options: " << e.what() << std::endl;
        exit(1);
    }
}