cmake_minimum_required(VERSION 3.5.1)
set (CMAKE_CXX_STANDARD 14)

project(Lecture_2)

add_executable(practice src/2-4/src/practice.cpp)

add_executable(car src/2-4/src/car.cpp src/2-4/src/car_main.cpp)

add_executable(astar src/2-astar/src/astar.cpp src/2-astar/src/astar_main.cpp )