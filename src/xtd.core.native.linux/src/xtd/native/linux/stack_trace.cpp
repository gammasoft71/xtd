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
#include "../../../../include/xtd/native/linux/shell_execute.hpp"
#include "../../../../include/xtd/native/linux/strings.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd::native;

#if defined(__ANDROID__) || defined(__CYGWIN__) || defined(__HAIKU__) || defined(__MINGW32__) || defined(__serenity__)

size_t stack_trace::get_native_offset() {
  return 0;
}

stack_trace::frame_collection stack_trace::get_frames(size_t skip_frames, bool need_file_info) {
  return {};
}
#else
#include <execinfo.h>
#include <dlfcn.h>
#include <link.h>
#include <cxxabi.h>
#include <iomanip>
#include <limits>
#include <sstream>
#include <unordered_map>

#include <iostream>

string __xtd_abi_demangle(const string& name);

namespace {
  using address = void*;
  using address_collection = vector<address>;
  using frame = tuple<string, size_t, size_t, string, size_t>;
  using frame_collection = vector<frame>;
  using module_info = tuple<string, size_t>;
  using command = tuple<string, vector<size_t>>;
  using command_collection = unordered_map<string, command>;
  
  module_info get_module_info(void* trace) {
    using link_map_ptr = link_map*;
    auto info = Dl_info {};
    auto link_map = link_map_ptr {};
    if (!dladdr1(trace, &info, reinterpret_cast<void**>(&link_map), RTLD_DL_LINKMAP)) return {"", numeric_limits<size_t>::max()};
    return {info.dli_fname, link_map->l_addr};
  }
  
  command_collection get_commands(const address_collection& addresses) {
    auto commands = command_collection {};
    for (auto index =  size_t {0}; index < addresses.size(); ++index) {
      auto [name, offset] = get_module_info(addresses[index]);
      if (name.empty()) continue;
      
      auto& [command, indices] = commands[name];
      if (command.empty()) {
        auto ss = stringstream {};
        ss << "addr2line -C -f -e \"" << name << "\"";
        command = ss.str();
      }
      auto ss = stringstream {};
      ss << " " << hex << (reinterpret_cast<size_t>(addresses[index]) - offset);
      command += ss.str();
      indices.push_back(index);
    }
    return commands;
  };
  
  frame_collection get_frames(const command_collection& commands, size_t count, bool need_file_info) {
    auto frames = frame_collection {count};
    
    for (const auto& [name, command] : commands) {
      auto& [command_to_run, indices] = command;
      //cout << "[command] = " << command_to_run << endl;
      //auto result = xtd::native::linux::shell_execute::run(command_to_run);
      //cout << result << endl;
      auto frame_strings = xtd::native::linux::strings::split(xtd::native::linux::shell_execute::run(command_to_run), {'\n'});
      for (auto index = size_t {}; index + 1 < frame_strings.size(); index += 2) {
        //cout << "   [" << indices[index / 2] << "] " << frame_strings[index];
        //if (index + 1 < frame_strings.size()) cout << " " <<  frame_strings[index + 1];
        //cout << endl;
        auto method = frame_strings[index] == "??" ? "" : frame_strings[index];
        auto file_name = string {};
        auto line = size_t {};
        if (index + 1 < frame_strings.size()) {
          file_name = frame_strings[index + 1].substr(0, frame_strings[index + 1].find(":"));
          if (file_name == "??") file_name = "";
          frame_strings[index + 1].erase(frame_strings[index + 1].begin(), frame_strings[index + 1].begin() + frame_strings[index + 1].find(":") + 1);
          try {
            line = stoi(frame_strings[index + 1].substr(0, frame_strings[index + 1].find(" ")));
          } catch (...) {
          }
        }
        frames[indices[index / 2]] = {file_name, line, size_t {}, method, size_t {}};
      }
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
  addresses.erase(addresses.begin(), addresses.begin() + skip_frames + get_native_offset() - 1);
  
  auto frames = frame_collection {};
  for (const auto& frame : ::get_frames(get_commands(addresses), addresses.size(), need_file_info)) {
    frames.push_back(frame);
    if (get<3>(frame) == "main") break;
  }
  return frames;
}
#endif
#endif
