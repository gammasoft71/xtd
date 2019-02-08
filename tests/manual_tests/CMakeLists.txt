cmake_minimum_required(VERSION 3.3)

project(manual_tests)

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/manual_tests.cpp)
target_link_libraries(${PROJECT_NAME} console)
