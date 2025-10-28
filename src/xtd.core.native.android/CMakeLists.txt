cmake_minimum_required(VERSION 3.20)

# Project
project(xtd.core.native.android)
include("../../scripts/cmake/xtd_commands.cmake")
include("../../scripts/cmake/xtd_version.cmake")
add_include_directories("include")

add_references(xtd.core.native)

add_sources(
  "include/xtd/core_native_export"
  "include/xtd/core_native_export.hpp"
  "include/xtd/xtd.core.native.android.hpp"
  "include/xtd/native/android/mutex.hpp"
  "include/xtd/native/android/semaphore.hpp"
  "include/xtd/native/android/shell_execute.hpp"
  "include/xtd/native/android/strings.hpp"
)
add_sources(
  "src/xtd/native/android/condition_variable.cpp"
  "src/xtd/native/android/console.cpp"
  "src/xtd/native/android/culture_info.cpp"
  "src/xtd/native/android/critical_section.cpp"
  "src/xtd/native/android/cryptography.cpp"
  "src/xtd/native/android/date_time.cpp"
  "src/xtd/native/android/debugger.cpp"
  "src/xtd/native/android/directory.cpp"
  "src/xtd/native/android/dns.cpp"
  "src/xtd/native/android/drive.cpp"
  "src/xtd/native/android/environment.cpp"
  "src/xtd/native/android/file.cpp"
  "src/xtd/native/android/file_system.cpp"
  "src/xtd/native/android/guid.cpp"
  "src/xtd/native/android/interlocked.cpp"
  "src/xtd/native/android/memory.cpp"
  "src/xtd/native/android/named_event_wait_handle.cpp"
  "src/xtd/native/android/named_mutex.cpp"
  "src/xtd/native/android/named_semaphore.cpp"
  "src/xtd/native/android/path.cpp"
  "src/xtd/native/android/process.cpp"
  "src/xtd/native/android/settings.cpp"
  "src/xtd/native/android/socket.cpp"
  "src/xtd/native/android/speech_synthesizer.cpp"
  "src/xtd/native/android/stack_trace.cpp"
  "src/xtd/native/android/system_sound.cpp"
  "src/xtd/native/android/thread.cpp"
  "src/xtd/native/android/types.cpp"
  "src/xtd/native/android/unnamed_event_wait_handle.cpp"
  "src/xtd/native/android/unnamed_mutex.cpp"
  "src/xtd/native/android/unnamed_semaphore.cpp"
)
target_type(${XTD_LIBRARY_TYPE})

# Install
add_install_include_directories("include/xtd")
install_component()
