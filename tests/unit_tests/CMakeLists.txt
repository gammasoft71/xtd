cmake_minimum_required(VERSION 3.3)

project(unit_tests)

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} src/main.cpp src/console_key_info.cpp)
target_link_libraries(${PROJECT_NAME} console)
add_dependencies(${PROJECT_NAME} catch)

add_test(NAME ${PROJECT_NAME} COMMAND $<TARGET_FILE_NAME:${PROJECT_NAME}> WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)
