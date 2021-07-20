#ifndef TESTCFD_H
#define TESTCFD_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <arrayfire.h>
#include <cxxopts.hpp>


#define GRID_SIZE 50

class TestCFD {

private:
    double endTime = 10;
    double time = 0;

    double timeStep = 0.0005; //default dt
    float increment;
    const bool adjustableTimeStep = false;

    double avgCFL = 0;
    const double maxCFL = 0.75;

    double errorVal = 1.0;

    float dx=1, dy=1, dz=1;

    af::array ux = af::constant(0, GRID_SIZE, GRID_SIZE+1, GRID_SIZE+1, f64); //velocity arrays
    af::array uy = af::constant(0, GRID_SIZE+1, GRID_SIZE, GRID_SIZE+1, f64);
    af::array uz = af::constant(0, GRID_SIZE+1, GRID_SIZE+1, GRID_SIZE, f64);

    af::array nux = af::constant(0, GRID_SIZE, GRID_SIZE+1, GRID_SIZE+1, f64); //updated velocity arrays
    af::array nuy = af::constant(0, GRID_SIZE+1, GRID_SIZE, GRID_SIZE+1, f64);
    af::array nuz = af::constant(0, GRID_SIZE+1, GRID_SIZE+1, GRID_SIZE, f64);

    af::array p = af::constant(1, GRID_SIZE+1, GRID_SIZE+1, GRID_SIZE+1, f64); //pressure array
    af::array pn = af::constant(1, GRID_SIZE+1, GRID_SIZE+1, GRID_SIZE+1, f64); //updated pressure array

    af::array m = af::constant(0, GRID_SIZE+1, GRID_SIZE+1, GRID_SIZE+1, f64); //error values

public:
    float getMaxCFL();
    float getAverageCFL();
    float getMaxDirectionalCFL(af::array arr, float d);
    float getMinimumTimeStep(af::array arr, float d);
    float computeTimeStep();

    void setBoundaryConditions();

    void printData();
    int main();
};

#endif