#include "testcfd.hpp"

using namespace af;

double endTime = 10;
double time = 0;

double timeStep = 0.0005; //default dt
const bool adjustableTimeStep = false;

double avgCFL = 0;
const double maxCFL = 0.75;

float dx=1, dy=1, dz=1;

array ux = constant(0, GRID_SIZE, GRID_SIZE+1, GRID_SIZE+1, f64); int dx = 0.1; //velocity arrays
array uy = constant(0, GRID_SIZE+1, GRID_SIZE, GRID_SIZE+1, f64); int dy = 0.1;
array uz = constant(0, GRID_SIZE+1, GRID_SIZE+1, GRID_SIZE, f64); int dz = 0.1;

array p = constant(0, GRID_SIZE+1, GRID_SIZE+1, GRID_SIZE+1, f64); //pressure array

f32 getMaxCFL() {
    return max((ux*(timeStep/dx))+(uy*(timeStep/dy))+(uz*(timeStep/dz)));
}
f32 getAverageCFL() {
    return mean((ux*(timeStep/dx))+(uy*(timeStep/dy))+(uz*(timeStep/dz)));
}
f32 getMaxDirectionalCFL(array arr, f32 d) {
    f32 max = max(arr*(timeStep/d));
}
f32 getMinimumTimeStep(array arr, f32 d) { //arr is a velocity array, d is dx, dy, or dz
    f32 max = getMaxDirectionalCFL(arr,d);
    return min((max*d)/arr);
}
f32 computeTimeStep() {
    f32 tx = getMinimumTimeStep(ux,dx);
    f32 ty = getMinimumTimeStep(uy,dy);
    f32 tz = getMinimumTimeStep(uz,dz);
    array t(1,3,(f32[]){tx,ty,tz});
    if(min(t) < timeStep) {
        return min(t);
    } else {
        return timeStep;
    }
}

int main() {

    int i,j,k; //Iteration vars
    float Re = 3200.0; //Reynold's number

    int iterations = 0;
    while(time <= maxTimeStep) {
        f32 increment = computeTimeStep();
        time += (time+increment>endTime ? endTime-time : increment); //Ensure simulation does not pass endTime

        //Insert CFD code here

        if(iterations % 1000 == 0) {
            std::cout << "Time incremenent is: " << increment << std::endl;
            std::cout << "Time is: " << time << std::endl;
            std::cout << "Max CFL is: " << getMaxCFL() << " | " << "Average CFL is: " << getAverageCFL() << stl::endl;
        }
        iterations++;
    }
}