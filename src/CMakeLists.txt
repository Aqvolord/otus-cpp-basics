cmake_minimum_required(VERSION 3.5)

project(statistics)

add_subdirectory(Source)

set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

