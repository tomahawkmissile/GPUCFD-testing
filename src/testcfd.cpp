#include "testcfd.hpp"

using namespace af;

float TestCFD::getMaxCFL() {
    float maxUX = max<float>(ux*(timeStep/dx));
    float maxUY = max<float>(uy*(timeStep/dy));
    float maxUZ = max<float>(uz*(timeStep/dz));

    float all[] = {maxUX,maxUY,maxUZ};
    return max<float>(array(1,3,all));
}
float TestCFD::getAverageCFL() {
    float maxUX = max<float>(ux*(timeStep/dx));
    float maxUY = max<float>(uy*(timeStep/dy));
    float maxUZ = max<float>(uz*(timeStep/dz));

    float all[] = {maxUX,maxUY,maxUZ};
    return mean<float>(array(1,3,all));
}
float TestCFD::getMaxDirectionalCFL(array arr, float d) {
    return max<float>(arr*(timeStep/d));
}
float TestCFD::getMinimumTimeStep(array arr, float d) { //arr is a velocity array, d is dx, dy, or dz
    float maximum = getMaxDirectionalCFL(arr,d);
    return min<float>((maximum*d)/arr);
}
float TestCFD::computeTimeStep() {
    float tx = getMinimumTimeStep(ux,dx);
    float ty = getMinimumTimeStep(uy,dy);
    float tz = getMinimumTimeStep(uz,dz);
    float timesteps[] = {tx,ty,tz};
    array t(1,3,timesteps);
    if(min<float>(t) < timeStep) {
        return min<float>(t);
    } else {
        return timeStep;
    }
}

void TestCFD::setBoundaryConditions() {
    ux(af::span, GRID_SIZE) = 1.0;
    ux(af::span, af::span, GRID_SIZE-1) = 1.0;

    //Velocity of 1 at boundary
}

void TestCFD::printData() {
    std::cout << "Time step is: " << increment << std::endl;
    std::cout << "Current time is: " << time << std::endl;
    std::cout << "Max CFL is: " << getMaxCFL() << " | " << "Average CFL is: " << getAverageCFL() << std::endl;
}

int TestCFD::main() {

    int i,j,k; //Iteration vars
    float Re = 3200.0; //Reynold's number

    setBoundaryConditions();

    int iterations = 0;
    while(time <= endTime) {
        if(adjustableTimeStep) {
            increment = computeTimeStep();
        } else {
            increment = timeStep;
        }
        
        time += (time+increment>endTime ? endTime-time : increment); //Ensure simulation does not pass endTime

        //Insert CFD code here
        // ...
        //Transient simulation


        //Solve u-momentum
        


        if(iterations % 1000 == 0) {
            printData();
        }
        if(time == endTime) {
            printData();
            break;
        }
        iterations++;
    }
    std::cout << "End" << std::endl;
}