#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <arrayfire.h>

#include "datatypes/typedefs.hpp"

#include "version.h"

using namespace af;

int main(int argc, char* argv[]) {

    std::cout << "Arrayfire Information:" << std::endl;
    std::cout << std::endl;

    int device = argc > 1 ? atoi(argv[1]) : 0;
    setDevice(device);
    info();

    std::cout << std::endl;
    std::cout << "Done." << std::endl;

    /*
    if(argc<2) {
        cout <<"GPUCFD Version " << GPUCFD_VERSION_MAJOR << "."
            << GPUCFD_VERSION_MINOR << endl;
        return 1;
    } else {
        
    }
    */
}