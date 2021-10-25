cmake_minimum_required(VERSION 3.20)
project(temp)

set(CMAKE_CXX_STANDARD 14)

add_executable(temp
        test/M/test.cpp
        test/M/Untitled-1.cpp
        test/Untitled-1.cpp
        11.coo.cpp
        makeDataGen.cpp
        monsterGen.cpp
        Untitled-1.cpp)

add_executable(Untitled-1 test/M/Untitled-1.cpp)
add_executable(makeDataGen makeDataGen.cpp)