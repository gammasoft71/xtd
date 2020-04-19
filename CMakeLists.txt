cmake_minimum_required(VERSION 3.3)

# Solution
project(xtd)
set(EXPORT_PROJECT_NAME ${PROJECT_NAME})

# Options
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT DEFINED EXPORT_PROJECT_NAME)
  set(EXPORT_PROJECT_NAME ${PROJECT_NAME})
endif ()

# Projects
add_subdirectory(src)
add_subdirectory(tools)

# Tests projects
option(ENABLE_TESTS "Enable tests" OFF)
if (ENABLE_TESTS)
  enable_testing()
endif ()

# install
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
  set (CMAKE_CONFIG
    "include(CMakeFindDependencyMacro)\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_commands.cmake\")\n"
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
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.consoleConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.delegatesConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.diagnosticsConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.drawingConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.coreConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake ${CMAKE_CONFIG})
  install(FILES src/xtd_core/scripts/cmake/xtd_commands.cmake DESTINATION cmake)

  set (CMAKE_XTD_FORMS_CONFIG
    "include(CMakeFindDependencyMacro)\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/xtd_commands.cmake\")\n"
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
    "  set(CMAKE_EXE_LINKER_FLAGS \"${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup\")\n"
    "endif ()\n"
  )

  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.formsConfig.cmake ${CMAKE_XTD_FORMS_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.ioConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.propertiesConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.stringsConfig.cmake ${CMAKE_CONFIG})
  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/xtd.tunitConfig.cmake ${CMAKE_CONFIG})

  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.consoleConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.delegatesConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.diagnosticsConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.drawingConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.coreConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.formsConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.ioConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.propertiesConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.stringsConfig.cmake DESTINATION cmake)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/xtd.tunitConfig.cmake DESTINATION cmake)
  install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
  install(DIRECTORY src/xtd_forms/resources DESTINATION share/xtd)
  install(DIRECTORY src/xtd_forms/docs/pictures/examples/. DESTINATION share/xtd/resources/pictures/examples/xtd_forms)
  option(ENABLE_INSTALL_EXAMPLES "Enable install examples" OFF)
  if (ENABLE_INSTALL_EXAMPLES)
    install(DIRECTORY src/xtd_console/examples/. DESTINATION share/xtd/examples/xtd_console)
    install(DIRECTORY src/xtd_forms/examples/. DESTINATION share/xtd/examples/xtd_forms)
    install(DIRECTORY src/xtd_tunit/examples/. DESTINATION share/xtd/examples/xtd_tunit)
  endif ()
endif ()
