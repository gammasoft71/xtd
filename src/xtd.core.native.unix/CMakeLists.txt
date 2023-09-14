cmake_minimum_required(VERSION 3.5)

# Project
project(xtd.core.native.unix)
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
  include/xtd/xtd.core.native.unix.h
  include/xtd/xtd.core.native.unix
  include/xtd/native/unix/mutex.h
  include/xtd/native/unix/semaphore.h
  include/xtd/native/unix/strings.h
  src/xtd/native/unix/console.cpp
  src/xtd/native/unix/ondition_variable.cpp
  src/xtd/native/unix/critical_section.cpp
  src/xtd/native/unix/cryptography.cpp
  src/xtd/native/unix/date_time.cpp
  src/xtd/native/unix/debugger.cpp
  src/xtd/native/unix/directory.cpp
  src/xtd/native/unix/dns.cpp
  src/xtd/native/unix/drive.cpp
  src/xtd/native/unix/environment.cpp
  src/xtd/native/unix/file.cpp
  src/xtd/native/unix/file_system.cpp
  src/xtd/native/unix/guid.cpp
  src/xtd/native/unix/interlocked.cpp
  src/xtd/native/unix/named_event_wait_handle.cpp
  src/xtd/native/unix/named_mutex.cpp
  src/xtd/native/unix/named_semaphore.cpp
  src/xtd/native/unix/path.cpp
  src/xtd/native/unix/process.cpp
  src/xtd/native/unix/socket.cpp
  src/xtd/native/unix/speech_synthesizer.cpp
  src/xtd/native/unix/stack_trace.cpp
  src/xtd/native/unix/system_sound.cpp
  src/xtd/native/unix/thread.cpp
  src/xtd/native/unix/translator.cpp
  src/xtd/native/unix/types.cpp
  src/xtd/native/unix/unnamed_event_wait_handle.cpp
  src/xtd/native/unix/unnamed_mutex.cpp
  src/xtd/native/unix/unnamed_semaphore.cpp
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
