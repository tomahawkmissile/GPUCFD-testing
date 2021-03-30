#ifndef TESTCFD_H
#define TESTCFD_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <arrayfire.h>
#include <cxxopts.hpp>


#define GRID_SIZE 50

class TestCFD {

public:
    f32 TestCFD::getMaxCFL();
    f32 TestCFD::getAverageCFL();
    f32 TestCFD::getMaxDirectionalCFL(array arr, f32 d);
    f32 TestCFD::getMinimumTimeStep(array arr, f32 d);
    f32 TestCFD::computeTimeStep();

    int TestCFD::main();
};

#endif