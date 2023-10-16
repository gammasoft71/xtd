cmake_minimum_required(VERSION 3.20)

project(image_iif)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image_iif.cpp)
resource(gammasoft_iif resources/gammasoft.iif)
target_type(CONSOLE_APPLICATION)
