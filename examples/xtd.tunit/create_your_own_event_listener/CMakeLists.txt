cmake_minimum_required(VERSION 3.3)

project(create_your_own_event_listener)
find_package(xtd.tunit REQUIRED)
add_executable(${PROJECT_NAME} src/create_your_own_event_listener.cpp)
target_link_libraries(${PROJECT_NAME} xtd.tunit)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd.tunit")
