cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.unix)
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
  "include/xtd/xtd.core.native.unix.hpp"
  "include/xtd/xtd.core.native.unix"
  "include/xtd/native/unix/mutex.hpp"
  "include/xtd/native/unix/mutex"
  "include/xtd/native/unix/semaphore.hpp"
  "include/xtd/native/unix/semaphore"
  "include/xtd/native/unix/shell_execute.hpp"
  "include/xtd/native/unix/shell_execute"
  "include/xtd/native/unix/strings.hpp"
  "include/xtd/native/unix/strings"
)
add_sources(
  "src/xtd/native/unix/condition_variable.cpp"
  "src/xtd/native/unix/console.cpp"
  "src/xtd/native/unix/critical_section.cpp"
  "src/xtd/native/unix/cryptography.cpp"
  "src/xtd/native/unix/date_time.cpp"
  "src/xtd/native/unix/debugger.cpp"
  "src/xtd/native/unix/directory.cpp"
  "src/xtd/native/unix/dns.cpp"
  "src/xtd/native/unix/drive.cpp"
  "src/xtd/native/unix/environment.cpp"
  "src/xtd/native/unix/file.cpp"
  "src/xtd/native/unix/file_system.cpp"
  "src/xtd/native/unix/guid.cpp"
  "src/xtd/native/unix/interlocked.cpp"
  "src/xtd/native/unix/memory.cpp"
  "src/xtd/native/unix/named_event_wait_handle.cpp"
  "src/xtd/native/unix/named_mutex.cpp"
  "src/xtd/native/unix/named_semaphore.cpp"
  "src/xtd/native/unix/path.cpp"
  "src/xtd/native/unix/process.cpp"
  "src/xtd/native/unix/settings.cpp"
  "src/xtd/native/unix/socket.cpp"
  "src/xtd/native/unix/speech_synthesizer.cpp"
  "src/xtd/native/unix/stack_trace.cpp"
  "src/xtd/native/unix/system_sound.cpp"
  "src/xtd/native/unix/thread.cpp"
  "src/xtd/native/unix/translator.cpp"
  "src/xtd/native/unix/types.cpp"
  "src/xtd/native/unix/unnamed_event_wait_handle.cpp"
  "src/xtd/native/unix/unnamed_mutex.cpp"
  "src/xtd/native/unix/unnamed_semaphore.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
