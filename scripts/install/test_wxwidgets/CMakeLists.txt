cmake_minimum_required(VERSION 3.0)
project(test_wxwidgets)

find_package(wxWidgets)
if (wxWidgets_FOUND)
  file(WRITE wxwidgets.lck)
else()
  file(REMOVE wxwidgets.lck)
endif()
