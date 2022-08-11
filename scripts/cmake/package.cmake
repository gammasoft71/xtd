## @file
## @brief Contains package settings.

#_______________________________________________________________________________
#                                                                         Common

set(CPACK_COMPONENTS_GROUPING ALL_COMPONENTS_IN_ONE)

SET(CPACK_OUTPUT_FILE_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/_packages")

set(CPACK_PACKAGE_CONTACT "gammasoft71@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Free open-source modern C++17 / C++20 framework to create console, forms (GUI like WinForms) and unit test applications on Microsoft Windows, Apple macOS and Linux." CACHE STRING "Package description for the package metadata")
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_PACKAGE_NAME ${PROJECT_NAME} CACHE STRING "The resulting package name")
set(CPACK_PACKAGE_VENDOR "Gammasoft71")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

# https://unix.stackexchange.com/a/11552/254512
# set(CPACK_PACKAGING_INSTALL_PREFIX "/opt/xtd")#/${CMAKE_PROJECT_VERSION}")
set(CPACK_VERBATIM_VARIABLES YES)

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")

#_______________________________________________________________________________
#                                                                         Bundle

set(CPACK_BUNDLE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake/xtd.icns")
set(CPACK_BUNDLE_NAME ${PROJECT_NAME})
set(CPACK_BUNDLE_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake/Info.plist")

#_______________________________________________________________________________
#                                                                         Debian

set(CPACK_DEB_COMPONENT_INSTALL YES)
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_DEBIAN_PACKAGE_DEPENDS
  #"build-essential"
  #"codeblocks"
  #"doxygen"
  #"libasound2-dev"
  #"libgsound-dev"
  #"libgtk-3-dev"
  #"libwxgtk3.2-gtk3-dev"
)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Gammasoft71")

#_______________________________________________________________________________
#                                                                            RPM

set(CPACK_RPM_PACKAGE_REQUIRES 
  #"alsa-lib-devel"
  #"gsound-devel"
  #"gtk3-devel"
)

#_______________________________________________________________________________
#                                                                          CPack

include(CPack)
