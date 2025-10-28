#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#include <xtd/native/assert_dialog_results>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <syslog.h>
#include <unistd.h>

using namespace xtd::native;

namespace {
  std::string get_process_name(pid_t pid) {
    auto stat_file = std::ifstream {"/proc/" + std::to_string(pid) + "/status"};
    if (!stat_file) return "Unknown";
    
    auto line = std::string {};
    getline(stat_file, line);
    auto start = line.find("Name:\t") + 1;
    
    if (start == std::string::npos) return "Unknown";
    start += std::string {"Name:\t"}.size() - 1;
    return line.substr(start, line.size() - start);
  }
}

void debugger::debug_break() {
  std::abort();
}

bool debugger::is_attached() {
  auto parent_process_name = get_process_name(getppid());
  return parent_process_name == "gdb" || parent_process_name == "lldb";
}

bool debugger::is_logging() {
  return true;
}

bool debugger::launch() {
  return true;
}

int32_t debugger::show_assert_dialog(const std::string& text, const std::string& caption) {
  return ADR_ABORT;
}

void debugger::log(int32_t level, const std::string& category, const std::string& message) {
  syslog(LOG_EMERG | LOG_USER, "%s", message.c_str());
  std::cerr << message << std::flush;
}
