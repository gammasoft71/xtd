cmake_minimum_required(VERSION 3.3)

# Project
project(xtd.core.native.win32)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
add_references(rpcrt4)
add_references(ws2_32)
add_references(xtd.core.native)
add_sources(
  include/xtd/xtd.core.native.win32.h
  include/xtd/xtd.core.native.win32
  include/xtd/native/win32/strings.h
  src/xtd/native/win32/console.cpp
  src/xtd/native/win32/cryptography.cpp
  src/xtd/native/win32/debugger.cpp
  src/xtd/native/win32/directory.cpp
  src/xtd/native/win32/dns.cpp
  src/xtd/native/win32/environment.cpp
  src/xtd/native/win32/file.cpp
  src/xtd/native/win32/guid.cpp
  src/xtd/native/win32/path.cpp
  src/xtd/native/win32/process.cpp
  src/xtd/native/win32/socket.cpp
  src/xtd/native/win32/system_sound.cpp
  src/xtd/native/win32/translator.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
