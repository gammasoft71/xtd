cmake_minimum_required(VERSION 3.20)

project(image_png)
find_package(xtd REQUIRED)
add_sources(README.md src/image_png.cpp)
resource(gammasoft_png resources/gammasoft.png)
target_type(CONSOLE_APPLICATION)
