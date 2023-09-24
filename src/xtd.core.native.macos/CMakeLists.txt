cmake_minimum_required(VERSION 3.5)

# Project
project(xtd.core.native.macos)
include(../../scripts/cmake/xtd_commands.cmake)
include(../../scripts/cmake/xtd_version.cmake)
add_include_directories(include)

# add external packages
if(MSVC)
  add_references()
elseif (APPLE)
  add_references(dl)
  add_references("-framework Foundation -framework Cocoa -framework AudioUnit")
elseif (ANDROID)
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
  include/xtd/xtd.core.native.macos.h
  include/xtd/xtd.core.native.macos
  include/xtd/native/macos/mutex.h
  include/xtd/native/macos/mutex
  include/xtd/native/macos/semaphore.h
  include/xtd/native/macos/semaphore
  include/xtd/native/macos/strings.h
  include/xtd/native/macos/strings
  src/xtd/native/macos/console.mm
  src/xtd/native/macos/condition_variable.mm
  src/xtd/native/macos/critical_section.mm
  src/xtd/native/macos/cryptography.mm
  src/xtd/native/macos/date_time.mm
  src/xtd/native/macos/debugger.mm
  src/xtd/native/macos/directory.mm
  src/xtd/native/macos/dns.mm
  src/xtd/native/macos/drive.mm
  src/xtd/native/macos/environment.mm
  src/xtd/native/macos/file.mm
  src/xtd/native/macos/file_system.mm
  src/xtd/native/macos/guid.mm
  src/xtd/native/macos/interlocked.mm
  src/xtd/native/macos/named_event_wait_handle.mm
  src/xtd/native/macos/named_mutex.mm
  src/xtd/native/macos/named_semaphore.mm
  src/xtd/native/macos/path.mm
  src/xtd/native/macos/process.mm
  src/xtd/native/macos/socket.mm
  src/xtd/native/macos/speech_synthesizer.mm
  src/xtd/native/macos/stack_trace.mm
  src/xtd/native/macos/system_sound.mm
  src/xtd/native/macos/thread.mm
  src/xtd/native/macos/translator.mm
  src/xtd/native/macos/types.mm
  src/xtd/native/macos/unnamed_event_wait_handle.mm
  src/xtd/native/macos/unnamed_mutex.mm
  src/xtd/native/macos/unnamed_semaphore.mm
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories(include/xtd)
install_component()
