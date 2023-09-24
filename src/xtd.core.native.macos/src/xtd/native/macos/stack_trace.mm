#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <execinfo.h>
#include <dlfcn.h>
#include <cxxabi.h>
#import <Foundation/Foundation.h>

using namespace std;
using namespace xtd::native;

namespace {
  string demangle_string(const string& method) {
    auto result = method;
    auto status = 0;
    auto demangled = abi::__cxa_demangle(method.c_str(), nullptr, 0, &status);
    if (status == 0 && demangled) result = demangled;
    free(demangled);
    return result;
  }
}

stack_trace::frames stack_trace::get_frames(size_t skip_frames) {
  //NSLog(@"%@", NSThread.callStackSymbols);
  static constexpr auto max_frames = size_t {1024};
  auto frames = stack_trace::frames {};
  auto traces = std::vector<void*> {};
  traces.resize(max_frames);
  auto nb_frames = static_cast<size_t>(backtrace(traces.data(), static_cast<int>(max_frames)));
  
  for (auto index = skip_frames + 1; index < nb_frames; ++index) {
    auto dl_info = Dl_info {};
    if (!dladdr(traces[index], &dl_info) || !dl_info.dli_sname) break;
    frames.push_back(std::make_tuple(dl_info.dli_fname, 0, 0, demangle_string(dl_info.dli_sname), reinterpret_cast<size_t>(dl_info.dli_saddr) - reinterpret_cast<size_t>(dl_info.dli_fbase)));
    if (demangle_string(dl_info.dli_sname) == std::string("main")) break;
  }
  return frames;
}
