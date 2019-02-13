#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "xtd.properties" for configuration "Release"
set_property(TARGET xtd.properties APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(xtd.properties PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libxtd.properties.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS xtd.properties )
list(APPEND _IMPORT_CHECK_FILES_FOR_xtd.properties "${_IMPORT_PREFIX}/lib/libxtd.properties.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
