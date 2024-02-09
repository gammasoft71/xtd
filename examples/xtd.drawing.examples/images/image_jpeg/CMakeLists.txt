cmake_minimum_required(VERSION 3.20)

project(image_jpeg)
find_package(xtd REQUIRED)
add_sources(README.md src/image_jpeg.cpp)
resource(gammasoft_jpeg resources/gammasoft.jpeg)
target_type(CONSOLE_APPLICATION)
