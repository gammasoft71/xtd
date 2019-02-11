cmake_minimum_required(VERSION 3.3)

project(wconsole1)
find_package(xtd.console REQUIRED)
add_executable(${PROJECT_NAME} src/wconsole1.cpp)
target_link_libraries(${PROJECT_NAME} xtd.console)
