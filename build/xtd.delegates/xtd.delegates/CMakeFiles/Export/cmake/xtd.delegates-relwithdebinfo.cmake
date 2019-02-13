#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "xtd.delegates" for configuration "RelWithDebInfo"
set_property(TARGET xtd.delegates APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(xtd.delegates PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libxtd.delegates.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS xtd.delegates )
list(APPEND _IMPORT_CHECK_FILES_FOR_xtd.delegates "${_IMPORT_PREFIX}/lib/libxtd.delegates.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
