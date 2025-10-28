cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.freebsd)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_include_directories("include")

# add external packages
if (ANDROID)
  add_references()
elseif (UNIX)
  find_package(PkgConfig REQUIRED)

  pkg_check_modules(GSOUND QUIET gsound)
  if (GSOUND_LIBRARY_DIRS)
    add_definitions(-D__XTD_USE_GSOUND__)
    add_include_directories(${GSOUND_INCLUDE_DIRS})
    add_reference_directories(${GSOUND_LIBRARY_DIRS})
    add_references(${GSOUND_LIBRARIES})
  else ()
    message(WARNING "GSound not found. Please install GSound end retry to build xtd to have sound.")
  endif ()
  
  pkg_check_modules(GTK REQUIRED gtk+-3.0)
  add_definitions(-D__XTD_USE_GTK__)
  add_include_directories(${GTK_INCLUDE_DIRS})
  add_reference_directories(${GTK_LIBRARY_DIRS})
if (${XTD_OPERATING_SYSTEM_NAME} STREQUAL "FreeBSD")
  add_references(-L${GTK_LIBRARY_DIRS})
endif ()
  add_references(${GTK_LIBRARIES})

  add_references(dl execinfo rt asound uuid pthread sysinfo)
endif ()

add_references(xtd.core.native)

add_sources(
  "include/xtd/xtd.core.native.freebsd.hpp"
  "include/xtd/native/freebsd/mutex.hpp"
  "include/xtd/native/freebsd/semaphore.hpp"
  "include/xtd/native/freebsd/shell_execute.hpp"
  "include/xtd/native/freebsd/strings.hpp"
  "include/xtd/native/freebsd/strings"
)
add_sources(
  "src/xtd/native/freebsd/condition_variable.cpp"
  "src/xtd/native/freebsd/console.cpp"
  "src/xtd/native/freebsd/culture_info.cpp"
  "src/xtd/native/freebsd/critical_section.cpp"
  "src/xtd/native/freebsd/cryptography.cpp"
  "src/xtd/native/freebsd/date_time.cpp"
  "src/xtd/native/freebsd/debugger.cpp"
  "src/xtd/native/freebsd/directory.cpp"
  "src/xtd/native/freebsd/dns.cpp"
  "src/xtd/native/freebsd/drive.cpp"
  "src/xtd/native/freebsd/environment.cpp"
  "src/xtd/native/freebsd/file.cpp"
  "src/xtd/native/freebsd/file_system.cpp"
  "src/xtd/native/freebsd/guid.cpp"
  "src/xtd/native/freebsd/interlocked.cpp"
  "src/xtd/native/freebsd/memory.cpp"
  "src/xtd/native/freebsd/named_event_wait_handle.cpp"
  "src/xtd/native/freebsd/named_mutex.cpp"
  "src/xtd/native/freebsd/named_semaphore.cpp"
  "src/xtd/native/freebsd/path.cpp"
  "src/xtd/native/freebsd/process.cpp"
  "src/xtd/native/freebsd/settings.cpp"
  "src/xtd/native/freebsd/socket.cpp"
  "src/xtd/native/freebsd/speech_synthesizer.cpp"
  "src/xtd/native/freebsd/stack_trace.cpp"
  "src/xtd/native/freebsd/system_sound.cpp"
  "src/xtd/native/freebsd/thread.cpp"
  "src/xtd/native/freebsd/types.cpp"
  "src/xtd/native/freebsd/unnamed_event_wait_handle.cpp"
  "src/xtd/native/freebsd/unnamed_mutex.cpp"
  "src/xtd/native/freebsd/unnamed_semaphore.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
