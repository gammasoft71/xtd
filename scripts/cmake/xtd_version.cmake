## @file
## @brief Contains xtd version.
## @remarks If you change the version of the porject xtd in the CMakeLists.txt (from the xtd root), the CMake script update_version_number.cmake will detect the change automatically and update the files that need the xtd version.
## @remarks see update_version_number.cmake

################################################################################
# xtd Version

set(XTD_VERSION ${PROJECT_XTD_VERSION})
set(XTD_VERSION_MAJOR ${PROJECT_XTD_VERSION_MAJOR})
set(XTD_VERSION_MINOR ${PROJECT_XTD_VERSION_MINOR})
set(XTD_VERSION_BUILD ${PROJECT_XTD_VERSION_BUILD})
set(XTD_VERSION_REVISION ${PROJECT_XTD_VERSION_REVISION})
set(XTD_NUMERIC_VERSION ${PROJECT_XTD_NUMERIC_VERSION})
