cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.linux)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_include_directories("include")

# add external packages
if (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "Haiku")
  add_references(network)
elseif (${XTD_NATIVE_OPERATING_SYSTEM} STREQUAL "SerenityOS")
  add_references()
elseif (UNIX)
  find_package(PkgConfig REQUIRED)

  add_definitions(-D__XTD_USE_ASOUND__)
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
  add_references(${GTK_LIBRARIES})

  add_references(dl rt asound uuid pthread)
endif ()

add_references(xtd.core.native)

add_sources(
  "include/xtd/core_native_export"
  "include/xtd/core_native_export.hpp"
  "include/xtd/xtd.core.native.linux.hpp"
  "include/xtd/native/linux/mutex.hpp"
  "include/xtd/native/linux/semaphore.hpp"
  "include/xtd/native/linux/shell_execute.hpp"
  "include/xtd/native/linux/strings.hpp"
)
add_sources(
  "src/xtd/native/linux/condition_variable.cpp"
  "src/xtd/native/linux/console.cpp"
  "src/xtd/native/linux/culture_info.cpp"
  "src/xtd/native/linux/critical_section.cpp"
  "src/xtd/native/linux/cryptography.cpp"
  "src/xtd/native/linux/date_time.cpp"
  "src/xtd/native/linux/debugger.cpp"
  "src/xtd/native/linux/directory.cpp"
  "src/xtd/native/linux/dns.cpp"
  "src/xtd/native/linux/drive.cpp"
  "src/xtd/native/linux/environment.cpp"
  "src/xtd/native/linux/file.cpp"
  "src/xtd/native/linux/file_system.cpp"
  "src/xtd/native/linux/guid.cpp"
  "src/xtd/native/linux/interlocked.cpp"
  "src/xtd/native/linux/memory.cpp"
  "src/xtd/native/linux/named_event_wait_handle.cpp"
  "src/xtd/native/linux/named_mutex.cpp"
  "src/xtd/native/linux/named_semaphore.cpp"
  "src/xtd/native/linux/path.cpp"
  "src/xtd/native/linux/process.cpp"
  "src/xtd/native/linux/settings.cpp"
  "src/xtd/native/linux/socket.cpp"
  "src/xtd/native/linux/speech_synthesizer.cpp"
  "src/xtd/native/linux/stack_trace.cpp"
  "src/xtd/native/linux/system_sound.cpp"
  "src/xtd/native/linux/thread.cpp"
  "src/xtd/native/linux/types.cpp"
  "src/xtd/native/linux/unnamed_event_wait_handle.cpp"
  "src/xtd/native/linux/unnamed_mutex.cpp"
  "src/xtd/native/linux/unnamed_semaphore.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
