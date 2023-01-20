cmake_minimum_required(VERSION 3.23)
project(Machine_room_reservation)

set(CMAKE_CXX_STANDARD 14)

add_executable(Machine_room_reservation main.cpp Identity.h Student.cpp Student.h Teacher.cpp Teacher.h Manager.cpp Manager.h GlobalFile.h)
