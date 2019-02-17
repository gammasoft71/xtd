cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.tunit VERSION 1.0.0)
set(INCLUDES
  include/xtd/__demangle.hpp
  include/xtd/__join__items.hpp
  include/xtd/assert.hpp
  include/xtd/assert_error.hpp
  include/xtd/class_cleanup_attribute.hpp
  include/xtd/class_event_args.hpp
  include/xtd/class_event_handler.hpp
  include/xtd/class_initialize_attribute.hpp
  include/xtd/console_unit_test.hpp
  include/xtd/default_insert_basic_ostream_operator.hpp
  include/xtd/line_info.hpp
  include/xtd/ostream_unit_test.hpp
  include/xtd/settings.hpp
  include/xtd/test.hpp
  include/xtd/registered_test_class.hpp
  include/xtd/test_cleanup_attribute.hpp
  include/xtd/test_event_args.hpp
  include/xtd/test_event_handler.hpp
  include/xtd/test_initialize_attribute.hpp
  include/xtd/test_method_attribute.hpp
  include/xtd/test_class.hpp
  include/xtd/test_class_attribute.hpp
  include/xtd/test_state.hpp
  include/xtd/tunit
  include/xtd/tunit.hpp
  include/xtd/unit_test.hpp
)
set(SOURCES
  src/__demangle_gcc.cpp
  src/__demangle_win32.cpp
  src/assert.cpp
  src/test.cpp
  src/test_class.cpp
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
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "xtd/src")

# install
install(DIRECTORY include/xtd/. DESTINATION include/xtd)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "\n"
  "get_filename_component(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
  "get_filename_component(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
  "\n"
  "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME})\n"
  "set(${PROJECT_NAME}_FOUND TRUE)\n"
  "\n"
  "set(CMAKE_CXX_STANDARD 17)\n"
  "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
  "if (MSVC)\n"
  "  set(CMAKE_CXX_FLAGS \"\${CMAKE_CXX_FLAGS} /utf-8\")\n"
  "endif ()\n"
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
