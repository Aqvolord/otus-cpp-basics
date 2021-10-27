cmake_minimum_required(VERSION 3.10)

project(container CXX)

add_executable(container
    main.cpp
    serialContainer.cpp
    listContainer.cpp
)

set_target_properties(container PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)



#include_directories(Include)

#file(GLOB SOURCES "Source/*.cpp")

#add_executable(container ${SOURCES})

