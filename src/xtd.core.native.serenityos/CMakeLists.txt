cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.serenityos)
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
  "include/xtd/xtd.core.native.serenityos.hpp"
  "include/xtd/native/serenityos/mutex.hpp"
  "include/xtd/native/serenityos/semaphore.hpp"
  "include/xtd/native/serenityos/shell_execute.hpp"
  "include/xtd/native/serenityos/strings.hpp"
)
add_sources(
  "src/xtd/native/serenityos/condition_variable.cpp"
  "src/xtd/native/serenityos/console.cpp"
  "src/xtd/native/serenityos/culture_info.cpp"
  "src/xtd/native/serenityos/critical_section.cpp"
  "src/xtd/native/serenityos/cryptography.cpp"
  "src/xtd/native/serenityos/date_time.cpp"
  "src/xtd/native/serenityos/debugger.cpp"
  "src/xtd/native/serenityos/directory.cpp"
  "src/xtd/native/serenityos/dns.cpp"
  "src/xtd/native/serenityos/drive.cpp"
  "src/xtd/native/serenityos/environment.cpp"
  "src/xtd/native/serenityos/file.cpp"
  "src/xtd/native/serenityos/file_system.cpp"
  "src/xtd/native/serenityos/guid.cpp"
  "src/xtd/native/serenityos/interlocked.cpp"
  "src/xtd/native/serenityos/memory.cpp"
  "src/xtd/native/serenityos/named_event_wait_handle.cpp"
  "src/xtd/native/serenityos/named_mutex.cpp"
  "src/xtd/native/serenityos/named_semaphore.cpp"
  "src/xtd/native/serenityos/path.cpp"
  "src/xtd/native/serenityos/process.cpp"
  "src/xtd/native/serenityos/settings.cpp"
  "src/xtd/native/serenityos/socket.cpp"
  "src/xtd/native/serenityos/speech_synthesizer.cpp"
  "src/xtd/native/serenityos/stack_trace.cpp"
  "src/xtd/native/serenityos/system_sound.cpp"
  "src/xtd/native/serenityos/thread.cpp"
  "src/xtd/native/serenityos/types.cpp"
  "src/xtd/native/serenityos/unnamed_event_wait_handle.cpp"
  "src/xtd/native/serenityos/unnamed_mutex.cpp"
  "src/xtd/native/serenityos/unnamed_semaphore.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
