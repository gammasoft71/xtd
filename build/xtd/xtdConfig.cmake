include(CMakeFindDependencyMacro)
include("${CMAKE_CURRENT_LIST_DIR}/xtd.cmake")

find_package(xtd.strings REQUIRED)
get_filename_component(xtd_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(xtd_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

set(xtd_LIBRARIES xtd)
set(xtd_FOUND TRUE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif ()
