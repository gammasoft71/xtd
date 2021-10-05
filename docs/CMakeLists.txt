cmake_minimum_required(VERSION 3.3)

# Project
project(docs)
include(../scripts/cmake/xtd_commands.cmake)
include(../scripts/cmake/xtd_version.cmake)

add_sources(
  README.md
  architecture.md
  c++.md
  capitalisation_conventions.md
  class_cleanup.md
  class_initialize.md
  coding_conventions_guidelines.md
  common_design_patterns.md
  console_classes.md
  contact.md
  dependences.md
  design_guidelines.md
  design_guidelines_for_exception.md
  designing_for_extensibility.md
  development_status.md
  development_status_cmake.md
  development_status_themes.md
  development_status_toolkits.md
  development_status_tools.md
  development_status_xtd_core.md
  development_status_xtd_drawing.md
  development_status_xtd_forms.md
  development_status_xtd_tunit.md
  documentation.md
  downloads.md
  examples.md
  extending_test.md
  external_tools_libraries_and_toolkits.md
  first_programs.md
  gallery.md
  gammasoft.md
  general_naming_conventions.md
  getting_started.md
  hierarchy.md
  home.md
  ignore_test_method.md
  introduction.md
  license.md
  line_info.md
  links.md
  member_design_guidelines.md
  names_of_classes_structs_and_interfaces.md
  names_of_libraries_and_dlls.md
  names_of_namespace.md
  names_of_type_members.md
  naming_guidelines.md
  naming_parameters.md
  naming_resources.md
  portability.md
  release_notes.md
  running_test.md
  test_class.md
  test_cleanup.md
  test_initialize.md
  test_method.md
  tools.md
  translations_status.md
  tutorial.md
  type_design_guidelines.md
  unit_testing_classes.md
  usage_guidelines.md
  writing_applications.md
  writing_console_application.md
  writing_gui_application.md
  writing_test_application.md
)
add_sources(
  ../AUTHORS.md
  ../CODE_OF_CONDUCT.md
  ../CONTRIBUTING.md
  ../LICENSE.md
  ../README.md
)
target_type(INTERFACE_LIBRARY)

# Install
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY pictures/examples/. DESTINATION share/xtd/resources/pictures/examples)
endif ()
