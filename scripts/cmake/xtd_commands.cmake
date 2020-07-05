## @file
## @brief Contains xtd specific CMake commands.

################################################################################
# Application properties commands

## @brief Specifie the the base namespace for files added to the project.
## @param DEFAULT_NAMESPACE the namespace to set.
## @remarks If you don't specify the application_default_namespace, it will be the same of the project name.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  application_default_namespace("my_namespace")
##  target_type(CONSOLE_APPLICATION)
## @endcode
macro(application_default_namespace DEFAULT_NAMESPACE)
  print("Add application default namespace [${DEFAULT_NAMESPACE}]...")
  set(APPLICATION_DEFAULT_NAMESPACE ${DEFAULT_NAMESPACE})
endmacro()

## @brief Specify if application is displaying in GNOME or KDE menu.
## @param DISPLAY option to display (ON or OFF)
## @remarks Only effect on linux.
## @remarks By default the application is registered but not visible in the general menu.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  application_display(ON)
##  target_type(GUI_APPLICATION)
## @endcode
macro(application_display DISPLAY)
  print("Add assembly display [${DISPLAY}]...")
  set(APPLICATION_DISPLAY ${DISPLAY})
endmacro()

## @brief Specify the icon file (.ico for Windows, icns for maOS and png or svg for linux) that you want to use as your program icon.
## @param ARGV0 the icon to set without extension. It can be empty.
## @remarks Do not specify the extesion of file. It's operatin system depedant.
## @remarks If you write multiplatform application you must have the specified file in ico, icns and png or svg formats.
## @remarks On Linux you can specify one icon format like Icon.png or Icon.svg (typically 512 x 512 pixels) or more icon format terminated by the number of pixels:
##   * Icon8.png (8 x 8 pixels)
##   * Icon16.png (16 x 16 pixels)
##   * Icon22.png (22 x 22 pixels)
##   * Icon24.png (24 x 24 pixels)
##   * Icon32.png (32 x 32 pixels)
##   * Icon36.png (36 x 36 pixels)
##   * Icon42.png (42 x 42 pixels)
##   * Icon48.png (48 x 48 pixels)
##   * Icon52.png (52 x 52 pixels)
##   * Icon64.png (64 x 64 pixels)
##   * Icon72.png (72 x 72 pixels)
##   * Icon96.png (96 x 96 pixels)
##   * Icon128.png (128 x 128 pixels)
##   * Icon192.png (192 x 192 pixels)
##   * Icon256.png (256 x 256 pixels)
##   * Icon512.png (512 x 512 pixels)
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  application_icon(my_icon)
##  target_type(CONSOLE_APPLICATION)
## @endcode
macro(application_icon)
  print("Add application icon [${ARGV0}]...")
  if (${ARGC} GREATER 1)
    message(FATAL_ERROR "Only one icon param")
  elseif (${ARGC} EQUAL 1)
    if (MSVC)
      set(APPLICATION_ICON ${ARGV0}.ico)
    elseif (APPLE)
      set(APPLICATION_ICON ${ARGV0}.icns)
      set_source_files_properties(${APPLICATION_ICON} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    elseif (UNIX)
      get_filename_component(APPLICATION_ICON_FILENAME ${ARGV0} NAME)
      foreach(FORMAT 8 16 22 24 32 36 42 48 52 64 72 96 128 192 256 512) 
        if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${ARGV0}${FORMAT}.png)
          configure_file(${ARGV0}${FORMAT}.png $ENV{HOME}/.local/share/icons/hicolor/${FORMAT}x${FORMAT}/apps/${APPLICATION_ICON_FILENAME}.png COPYONLY)
          set(APPLICATION_ICON ${ARGV0}${FORMAT}.png)
        endif ()
      endforeach()
      if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${ARGV0}.png)
        set(APPLICATION_ICON ${ARGV0}.png)
        configure_file(${APPLICATION_ICON} $ENV{HOME}/.local/share/icons/hicolor/512x512/apps/${APPLICATION_ICON_FILENAME}.png COPYONLY)
      endif ()
      if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${APPLICATION_ICON}.svg)
        set(APPLICATION_ICON ${ARGV0}.svg)
        configure_file(${APPLICATION_ICON}.svg $ENV{HOME}/.local/share/icons/hicolor/scalable/apps/${APPLICATION_ICON_FILENAME}.svg COPYONLY)
      endif ()
    endif ()
    
    auto_source_group(${APPLICATION_ICON}) 
  endif ()
endmacro()

## @brief Specifie the name of the output file.
## @param NAME the name to set.
## @remarks If you don't specify the application_name, it will be the same of the project name.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  application_name("my_exe")
##  target_type(CONSOLE_APPLICATION)
## @endcode
macro(application_name NAME)
  print("Add application name [${NAME}]...")
  set(APPLICATION_NAME ${NAME})
endmacro()

## @brief Speficy the application is not registered in the system.
## @remarks Only effect on linux.
## @remarks By default the application is registered but not visible in GNOME or KDE menu.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  application_registered(OFF)
##  target_type(GUI_APPLICATION)
## @endcode
macro(application_registered REGISTERED)
  print("Set application registered [${REGISTERED}]...")
  set(APPLICATION_REGISTERED ${REGISTERED})
  if (NOT APPLICATION_REGISTERED)
    file(REMOVE ${CMAKE_CURRENT_BINARY_DIR}/Resources/${APPLICATION_NAME}.desktop)
  endif ()
endmacro()

## @brief Specify the entry pointto be called when the application is load.
## @param ARGV0 the object that contains the entry point.
## @param ARGV1 the object definition file. (optional if you use TUnitMain_ or TUnitFrameworkMain_ entry point)
## @remarks Do not use this method of startup_(...) is present in your files or if you use standard c++ main() method.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  application_startup("my_project::my_class" my_project.cpp)
##  target_type(GUI_APPLICATION)
## @endcode
macro(application_startup ...)
  print("Add application startup [\"${ARGV0}\" ${ARGV1}]...")
  set(STARTUP_FILE properties/startup.cpp)
  if (${ARGC} EQUAL 2)
    set(MAIN_FILE ${ARGV1})
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" MAIN_FILE ${MAIN_FILE})
    file(RELATIVE_PATH STARTUP_OBJECT_RELATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/Properties ${CMAKE_CURRENT_SOURCE_DIR}/${MAIN_FILE})
    set(INCLUDE_FILE "#include \"${STARTUP_OBJECT_RELATIVE_PATH}\"\n")
  elseif ("${ARGV0}" STREQUAL "tunit_main_")
    set(INCLUDE_FILE "#include <xtd/tunit_main.h>\n")
  endif ()
  file(WRITE ${STARTUP_FILE}
    "#pragma region xtd generated code\n"
    "// This code was generated by CMake script.\n"
    "//\n"
    "// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.\n"
    "\n"
    "${INCLUDE_FILE}"
    "#include <xtd/startup.h>\n"
    "\n"
    "startup_(${ARGV0});\n"
    "#pragma endregion\n"
  )
  #source_group(src\\properties FILES ${STARTUP_FILE})
  auto_source_group(${STARTUP_FILE}) 
  set(PROJECT_SOURCES "${PROJECT_SOURCES};${STARTUP_FILE}")
endmacro()

## @brief Specify the type of application to build.
## @param TYPE Type of application.
## Possible values : 
## * CONSOLE_APPLICATION Console application
## * GUI_APPLICATION Gui application (Winforms)
## * TEST_APPLICATION Test application (TUnit)
## * MODULE_LIBRARY Module library
## * SHARED_LIBRARY Shared library (.dll or .so)
## * STATIC_LIBRARY Static library (.lib or .a)
## * CUSTOM_TARGET Target with no output.
## @remarks This method is required except container project like Solution.
## @remarks This method must be the last method.
## @remarks Call only once by project.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##  add_references(xtd.string xtd.core)
##
##  application_name("my_exe")
##  target_type(CONSOLE_APPLICATION)
## @endcode
macro(target_type TYPE)
  print("Add application type [${TYPE}]...")
  set(APPLICATION_TYPE "${TYPE}")
  
  include(${CMAKE_CURRENT_SOURCE_DIR}/properties/assembly_informations.cmake OPTIONAL)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/properties/assembly_informations.cmake)
    set(CMAKE_ASSEMBLY_INFORMATIONS properties/assembly_informations.cmake)
    auto_source_group(${CMAKE_ASSEMBLY_INFORMATIONS})
  endif ()
  
  include(${CMAKE_CURRENT_SOURCE_DIR}/properties/application_properties.cmake OPTIONAL)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/properties/application_properties.cmake)
    set(CMAKE_APPLICATION_PROPERTIES properties/application_properties.cmake)
    auto_source_group(${CMAKE_APPLICATION_PROPERTIES})
  endif ()
  
  include(${CMAKE_CURRENT_SOURCE_DIR}/properties/resources.cmake OPTIONAL)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/properties/resources.cmake)
    set(CMAKE_RESOURCES properties/resources.cmake)
    auto_source_group(${CMAKE_RESOURCES})
  endif ()
  
  include(${CMAKE_CURRENT_SOURCE_DIR}/properties/resourcestrings.cmake OPTIONAL)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/properties/resourcestrings.cmake)
    set(CMAKE_RESOURCE_STRINGS properties/resourcestrings.cmake)
    auto_source_group(${CMAKE_RESOURCE_STRINGS})
  endif ()
  
  include(${CMAKE_CURRENT_SOURCE_DIR}/properties/settings.cmake OPTIONAL)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/properties/settings.cmake)
    set(CMAKE_SETTINGS properties/settings.cmake)
    auto_source_group(${CMAKE_SETTINGS})
  endif ()
  
  if (NOT ${VERSION} STREQUAL "*")
    set(PROJECT_VERSION "${VERSION}")
  endif ()
  remove_definitions(-DXTD_ASSEMBLY_VERSION)
  add_definitions(-D__XTD_ASSEMBLY_VERSION__="${PROJECT_VERSION}")
  
  write_application_informations_file()
  write_assembly_informations()
  write_resources()
  write_resources_files()
  write_settings_files()
  
  set(ALL_FILES "${APPLICATION_ICON};${PROJECT_RESOURCE_FILES};${PROJECT_SOURCES};${CMAKE_ASSEMBLY_INFORMATIONS};${CMAKE_APPLICATION_PROPERTIES};${CMAKE_RESOURCES};${CMAKE_RESOURCE_STRINGS};${CMAKE_SETTINGS}")

  if ("${TYPE}" STREQUAL "CONSOLE_APPLICATION")
    add_executable(${APPLICATION_NAME} ${ALL_FILES})
    target_link_libraries(${APPLICATION_NAME} xtd.console ${PROJECT_REFERENCES})
  elseif ("${TYPE}" STREQUAL "GUI_APPLICATION" OR "${TYPE}" STREQUAL "WINDOWS_APPLICATION")
    add_executable(${APPLICATION_NAME} ${GUI} ${ALL_FILES})
    target_link_libraries(${APPLICATION_NAME} xtd.forms ${PROJECT_REFERENCES})
  elseif ("${TYPE}" STREQUAL "TEST_APPLICATION")
     add_executable(${APPLICATION_NAME} ${ALL_FILES})
     add_test(NAME ${APPLICATION_NAME} COMMAND $<TARGET_FILE_NAME:${APPLICATION_NAME}> --gtest_filter=*.* --gtest_output=xml:${APPLICATION_NAME}.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:${APPLICATION_NAME}>)
    target_link_libraries(${APPLICATION_NAME} xtd.tunit ${PROJECT_REFERENCES})
  elseif ("${TYPE}" STREQUAL "MODULE_LIBRARY")
    add_library(${APPLICATION_NAME} MODULE ${ALL_FILES})
    target_link_libraries(${APPLICATION_NAME} xtd.core ${PROJECT_REFERENCES})
  elseif ("${TYPE}" STREQUAL "SHARED_LIBRARY")
    string(TOUPPER ${APPLICATION_NAME} TARGET_NAME_UPPER)
    add_definitions(-D${TARGET_NAME_UPPER}_EXPORT)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
    add_library(${APPLICATION_NAME} SHARED ${ALL_FILES})
     if ("${APPLICATION_NAME}" STREQUAL "xtd.core")
      target_link_libraries(${APPLICATION_NAME} ${PROJECT_REFERENCES})
    else ()
      target_link_libraries(${APPLICATION_NAME} xtd.core ${PROJECT_REFERENCES})
    endif ()
  elseif ("${TYPE}" STREQUAL "STATIC_LIBRARY")
    add_library(${APPLICATION_NAME} STATIC ${ALL_FILES})
     if ("${APPLICATION_NAME}" STREQUAL "xtd.core")
      target_link_libraries(${APPLICATION_NAME} ${PROJECT_REFERENCES})
    else ()
      target_link_libraries(${APPLICATION_NAME} xtd.core ${PROJECT_REFERENCES})
    endif ()
  elseif ("${TYPE}" STREQUAL "CUSTOM_TARGET")
    add_custom_target(${APPLICATION_NAME} SOURCES ${ALL_FILES})
  else ()
    message(FATAL_ERROR "the TYPE must be on of theses value : CONSOLE_APPLICATION, GUI_APPLICATION, TEST_APPLICATION, MODULE_LIBRARY, SHARED_LIBRARY, STATIC_LIBRARY or CUSTOM_TARGET.")
  endif ()

  if (MSVC AND NOT "${TYPE}" STREQUAL "CUSTOM_TARGET")
    target_compile_options(${APPLICATION_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${APPLICATION_NAME}>/${APPLICATION_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
    target_compile_options(${APPLICATION_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${APPLICATION_NAME}>/${APPLICATION_NAME}.pdb>")
  endif ()

  if (EXISTS include)
    target_include_directories(${APPLICATION_NAME} PUBLIC $<INSTALL_INTERFACE:include>)
  endif ()

  if (PROJECT_INCLUDE_DIRECTORIES)
    foreach(INCLUDE_DIRECTORY ${PROJECT_INCLUDE_DIRECTORIES})
      file(RELATIVE_PATH INCLUDE_DIRECTORY_RELATIVE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${INCLUDE_DIRECTORY})
      target_include_directories(${APPLICATION_NAME} PUBLIC $<BUILD_INTERFACE:${INCLUDE_DIRECTORY}> $<INSTALL_INTERFACE:${INCLUDE_DIRECTORY_RELATIVE_PATH}>)
    endforeach()
  endif ()
endmacro()

################################################################################
# Assembly informations commands

## @brief Specifies a company name for the assembly manifest. Corresponds to AssemblyCompanyAttribute.
## @param COMPANY The company name to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_company("Gammasoft")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_company COMPANY)
  print("Add assembly company [${COMPANY}]...")
  set(ASSEMBLY_COMPANY "${COMPANY}")
endmacro()

## @brief Specifies a configuration for the assembly manifest. Corresponds to AssemblyConfigurationAttribute.
## @param CONFIGURATION The configuration to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_configuration("Beta public")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_configuration CONFIGURATION)
  print("Add assembly configuration [${CONFIGURATION}]...")
  set(ASSEMBLY_CONFIGURATION "${CONFIGURATION}")
endmacro()

## @brief Specifies a copyright notice for the assembly manifest. Corresponds to assembly_copyright_attribute.
## @param COPYRIGHT The copyright to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_copyright("© 2019 by Gammasoft.")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_copyright COPYRIGHT)
  print("Add assembly copyright [${COPYRIGHT}]...")
  set(ASSEMBLY_COPYRIGHT "${COPYRIGHT}")
endmacro()

## @brief Specifies the culture for the assembly manifest. Corresponds to assembly_configuration_attribute.
## @param CULTURE The culture to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
macro(assembly_culture CULTURE)
  print("Add assembly culture [${CULTURE}]...")
  set(ASSEMBLY_CULTURE "${CULTURE}")
endmacro()

## @brief Specifies an optional description for the assembly manifest. Corresponds to assembly_description_attribute.
## @param DESCRIPTION The description to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_description("The application to stuff it.")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_description DESCRIPTION)
  print("Add assembly description [${DESCRIPTION}]...")
  set(ASSEMBLY_DESCRIPTION "${DESCRIPTION}")
endmacro()

## @brief Specifies a version number that instructs the compiler to use a specific version for the Win32 file version resource. Corresponds to assembly_file_version_attribute.
## @param FILE_VERSION The file version to set (Major, Minor and build).
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_file_version("1.2.3")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_file_version FILE_VERSION)
  print("Add assembly file version [${FILE_VERSION}]...")
  set(ASSEMBLY_FILE_VERSION "${FILE_VERSION}")
endmacro()

## @brief Specify an unique GUID that identifies the assembly. When you create a project, Visual Studio generates a GUID for the assembly. Corresponds to Guid.
## @param GUID The guid to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_guid("54278852-4afa-4d73-b0ea-de21264f59f6")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_guid GUID)
  print("Add assembly guid [${GUID}]...")
  set(ASSEMBLY_GUID "${GUID}")
endmacro()

## @brief Specifies a product name for the assembly manifest. Corresponds to assembly_product_attribute.
## @param PRODUCT The product name to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_product("my_project")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_product PRODUCT)
  print("Add assembly product [${PRODUCT}]...")
  set(ASSEMBLY_PRODUCT "${PRODUCT}")
endmacro()

## @brief Specifies a title for the assembly manifest. Corresponds to assembly_title_attribute.
## @param TITLE The title to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_title("My Project")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_title TITLE)
  print("Add assembly title [${TITLE}]...")
  set(ASSEMBLY_TITLE "${TITLE}")
endmacro()

## @brief Specifies a trademark for the assembly manifest. Corresponds to assembly_trademark_attribute.
## @param TRADEMARK The trademark to set.
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
macro(assembly_trademark TRADEMARK)
  print("Add assembly trademark [${TRADEMARK}]...")
  set(ASSEMBLY_TRADEMARK "${TRADEMARK}")
endmacro()

## @brief Specifies the version of the assembly. Corresponds to assembly_version_attribute.
## @param ASSEMBLY_VERSION The version to set (Major, Minor and build).
## @remarks Call only once by project.
## @remarks This method must be call before target_type().
## @remarks This method is optional. 
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##
##  assembly_version("1.2.3")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(assembly_version VERSION)
  print("Add assembly version [${VERSION}]...")
  set(ASSEMBLY_VERSION "${VERSION}")
endmacro()

################################################################################
# Build commands

## @brief Specify the directory into which runtime target files should be built.
## @param OUTPUT_DIRECTORY the directory where runtime target files should be built.
## @remark This option is use mainly when a solution as more than one projec.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(MySolution)
##  find_package(xtd REQUIRED)
##
##  build_output_directory("${USER_DIRECTORY}/output")
##
##  add_projects(lib_project1 lib_project2 lib_project3)
##  add_projects(tests/test_lib_project1 tests/test_lib_project2 tests/test_lib_project_3)
## @endcode
macro(build_output_directory OUTPUT_DIRECTORY)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}")
  set(BUILD_OUTPUT_DIRECTORY "${OUTPUT_DIRECTORY}")
endmacro()

################################################################################
# Debug commands

## @brief Print arguments on console only if ENABLE_VERBOSE option is ON.
## @param ARGN arguments to print on console.
macro(print)
  if (ENABLE_VERBOSE)
    message(STATUS ${ARGN})
  endif ()
endmacro()

## @brief Print application properties, assembly informations, build options, project and system informations on console.
macro(print_project_informations)
  message(STATUS "")
  message(STATUS "Application properties:")
  message(STATUS "  Default namespace [\"${APPLICATION_DEFAULT_NAMESPACE}\"]")
  message(STATUS "  Icon [${APPLICATION_ICON}]")
  message(STATUS "  Name [\"${APPLICATION_NAME}\"]")
  message(STATUS "  Registered [${APPLICATION_REGISTERED}]")
  message(STATUS "  Startup file [${STARTUP_FILE}]")
  message(STATUS "  Type [${APPLICATION_TYPE}]")
  message(STATUS "")
  message(STATUS "Assembly Informations:")
  message(STATUS "  Company [\"${ASSEMBLY_COMPANY}\"]")
  message(STATUS "  Configuration [\"${ASSEMBLY_CONFIGURATION}\"]")
  message(STATUS "  Copyright [\"${ASSEMBLY_COPYRIGHT}\"]")
  message(STATUS "  Cultutre [\"${ASSEMBLY_CULTURE}\"]")
  message(STATUS "  Description [\"${ASSEMBLY_DESCRIPTION}\"]")
  message(STATUS "  File version [${ASSEMBLY_FILE_VERSION}]")
  message(STATUS "  Guid [\"${ASSEMBLY_GUID}\"]")
  message(STATUS "  Product [\"${ASSEMBLY_PRODUCT}\"]")
  message(STATUS "  Title [\"${ASSEMBLY_TITLE}\"]")
  message(STATUS "  Trademark [\"${ASSEMBLY_TRADEMARK}\"]")
  message(STATUS "  Version [${PROJECT_VERSION}]")
  message(STATUS "")
  message(STATUS "Build options:")
  message(STATUS "  Include directories [${PROJECT_INCLUDE_DIRECTORIES}]")
  message(STATUS "  Type [${BUILD_TYPE}]")
  message(STATUS "")
  message(STATUS "Project:")
  message(STATUS "  Application Settings [${PROJECT_APPLICATION_SETTINGS}]")
  message(STATUS "  Output directory [${BUILD_OUTPUT_DIRECTORY}]")
  message(STATUS "  Packages [${PROJECT_PACKAGES}]")
  message(STATUS "  Projects [${PROJECT_PROJECTS}]")
  message(STATUS "  References [${PROJECT_REFERENCES}]")
  message(STATUS "  Resources [${PROJECT_RESOURCES}]")
  message(STATUS "  Resource Strings [${PROJECT_RESOURCE_STRINGS}]")
  message(STATUS "  Sources [${PROJECT_SOURCES}]")
  message(STATUS "  User Settings [${PROJECT_USER_SETTINGS}]")
  message(STATUS "")
  message(STATUS "System informations:")
  message(STATUS "  CMake version [${CMAKE_VERSION}]")
  message(STATUS "  Compiler [${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}]")
  message(STATUS "  Install prefix [${CMAKE_INSTALL_PREFIX}]")
  message(STATUS "  System [${CMAKE_SYSTEM}]")
  message(STATUS "  User directory [${USER_DIRECTORY}]")
  message(STATUS "")
endmacro()

################################################################################
# Install commands

## @brief Install include directories.
## @param ARGN Include directories to install.
## @remarks This method is required for install package.
## @remarks This method can be call more than once in the same project.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(src/my_project1.cpp src/my_project2.cpp include/my_project/my_project.h include/my_project/my_project2.h)
##
##  target_type(STATIC_LIBRARY)
##
##  add_install_include_directories(include/my_project)
##  install_component()
##  install_application()
## @endcode
macro(add_install_include_directories)
  foreach(DIRECTORY ${ARGN})
    install(DIRECTORY ${DIRECTORY}/. DESTINATION include/${INSTALL_NAME})
    set(INSTALL_INCLUDE_DIRECTORIES "${INSTALL_INCLUDE_DIRECTORIES};${DIRECTORY}")
  endforeach()
endmacro()

## @brief Install include files.
## @param ARGN Include files to install.
## @remarks This method is required for install package.
## @remarks This method can be call more than once in the same project.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project1.cpp my_project2.cpp my_project.h MyProjec2.h)
##
##  target_type(STATIC_LIBRARY)
##
##  add_install_include_files(my_project1.h my_project2.h)
##  install_component()
##  install_application()
## @endcode
macro(add_install_include_files)
  install(FILES ${ARGN} DESTINATION include/${INSTALL_NAME})
  set(INSTALL_INCLUDE_FILES "${INSTALL_INCLUDE_FILES};${${ARGN}}")
endmacro()

## @brief Install component.
## @param ARGV0 Install name (optional).
## @remarks if install name no specified and install_name() method no called, the install name is equal to application name.
## @remarks This method is required for install package.
## @remarks This method must be call after add_references.
## @remarks Call only once by project.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp my_project.h)
##
##  target_type(STATIC_LIBRARY)
##
##  add_install_include_files(my_project.h)
##  install_component()
##  install_package()
## @endcode
macro(install_component)
  if (${ARGC} GREATER 1)
    message(FATAL_ERROR "Only INSTALL_NAME argument authorized or none.")
  elseif (${ARGC} EQUAL 1)
    set(INSTALL_NAME ${ARGV0})
  endif ()
  
  get_directory_property(HAS_PARENT PARENT_DIRECTORY)
  if (HAS_PARENT)
    set(INSTALL_COMPONENTS "${INSTALL_COMPONENTS};${APPLICATION_NAME}" PARENT_SCOPE)
  else ()
    set(INSTALL_COMPONENTS "${INSTALL_COMPONENTS};${APPLICATION_NAME}")
  endif ()
  
  if ("${APPLICATION_TYPE}" STREQUAL "CONSOLE_APPLICATION" OR "${APPLICATION_TYPE}" STREQUAL "GUI_APPLICATION" OR "${APPLICATION_TYPE}" STREQUAL "TEST_APPLICATION")
    set(DESTINATION bin)
  else ()
    set(DESTINATION lib)
  endif ()
  
  install(TARGETS ${APPLICATION_NAME} EXPORT ${INSTALL_NAME} DESTINATION ${DESTINATION})
  if ("${APPLICATION_TYPE}" STREQUAL "GUI_APPLICATION" OR "${APPLICATION_TYPE}" STREQUAL "CONSOLE_APPLICATION" OR "${APPLICATION_TYPE}" STREQUAL "TEST_APPLICATION")
    install(FILES ${PROJECT_RESOURCES} DESTINATION ${DESTINATION}/resources)
  endif ()
  if (MSVC)
    install(FILES $<TARGET_FILE_DIR:${INSTALL_NAME}>/${APPLICATION_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION ${DESTINATION} CONFIGURATIONS Debug OPTIONAL)
    install(FILES $<TARGET_FILE_DIR:${INSTALL_NAME}>/${APPLICATION_NAME}.pdb DESTINATION ${DESTINATION} CONFIGURATIONS Release OPTIONAL)
  endif ()
endmacro()

## @brief Specify the install name.
## @param NAME Install name.
## @remarks This method is optional.
## @remarks This method must be after add_references.
## @remarks Call only once by project.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp my_project.h)
##
##  target_type(STATIC_LIBRARY)
##
##  install_name("specific_project")
##  add_install_include_files(my_project.h)
##  install_component()
##  install_application()
## @endcode
macro(install_name NAME)
  set(INSTALL_NAME ${NAME})
endmacro()

## @brief Install package MODULE_LIBRARY, STATIC_LIBRARY or SHARED_LIBRAY package.
## @param ARGV0 Install name (optional).
## @remarks if install name no specified and install_name() method no called, the install name is equal to application name.
## @remarks This method is required for install package.
## @remarks This method must be after add_references.
## @remarks Call only once by project.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp my_project.h)
##
##  target_type(STATIC_LIBRARY)
##
##  add_install_include_files(my_project.h)
##  install_component()
##  install_package()
## @endcode
macro(install_package)
  if (${ARGC} GREATER 1)
    message(FATAL_ERROR "Only INSTALL_NAME argument authorized or none.")
  elseif (${ARGC} EQUAL 1)
    set(INSTALL_NAME ${ARGV0})
  endif ()
  if (PROJECT_PROJECTS)
    write_project_config_cmake()
    install(EXPORT ${INSTALL_NAME} DESTINATION cmake)
    install(FILES ${INSTALL_CMAKE_PROJECT_CONFIG_FILE} DESTINATION cmake)
  endif ()
endmacro()

################################################################################
# Project commands

## @brief Add include directory to current project.
## @param ARGN directories to add.
## @remarks This method can be call more than once in the same project.
## @remarks This method must be call before target_type().
## @remarks This method is optional.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_include_directory(include)
##  add_sources(my_project.cpp include/my_project/my_project.h)
##
##  target_type(STATIC_LIBRARY)
## @endcode
macro(add_include_directories)
  print("Add include directories [${ARGN}]...")
  foreach(INCLUDE_DIRECTORY ${ARGN})
    get_filename_component(INCLUDE_DIRECTORY_ABSOLUTE_PATH "${INCLUDE_DIRECTORY}" REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    set(PROJECT_INCLUDE_DIRECTORIES "${PROJECT_INCLUDE_DIRECTORIES};${INCLUDE_DIRECTORY_ABSOLUTE_PATH}")
  endforeach()
endmacro()

## @brief Adds, finds and loads settings from external required projects to current project.
## @param ARGN packages to add.
## @remarks This method can be call more than once in the same project.
## @remarks This method must be call before target_type().
## @remarks This method is optional.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_packages(my_package1 my_package2)
##  add_references(my_project1_in_my_package1 my_project1_in_my_package2 my_project2_in_my_package2)
##  add_sources(my_project.cpp)
##
##  target_type(CONSOLE_APPLICATION)
##
## @endcode
macro(add_packages)
  print("Add packages [${ARGN}]...")
  foreach(PACKAGE ${ARGN})
    find_package(${PACKAGE} REQUIRED)
  endforeach()
  set(PROJECT_PACKAGES "${PROJECT_PACKAGES};${ARGN}")
endmacro()

## @brief Add child projects to parent project.
## @param ARGN projects to add.
## @remarks  The path can be relative from CMAKE_CURRENT_SOURCE_DIR or absolute.
## @remarks This method can be call more than once in the same project.
## @remarks This method is optional except container project like Solution.
## @remarks This method must be call before target_type().
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(MySolution)
##  find_package(xtd REQUIRED)
##  add_projects(lib_project1 lib_project2 lib_project3)
##  add_projects(tests/test_lib_project1 tests/test_lib_project2 tests/test_lib_project_3)
## @endcode
macro(add_projects)
  print("Add projects [${ARGN}]...")
  foreach (PROJECT ${ARGN})
    get_filename_component(ABSOLUTE_PATH_PROJECT "${PROJECT}"  REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    if (NOT EXISTS ${ABSOLUTE_PATH_PROJECT})
      message(FATAL_ERROR "Cannot find project directory: ${PROJECT}")
    endif ()
    
    add_subdirectory("${PROJECT}")
    if (TARGET ${PROJECT})
       set_target_properties(${PROJECT} PROPERTIES FOLDER "${PROJECT_PATH}")
    endif ()
    set(PROJECT_PROJECTS "${PROJECT_PROJECTS};${PROJECT}")
  endforeach()
endmacro()

## @brief Add references (libraries) to current project.
## @param ARGN references to add.
## @remarks This method can be call more than once in the same project.
## @remarks This method must be call before target_type().
## @remarks This method is optional.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(my_project.cpp)
##  add_references(xtd.core xtd.console)
##  add_references(xtd.emoticons)
##
##  target_type(CONSOLE_APPLICATION)
##
## @endcode
macro(add_references)
  print("Add references [${ARGN}]...")
  set(PROJECT_REFERENCES "${WITCH_REFERENCES};${ARGN}")
endmacro()

## @brief Add resource to current project.
## @param NAME resource name to add.
## @param FILE resource file to add.
## @remarks  The path can be relative from CMAKE_CURRENT_SOURCE_DIR or absolute.
## @remarks This method can be call more than once in the same project.
## @remarks This method must be call before target_type().
## @remarks This method is optional.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(file.h file.cpp)
##  resource(image1 resources/image1.png)
##  resource(image2 resources/image2.bmp)
##  resource(animation1 animations/ani1.gif)
##
##  target_type(CONSOLE_APPLICATION)
## @endcode
macro(resource NAME FILE)
  if ("${NAME}" IN_LIST PROJECT_RESOURCE_NAMES)
    message(FATAL_ERROR "Duplicate resource NAME : ${NAME}")
  endif ()

  print("Add resource [${NAME} ${FILE}]...")

  get_filename_component(ABSOLUTE_PATH_FILE "${FILE}"  REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
  if (NOT EXISTS ${ABSOLUTE_PATH_FILE})
    message(FATAL_ERROR "Cannot find resource file: ${FILE}")
  endif ()

  auto_source_group(${FILE})
  set(PROJECT_RESOURCES "${PROJECT_RESOURCES};${NAME}=${FILE}")
  set(PROJECT_RESOURCE_NAMES "${PROJECT_RESOURCE_NAMES};${NAME}")
  set(PROJECT_RESOURCE_FILES "${PROJECT_RESOURCE_FILES};${FILE}")
endmacro()

## @brief Add resource string to current project.
## @param NAME Name of string to add.
## @param VALUE Value of string to add.
## @param COMMENT Comment of string to add.
## @remarks This method can be call more than once in the same project.
## @remarks This method must be call before target_type().
## @remarks This method is optional.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(file.h file.cpp)
##  resource_string(caption "\"Form examples\"" "Caption of main Form.")
##  resource_string(button_close_text "\"Close\"" "Text of close button.")
##
##  target_type(GUI_APPLICATION)
## @endcode
macro(resource_string NAME VALUE COMMENT)
  if ("${NAME}" IN_LIST PROJECT_RESOURCE_STRING_NAMES)
    message(FATAL_ERROR "Duplicate resource string NAME : ${NAME}")
  endif ()

  print("Add resource string [${NAME} ${VALUE} ${COMMENT}]...")

  get_filename_component(ABSOLUTE_PATH_FILE "${FILE}"  REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
  set(PROJECT_RESOURCE_STRINGS "${PROJECT_RESOURCE_STRINGS};${NAME}=${VALUE}=${COMMENT}")
  set(PROJECT_RESOURCE_STRING_NAMES "${PROJECT_RESOURCE_STRING_NAMES};${NAME}")
endmacro()

## @brief Add a setting to current project.
## @param NAME The name of setting to add.
## @param TYPE The type of setting to add.
## @param SCOPE The scope of setting to add (APPLICATION or USER).
## @param VALUE The value of setting to add.
## @remarks Application-scope settings are read only at run time.
## @remarks User-scope settings are read/write at run time, and their values can be changed and saved in code.
## @remarks This method can be call more than once in the same project.
## @remarks This method must be call before target_type().
## @remarks This method is optional.
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(file.h file.cpp)
##  setting(name string APPLICATION "\"Settings example\"")
##  setting(back_color xtd::drawing::color USER "xtd::drawing::color::spring_green")
##
##  target_type(CONSOLE_APPLICATION)
## @endcode
macro(setting NAME TYPE SCOPE VALUE)
  if ("${NAME}" IN_LIST PROJECT_SETTING_NAMES)
    message(FATAL_ERROR "Duplicate setting NAME : ${NAME}")
  endif ()

  if (NOT "${SCOPE}" STREQUAL "APPLICATION" AND NOT "${SCOPE}" STREQUAL "USER")
    message(FATAL_ERROR "The SCOPE can be only equals to APPLICATION or USER")
  endif ()

  print("Add setting application [${NAME} ${TYPE} ${SCOPE} ${VALUE}]...")

  if ("${SCOPE}" STREQUAL "APPLICATION")
    set(PROJECT_APPLICATION_SETTINGS "${PROJECT_APPLICATION_SETTINGS};${NAME}=${TYPE}=${VALUE}")
  else ()
    set(PROJECT_USER_SETTINGS "${PROJECT_USER_SETTINGS};${NAME}=${TYPE}=${VALUE}")
  endif ()
  set(PROJECT_SETTING_NAMES "${PROJECT_SETTING_NAMES};${NAME}")
endmacro()

## @brief Add source and header files to current project.
## @param ARGN Files list to add.
## @remarks  The path can be relative from CMAKE_CURRENT_SOURCE_DIR or absolute.
## @remarks This method can be call more than once in the same project.
## @remarks This method is required except container project like Solution.
## @remarks This method must be call before target_type().
## @par Examples
## @code
##  cmake_minimum_required(VERSION 3.3)
##
##  project(my_project)
##  find_package(xtd REQUIRED)
##  add_sources(file1.h file2.h options/file3.h)
##  add_sources(file1.cpp file2.cpp options/file3.cpp)
##  
##  target_type(CONSOLE_APPLICATION)
## @endcode
macro(add_sources)
  print("Add sources [${ARGN}]...")
  foreach (FILE ${ARGN})
    get_filename_component(ABSOLUTE_PATH_FILE "${FILE}"  REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    if (NOT EXISTS ${ABSOLUTE_PATH_FILE})
      message(FATAL_ERROR "Cannot find source file: ${FILE}")
    endif ()
  endforeach()

  auto_source_group(${ARGN}) 
  set(PROJECT_SOURCES "${PROJECT_SOURCES};${ARGN}")
endmacro()

################################################################################
# Write files

## @brief Write application informations file.
## @remarks Internal use only.
macro(write_application_informations_file)
  if (MSVC)
    write_windows_application_informations_file()
  elseif (APPLE)
    write_macos_application_informations_file()
  elseif (UNIX)
    write_linux_application_informations_file()
  endif ()
endmacro()

## @brief Write assembly information file. Typically property/assembly_info.cpp file.
## @remarks Internal use only.
macro(write_assembly_informations)
  if (NOT READING_ASSEMBLY_INFORMATIONS_FILE AND (ASSEMBLY_TITLE OR ASSEMBLY_DESCRIPTION OR ASSEMBLY_CONFIGURATION OR ASSEMBLY_COMPANY OR ASSEMBLY_PRODUCT OR ASSEMBLY_COPYRIGHT OR ASSEMBLY_TRADEMARK OR ASSEMBLY_CULTURE OR PROJECT_VERSION OR ASSEMBLY_FILE_VERSION OR ASSEMBLY_GUID))
    #print("Writing Assembly Information file [${ASSEMBLY_INFORMATIONS_FILE}]...")
    
    if (ASSEMBLY_TITLE)
      set(TITLE "${ASSEMBLY_TITLE}")
    else ()
      set(TITLE "${APPLICATION_NAME}")
    endif ()

    if (ASSEMBLY_CONFIGURATION)
      set(CONFIGURATION "${ASSEMBLY_CONFIGURATION}")
    else ()
      set(CONFIGURATION "${CMAKE_BUILD_TYPE}")
    endif ()
 
    if (ASSEMBLY_PRODUCT)
      set(PRODUCT "${ASSEMBLY_PRODUCT}")
    else ()
      set(PRODUCT "${APPLICATION_NAME}")
    endif ()

    if (ASSEMBLY_FILE_VERSION)
      set(FILE_VERSION "assembly_file_version_(\"${ASSEMBLY_FILE_VERSION}\");\n")
    else ()
      set(FILE_VERSION "")
    endif ()

    if (ASSEMBLY_GUID)
      set(GUID "assembly_guid_(\"${ASSEMBLY_GUID}\");\n")
    else ()
      set(GUID "")
    endif ()

    file(WRITE ${ASSEMBLY_INFORMATIONS_FILE}
      "#pragma region xtd generated code\n"
      "// This code was generated by CMake script.\n"
      "//\n"
      "// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.\n"
      "// Remarks : If this file was manually created, you need re-run cmake generator after creating\n"
      "//           or modifying any parameter bellow.\n"
      "\n"
      "#include <xtd/assembly_info.h>\n"
      "\n"
      "// Information about this assembly is defined by the following attributes.\n"
      "// Change them to the values specific to your project.\n"
      "\n"
      "assembly_title_(\"${TITLE}\");\n"
      "assembly_description_(\"${ASSEMBLY_DESCRIPTION}\");\n"
      "assembly_configuration_(\"${CONFIGURATION}\");\n"
      "assembly_company_(\"${ASSEMBLY_COMPANY}\");\n"
      "assembly_product_(\"${PRODUCT}\");\n"
      "assembly_copyright_(\"${ASSEMBLY_COPYRIGHT}\");\n"
      "assembly_trademark_(\"${ASSEMBLY_TRADEMARK}\");\n"
      "assembly_culture_(\"${ASSEMBLY_CULTURE}\");\n"
      "\n"
      "// The following GUID is for the ID of the typelib if this project is exposed to COM\n"
      "${GUID}"
      "\n"
      "// The assembly version has the format \"{Major}.{Minor}.{Build}.{Revision}\".\n"
      "// In not specify or empty or \"*\" the cmake project version is used.\n"
      "\n"
      "assembly_version_(\"${PROJECT_VERSION}\");\n"
      "${FILE_VERSION}"
      "#pragma endregion"
    )
    
    auto_source_group(${ASSEMBLY_INFORMATIONS_FILE})
    set(PROJECT_SOURCES ${PROJECT_SOURCES} ${ASSEMBLY_INFORMATIONS_FILE})
  endif ()
endmacro()

## @brief Write resources files. Typically  properties/resources.h and properties/resources.cpp
## @remarks Internal use only.
macro(write_resources_files)
  if (PROJECT_RESOURCES OR PROJECT_RESOURCE_STRINGS)
    write_resources_file_header()
  endif ()
endmacro()

## @brief Write resources files. Typically  properties/resources.h and properties/resources.cpp
## @remarks Internal use only.
macro(write_settings_files)
  if (PROJECT_APPLICATION_SETTINGS OR PROJECT_USER_SETTINGS)
    write_settings_file_header()
  endif ()
endmacro()

## @brief Write resources addes with resource.
## @remarks Internal use only.
macro(write_resources)
  if (CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(RESOURCES_DIRECTORY_ROOT ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
  else ()
    set(RESOURCES_DIRECTORY_ROOT ${CMAKE_CURRENT_BINARY_DIR})
  endif ()
 
  foreach (RESOURCE_LINE ${PROJECT_RESOURCES})
    split_resource(${RESOURCE_LINE} NAME FILE)
    get_filename_component(FILENAME ${FILE} NAME)
    if (APPLE AND "${APPLICATION_TYPE}" STREQUAL "GUI_APPLICATION")
      set_source_files_properties(${FILE} PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
    elseif ("${APPLICATION_TYPE}" STREQUAL "GUI_APPLICATION" OR "${APPLICATION_TYPE}" STREQUAL "CONSOLE_APPLICATION" OR "${APPLICATION_TYPE}" STREQUAL "TEST_APPLICATION")
      if (CMAKE_BUILD_TYPE)
        configure_file(${FILE} ${RESOURCES_DIRECTORY_ROOT}/resources/${FILENAME} COPYONLY)
      else ()
        configure_file(${FILE} ${RESOURCES_DIRECTORY_ROOT}/resources/${FILENAME} COPYONLY)
        configure_file(${FILE} ${RESOURCES_DIRECTORY_ROOT}/Debug/resources/${FILENAME} COPYONLY)
        configure_file(${FILE} ${RESOURCES_DIRECTORY_ROOT}/MinSizeRel/resources/${FILENAME} COPYONLY)
        configure_file(${FILE} ${RESOURCES_DIRECTORY_ROOT}/Release/resources/${FILENAME} COPYONLY)
        configure_file(${FILE} ${RESOURCES_DIRECTORY_ROOT}/RelWithDebInfo/resources/${FILENAME} COPYONLY)
      endif ()
    else ()
      message(FATAL_ERROR "Resource files can be add only with GUI_APPLICATION, CONSOLE_APPLICATION OR TEST_APPLICATION")
    endif ()
  endforeach ()
endmacro()

################################################################################
# Internal commands

## @brief Auto define a grouping for source files in IDE project generation from directory.
## @remarks Internal use only.
macro(auto_source_group)
  foreach(FILE ${ARGN})
    get_filename_component(FOLDER ${FILE} DIRECTORY)
    if (FOLDER)
      string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" FOLDER ${FOLDER})
      string(REPLACE "./" "" FOLDER ${FOLDER})
      string(REPLACE "/" "\\\\" FOLDER ${FOLDER})
      source_group(${FOLDER} FILES ${FILE})
    endif ()
  endforeach()
endmacro()

## @brief Read assembly information file. Typically property/assembly_info.cpp file.
## @remarks Internal use only.
macro(read_assembly_informations)
  if (EXISTS ${ASSEMBLY_INFORMATIONS_FILE})
    print("Reading Assembly Information file [${ASSEMBLY_INFORMATIONS_FILE}]...")
    set(READING_ASSEMBLY_INFORMATIONS_FILE ON)
      file(READ ${ASSEMBLY_INFORMATIONS_FILE} ASSEMBLY_INFORMATION_STRING)
    string(REPLACE "\n" ";" ASSEMBLY_INFORMATION_LIST ${ASSEMBLY_INFORMATION_STRING})
    list(REMOVE_ITEM ASSEMBLY_INFORMATION_LIST "")
  
    foreach(ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LIST})
      string(STRIP ${ASSEMBLY_INFORMATION_LINE} ASSEMBLY_INFORMATION_LINE)
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_title_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_TITLE "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_description_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_DESCRIPTION "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_configuration_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_CONFIGURATION "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_company_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_COMPANY "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_product_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_PRODUCT "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_copyright_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_COPYRIGHT "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_trademark_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_TRADEMARK "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_culture_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_CULTURE "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assemblyV_version_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_VERSION "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
  
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_file_version_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_FILE_VERSION "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
   
      if (${ASSEMBLY_INFORMATION_LINE} MATCHES "(assembly_guid_*)")
        string(REGEX MATCH "\\(.*\\)" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "(\"" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        string(REPLACE "\")" "" ASSEMBLY_INFORMATION_LINE ${ASSEMBLY_INFORMATION_LINE})
        set(ASSEMBLY_GUID "${ASSEMBLY_INFORMATION_LINE}")
      endif ()
    endforeach()
    set(READING_ASSEMBLY_INFORMATIONS_FILE OFF)
    auto_source_group(${ASSEMBLY_INFORMATIONS_FILE})
  endif ()
endmacro()

## @brief split resource to name and file.
## @remarks Internal use only.
macro(split_resource RESOURCE_LINE NAME FILE)
  set(RESOURCE_STR ${RESOURCE_LINE})
  string(FIND ${RESOURCE_STR} "=" INDEX)
  string(SUBSTRING ${RESOURCE_STR} 0 ${INDEX} NAME_STR)
  MATH(EXPR INDEX "${INDEX}+1")
  string(SUBSTRING ${RESOURCE_STR} ${INDEX} -1 FILE_STR)
  set(NAME ${NAME_STR})
  set(FILE ${FILE_STR})
endmacro()

## @brief split resource string to name, value and comment.
## @remarks Internal use only.
macro(split_resource_string RESOURCE_STRING NAME VALUE COMMENT)
  set(RESOURCE_STR ${RESOURCE_STRING})
  string(FIND ${RESOURCE_STR} "=\"" INDEX)
  string(SUBSTRING ${RESOURCE_STR} 0 ${INDEX} NAME_STR)
  MATH(EXPR INDEX "${INDEX}+1")
  string(SUBSTRING ${RESOURCE_STR} ${INDEX} -1 RESOURCE_STR)
  string(FIND ${RESOURCE_STR} "\"=" INDEX)
  MATH(EXPR INDEX "${INDEX}+1")
  string(SUBSTRING ${RESOURCE_STR} 0 ${INDEX} VALUE_STR)
  MATH(EXPR INDEX "${INDEX}+1")
  string(SUBSTRING ${RESOURCE_STR} ${INDEX} -1 COMMENT_STR)
  set(NAME ${NAME_STR})
  set(VALUE ${VALUE_STR})
  set(COMMENT ${COMMENT_STR})
endmacro()

## @brief split setting to name, type and value.
## @remarks Internal use only.
macro(split_setting SETTING NAME TYPE VALUE)
  set(SETTING_STR ${SETTING})
  string(FIND ${SETTING_STR} "=" INDEX)
  string(SUBSTRING ${SETTING_STR} 0 ${INDEX} NAME_STR)
  MATH(EXPR INDEX "${INDEX}+1")
  string(SUBSTRING ${SETTING_STR} ${INDEX} -1 SETTING_STR)
  string(FIND ${SETTING_STR} "=" INDEX)
  string(SUBSTRING ${SETTING_STR} 0 ${INDEX} TYPE_STR)
  MATH(EXPR INDEX "${INDEX}+1")
  string(SUBSTRING ${SETTING_STR} ${INDEX} -1 VALUE_STR)
  set(NAME ${NAME_STR})
  set(TYPE ${TYPE_STR})
  set(VALUE ${VALUE_STR})
endmacro()

## @brief Write macOS application informations file. Typically application_name.app/info.plist file.
## @remarks Internal use only.
macro(write_macos_application_informations_file)
  #print("Writing macOS application informations...")
  set(MACOSX_BUNDLE_BUNDLE_NAME "${ASSEMBLY_TITLE}")
  set(MACOSX_BUNDLE_COPYRIGHT ${ASSEMBLY_COPYRIGHT})
  # The following line produce the warning "[default] Unable to load Info.plist exceptions (eGPUOverrides)" in Xcode when Xcode run application.
  set(MACOSX_BUNDLE_GUI_IDENTIFIER "${ASSEMBLY_GUID}")
  get_filename_component(APPLICATION_ICON_FILENAME "${APPLICATION_ICON}" NAME)
  set(MACOSX_BUNDLE_ICON_FILE "${APPLICATION_ICON_FILENAME}")
  set(MACOSX_BUNDLE_INFO_STRING "${ASSEMBLY_DESCRIPTION}")
  if (ASSEMBLY_FILE_VERSION)
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${ASSEMBLY_FILE_VERSION})
  else ()
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION})
  endif ()
endmacro()

## @brief Write linux application informations file. Typically ~/.local/share/applications/application_name.desktop file.
## @remarks Internal use only.
macro(write_linux_application_informations_file)
  set(APPLICATION_INFORMATIONS_FILE ${CMAKE_CURRENT_BINARY_DIR}/resources/${APPLICATION_NAME}.desktop)
  
  set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
  if (CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
  endif ()
  #print("Writing linux application informations file [${APPLICATION_INFORMATIONS_FILE}]...")
 
  if (APPLICATION_DISPLAY)
    set(NO_DISPLAY "false")
  else ()  
    set(NO_DISPLAY "true")
  endif ()
  
  if ("${APPLICATION_TYPE}" STREQUAL "CONSOLE_APPLICATION" OR "${APPLICATION_TYPE}" STREQUAL "TEST_APPLICATION")
    set(TERMINAL "true")
  else ()  
    set(TERMINAL "false")
  endif ()
  
  if (ASSEMBLY_FILE_VERSION)
    set(VERSION ${ASSEMBLY_FILE_VERSION})
  else ()
    set(VERSION ${PROJECT_VERSION})
  endif ()
  
  if (APPLICATION_ICON)
    get_filename_component(APPLICATION_ICON_FILENAME ${APPLICATION_ICON} NAME_WE)
    set(ICON "Icon=${APPLICATION_ICON_FILENAME}\n")
  elseif (TERMINAL)
    set(ICON "Icon=terminal\n")
  endif ()
  
  if ("${ASSEMBLY_TITLE}" STREQUAL "")
    set(NAME "${APPLICATION_NAME}")
  else ()  
    set(NAME "${ASSEMBLY_TITLE}")
  endif ()
  
  file(WRITE ${APPLICATION_INFORMATIONS_FILE}
    "[Desktop Entry]\n"
    "Type=Application\n"
    "Encoding=UTF-8\n"
    "Comment=${ASSEMBLY_DESCRIPTION}\n"
    "Exec=${RUNTIME_OUTPUT_DIRECTORY}/${APPLICATION_NAME}\n"
    "${ICON}"
    "Name=${NAME}\n"
    "NoDisplay=${NO_DISPLAY}\n"
    "Terminal=${TERMINAL}\n"
    "Version=${VERSION}\n"
  )

  if (APPLICATION_REGISTERED)
    file(COPY ${CMAKE_CURRENT_BINARY_DIR}/resources/${APPLICATION_NAME}.desktop DESTINATION "$ENV{HOME}/.local/share/applications" FILE_PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ)
    configure_file(${CMAKE_CURRENT_BINARY_DIR}/resources/${APPLICATION_NAME}.desktop $ENV{HOME}/.local/share/applications/${APPLICATION_NAME}.desktop COPYONLY)
  endif ()

  source_group(Resources FILES ${APPLICATION_INFORMATIONS_FILE})
  set(PROJECT_SOURCES "${PROJECT_SOURCES};${APPLICATION_INFORMATIONS_FILE}")
endmacro()

## @brief Write windows application informations file. Typically ${CMAKE_CURRENT_BINARY_DIR}/resources/ApplicationName.rc file.
## @remarks Internal use only.
macro(write_windows_application_informations_file)
  set(APPLICATION_INFORMATIONS_FILE ${CMAKE_CURRENT_BINARY_DIR}/resources/${APPLICATION_NAME}.rc)

  #print("Writing windows application informations file [${APPLICATION_INFORMATIONS_FILE}]...")
  
  if (ASSEMBLY_FILE_VERSION)
    set(FILE_VERSION_STR "${ASSEMBLY_FILE_VERSION}.0")
  elseif (PROJECT_VERSION)
    set(FILE_VERSION_STR "${PROJECT_VERSION}.0")
  else ()
    set(FILE_VERSION_STR "1.0.0.0")
  endif ()

  if (NOT FILE_VERSION_STR OR "${FILE_VERSION_STR}" STREQUAL "" OR "${FILE_VERSION_STR}" STREQUAL ".0")
    set(FILE_VERSION "1,0,0,0")
  else ()
    string(REPLACE "." "," FILE_VERSION ${FILE_VERSION_STR})
  endif ()
  
  if (ASSEMBLY_FILE_VERSION)
    set(PRODUCT_VERSION_STR "${ASSEMBLY_FILE_VERSION}")
  elseif (PROJECT_VERSION)
    set(PRODUCT_VERSION_STR "${PROJECT_VERSION}")
  endif ()

  if (NOT PRODUCT_VERSION_STR OR "${PRODUCT_VERSION_STR}" STREQUAL "")
    set(PRODUCT_VERSION "1,0,0")
  else ()
    string(REPLACE "." "," PRODUCT_VERSION ${PRODUCT_VERSION_STR})
  endif ()
  
  string(TOUPPER ${APPLICATION_NAME} UPPER_APPLICATION_NAME)

  if (APPLICATION_ICON)
    get_filename_component(ABSOLUTE_PATH_FILE_ICON "${APPLICATION_ICON}"  REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    string(REPLACE "/" "\\\\" ABSOLUTE_PATH_FILE_ICON ${ABSOLUTE_PATH_FILE_ICON})
    set(IDI_EXECUTABLE_ICON "IDI_${UPPER_APPLICATION_NAME} ICON DISCARDABLE \"${ABSOLUTE_PATH_FILE_ICON}\"\n\n")
  endif ()

  file(WRITE ${APPLICATION_INFORMATIONS_FILE}
    "#pragma region xtd generated code\n"
    "// This code was generated by CMake script.\n"
    "//\n"
    "// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.\n"
    "\n"
    "#include <Windows.h>\n"
    "\n"
    "LANGUAGE LANG_NEUTRAL, SUBLANG_NEUTRAL\n"
    "#pragma code_page(65001)\n"
    "\n"
    "${IDI_EXECUTABLE_ICON}"
    "VS_VERSION_INFO VERSIONINFO\n"
    " FILEVERSION ${FILE_VERSION}\n"
    " PRODUCTVERSION ${PRODUCT_VERSION}\n"
    " FILEFLAGSMASK 0x0L\n"
    "#if !defined(NDEBUG)\n"
    " FILEFLAGS VS_FF_DEBUG\n"
    "#endif\n"
    " FILEOS VOS_NT\n"
    " FILETYPE VFT_APP\n"
    " FILESUBTYPE VFT2_UNKNOWN\n"
    "BEGIN\n"
    "  BLOCK \"StringFileInfo\"\n"
    "  BEGIN\n"
    "    BLOCK \"000004b0\"\n"
    "    BEGIN\n"
    "      VALUE \"CompanyName\", \"${ASSEMBLY_COMPANY}\"\n"
    "      VALUE \"FileDescription\", \"${ASSEMBLY_TITLE}\"\n"
    "      VALUE \"FileVersion\", \"${FILE_VERSION}\"\n"
    "      VALUE \"InternalName\", \"${APPLICATION_NAME}\"\n"
    "      VALUE \"LegalCopyright\", \"${ASSEMBLY_COPYRIGHT}\"\n"
    "      VALUE \"LegalTrademarks1\", \"${ASSEMBLY_TRADEMARK}\"\n"
    "      VALUE \"LegalTrademarks2\", \"${ASSEMBLY_TRADEMARK}\"\n"
    "      VALUE \"OriginalFilename\", \"${APPLICATION_NAME}.exe\"\n"
    "      VALUE \"ProductName\", \"${ASSEMBLY_PRODUCT}\"\n"
    "      VALUE \"ProductVersion\", \"${PRODUCT_VERSION}\"\n"
    "    END\n"
    "  END\n"
    "  BLOCK \"VarFileInfo\"\n"
    "  BEGIN\n"
    "    VALUE \"Translation\", 0x0, 1200\n"
    "  END\n"
    "END\n"
    "#pragma endregion\n"
  )
  
  source_group(Resources FILES ${APPLICATION_INFORMATIONS_FILE})
  set(PROJECT_SOURCES "${PROJECT_SOURCES};${APPLICATION_INFORMATIONS_FILE}")
endmacro()

## @brief Write project config cmake file. Typically ${CMAKE_CURRENT_BINARY_DIR}/${APPLICATION_NAME}Config.cmake
## @remarks Internal use only.
macro(write_project_config_cmake)
  string(TOUPPER ${APPLICATION_NAME} TARGET_NAME_UPPER)
  if (INSTALL_COMPONENTS)
    string(REPLACE ";" " " LIBRARIES ${INSTALL_COMPONENTS})
  endif ()
  if (PROJECT_REFERENCES)
    string(REPLACE ";" " " REFERENCES ${PROJECT_REFERENCES})
  endif ()
  set(INSTALL_CMAKE_PROJECT_CONFIG_FILE "${CMAKE_CURRENT_BINARY_DIR}/${APPLICATION_NAME}_config.cmake")
  file(WRITE ${INSTALL_CMAKE_PROJECT_CONFIG_FILE}
    "include(CMakeFindDependencyMacro)\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/${APPLICATION_NAME}.cmake\")\n"
    "\n"
    "get_filename_component(${TARGET_NAME_UPPER}_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
    "get_filename_component(${TARGET_NAME_UPPER}_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
    "\n"
    "find_dependency(xtd REQUIRED)\n"
  )

  foreach(PACKAGE ${PROJECT_PACKAGES})
    file(APPEND ${INSTALL_CMAKE_PROJECT_CONFIG_FILE} "find_dependency(${PACKAGE} REQUIRED)\n")
  endforeach()

  file(APPEND ${INSTALL_CMAKE_PROJECT_CONFIG_FILE}
    "\n"
    "set(${TARGET_NAME_UPPER}_LIBRARIES ${LIBRARIES} xtd.core ${REFERENCES})\n"
    "set(${TARGET_NAME_UPPER}_FOUND TRUE)\n"
  )
endmacro()

## @brief Write resources file header. Typically properties/resources.h
## @remarks Internal use only.
macro(write_resources_file_header)
  set(RESOURCES_FILE_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/properties/resources.h)

  if (APPLE AND "${APPLICATION_TYPE}" STREQUAL "GUI_APPLICATION")
    set(PREFIX_RESOURCE_PATH "\"..\", \"Resources\"")
  else ()
    set(PREFIX_RESOURCE_PATH "\"resources\"")
  endif ()

  file(WRITE ${RESOURCES_FILE_HEADER}
    "#pragma region xtd generated code\n"
    "// This code was generated by CMake script.\n"
    "//\n"
    "// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.\n"
    "\n"
    "#pragma once\n"
    "\n"
    "#include <exception>\n"
    "#include <${XTD_PROJECT_INCLUDE_FILE}>\n"
    "\n"
    "namespace ${APPLICATION_DEFAULT_NAMESPACE}::properties {\n"
    "  /// @brief A strongly-typed resource class, for looking up localized strings, etc.\n"
    "  /// @details This class was auto-generated by CMake script. To add or remove a member, edit your CMakeList.txt file then rerun cmake tools.\n"
    "  class resources static_ {\n"
    "  public:\n"
  )
  
  foreach(RESOURCE_LINE ${PROJECT_RESOURCES})
    split_resource(${RESOURCE_LINE} NAME FILE)
    get_filename_component(FILENAME ${FILE} NAME)
    get_filename_component(EXTENSION ${FILE} EXT)

    string(TOLOWER ${EXTENSION} EXTENSION)
    if ("${EXTENSION}" STREQUAL ".bmp" OR "${EXTENSION}" STREQUAL ".gif" OR "${EXTENSION}" STREQUAL ".jpeg" OR "${EXTENSION}" STREQUAL ".jpg" OR "${EXTENSION}" STREQUAL ".png" OR "${EXTENSION}" STREQUAL ".tif" OR "${EXTENSION}" STREQUAL ".tiff")
       file(APPEND ${RESOURCES_FILE_HEADER}
        "    /// @brief Looks up a localized resource of type xtd::drawing::bitmap.\n"
        "    static const xtd::drawing::bitmap& ${NAME}() {\n"
        "      static xtd::drawing::bitmap bitmap(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), ${PREFIX_RESOURCE_PATH}, \"${FILENAME}\"));\n"
        "      return bitmap;\n"
        "    }\n"
        "\n"
      )
    elseif ("${EXTENSION}" STREQUAL ".ico")
       file(APPEND ${RESOURCES_FILE_HEADER}
        "    /// @brief Looks up a localized resource of type xtd::drawing::icon.\n"
        "    static const xtd::drawing::icon& ${NAME}() {\n"
        "      static xtd::drawing::icon icon(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), ${PREFIX_RESOURCE_PATH}, \"${FILENAME}\"));\n"
        "      return icon;\n"
        "    }\n"
        "\n"
      )
    elseif ("${EXTENSION}" STREQUAL ".txt")
      file(APPEND ${RESOURCES_FILE_HEADER}
        "    /// @brief Looks up a localized resource of type std::string.\n"
        "    static const std::string& ${NAME}() {\n"
        "      static std::string text = xtd::io::file::read_all_text(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), ${PREFIX_RESOURCE_PATH}, \"${FILENAME}\"));\n"
        "      return text;\n"
        "    }\n"
        "\n"
      )
    elseif ("${EXTENSION}" STREQUAL ".wav")
      file(APPEND ${RESOURCES_FILE_HEADER}
        "    /// @brief Looks up a localized resource of type xtd::forms::sound.\n"
        "    static const xtd::object& ${NAME}() {\n"
        "      throw std::logic_error(\"not yet implemented\");\n"
        "    }\n"
        "\n"
      )
    else ()
      file(APPEND ${RESOURCES_FILE_HEADER}
        "    /// @brief Looks up a localized resource of type std::string.\n"
        "    static const std::string& ${NAME}() {\n"
        "      static std::string text = xtd::io::file::read_all_text(xtd::io::path::combine(xtd::io::path::get_directory_name(xtd::environment::get_command_line_args()[0]), ${PREFIX_RESOURCE_PATH}, \"${FILENAME}\"));\n"
        "      return text;\n"
        "    }\n"
        "\n"
      )
    endif ()
  endforeach()

    
  foreach(RESOURCE_STRING ${PROJECT_RESOURCE_STRINGS})
    split_resource_string(${RESOURCE_STRING} NAME VALUE COMMENT)

    file(APPEND ${RESOURCES_FILE_HEADER}
      "    /// @brief Looks up a localized resource of type std::string.\n"
      "    static const std::string& ${NAME}() {\n"
      "      static std::string str = ${VALUE};\n"
      "      return str;\n"
      "    }\n"
      "\n"
    )
  endforeach()
  
  file(APPEND ${RESOURCES_FILE_HEADER}
    "  };\n"
    "}\n"
    "\n"
    "#pragma endregion\n"
  )

  auto_source_group(${RESOURCES_FILE_HEADER}) 
  set(PROJECT_SOURCES "${PROJECT_SOURCES};${RESOURCES_FILE_HEADER}")
endmacro()

## @brief Write resources file header. Typically properties/settings.h
## @remarks Internal use only.
macro(write_settings_file_header)
  set(SETTINGS_FILE_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/properties/settings.h)

  file(WRITE ${SETTINGS_FILE_HEADER}
    "#pragma region xtd generated code\n"
    "// This code was generated by CMake script.\n"
    "//\n"
    "// Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.\n"
    "\n"
    "#pragma once\n"
    "\n"
    "#include <${XTD_PROJECT_INCLUDE_FILE}>\n"
    "\n"
    "namespace ${APPLICATION_DEFAULT_NAMESPACE}::properties {\n"
    "  class settings : public xtd::forms::component {\n"
    "  public:\n"
    "    settings() : ::${APPLICATION_DEFAULT_NAMESPACE}::properties::settings(true) {}\n"
    "\n"
    "    static ::${APPLICATION_DEFAULT_NAMESPACE}::properties::settings& default_settings() {\n"
    "      static ::${APPLICATION_DEFAULT_NAMESPACE}::properties::settings default_settings;\n"
    "      return default_settings;\n"
    "    }\n"
    "\n"
  )
    
  if (PROJECT_USER_SETTINGS)
    foreach(SETTING ${PROJECT_USER_SETTINGS})
      split_setting(${SETTING} NAME TYPE VALUE)
      file(APPEND ${SETTINGS_FILE_HEADER}
        "    ${TYPE} ${NAME}() const {return ${NAME}_;}\n"
        "    void ${NAME}(${TYPE} value) {${NAME}_ = value;}\n"
        "\n"
      )
    endforeach()
  endif ()
  
  if (PROJECT_APPLICATION_SETTINGS)
    foreach(SETTING ${PROJECT_APPLICATION_SETTINGS})
      split_setting(${SETTING} NAME TYPE VALUE)
      file(APPEND ${SETTINGS_FILE_HEADER}
        "    ${TYPE} ${NAME}() {return ${VALUE};}\n"
        "\n"
      )
    endforeach()
  endif ()

  
  file(APPEND ${SETTINGS_FILE_HEADER}
    "    void reload() {\n"
  )

  if (PROJECT_USER_SETTINGS)
    foreach(SETTING ${PROJECT_USER_SETTINGS})
      split_setting(${SETTING} NAME TYPE VALUE)
      file(APPEND ${SETTINGS_FILE_HEADER} "      ${NAME}_ = settings_.read(\"${NAME}\", ${NAME}_);\n")
    endforeach()
  endif ()

  file(APPEND ${SETTINGS_FILE_HEADER}
    "    }\n"
    "\n"
  )

  file(APPEND ${SETTINGS_FILE_HEADER}
    "    void reset() {\n"
    "      settings_.reset();\n"
    "      *this = settings(false);\n"
    "      reload();\n"
    "    }\n"
    "\n"
  )

  file(APPEND ${SETTINGS_FILE_HEADER}
    "    void save() {\n"
  )

  if (PROJECT_USER_SETTINGS)
    foreach(SETTING ${PROJECT_USER_SETTINGS})
      split_setting(${SETTING} NAME TYPE VALUE)
      file(APPEND ${SETTINGS_FILE_HEADER} "      settings_.write(\"${NAME}\", ${NAME}_);\n")
    endforeach()
    file(APPEND ${SETTINGS_FILE_HEADER} "      settings_.save();\n")
  endif ()

  file(APPEND ${SETTINGS_FILE_HEADER}
    "    }\n"
    "\n"
  )

  file(APPEND ${SETTINGS_FILE_HEADER}
    "  private:\n"
    "    settings(bool load) {if (load) reload();}\n"
    "    xtd::forms::settings settings_;\n"
  )

  if (PROJECT_USER_SETTINGS)
    foreach(SETTING ${PROJECT_USER_SETTINGS})
      split_setting(${SETTING} NAME TYPE VALUE)
      file(APPEND ${SETTINGS_FILE_HEADER}
        "    ${TYPE} ${NAME}_ {${VALUE}};\n"
      )
    endforeach()
  endif ()
  
  file(APPEND ${SETTINGS_FILE_HEADER}
    "  };\n"
    "}\n"
    "\n"
    "#pragma endregion\n"
  )

  auto_source_group(${SETTINGS_FILE_HEADER}) 
  set(PROJECT_SOURCES "${PROJECT_SOURCES};${SETTINGS_FILE_HEADER}")
endmacro()

################################################################################
# Variables

## @brief Contains default namespace use by application.
## @see application_default_namespace
set(APPLICATION_DEFAULT_NAMESPACE ${PROJECT_NAME})

## @brief Contains application name.
## @see application_name
set(APPLICATION_NAME ${PROJECT_NAME})

## @brief Contains boolean that specify if application is registered or not on the system.
##  * ON Registered
##  * OFF Not registered
## @see application_registered
set(APPLICATION_REGISTERED ON)

# @brief Contains build type (Debug or Release)
if (CMAKE_BUILD_TYPE)
  set(BUILD_TYPE ${CMAKE_BUILD_TYPE})
else()
  set(BUILD_TYPE Debug)
endif()

set(ASSEMBLY_INFORMATIONS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/properties/assembly_info.cpp")

## @brief The path to the top level of the build tree.
set(BINARY_DIRECTORY ${PROJECT_BINARY_DIR})

if(MSVC)
  set(GUI WIN32)
elseif (APPLE)
  set(GUI MACOSX_BUNDLE)
endif ()

## @brief The path to user home.
if (MSVC)
  set(USER_DIRECTORY "$ENV{HOMEPATH}")
  string(REPLACE "\\" "/" USER_DIRECTORY ${USER_DIRECTORY})
else ()
  set(USER_DIRECTORY "$ENV{HOME}")
endif ()

if (NOT INSTALL_NAME)
  set(INSTALL_NAME ${APPLICATION_NAME})
endif ()

## @brief Set project path. This path is used by add_prejects macro.
set(PROJECT_PATH "${PROJECT_PATH}/${PROJECT_NAME}")

################################################################################
# Globals settings

# set application informations (properties/assembly_info.cpp)
read_assembly_informations()

# standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# standard C
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON)
set(CMAKE_DEBUG_POSTFIX d)

enable_testing()

# add ASSEMBLY_VERSION definition
#if (NOT PROJECT_VERSION AND XTD_VERSION)
#  set(PROJECT_VERSION ${XTD_VERSION})
#  remove_definitions(-DXTD_APPLICATION_VERSION)
#  add_definitions(-D__XTD_APPLICATION_VERSION__="${PROJECT_VERSION}")
#endif ()

# add compile and link flags
if (MSVC)
  add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8 /wd4251 /wd4275")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif ()

add_definitions(-D__CMAKE_INSTALL_PREFIX__="${CMAKE_INSTALL_PREFIX}")
if (NOT XTD_PROJECT_INCLUDE_FILE)
  set(XTD_PROJECT_INCLUDE_FILE "xtd/xtd")
endif ()

if (NOT "${xtd_DIR}" STREQUAL "xtd_DIR-NOTFOUND")
  get_filename_component(XTD_PATH_BASE "${xtd_DIR}" DIRECTORY)
  add_definitions(-D__XTD_INCLUDE_PATH__="${XTD_PATH_BASE}/include")
  add_definitions(-D__XTD_LIB_PATH__="${XTD_PATH_BASE}/lib")
  add_definitions(-D__XTD_CONSOLE_INCLUDE_PATH__="${XTD_PATH_BASE}/include")
  add_definitions(-D__XTD_CONSOLE_LIB_PATH__="${XTD_PATH_BASE}/lib")
  add_definitions(-D__XTD_FORMS_INCLUDE_PATH__="${XTD_PATH_BASE}/include")
  add_definitions(-D__XTD_FORMS_LIB_PATH__="${XTD_PATH_BASE}/lib")
  add_definitions(-D__XTD_FORMS_RESOURCES_PATH__="${XTD_PATH_BASE}/share/xtd/resources")
else ()
  if (NOT "${xtd.forms_DIR}" STREQUAL "xtd.forms_DIR-NOTFOUND")
    get_filename_component(XTD_FORMS_PATH_BASE "${xtd.forms_DIR}" DIRECTORY)
    add_definitions(-D__XTD_FORMS_INCLUDE_PATH__="${XTD_FORMS_PATH_BASE}$/include")
    add_definitions(-D__XTD_FORMS_LIB_PATH__="${XTD_FORMS_PATH_BASE}$/lib")
    add_definitions(-D__XTD_FORMS_RESOURCES_PATH__="${XTD_FORMS_PATH_BASE}/share/xtd/resources")
  elseif (NOT "${xtd.console_DIR}" STREQUAL "xtd.console_DIR-NOTFOUND")
    get_filename_component(XTD_CONSOLE_PATH_BASE "${xtd.console_DIR}" DIRECTORY)
    add_definitions(-D__XTD_CONSOLE_INCLUDE_PATH__="${XTD_CONSOLE_PATH_BASE}$/include")
    add_definitions(-D__XTD_CONSOLE_LIB_PATH__="${XTD_CONSOLE_PATH_BASE}$/lib")
  endif ()
endif()

# add external packages
#if(NOT APPLE AND NOT ANDROID AND NOT CMAKE_HOST_SOLARIS AND UNIX)
#  find_package(PkgConfig REQUIRED)
#  pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
#  include_directories(${GTKMM_INCLUDE_DIRS})
#  link_directories(${GTKMM_LIBRARY_DIRS})
#  
#  pkg_check_modules(GSOUND REQUIRED gsound)
#  include_directories(${GSOUND_INCLUDE_DIRS})
#  link_directories(${GSOUND_LIBRARY_DIRS})
#endif ()

################################################################################
# Reference Guide Generator

option(ADD_COMMAND_REFERENCE_GUIDE_GENERATOR "Add command Referecne Guide Generator" ON)
option(DOWNLOAD_DOXYGEN "Download and build doxygen from Github" OFF)

if (ADD_COMMAND_REFERENCE_GUIDE_GENERATOR AND NOT DOXYGEN_FOUND)  
  find_package(Doxygen QUIET)
  if (DOXYGEN_FOUND)
    set(DOXYGEN_EXECUTABLE Doxygen::doxygen)
  elseif (NOT DOXYGEN_FOUND AND DOWNLOAD_DOXYGEN)
    ExternalProject_Add(doxygen GIT_REPOSITORY https://github.com/doxygen/doxygen.git GIT_TAG Release_1_8_13 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
    set(DOXYGEN_FOUND TRUE)
    set(DOXYGEN_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/doxygen)
    set(DOXYGEN_PROJECT doxygen)
  else ()
    message(FATAL_ERROR "Doxygen not found try with set \"DOWNLOAD_DOXYGEN\" option to ON")
  endif ()
  
  if (NOT "$ENV{PROJECT_DOCUMENTATION_ROOT}" STREQUAL "")
    set(PROJECTS_DOCUMENTATIONS "$ENV{PROJECT_DOCUMENTATION_ROOT}")
  elseif (NOT "$ENV{HOMEPATH}" STREQUAL "")
    set(PROJECTS_DOCUMENTATIONS "$ENV{HOMEPATH}\\Projects\\Documentations")
  elseif (NOT "$ENV{HOME}" STREQUAL "")
    set(PROJECTS_DOCUMENTATIONS "$ENV{HOME}/Projects/Documentations")
  else ()
    set(PROJECTS_DOCUMENTATIONS "~/Projects/Documentations")
  endif ()
  
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/docs)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/docs/. DESTINATION ${PROJECTS_DOCUMENTATIONS}/${PROJECT_NAME}/docs)
  endif ()
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/examples)
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/examples/. DESTINATION ${PROJECTS_DOCUMENTATIONS}/${PROJECT_NAME}/examples)
  endif ()
  file(MAKE_DIRECTORY ${PROJECTS_DOCUMENTATIONS}/${PROJECT_NAME}/ReferenceGuide)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/.doxygen.txt)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.doxygen.txt ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt @ONLY)
    add_custom_target(ReferenceGuideGenerator ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt WORKING_DIRECTORY ${PROJECTS_DOCUMENTATIONS}/${PROJECT_NAME} COMMENT "Doxygen Reference Guide generation" DEPENDS ${DOXYGEN_PROJECT} VERBATIM)
  else ()
    add_custom_target(ReferenceGuideGenerator WORKING_DIRECTORY ${PROJECTS_DOCUMENTATIONS}/${PROJECT_NAME} COMMENT "Doxygen Reference Guide generation" DEPENDS ${DOXYGEN_PROJECT} VERBATIM)
  endif ()
  set_target_properties(ReferenceGuideGenerator PROPERTIES FOLDER commands)
endif ()
