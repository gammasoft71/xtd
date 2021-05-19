#include "../../../include/xtd/diagnostics/process.h"
#include <cstdlib>

using namespace std;
using namespace xtd::diagnostics;

process&  process::kill() {
  
  return *this;
}

process process::start(const process_start_info &start_info) {
  process process;
  process.start_info(start_info);
  /// @todo create native process (fork on linux and macOS and  CreateProcess on Windows
  ::system(strings::format("{} {}", process.start_info().file_name(), process.start_info().arguments()).c_str());
  return process;
}

process& process::wait_for_exit() {
  return *this;
}
