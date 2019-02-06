cmake_minimum_required(VERSION 3.3)

# Solution
project(examples)

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
else ()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY}/${CMAKE_CURRENT_BINARY_DIR})
endif ()

add_subdirectory(console1)
add_subdirectory(console2)
add_subdirectory(console_beep)
add_subdirectory(console_color)
add_subdirectory(hello_world)
add_subdirectory(hello_world2)
