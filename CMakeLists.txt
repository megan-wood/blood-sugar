cmake_minimum_required(VERSION 3.21)
project(BloodSugarProgram)

set(CMAKE_CXX_STANDARD 14)

add_executable(BloodSugarProgram main.cpp input_validation.cpp input_validation.h read_file.cpp read_file.h Entry.cpp Entry.h Date.cpp Date.h range_ave.cpp range_ave.h number_ave.cpp number_ave.h)
