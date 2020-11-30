cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.forms.native.qt5 )
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
find_package(Qt5Widgets CONFIG REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
add_include_directories(include)
add_references(xtd.drawing xtd.forms.native Qt5::Widgets)
add_sources(
  include/xtd/xtd.forms.native.qt5.h
  include/xtd/xtd.forms.native.qt5
  src/xtd/forms/native/qt5/forms.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
