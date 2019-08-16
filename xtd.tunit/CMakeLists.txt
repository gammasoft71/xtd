cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.tunit VERSION 1.0.0)
set(INCLUDES
  include/xtd/__console_color.hpp
  include/xtd/__demangle.hpp
  include/xtd/__tunit_join__items.hpp
  include/xtd/abort_error.hpp
  include/xtd/assert.hpp
  include/xtd/assert_error.hpp
  include/xtd/assume.hpp
  include/xtd/base_assert.hpp
  include/xtd/class_cleanup_attribute.hpp
  include/xtd/class_event_args.hpp
  include/xtd/class_initialize_attribute.hpp
  include/xtd/collection_assert.hpp
  include/xtd/collection_assume.hpp
  include/xtd/collection_valid.hpp
  include/xtd/console_unit_test.hpp
  include/xtd/default_insert_basic_ostream_operator.hpp
  include/xtd/default_main.hpp
  include/xtd/directory_assert.hpp
  include/xtd/directory_assume.hpp
  include/xtd/directory_valid.hpp
  include/xtd/event_listener.hpp
  include/xtd/file_assert.hpp
  include/xtd/file_assume.hpp
  include/xtd/file_valid.hpp
  include/xtd/ignore_error.hpp
  include/xtd/line_info.hpp
  include/xtd/main_page.hpp
  include/xtd/ostream_event_listener.hpp
  include/xtd/ostream_unit_test.hpp
  include/xtd/settings.hpp
  include/xtd/string_assert.hpp
  include/xtd/string_assume.hpp
  include/xtd/string_valid.hpp
  include/xtd/test.hpp
  include/xtd/registered_test_class.hpp
  include/xtd/test_cleanup_attribute.hpp
  include/xtd/test_event_args.hpp
  include/xtd/test_initialize_attribute.hpp
  include/xtd/test_method_attribute.hpp
  include/xtd/test_class.hpp
  include/xtd/test_class_attribute.hpp
  include/xtd/test_state.hpp
  include/xtd/tunit
  include/xtd/tunit.hpp
  include/xtd/tunit_event_args.hpp
  include/xtd/unit_test.hpp
  include/xtd/valid.hpp
  include/xtd/xtd.tunit
  include/xtd/xtd.tunit.hpp
)
set(SOURCES
  src/__console_color_gcc.cpp
  src/__console_color_win32.cpp
  src/__demangle_gcc.cpp
  src/__demangle_win32.cpp
  src/base_assert.cpp
  src/test.cpp
  src/test_class.cpp
  src/unit_test.cpp
)
source_group(include FILES ${INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif ()

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
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
