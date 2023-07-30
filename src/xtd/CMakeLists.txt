cmake_minimum_required(VERSION 3.5)

# Project
project(xtd)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
include(references.cmake)

if (XTD_BUILD_LIBRARIES_XTD_FORMS AND XTD_BUILD_LIBRARIES_XTD_DRAWING AND XTD_BUILD_LIBRARIES_XTD_CORE)
  add_definitions(-D__SYSTEM__REPORT__=1)
  set(SYSTEM_REPORT_FILES include/xtd/system_report.h include/xtd/system_report src/xtd/system_report.cpp)
endif ()

add_sources(
  include/doxygen/cmake_build_options_page.dox
  include/doxygen/cmake_commands_page.dox
  include/doxygen/colors_page.dox
  include/doxygen/containers_appearances_page.dox
  include/doxygen/controls_appearances_page.dox
  include/doxygen/countries_appearances_page.dox
  include/doxygen/cursors_appearances_page.dox
  include/doxygen/dialogs_appearances_page.dox
  include/doxygen/format_page.dox
  include/doxygen/forms_appearances_page.dox
  include/doxygen/groups.dox
  include/doxygen/images_appearances_page.dox
  include/doxygen/license_page.dox
  include/doxygen/main_page.dox
  include/doxygen/menus_ans_toolbars_appearances_page.dox
  include/doxygen/system_colors_page.dox
  include/doxygen/xtd_cmake_examples.dox
  include/doxygen/xtd_core_examples.dox
  include/doxygen/xtd_drawing_examples.dox
  include/doxygen/xtd_forms_examples.dox
  include/doxygen/xtd_tunit_examples.dox
  include/xtd/xtd
  include/xtd/xtd
  include/xtd/xtd.h
  ${SYSTEM_REPORT_FILES}
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
