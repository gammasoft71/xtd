cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.haiku)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_include_directories("include")

add_references(network)
add_references(xtd.core.native)

add_sources(
  "include/xtd/core_native_export"
  "include/xtd/core_native_export.hpp"
  "include/xtd/xtd.core.native.haiku.hpp"
  "include/xtd/native/haiku/mutex.hpp"
  "include/xtd/native/haiku/semaphore.hpp"
  "include/xtd/native/haiku/shell_execute.hpp"
  "include/xtd/native/haiku/strings.hpp"
)
add_sources(
  "src/xtd/native/haiku/condition_variable.cpp"
  "src/xtd/native/haiku/console.cpp"
  "src/xtd/native/haiku/culture_info.cpp"
  "src/xtd/native/haiku/critical_section.cpp"
  "src/xtd/native/haiku/cryptography.cpp"
  "src/xtd/native/haiku/date_time.cpp"
  "src/xtd/native/haiku/debugger.cpp"
  "src/xtd/native/haiku/directory.cpp"
  "src/xtd/native/haiku/dns.cpp"
  "src/xtd/native/haiku/drive.cpp"
  "src/xtd/native/haiku/environment.cpp"
  "src/xtd/native/haiku/file.cpp"
  "src/xtd/native/haiku/file_system.cpp"
  "src/xtd/native/haiku/guid.cpp"
  "src/xtd/native/haiku/interlocked.cpp"
  "src/xtd/native/haiku/memory.cpp"
  "src/xtd/native/haiku/named_event_wait_handle.cpp"
  "src/xtd/native/haiku/named_mutex.cpp"
  "src/xtd/native/haiku/named_semaphore.cpp"
  "src/xtd/native/haiku/path.cpp"
  "src/xtd/native/haiku/process.cpp"
  "src/xtd/native/haiku/settings.cpp"
  "src/xtd/native/haiku/socket.cpp"
  "src/xtd/native/haiku/speech_synthesizer.cpp"
  "src/xtd/native/haiku/stack_trace.cpp"
  "src/xtd/native/haiku/system_sound.cpp"
  "src/xtd/native/haiku/thread.cpp"
  "src/xtd/native/haiku/types.cpp"
  "src/xtd/native/haiku/unnamed_event_wait_handle.cpp"
  "src/xtd/native/haiku/unnamed_mutex.cpp"
  "src/xtd/native/haiku/unnamed_semaphore.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
