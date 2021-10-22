cmake_minimum_required(VERSION 3.5)

project(statistics)

include_directories(Include)

file(GLOB SOURCES "Source/*.cpp")

add_executable(statistics ${SOURCES})

set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
