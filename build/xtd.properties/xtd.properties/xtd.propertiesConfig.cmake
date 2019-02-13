include(CMakeFindDependencyMacro)
include("${CMAKE_CURRENT_LIST_DIR}/xtd.properties.cmake")

get_filename_component(xtd.properties_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(xtd.properties_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

set(xtd.properties_LIBRARIES xtd.properties)
set(xtd.properties_FOUND TRUE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
endif ()
