
cmake_minimum_required(VERSION 3.11)

add_library(nlohmann-json INTERFACE)
target_include_directories(nlohmann-json SYSTEM INTERFACE include)