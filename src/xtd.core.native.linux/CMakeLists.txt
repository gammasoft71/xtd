cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.linux)
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
  include/xtd/xtd.core.native.linux.h
  include/xtd/xtd.core.native.linux
  include/xtd/native/linux/mutex.h
  include/xtd/native/linux/mutex
  include/xtd/native/linux/semaphore.h
  include/xtd/native/linux/semaphore
  include/xtd/native/linux/strings.h
  include/xtd/native/linux/strings
  src/xtd/native/linux/condition_variable.cpp
  src/xtd/native/linux/console.cpp
  src/xtd/native/linux/critical_section.cpp
  src/xtd/native/linux/cryptography.cpp
  src/xtd/native/linux/date_time.cpp
  src/xtd/native/linux/debugger.cpp
  src/xtd/native/linux/directory.cpp
  src/xtd/native/linux/dns.cpp
  src/xtd/native/linux/drive.cpp
  src/xtd/native/linux/environment.cpp
  src/xtd/native/linux/file.cpp
  src/xtd/native/linux/file_system.cpp
  src/xtd/native/linux/guid.cpp
  src/xtd/native/linux/interlocked.cpp
  src/xtd/native/linux/named_event_wait_handle.cpp
  src/xtd/native/linux/named_mutex.cpp
  src/xtd/native/linux/named_semaphore.cpp
  src/xtd/native/linux/path.cpp
  src/xtd/native/linux/process.cpp
  src/xtd/native/linux/socket.cpp
  src/xtd/native/linux/speech_synthesizer.cpp
  src/xtd/native/linux/stack_trace.cpp
  src/xtd/native/linux/system_sound.cpp
  src/xtd/native/linux/thread.cpp
  src/xtd/native/linux/translator.cpp
  src/xtd/native/linux/types.cpp
  src/xtd/native/linux/unnamed_event_wait_handle.cpp
  src/xtd/native/linux/unnamed_mutex.cpp
  src/xtd/native/linux/unnamed_semaphore.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
