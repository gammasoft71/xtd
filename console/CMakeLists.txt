cmake_minimum_required(VERSION 3.3)

# Project
project(console VERSION 1.0.0)
set(INCLUDES
  include/console/__format.hpp
  include/console/__get_err_rdbuf.hpp
  include/console/__get_in_rdbuf.hpp
  include/console/__get_out_rdbuf.hpp
  include/console/__opaque_console.hpp
  include/console/background_color.hpp
  include/console/basic_console.hpp
  include/console/beep.hpp
  include/console/console
  include/console/console.hpp
  include/console/console_color.hpp
  include/console/console_key.hpp
  include/console/console_key_info.hpp
  include/console/console_modifiers.hpp
  include/console/console_special_key.hpp
  include/console/foreground_color.hpp
  include/console/format.hpp
  include/console/reset_color.hpp
)
set(SOURCES
  src/__opaque_console_gcc.cpp
  src/__opaque_console_win32.cpp
)
source_group(include FILES ${INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library properties
add_library(${PROJECT_NAME} STATIC ${INCLUDES} ${SOURCES})
if (MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
endif ()
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> PUBLIC $<INSTALL_INTERFACE:include>)

# install
install(DIRECTORY include/console/. DESTINATION include/console)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/consoleConfig.cmake
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "\n"
  "get_filename_component(CONSOLE_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
  "get_filename_component(CONSOLE_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
  "\n"
  "set(CONSOLE_LIBRARIES console)\n"
  "set(CONSOLE_FOUND TRUE)\n"
  "\n"
  "set(CMAKE_CXX_STANDARD 17)\n"
  "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
  "if (MSVC)\n"
  "  set(CMAKE_CXX_FLAGS \"${CMAKE_CXX_FLAGS} /utf-8\")\n"
  "endif ()\n"
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/consoleConfig.cmake DESTINATION cmake)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
