cmake_minimum_required(VERSION 3.3)

#Project
project(xtd.forms.manual_tests)
set(SOURCES
  src/manual_tests.cpp
)
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

# Target
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})
target_link_libraries(${PROJECT_NAME} xtd.forms)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/tests")
