cmake_minimum_required(VERSION 3.10)

project(GPUCFD VERSION 1.0)

add_executable(GPUCFD main.cpp)

configure_file(version.h.in version.h)
target_include_directories(GPUCFD PUBLIC "${PROJECT_BINARY_DIR}")

find_package(ArrayFire)
# To use Unified backend, do the following.
# Unified backend lets you choose the backend at runtime
target_link_libraries(GPUCFD ArrayFire::af)