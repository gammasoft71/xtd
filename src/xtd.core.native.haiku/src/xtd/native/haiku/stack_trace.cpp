#if __cpp_lib_stacktrace >= 202011l

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <stacktrace>

using namespace std;
using namespace xtd::native;

size_t stack_trace::get_native_offset() {
  return 3;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  auto frames = frame_collection {};
  for (auto& entry : std::stacktrace::current(skip_frames + get_native_offset())) {
    frames.push_back({need_file_info ? entry.source_file() : "", need_file_info ? static_cast<size_t>(entry.source_line()) : size_t {}, size_t {}, entry.description(), size_t {}});
    if (std::get<3>(frames.back()) == "main") break;
  }
  return frames;
}

#else

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#include "../../../../include/xtd/native/haiku/shell_execute.hpp"
#include "../../../../include/xtd/native/haiku/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd::native;

size_t stack_trace::get_native_offset() {
  return 0;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  return {};
}
#endif
