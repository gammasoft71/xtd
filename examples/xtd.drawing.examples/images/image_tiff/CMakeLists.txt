cmake_minimum_required(VERSION 3.20)

project(image_tiff)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image_tiff.cpp)
resource(gammasoft_tiff resources/gammasoft.tiff)
target_type(CONSOLE_APPLICATION)
