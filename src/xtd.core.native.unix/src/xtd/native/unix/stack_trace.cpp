#include <version>
#if __cpp_lib_stacktrace >= 202011l

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <stacktrace>
#include <string>

using namespace std;
using namespace xtd::native;

namespace {
  std::string extract_function_name(const std::string& description) {
    if (description.empty()) return "unknown";
    auto start = description.find('!');
    start = (start == std::string::npos) ? 0 : start + 1;
    auto end = description.find('+', start);
    if (end == std::string::npos) return description.substr(start);
    return description.substr(start, end - start);
  }
}

size_t stack_trace::get_native_offset() {
  return 2;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  auto frames = frame_collection {};
  for (auto& entry : std::stacktrace::current(skip_frames + get_native_offset())) {
    frames.push_back({need_file_info ? entry.source_file() : "", need_file_info ? static_cast<size_t>(entry.source_line()) : size_t {}, size_t {}, extract_function_name(entry.description()), size_t {}});
    if (std::get<3>(frames.back()) == "main") break;
  }
  return frames;
}

#else

#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <execinfo.h>
#include <dlfcn.h>
#include <cxxabi.h>

using namespace std;
using namespace xtd::native;

string __xtd_abi_demangle(const string& name);

size_t stack_trace::get_native_offset() {
  return 3;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  static constexpr size_t max_frames = 1024;
  auto frames = stack_trace::frame_collection {};
  auto traces = vector<void*> {};
  traces.resize(max_frames);
  auto nb_frames = static_cast<size_t>(backtrace(traces.data(), static_cast<int>(max_frames)));
  
  for (auto index = skip_frames + get_native_offset(); index < nb_frames; ++index) {
    auto dl_info = Dl_info {};
    if (!dladdr(traces[index], &dl_info) || !dl_info.dli_sname) break;
    if (!need_file_info) frames.push_back(make_tuple("", 0, 0, __xtd_abi_demangle(dl_info.dli_sname), 0));
    else frames.push_back(make_tuple(dl_info.dli_fname, 0, 0, __xtd_abi_demangle(dl_info.dli_sname), reinterpret_cast<size_t>(dl_info.dli_saddr) - reinterpret_cast<size_t>(dl_info.dli_fbase)));
    if (__xtd_abi_demangle(dl_info.dli_sname) == string("main")) break;
  }
  return frames;
}

#endif
