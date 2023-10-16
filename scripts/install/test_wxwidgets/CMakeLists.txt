cmake_minimum_required(VERSION 3.20)
project(test_wxwidgets)

find_package(wxWidgets 3.2.0)
if (wxWidgets_FOUND)
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/wxwidgets.lck)
else()
  file(REMOVE ${CMAKE_CURRENT_BINARY_DIR}/wxwidgets.lck)
endif()
