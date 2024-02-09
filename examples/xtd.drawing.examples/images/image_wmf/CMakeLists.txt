cmake_minimum_required(VERSION 3.20)

project(image_wmf)
find_package(xtd REQUIRED)
add_sources(README.md src/image_wmf.cpp)
resource(gammasoft_wmf resources/gammasoft.wmf)
target_type(CONSOLE_APPLICATION)
