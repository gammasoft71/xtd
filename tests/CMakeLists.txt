cmake_minimum_required(VERSION 3.3)

project(tests)

if (XTD_WXWIDGETS)
  find_package(wxWidgets REQUIRED)
  include(${wxWidgets_USE_FILE})
  set(XTD_NATIVE_LIBRARY ${wxWidgets_LIBRARIES})
endif ()

add_subdirectory(xtd.forms.manual_tests)
add_subdirectory(xtd.forms.unit_tests)
