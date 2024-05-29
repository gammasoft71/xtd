cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.posix)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)

# add external packages
if (ANDROID)
  add_references()
elseif (UNIX)
  find_package(PkgConfig REQUIRED)

  pkg_check_modules(GSOUND QUIET gsound)
  if (GSOUND_LIBRARY_DIRS)
    include_directories(${GSOUND_INCLUDE_DIRS})
    link_directories(${GSOUND_LIBRARY_DIRS})
    add_definitions(-D__XTD_USE_GSOUND__)
  else ()
    message(WARNING "GSound not found. Please install GSound end retry to build xtd to have sound.")
  endif ()
  
  pkg_check_modules(GTK REQUIRED gtk+-3.0)
  include_directories(${GTK_INCLUDE_DIRS})
  link_directories(${GTK_LIBRARY_DIRS})

  add_references(dl rt asound uuid pthread ${GSOUND_LIBRARIES} ${GTK_LIBRARIES})
endif ()

add_references(xtd.core.native)

add_sources(
  include/xtd/xtd.core.native.posix.h
  include/xtd/xtd.core.native.posix
  include/xtd/native/posix/mutex.h
  include/xtd/native/posix/mutex
  include/xtd/native/posix/semaphore.h
  include/xtd/native/posix/semaphore
  include/xtd/native/posix/strings.h
  include/xtd/native/posix/strings
  src/xtd/native/posix/condition_variable.cpp
  src/xtd/native/posix/console.cpp
  src/xtd/native/posix/critical_section.cpp
  src/xtd/native/posix/cryptography.cpp
  src/xtd/native/posix/date_time.cpp
  src/xtd/native/posix/debugger.cpp
  src/xtd/native/posix/directory.cpp
  src/xtd/native/posix/dns.cpp
  src/xtd/native/posix/drive.cpp
  src/xtd/native/posix/environment.cpp
  src/xtd/native/posix/file.cpp
  src/xtd/native/posix/file_system.cpp
  src/xtd/native/posix/guid.cpp
  src/xtd/native/posix/interlocked.cpp
  src/xtd/native/posix/named_event_wait_handle.cpp
  src/xtd/native/posix/named_mutex.cpp
  src/xtd/native/posix/named_semaphore.cpp
  src/xtd/native/posix/path.cpp
  src/xtd/native/posix/process.cpp
  src/xtd/native/posix/settings.cpp
  src/xtd/native/posix/socket.cpp
  src/xtd/native/posix/speech_synthesizer.cpp
  src/xtd/native/posix/stack_trace.cpp
  src/xtd/native/posix/system_sound.cpp
  src/xtd/native/posix/thread.cpp
  src/xtd/native/posix/translator.cpp
  src/xtd/native/posix/types.cpp
  src/xtd/native/posix/unnamed_event_wait_handle.cpp
  src/xtd/native/posix/unnamed_mutex.cpp
  src/xtd/native/posix/unnamed_semaphore.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
