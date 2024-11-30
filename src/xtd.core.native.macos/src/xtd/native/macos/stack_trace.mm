#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/stack_trace>
#include "../../../../include/xtd/native/macos/shell_execute.hpp"
#include "../../../../include/xtd/native/macos/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <execinfo.h>
#import <unistd.h>
#include <dlfcn.h>
#include <cxxabi.h>
#include <limits>
#include <sstream>

using namespace abi;
using namespace std;
using namespace xtd::native;

string __xtd_abi_demangle(const string& name);

namespace {
  using address = void*;
  using address_collection = vector<address>;
  using frame = tuple<string, size_t, size_t, string, size_t>;
  using frame_collection = vector<frame>;

  tuple<string, size_t> get_method_and_offset(address address) {
    auto dl_info = Dl_info {};
    if (!dladdr(address, &dl_info)) return make_tuple("", numeric_limits<size_t>::max());
    return make_tuple(__xtd_abi_demangle(dl_info.dli_sname ? dl_info.dli_sname : ""), reinterpret_cast<size_t>(address) - reinterpret_cast<size_t>(dl_info.dli_saddr));
  }

  frame_collection get_frames_without_file_info(const address_collection& addresses) {
    auto frames = ::frame_collection {};
    for (const auto& address : addresses) {
      auto [method, offset] = get_method_and_offset(address);
      frames.emplace_back("", size_t {}, size_t {}, method, offset);
    }
    return frames;
  }

  frame_collection get_frames(const address_collection& addresses) {
    auto ss = stringstream {};
    ss << "atos -p " << getpid() << " ";
    for (const auto& address : addresses)
      ss << address << " ";
    auto frame_strings = xtd::native::macos::strings::split(xtd::native::macos::shell_execute::run(ss.str()), {'\n'});
    auto frames = ::frame_collection {};
    for (auto index = size_t {}; index < frame_strings.size(); ++index) {
      if (frame_strings[index].size() < 2) continue;;
      frame_strings[index].erase(frame_strings[index].begin() + frame_strings[index].size() - 1, frame_strings[index].end());
      auto method = string {};
      if (frame_strings[index].find(" (in") != frame_strings[index].npos) {
        method = frame_strings[index].substr(0, frame_strings[index].find(" (in"));
        frame_strings[index].erase(frame_strings[index].begin(), frame_strings[index].begin() + frame_strings[index].find(" (in") + 4);
        frame_strings[index].erase(frame_strings[index].begin(), frame_strings[index].begin() + frame_strings[index].find(") (") + 3);
      }
      auto file_name = string {};
      auto line = size_t {};
      if (frame_strings[index].find(":") != frame_strings[index].npos) {
        file_name = frame_strings[index].substr(0, frame_strings[index].find(":"));
        frame_strings[index].erase(frame_strings[index].begin(), frame_strings[index].begin() + frame_strings[index].find(":") + 1);
        try {
          line = stoi(frame_strings[index]);
        } catch (...) {
        }
      }
      auto [dummy, offset] = get_method_and_offset(addresses[index]);
      frames.emplace_back(file_name, line, size_t {}, method, offset);
    }
    return frames;
  }
}

size_t stack_trace::get_native_offset() {
  return 3;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  auto addresses = address_collection {size_t {1024}};
  addresses.resize(static_cast<size_t>(backtrace(addresses.data(), static_cast<int>(addresses.size()))));
  if (skip_frames + get_native_offset() > addresses.size() || skip_frames > numeric_limits<size_t>::max() - get_native_offset()) return {};
  addresses.erase(addresses.begin(), addresses.begin() + skip_frames + get_native_offset());

  auto frames = frame_collection {};
  for (const auto& frame : need_file_info ? ::get_frames(addresses) : get_frames_without_file_info(addresses)) {
    if (get<3>(frame) == "start") break;
    frames.push_back(frame);
  }
  return frames;
}
