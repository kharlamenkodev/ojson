cmake_minimum_required(VERSION 3.1...3.14)

project(ojson VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(nlohmann_json 3.2.0 REQUIRED)

if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()