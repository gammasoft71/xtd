cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.tunit VERSION 1.0.0)
set(INCLUDES
  include/xtd/__console_color.h
  include/xtd/__demangle.h
  include/xtd/__tunit_join__items.h
  include/xtd/abort_error.h
  include/xtd/assert.h
  include/xtd/assert_error.h
  include/xtd/assume.h
  include/xtd/base_assert.h
  include/xtd/class_cleanup_attribute.h
  include/xtd/class_event_args.h
  include/xtd/class_initialize_attribute.h
  include/xtd/collection_assert.h
  include/xtd/collection_assume.h
  include/xtd/collection_valid.h
  include/xtd/console_unit_test.h
  include/xtd/default_insert_basic_ostream_operator.h
  include/xtd/default_main.h
  include/xtd/directory_assert.h
  include/xtd/directory_assume.h
  include/xtd/directory_valid.h
  include/xtd/event_listener.h
  include/xtd/file_assert.h
  include/xtd/file_assume.h
  include/xtd/file_valid.h
  include/xtd/ignore_error.h
  include/xtd/line_info.h
  include/xtd/main_page.h
  include/xtd/ostream_event_listener.h
  include/xtd/ostream_unit_test.h
  include/xtd/settings.h
  include/xtd/string_assert.h
  include/xtd/string_assume.h
  include/xtd/string_valid.h
  include/xtd/test.h
  include/xtd/registered_test_class.h
  include/xtd/test_cleanup_attribute.h
  include/xtd/test_event_args.h
  include/xtd/test_initialize_attribute.h
  include/xtd/test_method_attribute.h
  include/xtd/test_class.h
  include/xtd/test_class_attribute.h
  include/xtd/test_state.h
  include/xtd/tunit
  include/xtd/tunit.h
  include/xtd/tunit_event_args.h
  include/xtd/tunit_main.h
  include/xtd/unit_test.h
  include/xtd/valid.h
  include/xtd/xtd.tunit
  include/xtd/xtd.tunit.h
)
set(SOURCES
  src/__console_color_gcc.cpp
  src/__console_color_win32.cpp
  src/__demangle_gcc.cpp
  src/__demangle_win32.cpp
  src/base_assert.cpp
  src/tunit_main.cpp
  src/test.cpp
  src/test_class.cpp
  src/unit_test.cpp
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
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${EXPORT_PROJECT_NAME} DESTINATION lib)
