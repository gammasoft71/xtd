cmake_minimum_required(VERSION 3.20)

project(image_icns)
find_package(xtd REQUIRED)
add_sources(README.md src/image_icns.cpp)
resource(gammasoft_icns resources/gammasoft.icns)
target_type(CONSOLE_APPLICATION)
