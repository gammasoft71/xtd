cmake_minimum_required(VERSION 3.0)
project(xtd.forms.test)

set(sources
  xtd.forms.test.cpp
  application.h
  control.h
  form.h
  native/application_api.h
  native/control_api.h
  native/form_api.h
  native/application_api_universal.cpp
  native/control_api_universal.cpp
  native/form_api_universal.cpp
)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
link_libraries(${wxWidgets_LIBRARIES})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(xtd.forms.test WIN32 MACOSX_BUNDLE ${sources})
