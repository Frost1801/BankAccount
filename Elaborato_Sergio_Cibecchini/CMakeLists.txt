cmake_minimum_required(VERSION 3.20)
project(Elaborato_Sergio_Cibecchini)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(Elaborato_Sergio_Cibecchini main.cpp Interface.cpp Interface.h Account.cpp Account.h testInterface.cpp testAccount.cpp)

target_link_libraries(Elaborato_Sergio_Cibecchini gtest gtest_main)