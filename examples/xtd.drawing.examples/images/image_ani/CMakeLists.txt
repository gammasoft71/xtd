cmake_minimum_required(VERSION 3.20)

project(image_ani)
find_package(xtd REQUIRED)
add_sources(README.md src/image_ani.cpp)
resource(gammasoft_ani resources/gammasoft.ani)
target_type(CONSOLE_APPLICATION)
