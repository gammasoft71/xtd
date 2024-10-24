#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#include "../../../../include/xtd/native/macos/shell_execute.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <execinfo.h>
#include <dlfcn.h>
#include <cxxabi.h>
#include <iostream>
#include <sstream>
#import <Foundation/Foundation.h>

using namespace xtd::native;

namespace {
  constexpr size_t native_offset = 3;
  
  std::string demangle_string(const std::string& method) {
    auto result = method;
    auto status = 0;
    auto demangled = abi::__cxa_demangle(method.c_str(), nullptr, 0, &status);
    if (status == 0 && demangled) result = demangled;
    free(demangled);
    return result;
  }
  
  std::tuple<std::string, size_t, std::string> get_frame_from_address(void* address) {
    auto ss = std::stringstream {};
    ss << "atos -p " << getpid() << " " << address;
    auto frame_string = xtd::native::macos::shell_execute::run(ss.str());
    if (frame_string.empty() || frame_string.size() < 2) return {};
    frame_string.erase(frame_string.begin() + frame_string.size() - 2, frame_string.end());
    auto method = std::string {};
    if (frame_string.find(" (in") != frame_string.npos) {
      method = frame_string.substr(0, frame_string.find(" (in"));
      frame_string.erase(frame_string.begin(), frame_string.begin() + frame_string.find(" (in") + 4);
      frame_string.erase(frame_string.begin(), frame_string.begin() + frame_string.find(") (") + 3);
    }
    auto file_name = std::string {};
    auto line = size_t {0};
    if (frame_string.find(":") != frame_string.npos) {
      file_name = frame_string.substr(0, frame_string.find(":"));
      frame_string.erase(frame_string.begin(), frame_string.begin() + frame_string.find(":") + 1);
      line = std::stoi(frame_string);
    }
    return {file_name, line, method};
  }
}

size_t stack_trace::get_native_offset() {
  return native_offset;
}

stack_trace::frames stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  if (skip_frames > std::numeric_limits<size_t>::max() - native_offset) return {};
  static constexpr auto max_frames = size_t {1024};
  auto frames = stack_trace::frames {};
  auto traces = std::vector<void*> {};
  traces.resize(max_frames);
  auto nb_frames = static_cast<size_t>(backtrace(traces.data(), static_cast<int>(max_frames)));
  
  for (auto index = skip_frames + native_offset; index < nb_frames; ++index) {
    auto dl_info = Dl_info {};
    if (!dladdr(traces[index], &dl_info) || !dl_info.dli_sname) continue;
    if (demangle_string(dl_info.dli_sname) == std::string("start")) break;
    if (!need_file_info) frames.push_back(std::make_tuple("", 0, 0, demangle_string(dl_info.dli_sname), 0));
    else {
      auto [file_name, line, method] = get_frame_from_address(traces[index]);
      frames.push_back(std::make_tuple(file_name, line, 0, method, reinterpret_cast<size_t>(dl_info.dli_saddr) - reinterpret_cast<size_t>(dl_info.dli_fbase)));
    }
  }
  return frames;
}
