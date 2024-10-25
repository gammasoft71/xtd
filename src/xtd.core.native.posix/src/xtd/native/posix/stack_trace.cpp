#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <execinfo.h>
#include <dlfcn.h>
#include <cxxabi.h>

using namespace std;
using namespace xtd::native;

namespace {
  constexpr size_t native_offset = 3;
  
  string demangle_string(const string& method) {
    auto result = method;
    auto status = 0;
    auto demangled = abi::__cxa_demangle(method.c_str(), nullptr, 0, &status);
    if (status == 0 && demangled) result = demangled;
    free(demangled);
    return result;
  }
}

size_t stack_trace::get_native_offset() {
  return native_offset;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  static constexpr size_t max_frames = 1024;
  auto frames = stack_trace::frame_collection {};
  auto traces = std::vector<void*> {};
  traces.resize(max_frames);
  auto nb_frames = static_cast<size_t>(backtrace(traces.data(), static_cast<int>(max_frames)));
  
  for (auto index = skip_frames + native_offset; index < nb_frames; ++index) {
    auto dl_info = Dl_info {};
    if (!dladdr(traces[index], &dl_info) || !dl_info.dli_sname) break;
    if (!need_file_info) frames.push_back(std::make_tuple("", 0, 0, demangle_string(dl_info.dli_sname), 0));
    else frames.push_back(std::make_tuple(dl_info.dli_fname, 0, 0, demangle_string(dl_info.dli_sname), reinterpret_cast<size_t>(dl_info.dli_saddr) - reinterpret_cast<size_t>(dl_info.dli_fbase)));
    if (demangle_string(dl_info.dli_sname) == std::string("main")) break;
  }
  return frames;
}
