cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.win32)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)
if (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "MSYS")
  add_references(msvcrt Version)
endif ()

add_references(xtd.core.native rpcrt4 ws2_32 ${XTD_CORE_NATIVE_3RDPARTY_LIBRARIES})
add_sources(
  include/xtd/xtd.core.native.win32.h
  include/xtd/xtd.core.native.win32
  include/xtd/native/win32/strings.h
  include/xtd/native/win32/strings
  src/xtd/native/win32/console.cpp
  src/xtd/native/win32/condition_variable.cpp
  src/xtd/native/win32/critical_section.cpp
  src/xtd/native/win32/cryptography.cpp
  src/xtd/native/win32/date_time.cpp
  src/xtd/native/win32/debugger.cpp
  src/xtd/native/win32/directory.cpp
  src/xtd/native/win32/dns.cpp
  src/xtd/native/win32/drive.cpp
  src/xtd/native/win32/environment.cpp
  src/xtd/native/win32/file.cpp
  src/xtd/native/win32/file_system.cpp
  src/xtd/native/win32/guid.cpp
  src/xtd/native/win32/interlocked.cpp
  src/xtd/native/win32/named_event_wait_handle.cpp
  src/xtd/native/win32/named_mutex.cpp
  src/xtd/native/win32/named_semaphore.cpp
  src/xtd/native/win32/path.cpp
  src/xtd/native/win32/process.cpp
  src/xtd/native/win32/socket.cpp
  src/xtd/native/win32/speech_synthesizer.cpp
  src/xtd/native/win32/stack_trace.cpp
  src/xtd/native/win32/system_sound.cpp
  src/xtd/native/win32/thread.cpp
  src/xtd/native/win32/translator.cpp
  src/xtd/native/win32/types.cpp
  src/xtd/native/win32/unnamed_event_wait_handle.cpp
  src/xtd/native/win32/unnamed_mutex.cpp
  src/xtd/native/win32/unnamed_semaphore.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
