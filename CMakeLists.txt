cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)

# Options
option(XTD_BUILD_LIBRARIES_XTD_CORE "Build xtd.core libraries" ON)
option(XTD_BUILD_LIBRARIES_XTD_DRAWING "Build xtd.drawing libraries" ON)
option(XTD_BUILD_LIBRARIES_XTD_FORMS "Build xtd.forms libraries" ON)
option(XTD_BUILD_LIBRARIES_XTD_TUNIT "Build xtd.tunit libraries" ON)
option(XTD_BUILD_SHARED_LIBRARIES "Build shared libraries" OFF)
option(XTD_BUILD_TESTS_XTD_CORE "Build xtd.core tests" OFF)
option(XTD_BUILD_TESTS_XTD_DRAWING "Build xtd.drawing tests" OFF)
option(XTD_BUILD_TESTS_XTD_FORMS "Build xtd.forms tests" OFF)
option(XTD_BUILD_TESTS_XTD_TUNIT "Build xtd.tunit tests" OFF)
option(XTD_BUILD_TOOL_GUIDGEN_COMMAND_LINE "Build tool guidgen command line" ON)
option(XTD_BUILD_TOOL_GUIDGEN_GUI "Build tool guidgen GUI" ON)
option(XTD_BUILD_TOOL_SLEEPFOR_COMMAND_LINE "Build tool sleepfor command line" ON)
option(XTD_BUILD_TOOL_XTDC_COMMAND_LINE "Build tool xtdc command line" ON)
option(XTD_BUILD_TOOL_XTDC_GUI "Enable tool xtdc-gui GUI" ON)
option(XTD_DOWNLOAD_DOXYGEN "Download and build doxygen from Github" OFF)
option(XTD_ENABLE_COMMAND_REFERENCE_GUIDE_GENERATOR "Enable command Reference Guide Generator" OFF)
option(XTD_ENABLE_COVERAGE "Enable code coverage" OFF)
option(XTD_INSTALL_EXAMPLES "Install examples" ON)
option(XTD_INSTALL_RESOURCES "Install resources" ON)
option(XTD_SET_COMPILER_OPTION_WARNINGS_TO_ALL "Enable compiler option warnings to all" ON)
option(XTD_SET_COMPILER_OPTION_WARNINGS_AS_ERRORS "Enable compiler option warnings as errors" ON)
add_definitions(-D__XTD_INSTALL_PATH__="${CMAKE_INSTALL_PREFIX}")
add_definitions(-D__XTD_RESOURCES_PATH__="${CMAKE_INSTALL_PREFIX}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake)

# incldue xtd_commands
include(scripts/cmake/xtd_commands.cmake)
include(scripts/cmake/xtd_version.cmake)
include(scripts/cmake/update_export.cmake)
include(scripts/cmake/update_version_number.cmake)

# Graphic toolkits definitions
if (WIN32)
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" Windows macOS linux iOS android)
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" wxwidgets msw qt5 fltk)
elseif (APPLE)
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" macOS Windows linux iOS android)
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" wxwidgets cocoa qt5 fltk)
else ()
  choice_options(XTD_NATIVE_OPERATING_SYSTEM "Choose Operating System for native system libraries" linux Windows macOS iOS android)
  choice_options(XTD_NATIVE_GRAPHIC_TOOLKIT "Choose toolkit for native drawing and forms libraries" wxwidgets gtk4 gtk3 qt5 fltk)
endif ()

# Options validations
if (XTD_BUILD_LIBRARIES_XTD_DRAWING AND NOT XTD_BUILD_LIBRARIES_XTD_CORE)
  message(FATAL_ERROR "Build xtd.core libraries must must be set to ON: xtd.drawing depends of xtd.core")
endif ()

if (XTD_BUILD_LIBRARIES_XTD_FORMS AND NOT XTD_BUILD_LIBRARIES_XTD_DRAWING)
  message(FATAL_ERROR "Build xtd.drawing libraries must must be set to ON: xtd.drawing depends of xtd.drawing")
endif ()

if (XTD_BUILD_LIBRARIES_XTD_TUNIT AND NOT XTD_BUILD_LIBRARIES_XTD_CORE)
  message(FATAL_ERROR "Build xtd.core libraries must must be set to ON: xtd.tunit depends of xtd.core")
endif ()

if (XTD_BUILD_TESTS_XTD_CORE AND NOT XTD_BUILD_LIBRARIES_XTD_CORE)
  message(FATAL_ERROR "Build xtd.core libraries must must be set to ON: xtd.core.manual.tests and xtd.core.unit.tests depends of xtd.core")
endif ()

if (XTD_BUILD_TESTS_XTD_CORE AND NOT XTD_BUILD_LIBRARIES_XTD_TUNIT)
  message(FATAL_ERROR "Build xtd.tunit libraries must must be set to ON: xtd.core.unit.tests depends of xtd.tunit")
endif ()

if (XTD_BUILD_TESTS_XTD_DRAWING AND NOT XTD_BUILD_LIBRARIES_XTD_DRAWING)
  message(FATAL_ERROR "Build xtd.drawing libraries must must be set to ON: xtd.drawing.manual.tests and xtd.drawing.unit.tests depends of xtd.drawing")
endif ()

if (XTD_BUILD_TESTS_XTD_DRAWING AND NOT XTD_BUILD_LIBRARIES_XTD_TUNIT)
  message(FATAL_ERROR "Build xtd.tunit libraries must must be set to ON: xtd.drawing.unit.tests depends of xtd.tunit")
endif ()

if (XTD_BUILD_TESTS_XTD_FORMS AND NOT XTD_BUILD_LIBRARIES_XTD_FORMS)
  message(FATAL_ERROR "Build xtd.forms libraries must must be set to ON: xtd.forms.manual.tests and xtd.forms.unit.tests depends of xtd.forms")
endif ()

if (XTD_BUILD_TESTS_XTD_FORMS AND NOT XTD_BUILD_LIBRARIES_XTD_TUNIT)
  message(FATAL_ERROR "Build xtd.tunit libraries must must be set to ON: xtd.forms.unit.tests depends of xtd.tunit")
endif ()

if (XTD_BUILD_TESTS_XTD_TUNIT AND NOT XTD_BUILD_LIBRARIES_XTD_TUNIT)
  message(FATAL_ERROR "Build xtd.tunit libraries must must be set to ON: xtd.tunit.manual.tests and xtd.tunit.unit.tests depends of xtd.tunit")
endif ()

if (XTD_BUILD_TOOL_GUIDGEN_COMMAND_LINE AND NOT XTD_BUILD_LIBRARIES_XTD_CORE)
  message(FATAL_ERROR "Build xtd.core libraries must must be set to ON: guidgen command line tool depends of xtd.core")
endif ()

if (XTD_BUILD_TOOL_GUIDGEN_GUI AND NOT XTD_BUILD_LIBRARIES_XTD_FORMS)
  message(FATAL_ERROR "Build xtd.forms libraries must must be set to ON: guidgen-gui GUI tool depends of xtd.forms")
endif ()

if (XTD_BUILD_TOOL_XTDC_COMMAND_LINE AND NOT XTD_BUILD_LIBRARIES_XTD_CORE)
  message(FATAL_ERROR "Build xtd.core libraries must must be set to ON: xtdc command line tool depends of xtd.core")
endif ()

if (XTD_BUILD_TOOL_XTDC_GUI AND NOT XTD_BUILD_LIBRARIES_XTD_FORMS)
  message(FATAL_ERROR "Build xtd.forms libraries must must be set to ON: xtdc-gu GUI tool depends of xtd.forms")
endif ()

# set core native library
if ("${XTD_NATIVE_OPERATING_SYSTEM}" STREQUAL "Windows")
  set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.win32)
else ()
  set(XTD_CORE_NATIVE_LIBRARY xtd.core.native.unix)
endif ()

# set drawing and forms native library
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "cocoa")
  message(WARNING "Cocoa toolkit is only supported for development, used wxwidgets instead.\nCocoa toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.cocoa)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.cocoa)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "fltk")
  message(WARNING "FLTK toolkit is only supported for xtd framework development, used wxwidgets instead.\nFLTK toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.fltk)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "gtk3")
  message(WARNING "Gtk+3 toolkit is only supported for xtd framework development, used wxwidgets instead.\nGtk+3 toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk3)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk3)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "gtk4")
  message(WARNING "Gttk+4 toolkit is only supported for xtd framework development, used wxwidgets instead.\nGtk+4 toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.gtk4)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.gtk4)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "qt5")
  message(WARNING "Qt5 toolkit is only supported for xtd framework development, used wxwidgets instead.\nQt5 toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.qt5)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.fltk)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "msw")
  message(WARNING "Microsoft Windows toolkit is only supported for xtd framework development, used wxwidgets instead.\nMicrosoft Windows toolkit will be disponible in a future release.")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.win32)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.win32)
endif ()
if ("${XTD_NATIVE_GRAPHIC_TOOLKIT}" STREQUAL "wxwidgets")
  set(XTD_DRAWING_NATIVE_LIBRARY xtd.drawing.native.wxwidgets)
  set(XTD_FORMS_NATIVE_LIBRARY xtd.forms.native.wxwidgets)
endif ()

# Code coverage
if (XTD_ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
  set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} --coverage")
endif ()

# set xtd library type (shared or static)
if (XTD_BUILD_SHARED_LIBRARIES)
  set(XTD_LIBRARY_TYPE SHARED_LIBRARY)
else()
  set(XTD_LIBRARY_TYPE STATIC_LIBRARY)
endif()

if (XTD_BUILD_TESTS_XTD_CORE OR XTD_BUILD_TESTS_XTD_DRAWING OR XTD_BUILD_TESTS_XTD_FORMS OR  XTD_BUILD_TESTS_XTD_TUNIT)
  enable_testing()
endif ()

# Projects
add_projects(docs locale scripts src tests tools themes)

# Updates export file
xtd_update_export_file(src/xtd.3rdparty.call_stack/call_stack_export.h XTD_3RDPARTY_CALL_STACK_EXPORT call_stack_export_)
string(REPLACE "." "_" XTD_CORE_NATIVE_LIBRARY_UPPER ${XTD_CORE_NATIVE_LIBRARY})
string(TOUPPER ${XTD_CORE_NATIVE_LIBRARY_UPPER} XTD_CORE_NATIVE_LIBRARY_UPPER)
xtd_update_export_file(src/${XTD_CORE_NATIVE_LIBRARY}/include/xtd/core_native_export.h ${XTD_CORE_NATIVE_LIBRARY_UPPER}_EXPORT core_native_export_)
xtd_update_export_file(src/xtd.core/include/xtd/core_export.h XTD_CORE_EXPORT core_export_)
string(REPLACE "." "_" XTD_DRAWING_NATIVE_LIBRARY_UPPER ${XTD_DRAWING_NATIVE_LIBRARY})
string(TOUPPER ${XTD_DRAWING_NATIVE_LIBRARY_UPPER} XTD_DRAWING_NATIVE_LIBRARY_UPPER)
xtd_update_export_file(src/${XTD_DRAWING_NATIVE_LIBRARY}/include/xtd/drawing_native_export.h ${XTD_DRAWING_NATIVE_LIBRARY_UPPER}_EXPORT drawing_native_export_)
xtd_update_export_file(src/xtd.drawing/include/xtd/drawing_export.h XTD_DRAWING_EXPORT drawing_export_)
string(REPLACE "." "_" XTD_FORMS_NATIVE_LIBRARY_UPPER ${XTD_FORMS_NATIVE_LIBRARY})
string(TOUPPER ${XTD_FORMS_NATIVE_LIBRARY_UPPER} XTD_FORMS_NATIVE_LIBRARY_UPPER)
xtd_update_export_file(src/${XTD_FORMS_NATIVE_LIBRARY}/include/xtd/forms_native_export.h ${XTD_FORMS_NATIVE_LIBRARY_UPPER}_EXPORT forms_native_export_)

xtd_update_export_file(src/xtd.forms/include/xtd/forms_export.h XTD_FORMS_EXPORT forms_export_)
xtd_update_export_file(src/xtd.tunit/include/xtd/tunit_export.h XTD_TUNIT_EXPORT tunit_export_)
xtd_update_export_file(src/xtd/include/xtd/export.h XTD_EXPORT export_)

# install
install_package()
# override with specific xtd cmake config file
set(XTD_CONFIG_CMAKE_FILE ${CMAKE_CURRENT_BINARY_DIR}/xtdConfig.cmake)
file(WRITE "${XTD_CONFIG_CMAKE_FILE}"
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_modules/xtd_commands.cmake\")\n"
  "set(CMAKE_MODULE_PATH \${CMAKE_MODULE_PATH} \${CMAKE_CURRENT_LIST_DIR}/xtd_modules)\n"
  "\n"
  "set(${PROJECT_NAME}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\")\n"
  "set(${PROJECT_NAME}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\")\n"
  "set(${PROJECT_NAME}_LIBRARIES ${PROJECT_NAME} xtd.3rdparty.call_stack xtd.core xtd.drawing xtd.forms xtd.tunit xtd)\n"
  "set(${PROJECT_NAME}_FOUND TRUE)\n"
)
install(FILES scripts/cmake/xtd_commands.cmake DESTINATION cmake/xtd_modules)
install(FILES scripts/cmake/MacOSXBundleInfo.plist.in DESTINATION cmake/xtd_modules)
if (XTD_INSTALL_RESOURCES)
  install(DIRECTORY resources DESTINATION share/xtd)
endif ()
if (XTD_INSTALL_EXAMPLES)
  install(DIRECTORY examples/. DESTINATION share/xtd/examples)
endif ()
