cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.native.unix)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
if (APPLE)
  add_references("-framework Foundation -framework Cocoa")
elseif (NOT ANDROID)
  find_package(PkgConfig)
  pkg_check_modules(GTK gtk+-3.0)
  include_directories(${GTK_INCLUDE_DIRS})
  link_directories(${GTK_LIBRARY_DIRS})
  add_references(uuid pthread ${GTK_LIBRARIES})
endif ()
add_references(xtd.core.native)
add_sources(
  include/xtd/xtd.core.native.unix.h
  include/xtd/xtd.core.native.unix
  include/xtd/native/unix/strings.h
  src/xtd/native/unix/console.cpp
  src/xtd/native/unix/cryptography.cpp
  src/xtd/native/unix/debugger.cpp
  src/xtd/native/unix/dns.cpp
  src/xtd/native/unix/environment.cpp
  src/xtd/native/unix/file.cpp
  src/xtd/native/unix/guid.cpp
  src/xtd/native/unix/path.cpp
  src/xtd/native/unix/process.cpp
  src/xtd/native/unix/socket.cpp
  src/xtd/native/unix/translator.cpp
)
if (APPLE)
  add_sources(
    src/xtd/native/unix/debugger.mm
    src/xtd/native/unix/translator.mm
  )
endif()
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
